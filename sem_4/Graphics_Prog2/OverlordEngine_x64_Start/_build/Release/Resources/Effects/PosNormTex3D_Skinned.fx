float4x4 gWorld : WORLD;
float4x4 gWorldViewProj : WORLDVIEWPROJECTION; 
float4x4 gBones[70];
float3 gLightDirection = float3(-0.577f, -0.577f, 0.577f);

Texture2D gDiffuseMap;
SamplerState samLinear
{
    Filter = MIN_MAG_MIP_LINEAR;
    AddressU = Wrap;// or Mirror or Clamp or Border
    AddressV = Wrap;// or Mirror or Clamp or Border
};

RasterizerState Solid
{
	FillMode = SOLID;
	CullMode = FRONT;
};

struct VS_INPUT{
	float3 pos : POSITION;
	float3 normal : NORMAL;
	float2 texCoord : TEXCOORD;
	float4 blendIndices : BLENDINDICES;
	float4 blendWeights : BLENDWEIGHTS;
};
struct VS_OUTPUT{
	float4 pos : SV_POSITION;
	float3 normal : NORMAL;
	float2 texCoord : TEXCOORD;
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

BlendState NoBlending
{
	BlendEnable[0] = FALSE;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output;

	//Step 1: transformedPosition
	float4 transformedPosition = float4(0.f, 0.f, 0.f, 0.f);

	//Step 2: transformedNormal
	float3 transformedNormal = float3(0.f, 0.f, 0.f);

	//Step 3: for each bone
	for (int index = 0; index < 4; ++index)
	{
		//Step 3a: get the current boneIndex and make sure this index is not smaller then 0
		float boneIndex = input.blendIndices[index];
		if (boneIndex < 0) continue;

		//Step 3b & 3c: calcuate boneSpace position & normal with gBones matrix and append this position and normal to the transformedPosition & transformedNormal based on the corresponding bone weight
		transformedPosition += mul(float4(input.pos, 1.f), gBones[(int)boneIndex]) * input.blendWeights[index];
		transformedNormal += mul(float4(input.normal, 0.f), gBones[(int)boneIndex]) * input.blendWeights[index];
	}

	//Step 4: make sure the w-component of the transformedPosition is 1
	transformedPosition.w = 1.f;

	//normalize the transformedNormal
	transformedNormal = normalize(transformedNormal);

	// Step 5: transform the transformedPosition to Clipping space with the WVP matrix
	output.pos = mul (transformedPosition, gWorldViewProj );

	// Step 6: transform the transformedNormal to world space with the world matrix (rotation only!!! no translation or scaling)
	output.normal = normalize(mul(input.normal, (float3x3)gWorld));

	output.texCoord = input.texCoord;

	return output;
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(VS_OUTPUT input) : SV_TARGET
{

	float4 diffuseColor = gDiffuseMap.Sample( samLinear,input.texCoord );
	float3 color_rgb= diffuseColor.rgb;
	float color_a = diffuseColor.a;
	
	//HalfLambert Diffuse :)
	float diffuseStrength = dot(input.normal, -gLightDirection);
	diffuseStrength = diffuseStrength * 0.5 + 0.5;
	diffuseStrength = saturate(diffuseStrength);
	color_rgb = color_rgb * diffuseStrength;

	return float4( color_rgb , color_a );
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
		SetBlendState(NoBlending, float4(0.0f, 0.0f, 0.0f, 0.0f), 0xFFFFFFFF);

		SetVertexShader( CompileShader( vs_4_0, VS() ) );
		SetGeometryShader( NULL );
		SetPixelShader( CompileShader( ps_4_0, PS() ) );
    }
}

