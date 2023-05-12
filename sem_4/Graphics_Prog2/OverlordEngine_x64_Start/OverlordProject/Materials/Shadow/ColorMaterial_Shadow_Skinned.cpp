#include "stdafx.h"
#include "ColorMaterial_Shadow_Skinned.h"

ColorMaterial_Shadow_Skinned::ColorMaterial_Shadow_Skinned() :
	Material(L"Effects/Shadow/PosNormCol3D_Shadow_Skinned.fx")
{}

void ColorMaterial_Shadow_Skinned::SetColor(const XMFLOAT4& color) const
{
	SetVariable_Vector(L"gColor", color);
}

void ColorMaterial_Shadow_Skinned::InitializeEffectVariables()
{
}

void ColorMaterial_Shadow_Skinned::OnUpdateModelVariables(const SceneContext& sceneContext, const ModelComponent* pModel) const
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

	//4. Update Bones
	ModelAnimator* pModelAnimator{ pModel->GetAnimator() };
	ASSERT_NULL_(pModelAnimator);

	const auto& boneTransforms{ pModelAnimator->GetBoneTransforms() };
	SetVariable_MatrixArray(L"gBones", reinterpret_cast<const float*>(boneTransforms.data()), static_cast<UINT>(boneTransforms.size()));
}
