#include "stdafx.h"
#include "ExamScene.h"
#include "Materials/ColorMaterial.h"
#include "Materials/DiffuseMaterial.h"
#include "Materials/DiffuseMaterial_Skinned.h"
#include "Materials/Shadow/ColorMaterial_Shadow_Skinned.h"
#include "Prefabs/Character.h"
#include "Grid.h"

void ExamScene::Initialize()
{
	m_SceneContext.settings.enableOnGUI = true;

	auto& pPhysX{ PxGetPhysics() };
	const auto pDefaultMaterial{ pPhysX.createMaterial(0.5f, 0.5f, 0.5f) };
	auto pBounceyMat{ pDefaultMaterial };

	//CAMERA
	auto m_pFixedCamera = new FixedCamera();
	const float cameraZOffset{ -2.5f };
	m_pFixedCamera->GetTransform()->Translate(0.f, 25.f, 0.f);
	m_pFixedCamera->GetTransform()->Rotate(85.f, 0.f, 0.f);
	AddChild(m_pFixedCamera);
	SetActiveCamera(m_pFixedCamera->GetComponent<CameraComponent>());

	//ground plane
	GameSceneExt::CreatePhysXGroundPlane(*this, pBounceyMat);

	//character
	CharacterDesc characterDesc{ pDefaultMaterial, 0.25f, 0.75f };
	characterDesc.useController = true;
	characterDesc.canJump = false;
	characterDesc.useOwnCamera = false;
	characterDesc.stepOffset = 0.f;
	characterDesc.lookTowardsWalkDirection = true;
	characterDesc.playerIndex = GamepadIndex::playerOne;
	
	auto pCharacter = AddChild(new Character(characterDesc, CharacterAnimationState::idle));
	auto pChildObject{ pCharacter->AddChild(new GameObject()) };
	auto pModel{ pChildObject->AddComponent(new ModelComponent(L"Meshes/Player.ovm")) };
	pChildObject->GetTransform()->Translate(0.f, -0.5f, 0.f);
	pModel->GetTransform()->Scale(0.01f);
	auto pWhiteMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	pWhiteMaterial->SetColor(XMFLOAT4(Colors::White));
	auto pBlackMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	pBlackMaterial->SetColor(XMFLOAT4(Colors::Black));
	auto pPinkMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	pPinkMaterial->SetColor(XMFLOAT4(Colors::LightPink));
	auto pYellowMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	pYellowMaterial->SetColor(XMFLOAT4(1.f, 177.f / 255.f, 26.f / 255.f, 1.f));
	auto pBlueMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	pBlueMaterial->SetColor(XMFLOAT4(Colors::Blue));
	auto pFaceMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	pFaceMaterial->SetColor(XMFLOAT4(253.f / 255.f, 212.f / 255.f, 126.f / 255.f, 1.f));
	pModel->SetMaterial(pBlackMaterial, 0u); //eyebrows
	pModel->SetMaterial(pBlueMaterial, 1u); //body
	pModel->SetMaterial(pPinkMaterial, 2u); //hands
	pModel->SetMaterial(pPinkMaterial, 3u); //feet
	pModel->SetMaterial(pWhiteMaterial, 4u); //stick on head
	pModel->SetMaterial(pBlackMaterial, 5u); //belt
	pModel->SetMaterial(pBlackMaterial, 6u); //eyes
	pModel->SetMaterial(pWhiteMaterial, 7u); //head
	pModel->SetMaterial(pWhiteMaterial, 8u); //arms
	pModel->SetMaterial(pWhiteMaterial, 9u); //legs
	pModel->SetMaterial(pPinkMaterial, 10u); //head ball
	pModel->SetMaterial(pFaceMaterial, 11u); //face
	pModel->SetMaterial(pYellowMaterial, 12u); //belt buckle
	pCharacter->SetModelAnimator(pModel->GetAnimator());
	pCharacter->SetPChild(pChildObject);
	pCharacter->GetTransform()->Translate(7.f, 5.f, 5.f);
	
	m_Characters.push_back(pCharacter);
	
	characterDesc.playerIndex = GamepadIndex::playerTwo;
	
	pCharacter = AddChild(new Character(characterDesc));
	pCharacter->GetTransform()->Translate(-5.f, 5.f, 0.f);

	m_Characters.push_back(pCharacter);
	
	//Input
	m_SceneContext.pInput->AddInputAction(InputAction(player1PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, GamepadIndex::playerOne));
	m_SceneContext.pInput->AddInputAction(InputAction(player2PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, GamepadIndex::playerTwo));

	constexpr int amountOfRows{ 15 };
	constexpr int amountOfCollumns{ 15 };
	m_pGrid = new Grid(amountOfRows, amountOfCollumns, this, pBounceyMat);

	//translate Camera to middle of the grid on xz-plane
	m_pFixedCamera->GetTransform()->Translate(amountOfRows / 2.f, 20.f, amountOfCollumns / 2.f + cameraZOffset);
	m_SceneContext.pLights->SetDirectionalLight({ -amountOfRows, 50.f, -amountOfCollumns }, { 0.5f, -0.8f, 0.5f });
}

ExamScene::~ExamScene()
{
	delete m_pGrid;
}

void ExamScene::Update()
{
	if (m_SceneContext.pInput->IsActionTriggered(player1PlantBomb) && m_pGrid)
	{
		m_pGrid->PlaceBomb(m_Characters[0]->GetTransform()->GetWorldPosition(), &m_Characters[0]->GetCharacterDescription());
	}
	
	if (m_SceneContext.pInput->IsActionTriggered(player2PlantBomb) && m_pGrid)
	{
		m_pGrid->PlaceBomb(m_Characters[1]->GetTransform()->GetWorldPosition(), &m_Characters[1]->GetCharacterDescription());
	}

	if(m_pGrid)
		m_pGrid->Update();
}

void ExamScene::Reset()
{}