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

/// Create Depth Stencil State (ENABLE DEPTH WRITING)
/// Create Rasterizer State (Backface culling) 

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


//PIXEL SHADER
//------------
float4 PS(PS_INPUT input): SV_Target
{
	// Step 1: find the dimensions of the texture (the texture has a method for that)
    float width, height, levels;
	gTexture.GetDimensions(0, width, height, levels);
	
	// Step 2: calculate dx and dy (UV space for 1 pixel)	
    float dx = 1.f / width;
    float dy = 1.f / height;
	
	// Step 3: Create a double for loop (5 iterations each)
    float4 finalColor = float4(0.f, 0.f, 0.f, 0.f);
    int blurDiameter = 5;
    for (int i = 0; i < blurDiameter; ++i)
    {
        //Inside the loop, calculate the offset in each direction. Make sure not to take every pixel but move by 2 pixels each time
        for (int j = 0; j < blurDiameter; ++j)
        {
            float2 offset = float2(dx * 2 * (i - blurDiameter / 2), dy * 2 * (j - blurDiameter / 2));
            //Do a texture lookup using your previously calculated uv coordinates + the offset, and add to the final color
            float2 uv = input.TexCoord + offset;
            float4 color = gTexture.Sample(samPoint, uv);
            finalColor += color;
        }
    }

// Step 4: Divide the final color by the number of passes (in this case 5*5)
    finalColor /= 25.f;

// Step 5: return the final color
    return finalColor;
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