//Precompiled Header [ALWAYS ON TOP IN CPP]
#include "stdafx.h"
#include "ModelTestScene.h"
#include "Materials/ColorMaterial.h"
#include "Materials/DiffuseMaterial.h"

ModelTestScene::ModelTestScene() :
	GameScene(L"MinionScene") {}

void ModelTestScene::Initialize()
{
	auto& pPhysX{ PxGetPhysics() };
	auto pBounceyMat{ pPhysX.createMaterial(0.5f, 0.5f, 0.f) };

	//ground plane
	GameSceneExt::CreatePhysXGroundPlane(*this, pBounceyMat);

	//color material
	//ColorMaterial* pMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial>() };
	//pMaterial->SetVariable_Vector(L"gColor", XMFLOAT4(Colors::Red));
	
	//diffuse material
	DiffuseMaterial* pMaterial{ MaterialManager::Get()->CreateMaterial<DiffuseMaterial>() };
	pMaterial->SetDiffuseTexture(L"Textures/Chair_Dark.dds");

	const auto pModel{ new ModelComponent(L"Meshes/Chair.ovm") };

	pModel->SetMaterial(pMaterial);

	//chair
	m_pChair = new GameObject();
	m_pChair->AddComponent(pModel);
	AddChild(m_pChair);
	
	const auto pConvexMesh{ ContentManager::Load<PxConvexMesh>(L"Meshes/Chair.ovpc") };
	auto pRigidBody{ m_pChair->AddComponent(new RigidBodyComponent(false)) };
	pRigidBody->AddCollider(PxConvexMeshGeometry(pConvexMesh), *pBounceyMat);
	
	m_pChair->GetTransform()->Translate(0, 5, 0);
}

void ModelTestScene::Update()
{
	
}

void ModelTestScene::Draw()
{
	//Optional
}

void ModelTestScene::OnGUI()
{
	ImGui::Text("This only activates if\n SceneSettings.enableOnGUI is True.\n\n");
	ImGui::Text("Use ImGui to add custom\n controllable scene parameters!");
	ImGui::ColorEdit3("Demo ClearColor", &m_SceneContext.settings.clearColor.x, ImGuiColorEditFlags_NoInputs);
}
