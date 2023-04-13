//Precompiled Header [ALWAYS ON TOP IN CPP]
#include "stdafx.h"
#include "SpikyScene.h"
#include "Materials/DiffuseMaterial.h"

void SpikyScene::Initialize()
{
	m_pSpikyMaterial = MaterialManager::Get()->CreateMaterial<SpikyMaterial>();

	const auto pModel{ new ModelComponent(L"Meshes/OctaSphere.ovm") };

	pModel->SetMaterial(m_pSpikyMaterial);

	//octa sphere
	m_pOctaSphere = new GameObject();
	m_pOctaSphere->AddComponent(pModel);
	AddChild(m_pOctaSphere);

	m_pOctaSphere->GetTransform()->Scale(15.f, 15.f, 15.f);

	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.enableOnGUI = true;
}

void SpikyScene::Update()
{
	const float rotationSpeed{ 20.f }; //in degrees
	m_CurrentYRotation += rotationSpeed * m_SceneContext.pGameTime->GetElapsed();
	m_pOctaSphere->GetTransform()->Rotate(0.f, m_CurrentYRotation, 0.f);
}

void SpikyScene::OnGUI()
{
	m_pSpikyMaterial->DrawImGui();
}