#include "stdafx.h"
#include "UberMaterial.h"

UberMaterial::UberMaterial()
	:Material<UberMaterial>(L"Effects/UberShader.fx")
{
}

void UberMaterial::InitializeEffectVariables()
{
	SetVariable_Vector(L"gLightDirection", XMFLOAT3(-0.551f, 0.534f, -0.641f));

	SetVariable_Scalar(L"gFlipGreenChannel", true);

	SetVariable_Scalar(L"gReflectionStrength", 0.6f);
	SetVariable_Scalar(L"gRefractionStrength", 0.3f);
	SetVariable_Scalar(L"gRefractionIndex", 0.9f);

	SetVariable_Scalar(L"gUseFresnelFalloff", true);
	SetVariable_Scalar(L"gFresnelPower", 2.f);
	SetVariable_Scalar(L"gFresnelMultiplier", 1.5f);
	SetVariable_Scalar(L"gFresnelHardness", 2.f);
	SetVariable_Scalar(L"gOpacityIntensity", 1.f);

	SetVariable_Scalar(L"gUseTextureDiffuse", true);
	SetVariable_Texture(L"gTextureDiffuse", ContentManager::Load<TextureData>(L"Textures/CobbleStone_DiffuseMap.dds"));

	SetVariable_Scalar(L"gUseTextureSpecularIntensity", true);
	SetVariable_Texture(L"gTextureSpecularIntensity", ContentManager::Load<TextureData>(L"Textures/CobbleStone_HeightMap.dds"));

	SetVariable_Scalar(L"gUseTextureNormal", true);
	SetVariable_Texture(L"gTextureNormal", ContentManager::Load<TextureData>(L"Textures/CobbleStone_NormalMap.dds"));

	SetVariable_Scalar(L"gUseEnvironmentMapping", true);
	SetVariable_Texture(L"gCubeEnvironment", ContentManager::Load<TextureData>(L"Textures/sunol_Cubemap.dds"));

	SetVariable_Scalar(L"gUseSpecularPhong", true);
}