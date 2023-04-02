#include "stdafx.h"
#include "SoftwareSkinningScene_1.h"
#include "Materials/ColorMaterial.h"
#include "Prefabs/BoneObject.h"

void SoftwareSkinningScene_1::Initialize()
{
	auto pColorMat{ MaterialManager::Get()->CreateMaterial<ColorMaterial>() };
	pColorMat->SetColor(XMFLOAT4(Colors::LightGray));
	auto pRoot{ new GameObject() };
	m_pBone0 = new BoneObject(pColorMat, 15.f);
	pRoot->AddChild(m_pBone0);
	m_pBone1 = new BoneObject(pColorMat, 15.f);
	m_pBone0->AddBone(m_pBone1);
	AddChild(pRoot);

	m_SceneContext.settings.enableOnGUI = true;
}

void SoftwareSkinningScene_1::Update()
{
	if (m_AutoRotate)
	{
		if (m_BoneRotation <= -45.f)
			m_RotationSign = 1;
		else if (m_BoneRotation >= 45.f)
			m_RotationSign = -1;

		float rotationSpeed{ 45.f };
		if (m_RotationSign == -1)
			rotationSpeed *= -1;

		m_BoneRotation += rotationSpeed * m_SceneContext.pGameTime->GetElapsed();
		m_pBone0->GetTransform()->Rotate(0.f, 0.f, m_BoneRotation);
		m_pBone1->GetTransform()->Rotate(0.f, 0.f, -m_BoneRotation * 2.f);

		m_Bone0Rotation.x = 0.f;
		m_Bone0Rotation.y = 0.f;
		m_Bone0Rotation.z = m_BoneRotation;
		m_Bone1Rotation.x = 0.f;
		m_Bone1Rotation.y = 0.f;
		m_Bone1Rotation.z = -m_BoneRotation * 2.f;
	}
	else
	{
		m_pBone0->GetTransform()->Rotate(m_Bone0Rotation.x, m_Bone0Rotation.y, m_Bone0Rotation.z);
		m_pBone1->GetTransform()->Rotate(m_Bone1Rotation.x, m_Bone1Rotation.y, m_Bone1Rotation.z);
	}
}

void SoftwareSkinningScene_1::OnGUI()
{	
	ImGui::BeginDisabled(m_AutoRotate);
	ImGui::DragFloat3("Bone 0 - ROT", ConvertUtil::ToImFloatPtr(m_Bone0Rotation), 1.f, -360.f, 360.f);
	ImGui::DragFloat3("Bone 1 - ROT", ConvertUtil::ToImFloatPtr(m_Bone1Rotation), 1.f, -360.f, 360.f);
	ImGui::EndDisabled();
	
	ImGui::Checkbox("Auto Rotate", &m_AutoRotate);
}