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

	//auto& pPhysX{ PxGetPhysics() };
	//const auto pDefaultMaterial{ pPhysX.createMaterial(0.5f, 0.5f, 0.5f) };
	//auto pBounceyMat{ pDefaultMaterial };

	m_pMenuBackground = new GameObject();
	m_pMenuBackground->AddComponent(new SpriteComponent(L"Textures/MenuBackGround.png"));
	m_pMenuBackground->GetTransform()->Translate(0.f, 0.f, 0.3f);

	m_pFont = ContentManager::Load<SpriteFont>(L"SpriteFonts/Consolas_32.fnt");

	m_DeselectedButtonXPos = m_SceneContext.windowWidth / 2.f;

	m_pBattleButton = new GameObject();
	m_pBattleButton->AddComponent(new SpriteComponent(L"Textures/BattleButtonDeselected.png", { 0.f, 1.f }));
	m_pBattleButton->GetTransform()->Translate(m_DeselectedButtonXPos, m_SceneContext.windowHeight / 2.f, 0.2f);
	m_pBattleButton->GetTransform()->Scale(0.5f);

	m_pContinueButton = new GameObject();
	m_pContinueButton->AddComponent(new SpriteComponent(L"Textures/ContinueButtonDeselected.png", { 0.f, 1.f }));
	m_pContinueButton->GetTransform()->Translate(m_DeselectedButtonXPos, m_SceneContext.windowHeight / 2.f, 0.2f);
	m_pContinueButton->GetTransform()->Scale(0.5f);

	m_pExitButton = new GameObject();
	m_pExitButton->AddComponent(new SpriteComponent(L"Textures/ExitButtonDeselected.png"));
	m_pExitButton->GetTransform()->Translate(m_DeselectedButtonXPos, m_SceneContext.windowHeight / 2.f + 5.f, 0.2f);
	m_pExitButton->GetTransform()->Scale(0.5f);

	m_pRestartButton = new GameObject();
	m_pRestartButton->AddComponent(new SpriteComponent(L"Textures/RestartButtonDeselected.png", { 0.f, -1 }));
	m_pRestartButton->GetTransform()->Translate(m_DeselectedButtonXPos, m_SceneContext.windowHeight / 2.f + 10.f, 0.2f);
	m_pRestartButton->GetTransform()->Scale(0.5f);
	
	m_pToMainMenuButton = new GameObject();
	m_pToMainMenuButton->AddComponent(new SpriteComponent(L"Textures/ToMainMenuButtonDeselected.png", { 0.f, -2 }));
	m_pToMainMenuButton->GetTransform()->Translate(m_DeselectedButtonXPos, m_SceneContext.windowHeight / 2.f + 15.f, 0.2f);
	m_pToMainMenuButton->GetTransform()->Scale(0.5f);

	NavigateToMenu(Menus::mainMenu);

	//m_pMenuBackgroundSprite = AddChild(new GameObject());
	//m_pMenuBackgroundSprite->AddComponent(new SpriteComponent(L"Textures/MenuBackGround.png"));
	//CAMERA
	//auto m_pFixedCamera = new FixedCamera();
	//const float cameraZOffset{ -2.5f };
	//m_pFixedCamera->GetTransform()->Translate(0.f, 25.f, 0.f);
	//m_pFixedCamera->GetTransform()->Rotate(85.f, 0.f, 0.f);
	//AddChild(m_pFixedCamera);
	//SetActiveCamera(m_pFixedCamera->GetComponent<CameraComponent>());

	////ground plane
	//GameSceneExt::CreatePhysXGroundPlane(*this, pBounceyMat);

	////character
	//CharacterDesc characterDesc{ pDefaultMaterial, 0.25f, 0.75f };
	//characterDesc.useController = true;
	//characterDesc.canJump = false;
	//characterDesc.useOwnCamera = false;
	//characterDesc.stepOffset = 0.f;
	//characterDesc.lookTowardsWalkDirection = true;
	//characterDesc.playerIndex = GamepadIndex::playerOne;
	//
	//auto pCharacter = AddChild(new Character(characterDesc, CharacterAnimationState::idle));
	//auto pChildObject{ pCharacter->AddChild(new GameObject()) };
	//auto pModel{ pChildObject->AddComponent(new ModelComponent(L"Meshes/Player.ovm")) };
	//pChildObject->GetTransform()->Translate(0.f, -0.5f, 0.f);
	//pModel->GetTransform()->Scale(0.01f);
	//auto pWhiteMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	//pWhiteMaterial->SetColor(XMFLOAT4(Colors::White));
	//auto pBlackMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	//pBlackMaterial->SetColor(XMFLOAT4(Colors::Black));
	//auto pPinkMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	//pPinkMaterial->SetColor(XMFLOAT4(Colors::LightPink));
	//auto pYellowMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	//pYellowMaterial->SetColor(XMFLOAT4(1.f, 177.f / 255.f, 26.f / 255.f, 1.f));
	//auto pBlueMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	//pBlueMaterial->SetColor(XMFLOAT4(Colors::Blue));
	//auto pFaceMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
	//pFaceMaterial->SetColor(XMFLOAT4(253.f / 255.f, 212.f / 255.f, 126.f / 255.f, 1.f));
	//pModel->SetMaterial(pBlackMaterial, 0u); //eyebrows
	//pModel->SetMaterial(pBlueMaterial, 1u); //body
	//pModel->SetMaterial(pPinkMaterial, 2u); //hands
	//pModel->SetMaterial(pPinkMaterial, 3u); //feet
	//pModel->SetMaterial(pWhiteMaterial, 4u); //stick on head
	//pModel->SetMaterial(pBlackMaterial, 5u); //belt
	//pModel->SetMaterial(pBlackMaterial, 6u); //eyes
	//pModel->SetMaterial(pWhiteMaterial, 7u); //head
	//pModel->SetMaterial(pWhiteMaterial, 8u); //arms
	//pModel->SetMaterial(pWhiteMaterial, 9u); //legs
	//pModel->SetMaterial(pPinkMaterial, 10u); //head ball
	//pModel->SetMaterial(pFaceMaterial, 11u); //face
	//pModel->SetMaterial(pYellowMaterial, 12u); //belt buckle
	//pCharacter->SetModelAnimator(pModel->GetAnimator());
	//pCharacter->SetPChild(pChildObject);
	//pCharacter->GetTransform()->Translate(7.f, 5.f, 5.f);
	//
	//m_Characters.push_back(pCharacter);
	//
	//characterDesc.playerIndex = GamepadIndex::playerTwo;
	//
	//pCharacter = AddChild(new Character(characterDesc));
	//pCharacter->GetTransform()->Translate(-5.f, 5.f, 0.f);

	//m_Characters.push_back(pCharacter);
	//
	////Input
	//m_SceneContext.pInput->AddInputAction(InputAction(player1PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, GamepadIndex::playerOne));
	//m_SceneContext.pInput->AddInputAction(InputAction(player2PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, GamepadIndex::playerTwo));

	//constexpr int amountOfRows{ 15 };
	//constexpr int amountOfCollumns{ 15 };
	//m_pGrid = new Grid(amountOfRows, amountOfCollumns, this, pBounceyMat);

	////translate Camera to middle of the grid on xz-plane
	//m_pFixedCamera->GetTransform()->Translate(amountOfRows / 2.f, 20.f, amountOfCollumns / 2.f + cameraZOffset);
	//m_SceneContext.pLights->SetDirectionalLight({ -amountOfRows, 50.f, -amountOfCollumns }, { 0.5f, -0.8f, 0.5f });
}

