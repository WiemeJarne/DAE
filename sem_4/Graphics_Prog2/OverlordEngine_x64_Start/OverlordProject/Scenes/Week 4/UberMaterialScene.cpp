#include "stdafx.h"
#include "UberMaterialScene.h"
#include "Materials/UberMaterial.h"

void UberMaterialScene::Initialize()
{
	m_pSphere = new GameObject();
	AddChild(m_pSphere);
	
	m_pUberMaterial = MaterialManager::Get()->CreateMaterial<UberMaterial>();

	const auto pModel{ new ModelComponent(L"Meshes/Sphere.ovm") };

	pModel->SetMaterial(m_pUberMaterial);

	m_pSphere->AddComponent(pModel);

	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.enableOnGUI = true;
	m_SceneContext.pCamera->GetTransform()->Translate(0.f, 15.f, -25.f);

	m_pSphere->GetTransform()->Scale(5, 5, 5);
}

void UberMaterialScene::Update()
{
	const float rotationSpeed{ 20.f }; //in degrees
	m_CurrentYRotation += rotationSpeed * m_SceneContext.pGameTime->GetElapsed();
	m_pSphere->GetTransform()->Rotate(0.f, m_CurrentYRotation, 0.f);
}

void UberMaterialScene::OnGUI()
{
	m_pUberMaterial->DrawImGui();
}
