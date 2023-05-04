#include "stdafx.h"
#include "ExamScene.h"
#include "Materials/ColorMaterial.h"
#include "Materials/DiffuseMaterial.h"
#include "Materials/DiffuseMaterial_Skinned.h"
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
	const float cameraZOffset{ -3.f };
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
	characterDesc.maxMoveSpeed = 5.f;
	characterDesc.playerIndex = GamepadIndex::playerOne;
	
	auto pCharacter = AddChild(new Character(characterDesc));
	pCharacter->GetTransform()->Translate(7.f, 5.f, 5.f);

	m_Characters.push_back(pCharacter);
	
	characterDesc.playerIndex = GamepadIndex::playerTwo;
	
	pCharacter = AddChild(new Character(characterDesc));
	pCharacter->GetTransform()->Translate(-5.f, 5.f, 0.f);

	m_Characters.push_back(pCharacter);
	
	//Input
	m_SceneContext.pInput->AddInputAction(InputAction(player1PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, GamepadIndex::playerOne));
	m_SceneContext.pInput->AddInputAction(InputAction(player2PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, GamepadIndex::playerTwo));

	const int amountOfRows{ 15 };
	const int amountOfCollumns{ 15 };
	m_pGrid = new Grid(amountOfRows, amountOfCollumns, this, pBounceyMat);

	//translate Camera to middle of the grid on xz-plane
	m_pFixedCamera->GetTransform()->Translate(amountOfRows / 2.f, 30.f, amountOfCollumns / 2.f + cameraZOffset);
	
	//auto pAnimator = pModel->GetAnimator();
	//pAnimator->SetAnimation(0);
	//pAnimator->SetAnimationSpeed(1.f);
	//pAnimator->Play();
}

void ExamScene::Update()
{
	if (m_SceneContext.pInput->IsActionTriggered(player1PlantBomb))
	{
		m_pGrid->PlaceBomb(m_Characters[0]->GetTransform()->GetWorldPosition(), 2);
	}
	
	if (m_SceneContext.pInput->IsActionTriggered(player2PlantBomb))
	{
		m_pGrid->PlaceBomb(m_Characters[1]->GetTransform()->GetWorldPosition(), 2);
	}

	m_pGrid->Update();
}

void ExamScene::Reset()
{}