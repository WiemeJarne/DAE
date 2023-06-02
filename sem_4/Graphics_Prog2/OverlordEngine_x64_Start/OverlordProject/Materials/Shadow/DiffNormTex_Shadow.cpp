#include "stdafx.h"
#include "DiffNormTex_Shadow.h"

DiffNormTex_Shadow::DiffNormTex_Shadow() :
	Material(L"Effects/Shadow/DiffNormTex_Shadow.fx")
{}

void DiffNormTex_Shadow::SetDiffuseTexture(const std::wstring& assetFile)
{
	m_pDiffuseTexture = ContentManager::Load<TextureData>(assetFile);
	SetVariable_Texture(L"gDiffuseMap", m_pDiffuseTexture);
}

void DiffNormTex_Shadow::SetNormalMap(const std::wstring& assetFile)
{
	m_pNormalMap = ContentManager::Load<TextureData>(assetFile);
	SetVariable_Texture(L"gNormalMap", m_pNormalMap);
}

void DiffNormTex_Shadow::InitializeEffectVariables()
{
}

void DiffNormTex_Shadow::OnUpdateModelVariables(const SceneContext& sceneContext, const ModelComponent* pModel) const
{

	//Update The Shader Variables
	//1. Update the LightWVP > Used to Transform a vertex into Light clipping space
	//	LightWVP = model_world * light_viewprojection
	//	(light_viewprojection [LightVP] can be acquired from the ShadowMapRenderer)
	const XMMATRIX lightWVP{ XMLoadFloat4x4(&pModel->GetTransform()->GetWorld()) * XMLoadFloat4x4(&ShadowMapRenderer::Get()->GetLightVP()) };

	XMFLOAT4X4 fLightWVP{};
	XMStoreFloat4x4(&fLightWVP, lightWVP);

	SetVariable_Matrix(L"gWorldViewProj_Light", reinterpret_cast<const float*>(&fLightWVP));

	//2. Update the ShadowMap texture
	SetVariable_Texture(L"gShadowMap", ShadowMapRenderer::Get()->GetShadowMap());

	//3. Update the Light Direction (retrieve the direction from the LightManager > sceneContext)
	SetVariable_Vector(L"gLightDirection", sceneContext.pLights->GetDirectionalLight().direction);

	SetVariable_Matrix(L"gViewInverse", sceneContext.pCamera->GetViewInverse());
}
