#include "stdafx.h"
#include "BoneObject.h"

BoneObject::BoneObject(BaseMaterial* pMaterial, float lenght)
	: m_pMaterial{ pMaterial },
	  m_Lenght{ lenght }
{}

void BoneObject::Initialize(const SceneContext&)
{
	auto pEmpty{ new GameObject() };
	AddChild(pEmpty);
	auto pModel{ new ModelComponent(L"Meshes/Bone.ovm") };
	pEmpty->AddComponent(pModel);
	pModel->SetMaterial(m_pMaterial);
	pEmpty->GetTransform()->Rotate(0.f, -90.f, 0.f);
	pEmpty->GetTransform()->Scale(m_Lenght);
}

void BoneObject::AddBone(BoneObject* pBone)
{
	pBone->GetTransform()->Translate(m_Lenght, 0.f, 0.f);
	AddChild(pBone);
}

void BoneObject::CalculateBindPose()
{
	XMStoreFloat4x4(&m_BindPose, XMMatrixInverse(nullptr, DirectX::XMLoadFloat4x4(&GetTransform()->GetWorld())));

	for (auto& child : GetChildren<BoneObject>())
	{
		child->CalculateBindPose();
	}
}