ExamScene::~ExamScene()
{
	SafeDelete(m_pGrid);
}

void ExamScene::Update()
{
	m_SecSinceSelectedButton += m_SceneContext.pGameTime->GetElapsed();

	constexpr float epsilon{ 0.9f };
	auto leftStickPos{ m_SceneContext.pInput->GetThumbstickPosition() };
	
	if (abs(leftStickPos.y) > epsilon)
	{
		if (leftStickPos.y < 0.f)
		{
			switch (m_CurrentMenu)
			{
			case Menus::mainMenu:
				if (m_SelectedButton == Buttons::battle)
				{
					DeselectButton(Buttons::battle);
					SelectButton(Buttons::exit);
				}
				break;

			case Menus::inGameMenu:

				switch (m_SelectedButton)
				{
				case Buttons::Continue:
					DeselectButton(m_SelectedButton);
					SelectButton(Buttons::exit);
					break;

				case Buttons::exit:
					DeselectButton(m_SelectedButton);
					SelectButton(Buttons::restart);
					break;

				case Buttons::restart:
					DeselectButton(m_SelectedButton);
					SelectButton(Buttons::toMainMenu);
					break;
				}

				break;

			case Menus::endMenu:
				break;

			case Menus::none:
				break;
			}
		}

		if (leftStickPos.y > 0.f)
		{
			switch (m_CurrentMenu)
			{
			case Menus::mainMenu:
				if (m_SelectedButton == Buttons::exit)
				{
					DeselectButton(m_SelectedButton);
					SelectButton(Buttons::battle);
				}
				break;

			case Menus::inGameMenu:

				switch (m_SelectedButton)
				{
				case Buttons::exit:
					DeselectButton(m_SelectedButton);
					SelectButton(Buttons::Continue);
					break;

				case Buttons::restart:
					DeselectButton(m_SelectedButton);
					SelectButton(Buttons::exit);
					break;

				case Buttons::toMainMenu:
					DeselectButton(m_SelectedButton);
					SelectButton(Buttons::restart);
					break;
				}

				break;

			case Menus::endMenu:
				break;

			case Menus::none:
				break;
			}
		}
	}

	if (m_SelectedButton == Buttons::exit && m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_A))
	{
		exit(EXIT_SUCCESS);
	}

	if (m_SceneContext.pInput->IsKeyboardKey(InputState::pressed, 'D'))
	{
		NavigateToMenu(Menus::none);
	}
	if (m_SceneContext.pInput->IsKeyboardKey(InputState::pressed, 'A'))
	{
		NavigateToMenu(Menus::inGameMenu);
	}

	if (m_Characters.size() >= 1 && m_SceneContext.pInput->IsActionTriggered(player1PlantBomb) && m_pGrid)
	{
		m_pGrid->PlaceBomb(m_Characters[0]->GetTransform()->GetWorldPosition(), &m_Characters[0]->GetCharacterDescription());
	}
	
	if (m_Characters.size() >= 2 && m_SceneContext.pInput->IsActionTriggered(player2PlantBomb) && m_pGrid)
	{
		m_pGrid->PlaceBomb(m_Characters[1]->GetTransform()->GetWorldPosition(), &m_Characters[1]->GetCharacterDescription());
	}

	if(m_pGrid)
		m_pGrid->Update();
}

