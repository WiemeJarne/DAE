#include "stdafx.h"
#include "UberMaterialScene.h"
#include "Materials/UberMaterial.h"

UberMaterialScene::UberMaterialScene() :
	GameScene(L"UberMaterialScene") {}

void UberMaterialScene::Initialize()
{
	m_pShpere = new GameObject();
	AddChild(m_pShpere);
	
	m_pUberMaterial = MaterialManager::Get()->CreateMaterial<UberMaterial>();

	const auto pModel{ new ModelComponent(L"Meshes/Sphere.ovm") };

	pModel->SetMaterial(m_pUberMaterial);

	m_pShpere->AddComponent(pModel);

	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.enableOnGUI = true;

	m_pShpere->GetTransform()->Scale(5, 5, 5);
}

void UberMaterialScene::Update()
{

}

void UberMaterialScene::Draw()
{
	//Optional
}

void UberMaterialScene::OnGUI()
{
	m_pUberMaterial->DrawImGui();
}
