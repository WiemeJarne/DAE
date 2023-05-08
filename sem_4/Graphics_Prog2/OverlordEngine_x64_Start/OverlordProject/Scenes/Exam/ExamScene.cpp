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
	//auto m_pFixedCamera = new FixedCamera();
	//const float cameraZOffset{ -3.f };
	//m_pFixedCamera->GetTransform()->Translate(0.f, 25.f, 0.f);
	//m_pFixedCamera->GetTransform()->Rotate(85.f, 0.f, 0.f);
	//AddChild(m_pFixedCamera);
	//SetActiveCamera(m_pFixedCamera->GetComponent<CameraComponent>());

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

	//constexpr int amountOfRows{ 15 };
	//constexpr int amountOfCollumns{ 15 };
	//m_pGrid = new Grid(amountOfRows, amountOfCollumns, this, pBounceyMat);

	//translate Camera to middle of the grid on xz-plane
	//m_pFixedCamera->GetTransform()->Translate(amountOfRows / 2.f, 30.f, amountOfCollumns / 2.f + cameraZOffset);
	
	auto pBonusMaterial{ MaterialManager::Get()->CreateMaterial<DiffuseMaterial>() };
	pBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/FullFire.png");

	auto pBonus{ AddChild(new GameObject()) };
	auto pModel{ pBonus->AddComponent(new ModelComponent(L"Meshes/Bonus.ovm")) };
	pModel->SetMaterial(pBonusMaterial);
	pBonus->GetTransform()->Scale(0.01f);
	
	auto pAnimator = pModel->GetAnimator();
	auto clipCount{pAnimator->GetClipCount()};
	std::cout << clipCount << '\n';
	auto clipNames { new char* [clipCount] };
	for (UINT i{ 0 }; i < clipCount; ++i)
	{
		auto clipName = StringUtil::utf8_encode(pAnimator->GetClip(static_cast<int>(i)).name);
		const auto clipSize = clipName.size();
		clipNames[i] = new char[clipSize + 1];
		strncpy_s(clipNames[i], clipSize + 1, clipName.c_str(), clipSize);
	}
	pAnimator->SetAnimation(0);
	pAnimator->SetAnimationSpeed(1.f);
	pAnimator->Play();
	std::cout << pAnimator->IsPlaying() << '\n';
}

void ExamScene::Update()
{
	if (m_SceneContext.pInput->IsActionTriggered(player1PlantBomb) && m_pGrid)
	{
		m_pGrid->PlaceBomb(m_Characters[0]->GetTransform()->GetWorldPosition(), 2);
	}
	
	if (m_SceneContext.pInput->IsActionTriggered(player2PlantBomb) && m_pGrid)
	{
		m_pGrid->PlaceBomb(m_Characters[1]->GetTransform()->GetWorldPosition(), 2);
	}

	if(m_pGrid)
		m_pGrid->Update();
}

void ExamScene::Reset()
{}