void ExamScene::Reset()
{}

void ExamScene::NavigateToMenu(Menus menuToNavigateTo)
{
	if (m_CurrentMenu == menuToNavigateTo)
		return;

	switch (menuToNavigateTo)
	{
	case Menus::mainMenu:
		
		//first remove all UI element by navigating to Menus::none
		NavigateToMenu(Menus::none);

		AddChild(m_pMenuBackground);
		AddChild(m_pBattleButton);
		AddChild(m_pExitButton);

		SelectButton(Buttons::battle, true);

		m_CurrentMenu = Menus::mainMenu;

		break;

	case Menus::inGameMenu:

		//first remove all UI element by navigating to Menus::none
		NavigateToMenu(Menus::none);

		AddChild(m_pMenuBackground);
		AddChild(m_pContinueButton);
		AddChild(m_pRestartButton);
		AddChild(m_pExitButton);
		AddChild(m_pToMainMenuButton);

		SelectButton(Buttons::Continue, true);

		m_SelectedButton = Buttons::Continue;
		m_CurrentMenu = Menus::inGameMenu;

		break;

	case Menus::endMenu:
		break;

	case Menus::none:

		switch (m_CurrentMenu)
		{
		case ExamScene::Menus::mainMenu:
			RemoveChild(m_pMenuBackground);
			RemoveChild(m_pBattleButton);
			RemoveChild(m_pExitButton);
			break;

		case ExamScene::Menus::inGameMenu:
			RemoveChild(m_pMenuBackground);
			RemoveChild(m_pContinueButton);
			RemoveChild(m_pRestartButton);
			RemoveChild(m_pExitButton);
			RemoveChild(m_pToMainMenuButton);
			break;

		case ExamScene::Menus::endMenu:

			break;
		}

		switch (m_SelectedButton)
		{
		case Buttons::battle:
			DeselectButton(Buttons::battle);
			break;

		case Buttons::exit:
			DeselectButton(Buttons::exit);
			break;

		case Buttons::restart:
			DeselectButton(Buttons::restart);
			break;

		case Buttons::toMainMenu:
			DeselectButton(Buttons::toMainMenu);
			break;

		case Buttons::Continue:
			DeselectButton(Buttons::Continue);
			break;
		}

		SelectButton(Buttons::none, true);
		m_CurrentMenu = Menus::none;
	}
}

