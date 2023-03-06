//DX10 - FLAT SHADER
//Digital Arts & Entertainment


//GLOBAL VARIABLES
//****************
float4x4 gMatrixWorldViewProj : WORLDVIEWPROJECTION;
float4x4 gMatrixWorld : WORLD;

float4 gColorDiffuse : COLOR = float4(1.0, 1.0, 1.0, 1.0);

float3 gLightDirection : DIRECTION
<
	string UIName = "DirectionalLight";
	string Object = "TargetLight";
>
= float3(1,0,0);

float4 gColorAmbient : COLOR = float4(0,0,0,0);
float gAmbientIntensity
<
	string UIName = "Ambient Intensity";
	string UIWidget = "Slider";
	float UIMin = 0.0;
	float UIMax = 1.0;
	float UIStep = 0.01;
>
= 0.0f;

Texture2D gTextureDiffuse
<
	string UIName = "Diffuse Texture";
	string ResourceName = "CobbleStone_DiffuseMap.dds";
	string ResourceType = "2D";
>;

//STATES
//******
RasterizerState gRS_NoCulling { CullMode = NONE; };
SamplerState gSamplet
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = WRAP;
	AddressV = WRAP;
};

//Input/Outpt Struct
struct VS_INPUT
{
	float3 Position : POSITION;
	float3 Normal : NORMAL;
	float2 TexCoord : TEXCOORD0;
};

struct VS_OUTPUT
{
	float4 Position : SV_POSITION;
	float3 Normal : NORMAL;
	float2 TexCoord : TEXCOORD0;
};

//MAIN VERTEX SHADER
//******************
VS_OUTPUT MainVS(VS_INPUT input)
{
	VS_OUTPUT output = (VS_OUTPUT)0;
	
	output.Position = mul(float4(input.Position, 1.0f), gMatrixWorldViewProj);
	output.Normal = mul(input.Normal, (float3x3)gMatrixWorld);
	output.TexCoord = input.TexCoord;
	
	return output;
}


//MAIN PIXEL SHADER
//*****************
float4 MainPS(VS_OUTPUT input) : SV_TARGET
{
	float diffuseStrength = dot(input.Normal, -gLightDirection);
	float4 diffuse = gColorDiffuse * saturate(diffuseStrength);
	diffuse *= gTextureDiffuse.Sample(gSamplet, input.TexCoord);
	
	float4 ambient = gColorAmbient * gAmbientIntensity;
	
	return diffuse;
}


//TECHNIQUES
//**********
technique10 DefaultTechnique {
	pass p0 {
		SetRasterizerState(gRS_NoCulling);	
		SetVertexShader(CompileShader(vs_4_0, MainVS()));
		SetPixelShader(CompileShader(ps_4_0, MainPS()));
	}
}