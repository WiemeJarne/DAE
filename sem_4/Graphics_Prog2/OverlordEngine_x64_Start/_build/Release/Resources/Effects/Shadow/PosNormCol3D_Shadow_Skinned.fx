float4x4 gWorld : WORLD;
float4x4 gWorldViewProj : WORLDVIEWPROJECTION;
float4x4 gWorldViewProj_Light;
float3 gLightDirection = float3(-0.577f, -0.577f, 0.577f);
float gShadowMapBias = 0.01f;
float4x4 gBones[70];
float4 gColor = float4(1.0f, 1.0f, 1.0f, 1.0f);

Texture2D gShadowMap;

SamplerComparisonState cmpSampler
{
	// sampler state
	Filter = COMPARISON_MIN_MAG_MIP_LINEAR;
	AddressU = MIRROR;
	AddressV = MIRROR;

	// sampler comparison state
	ComparisonFunc = LESS_EQUAL;
};

SamplerState samLinear
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;// or Mirror or Clamp or Border
	AddressV = Wrap;// or Mirror or Clamp or Border
};

struct VS_INPUT {
	float3 pos : POSITION;
	float3 normal : NORMAL;
	float4 BoneIndices : BLENDINDICES;
	float4 BoneWeights : BLENDWEIGHTS;
};
struct VS_OUTPUT {
	float4 pos : SV_POSITION;
	float3 normal : NORMAL;
	float4 lPos : TEXCOORD1;
};

DepthStencilState EnableDepth
{
	DepthEnable = TRUE;
	DepthWriteMask = ALL;
};

RasterizerState NoCulling
{
	CullMode = NONE;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VS(VS_INPUT input) {

	VS_OUTPUT output = (VS_OUTPUT)0;

	float4 transformedPosition = float4(0.f, 0.f, 0.f, 0.f);

	float3 transformedNormal = float3(0.f, 0.f, 0.f);

	for (int index = 0; index < 4; ++index)
	{
		float boneIndex = input.BoneIndices[index];
		if (boneIndex < 0) continue;

		transformedPosition += mul(float4(input.pos, 1.f), gBones[boneIndex]) * input.BoneWeights[index];
		transformedNormal += mul(float4(input.normal, 0.f), gBones[boneIndex]) * input.BoneWeights[index];
	}

	transformedPosition.w = 1.f;

	output.pos = mul(transformedPosition, gWorldViewProj);
	output.normal = normalize(mul(transformedNormal, (float3x3)gWorld));
	output.lPos = mul(transformedPosition, gWorldViewProj_Light);

	return output;
}

float2 texOffset(int u, int v)
{
	//return offseted value (our shadow map has the following dimensions: 1280 * 720)
	return float2(u / 1280.f, v / 720.f);
}

float EvaluateShadowMap(float4 lpos)
{
	lpos.xyz /= lpos.w;

	//if position is not visible to the light don't eluminate it
	if (lpos.x < -1.f || lpos.x > 1.f
		|| lpos.y < -1.f || lpos.y > 1.f
		|| lpos.z < 0.f || lpos.z > 1.f)
		return 0.f;

	//transfomr clip space coords to texture space coords ( [-1,1] to [0,1] )
	lpos.x = lpos.x / 2.f + 0.5f;
	lpos.y = lpos.y / -2.f + 0.5f;

	//apply shadow map bias
	lpos.z -= gShadowMapBias;

	//PCF sampling for shadow map
	float sum = 0;

	for (float y = -1.5f; y <= 1.5f; y += 1.f)
	{
		for (float x = -1.5f; x <= 1.5f; x += 1.f)
		{
			sum += gShadowMap.SampleCmpLevelZero(cmpSampler, lpos.xy + texOffset(x, y), lpos.z);
		}
	}

	//sample shadow map - point sampler
	float shadowMapDepth = sum / 16.f;

	return lerp(0.25f, 1.f, shadowMapDepth);
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(VS_OUTPUT input) : SV_TARGET{

	float shadowValue = EvaluateShadowMap(input.lPos);

	float3 color_rgb = gColor.rgb;
	float color_a = gColor.a;

	//HalfLambert Diffuse :)
	float diffuseStrength = dot(input.normal, -gLightDirection);
	diffuseStrength = diffuseStrength * 0.5 + 0.5;
	diffuseStrength = saturate(diffuseStrength);
	color_rgb = color_rgb * diffuseStrength;

	return float4(color_rgb * shadowValue, color_a);
}

//--------------------------------------------------------------------------------------
// Technique
//--------------------------------------------------------------------------------------
technique11 Default
{
	pass P0
	{
		SetRasterizerState(NoCulling);
		SetDepthStencilState(EnableDepth, 0);

		SetVertexShader(CompileShader(vs_4_0, VS()));
		SetGeometryShader(NULL);
		SetPixelShader(CompileShader(ps_4_0, PS()));
	}
}