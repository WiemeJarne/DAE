#include "stdafx.h"
#include "UberMaterialScene.h"
#include "Materials/UberMaterial.h"

UberMaterialScene::UberMaterialScene() :
	GameScene(L"UberMaterialScene") {}

void UberMaterialScene::Initialize()
{
	m_pShpere = new GameObject();
	AddChild(m_pShpere);
	
	UberMaterial* pMaterial{ MaterialManager::Get()->CreateMaterial<UberMaterial>() };

	const auto pModel{ new ModelComponent(L"Meshes/Sphere.ovm") };

	pModel->SetMaterial(pMaterial);

	m_pShpere->AddComponent(pModel);

	//m_SceneContext.settings.drawGrid = false;
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
	ImGui::Text("This only activates if\n SceneSettings.enableOnGUI is True.\n\n");
	ImGui::Text("Use ImGui to add custom\n controllable scene parameters!");
	ImGui::ColorEdit3("Demo ClearColor", &m_SceneContext.settings.clearColor.x, ImGuiColorEditFlags_NoInputs);
}
