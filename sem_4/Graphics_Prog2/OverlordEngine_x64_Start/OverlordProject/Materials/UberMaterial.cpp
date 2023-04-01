#include "stdafx.h"
#include "UberMaterial.h"

UberMaterial::UberMaterial()
	:Material<UberMaterial>(L"Effects/UberShader.fx")
{
}

void UberMaterial::InitializeEffectVariables()
{
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