void ExamScene::SelectButton(Buttons button, bool skipDelayTime)
{
	if (!skipDelayTime && m_SecSinceSelectedButton < 0.2f)
		return;

	m_SecSinceSelectedButton = 0.f;
	
	GameObject* pButton{};
	std::wstring texturefilePath{};

	switch (button)
	{
	case Buttons::battle:
		pButton = m_pBattleButton;
		texturefilePath = L"Textures/BattleButtonSelected.png";
		break;

	case Buttons::exit:
		pButton = m_pExitButton;
		texturefilePath = L"Textures/ExitButtonSelected.png";
		break;

	case Buttons::restart:
		pButton = m_pRestartButton;
		texturefilePath = L"Textures/RestartButtonSelected.png";
		break;

	case Buttons::toMainMenu:
		pButton = m_pToMainMenuButton;
		texturefilePath = L"Textures/ToMainMenuButtonSelected.png";
		break;

	case Buttons::Continue:
		pButton = m_pContinueButton;
		texturefilePath = L"Textures/ContinueButtonSelected.png";
		break;
	}

	m_SelectedButton = button;

	if (!pButton)
		return;

	pButton->GetComponent<SpriteComponent>()->SetTexture(texturefilePath);
	auto previousBattleButtonPos{ pButton->GetTransform()->GetWorldPosition() };
	pButton->GetTransform()->Translate(m_DeselectedButtonXPos + m_SelectedButtonXOffset, previousBattleButtonPos.y, previousBattleButtonPos.z);
}

void ExamScene::DeselectButton(Buttons button)
{
	if (m_SecSinceSelectedButton < 0.2f)
		return;

	GameObject* pButton{};
	std::wstring texturefilePath{};

	switch (button)
	{
	case Buttons::battle:
		pButton = m_pBattleButton;
		texturefilePath = L"Textures/BattleButtonDeselected.png";
		break;

	case Buttons::exit:
		pButton = m_pExitButton;
		texturefilePath = L"Textures/ExitButtonDeselected.png";
		break;

	case Buttons::restart:
		pButton = m_pRestartButton;
		texturefilePath = L"Textures/RestartButtonDeselected.png";
		break;

	case Buttons::toMainMenu:
		pButton = m_pToMainMenuButton;
		texturefilePath = L"Textures/ToMainMenuButtonDeselected.png";
		break;

	case Buttons::Continue:
		pButton = m_pContinueButton;
		texturefilePath = L"Textures/ContinueButtonDeselected.png";
		break;
	}

	if (!pButton)
		return;

	pButton->GetComponent<SpriteComponent>()->SetTexture(texturefilePath);
	auto previousBattleButtonPos{ pButton->GetTransform()->GetWorldPosition() };
	pButton->GetTransform()->Translate(m_DeselectedButtonXPos, previousBattleButtonPos.y, previousBattleButtonPos.z);
}