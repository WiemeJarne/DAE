float4x4 gWorld : WORLD;
float4x4 gWorldViewProj : WORLDVIEWPROJECTION;
float4x4 gWorldViewProj_Light;
float4x4 gViewInverse;
float3 gLightDirection = float3(-0.577f, -0.577f, 0.577f);
float gShadowMapBias = 0.01f;

Texture2D gDiffuseMap;
Texture2D gNormalMap;
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
	AddressW = Wrap;// or Mirror or Clamp or Border
};

SamplerState samPoint
{
	Filter = MIN_MAG_MIP_POINT;
	AddressU = Wrap;// or Mirror or Clamp or Border
	AddressV = Wrap;// or Mirror or Clamp or Border
};

RasterizerState Solid
{
	FillMode = SOLID;
	CullMode = FRONT;
};

struct VS_INPUT
{
	float3 pos : POSITION;
	float3 normal : NORMAL;
	float3 tangent : TANGENT;
	float2 texCoord : TEXCOORD;
};

struct VS_OUTPUT
{
	float4 pos : SV_POSITION;
	float4 worldPos : COLOR0;
	float3 normal : NORMAL;
	float3 tangent : TANGENT;
	float2 texCoord : TEXCOORD;
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

float3 CalculateNormal(float3 tangent, float3 normal, float2 texCoord)
{
	float3 newNormal = normal;

	float3 binormal = cross(normal, tangent);

	//if (gFlipGreenChannel)
	//{
	//	binormal = -binormal;
	//}

	float3 normalMap = gNormalMap.Sample(samLinear, texCoord).rgb;

	normalMap = 2.f * normalMap - float3(1.f, 1.f, 1.f);

	float4x4 tangentSpaceAxis = float4x4(float4(tangent, 0.f), float4(binormal, 0.f), float4(normal, 0.f), float4(0.f, 0.f, 0.f, 1.f));

	newNormal = normalize(mul(float4(normalMap, 0.f), tangentSpaceAxis).xyz);

	return newNormal;
}

float3 CalculateDiffuse(float3 normal, float2 texCoord)
{
	float3 diffuseColor = gDiffuseMap.Sample(samLinear, texCoord).rgb;

	float diffuseIntensity = dot(normal, -gLightDirection);
	diffuseIntensity *= 0.5f;
	diffuseIntensity += 0.5f;
	diffuseIntensity = pow(diffuseIntensity, 2);
	
	return saturate(diffuseColor * diffuseIntensity);
}

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;

	//complete Vertex Shader
	output.pos = mul(float4(input.pos, 1.f), gWorldViewProj);
	output.worldPos = mul(float4(input.pos, 1.f), gWorld);
	output.normal = normalize(mul(input.normal, (float3x3)gWorld));
	output.tangent = normalize(mul(input.tangent, (float3x3)gWorld));
	output.texCoord = input.texCoord;
	//project our position to light clip space and store it in lPos
	output.lPos = mul(float4(input.pos, 1.f), gWorldViewProj_Light);

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
float4 PS(VS_OUTPUT input) : SV_TARGET
{
	float shadowValue = EvaluateShadowMap(input.lPos);

	float3 viewDirection = normalize(input.worldPos.xyz - gViewInverse[3].xyz);

	//normal
	float3 newNormal = CalculateNormal(input.tangent, input.normal, input.texCoord);

	//diffuse
	float3 diffColor = CalculateDiffuse(newNormal, input.texCoord);

	//float4 diffuseColor = gDiffuseMap.Sample(samLinear,input.texCoord);
	//float3 color_rgb = diffuseColor.rgb;
	//float color_a = diffuseColor.a;

	//HalfLambert Diffuse :)
	//float diffuseStrength = dot(input.normal, -gLightDirection);
	//diffuseStrength = diffuseStrength * 0.5 + 0.5;
	//diffuseStrength = saturate(diffuseStrength);
	//color_rgb = color_rgb * diffuseStrength;

	//final color calculation
	float3 finalColor = diffColor;

	return float4(finalColor, 1.f);

	//return float4(color_rgb * shadowValue , color_a);
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