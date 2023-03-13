#include "stdafx.h"
#include "UberMaterial.h"

UberMaterial::UberMaterial()
	:Material<UberMaterial>(L"Effects/UberShader.fx")
{
}

void UberMaterial::InitializeEffectVariables()
{
	auto texture = ContentManager::Load<TextureData>(L"Textures/CobbleStone_DiffuseMap.dds");
	SetVariable_Texture(L"gTextureDiffuse", texture);
}