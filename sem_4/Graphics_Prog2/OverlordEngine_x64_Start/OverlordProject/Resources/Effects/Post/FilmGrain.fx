//=============================================================================
//// Shader uses position and texture
//=============================================================================
SamplerState samPoint
{
    Filter = MIN_MAG_MIP_POINT;
    AddressU = Mirror;
    AddressV = Mirror;
};

Texture2D gTexture;
float gGrainStrenght = 0.2f;

DepthStencilState EnableDepthWriting
{
    DepthEnable = true;
    DepthWriteMask = ALL;
    DepthFunc = LESS_EQUAL;
};

RasterizerState BackfaceCulling
{
    CullMode = BACK;
    FillMode = SOLID;
};

//IN/OUT STRUCTS
//--------------
struct VS_INPUT
{
    float3 Position : POSITION;
    float2 TexCoord : TEXCOORD0;

};

struct PS_INPUT
{
    float4 Position : SV_POSITION;
    float2 TexCoord : TEXCOORD1;
};

//VERTEX SHADER
//-------------
PS_INPUT VS(VS_INPUT input)
{
    PS_INPUT output = (PS_INPUT)0;

    // Set the Position
    output.Position = float4(input.Position, 1.f);

    // Set the TexCoord
    output.TexCoord = input.TexCoord;

    return output;
}

float random(float2 p)
{
        float seed = dot(p, float2(12.9898, 78.233)) + fract(sin(dot(p, float2(4.5453, 23.187))) * 43758.5453);
        return frac(seed);
}


//PIXEL SHADER
//------------
float4 PS(PS_INPUT input) : SV_Target
{
    // Step 1: sample the texture
    float4 sampled = gTexture.Sample(samPoint, input.TexCoord);

    return sampled * random(input.TexCoord) * gGrainStrenght;
}


//TECHNIQUE
//---------
technique11 Blur
{
    pass P0
    {
        SetDepthStencilState(EnableDepthWriting, 0);
        SetRasterizerState(BackfaceCulling);
        SetVertexShader(CompileShader(vs_4_0, VS()));
        SetPixelShader(CompileShader(ps_4_0, PS()));
    }
}