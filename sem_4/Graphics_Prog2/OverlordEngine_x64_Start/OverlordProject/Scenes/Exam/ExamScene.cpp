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
	srand(static_cast<unsigned int>(time(nullptr)));

	m_SceneContext.settings.enableOnGUI = true;

	auto& pPhysX{ PxGetPhysics() };
	m_pDefaultMaterial = pPhysX.createMaterial(0.5f, 0.5f, 0.5f);

	m_Characters.resize(4);

	//CAMERA
	auto m_pFixedCamera = new FixedCamera();
	//
	//m_pFixedCamera->GetTransform()->Translate(0.f, 5.f, -5.f);
	//m_pFixedCamera->GetTransform()->Rotate(45.f, 0.f, 0.f);
	AddChild(m_pFixedCamera);
	SetActiveCamera(m_pFixedCamera->GetComponent<CameraComponent>());

	m_pFont = ContentManager::Load<SpriteFont>(L"SpriteFonts/Consolas_48.fnt");
	
	InitializeSprites();

	//grass material
	auto pGrassMaterial{ MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>() };
	pGrassMaterial->SetDiffuseTexture(L"Textures/Diffuse_Seamless_Grass_Tile.png");

	m_pTerrain = AddChild(new GameObject());
	auto pModel{ m_pTerrain->AddComponent(new ModelComponent(L"Meshes/Terrain.ovm")) };
	pModel->SetMaterial(pGrassMaterial);
	m_pTerrain->GetTransform()->Scale(0.01f);
	m_pTerrain->GetTransform()->Translate(0.f, -5.f, 0.f);

	NavigateToMenu(Menus::mainMenu);

	////ground plane
	GameSceneExt::CreatePhysXGroundPlane(*this, m_pDefaultMaterial);

	m_pRedMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
	m_pRedMaterial->SetColor(XMFLOAT4(Colors::IndianRed));
	m_pSkinMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
	m_pSkinMaterial->SetColor(XMFLOAT4(253.f / 255.f, 212.f / 255.f, 126.f / 255.f, 1.f));
	m_pBlueMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
	m_pBlueMaterial->SetColor(XMFLOAT4(Colors::CornflowerBlue));
	m_pBlackMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
	m_pBlackMaterial->SetColor(XMFLOAT4(0.2f, 0.2f, 0.2f, 1.f));
	m_pYellowMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
	m_pYellowMaterial->SetColor(XMFLOAT4(1.f, 177.f / 255.f, 26.f / 255.f, 1.f));
	m_pWhiteMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
	m_pWhiteMaterial->SetColor(XMFLOAT4(Colors::White));	

	Reset();
}

ExamScene::~ExamScene()
{
	SafeDelete(m_pGrid);
}

void ExamScene::Update()
{
	UpdateButtons();

	UpdateMenus();

	if (m_CurrentMenu == Menus::joinMenu)
	{
		if(m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START))
			JoinGame(GamepadIndex::playerOne);

		if (m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START, GamepadIndex::playerTwo))
			JoinGame(GamepadIndex::playerTwo);

		if (m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START, GamepadIndex::playerThree))
			JoinGame(GamepadIndex::playerThree);

		if (m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START, GamepadIndex::playerFour))
			JoinGame(GamepadIndex::playerFour);

		if (m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_A)
			|| m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_A, GamepadIndex::playerTwo)
			|| m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_A, GamepadIndex::playerThree)
			|| m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_A, GamepadIndex::playerFour))
		{
			StartRound();
		}
	}

	if (m_IsPaused)
		return;

	if (m_Characters[0] && m_SceneContext.pInput->IsActionTriggered(player1PlantBomb) && m_pGrid && !m_Characters[0]->GetCharacterDescription().isDead)
	{
		m_pGrid->PlaceBomb(m_Characters[0]->GetTransform()->GetWorldPosition(), &m_Characters[0]->GetCharacterDescription());
	}
	
	if (m_Characters[1] && m_SceneContext.pInput->IsActionTriggered(player2PlantBomb) && m_pGrid && !m_Characters[1]->GetCharacterDescription().isDead)
	{
		m_pGrid->PlaceBomb(m_Characters[1]->GetTransform()->GetWorldPosition(), &m_Characters[1]->GetCharacterDescription());
	}

	if (m_Characters[2] && m_SceneContext.pInput->IsActionTriggered(player3PlantBomb) && m_pGrid && !m_Characters[2]->GetCharacterDescription().isDead)
	{
		m_pGrid->PlaceBomb(m_Characters[2]->GetTransform()->GetWorldPosition(), &m_Characters[2]->GetCharacterDescription());
	}

	if (m_Characters[3] && m_SceneContext.pInput->IsActionTriggered(player4PlantBomb) && m_pGrid && !m_Characters[3]->GetCharacterDescription().isDead)
	{
		m_pGrid->PlaceBomb(m_Characters[3]->GetTransform()->GetWorldPosition(), &m_Characters[3]->GetCharacterDescription());
	}

	if(m_pGrid)
		m_pGrid->Update();
}

void ExamScene::UpdateButtons()
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

			case Menus::pauseMenu:

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

			case Menus::pauseMenu:

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
}

void ExamScene::UpdateMenus()
{
	if (m_CountDown)
	{
		m_TimeLeft -= m_SceneContext.pGameTime->GetElapsed();

		if (m_TimeLeft <= 0.f)
		{
			TextRenderer::Get()->DrawText(m_pFont, StringUtil::utf8_decode("GO"), XMFLOAT2(m_SceneContext.windowWidth / 2.f, m_SceneContext.windowHeight / 2.f), XMFLOAT4(Colors::White));
			m_IsPaused = false;
			m_CountDown = false;
			m_TimeLeft = m_RoundDurationSec;

			//make the players able to move
			if (m_Characters[0])
			{
				m_Characters[0]->GetCharacterDescription().canWalk = true;
			}

			if (m_Characters[1])
			{
				m_Characters[1]->GetCharacterDescription().canWalk = true;
			}

			if (m_Characters[2])
			{
				m_Characters[2]->GetCharacterDescription().canWalk = true;
			}

			if (m_Characters[3])
			{
				m_Characters[3]->GetCharacterDescription().canWalk = true;
			}
		}
		else
		{
			TextRenderer::Get()->DrawText(m_pFont, StringUtil::utf8_decode(std::to_string(static_cast<int>(ceilf(m_TimeLeft)))), XMFLOAT2(m_SceneContext.windowWidth / 2.f, m_SceneContext.windowHeight / 2.f), XMFLOAT4(Colors::White));
		}
	}

	if (!m_IsPaused)
	{
		m_TimeLeft -= m_SceneContext.pGameTime->GetElapsed();

		TextRenderer::Get()->DrawText(m_pFont, StringUtil::utf8_decode(std::to_string(static_cast<int>(ceilf(m_TimeLeft)))), XMFLOAT2(m_SceneContext.windowWidth / 2.f, 0.f), XMFLOAT4(Colors::White));

		if (m_TimeLeft <= 0.f)
		{
			m_IsPaused = true;
			NavigateToMenu(Menus::endMenu);
		}
	}

	if (m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_A))
	{
		switch (m_SelectedButton)
		{
		case Buttons::battle:
			NavigateToMenu(Menus::joinMenu);
			break;

		case Buttons::exit:
			exit(EXIT_SUCCESS);
			break;

		case Buttons::restart:

			break;

		case Buttons::toMainMenu:
			NavigateToMenu(Menus::mainMenu);
			break;

		case Buttons::Continue:
			NavigateToMenu(Menus::inGameUI);
			break;
		}
	}

	if (m_CurrentMenu == Menus::joinMenu)
	{
		TextRenderer::Get()->DrawText(m_pFont, StringUtil::utf8_decode(m_JoinScreenText), XMFLOAT2(125.f, m_SceneContext.windowHeight - 100.f), XMFLOAT4(Colors::Black));
	}

	if (m_CurrentMenu == Menus::inGameUI)
	{
		if (m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START)
			|| m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START, GamepadIndex::playerTwo)
			|| m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START, GamepadIndex::playerThree)
			|| m_SceneContext.pInput->IsGamepadButton(InputState::pressed, XINPUT_GAMEPAD_START, GamepadIndex::playerFour))
		{
			NavigateToMenu(Menus::pauseMenu);
		}
	}
}

void ExamScene::Reset()
{
	//delete all the characters and the grid and set the lightDirection
	for (auto pCharacter : m_Characters)
	{
		if (pCharacter)
		{
			RemoveChild(pCharacter, true);
		}
	}

	m_IsPaused = true;

	m_Characters.clear();
	m_Characters.resize(4);

	SafeDelete(m_pGrid);

	m_SceneContext.pLights->SetDirectionalLight({ -10.f, 50.f, -10.f }, { 0.f, -0.8f, 0.f });
}

void ExamScene::NavigateToMenu(Menus menuToNavigateTo)
{
	if (m_CurrentMenu == menuToNavigateTo)
		return;

	constexpr float cameraZOffset{ -2.5f };
	float amountOfRows{};
	float amountOfColumns{};

	if (m_pGrid && menuToNavigateTo == Menus::inGameUI)
	{
		amountOfRows = static_cast<float>(m_pGrid->GetAmountOfRow());
		amountOfColumns = static_cast<float>(m_pGrid->GetAmountOfColumns());
	}	

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

		Reset();

		break;

	case Menus::joinMenu:

		//first remove all UI element by navigating to Menus::none
		NavigateToMenu(Menus::none);

		m_SceneContext.pCamera->GetTransform()->Translate(0.f, 5.f, -5.f);
		m_SceneContext.pCamera->GetTransform()->Rotate(45.f, 0.f, 0.f);

		m_CurrentMenu = Menus::joinMenu;

		break;

	case Menus::inGameUI:

		//first remove all UI element by navigating to Menus::none
		NavigateToMenu(Menus::none);

		//translate Camera to middle of the grid on xz-plane
		m_SceneContext.pCamera->GetTransform()->Translate(amountOfRows / 2.f, 20.f, amountOfColumns / 2.f + cameraZOffset);
		m_SceneContext.pCamera->GetTransform()->Rotate(85.f, 0.f, 0.f);
		m_SceneContext.pLights->SetDirectionalLight({ -amountOfRows, 50.f, -amountOfColumns }, { 0.5f, -0.8f, 0.5f });

		m_CurrentMenu = Menus::inGameUI;

		break;

	case Menus::pauseMenu:

		//first remove all UI element by navigating to Menus::none
		NavigateToMenu(Menus::none);

		AddChild(m_pMenuBackground);
		AddChild(m_pContinueButton);
		AddChild(m_pRestartButton);
		AddChild(m_pExitButton);
		AddChild(m_pToMainMenuButton);

		SelectButton(Buttons::Continue, true);

		m_SelectedButton = Buttons::Continue;
		m_CurrentMenu = Menus::pauseMenu;

		break;

	case Menus::endMenu:
		break;

	case Menus::none:

		switch (m_CurrentMenu)
		{
		case Menus::mainMenu:
			RemoveChild(m_pMenuBackground);
			RemoveChild(m_pBattleButton);
			RemoveChild(m_pExitButton);
			break;

		case Menus::pauseMenu:
			RemoveChild(m_pMenuBackground);
			RemoveChild(m_pContinueButton);
			RemoveChild(m_pRestartButton);
			RemoveChild(m_pExitButton);
			RemoveChild(m_pToMainMenuButton);
			break;

		case Menus::endMenu:

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

void ExamScene::InitializeSprites()
{
	m_pMenuBackground = new GameObject();
	m_pMenuBackground->AddComponent(new SpriteComponent(L"Textures/MenuBackGround.png"));
	m_pMenuBackground->GetTransform()->Translate(0.f, 0.f, 0.3f);

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
}

void ExamScene::JoinGame(GamepadIndex gamepadIndex)
{
	if (!m_IsPaused && m_CurrentMenu != Menus::joinMenu)
		return;

	//character
	CharacterDesc characterDesc{ m_pDefaultMaterial, 0.25f, 0.75f };
	characterDesc.useController = true;
	characterDesc.canJump = false;
	characterDesc.canWalk = false;
	characterDesc.useOwnCamera = false;
	characterDesc.stepOffset = 0.f;
	characterDesc.lookTowardsWalkDirection = true;
	characterDesc.playerIndex = gamepadIndex;

	auto pCharacter = AddChild(new Character(characterDesc));
	auto pChildObject{ pCharacter->AddChild(new GameObject()) };
	auto pModel = pChildObject->AddComponent(new ModelComponent(L"Meshes/Player.ovm"));
	pChildObject->GetTransform()->Translate(0.f, -0.5f, 0.f);
	pModel->GetTransform()->Scale(0.01f);

	ColorMaterial_Shadow_Skinned* pArmsAndLegsMaterial{};
	ColorMaterial_Shadow_Skinned* pFaceMaterial{};
	ColorMaterial_Shadow_Skinned* pBodyMaterial{};
	ColorMaterial_Shadow_Skinned* pBeltMaterial{};
	ColorMaterial_Shadow_Skinned* pHeadMaterial{};

	if (gamepadIndex == GamepadIndex::playerOne)
	{
		pArmsAndLegsMaterial = m_pWhiteMaterial;
		pFaceMaterial = m_pSkinMaterial;
		pBodyMaterial = m_pBlueMaterial;
		pBeltMaterial = m_pBlackMaterial;
		pHeadMaterial = m_pWhiteMaterial;
		pCharacter->GetTransform()->Translate(-2.f, 1.f, 0.f);
		m_SceneContext.pInput->AddInputAction(InputAction(player1PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, gamepadIndex));
	}
	else if (gamepadIndex == GamepadIndex::playerTwo)
	{
		pArmsAndLegsMaterial = m_pSkinMaterial;
		pFaceMaterial = m_pSkinMaterial;
		pBodyMaterial = m_pBlackMaterial;
		pBeltMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
		pBeltMaterial->SetColor(XMFLOAT4(Colors::LightGray));
		pHeadMaterial = m_pBlackMaterial;
		pCharacter->GetTransform()->Translate(-1.f, 1.f, 0.f);
		m_SceneContext.pInput->AddInputAction(InputAction(player2PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, gamepadIndex));
	}
	else if (gamepadIndex == GamepadIndex::playerThree)
	{
		auto pPinkMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
		pPinkMaterial->SetColor(XMFLOAT4(Colors::Pink));
		auto pHotPinkMaterial{ MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>() };
		pHotPinkMaterial->SetColor(XMFLOAT4(Colors::HotPink));
		pArmsAndLegsMaterial = pPinkMaterial;
		pFaceMaterial = pPinkMaterial;
		pBodyMaterial = pHotPinkMaterial;
		pBeltMaterial = pPinkMaterial;
		pHeadMaterial = pHotPinkMaterial;
		pCharacter->GetTransform()->Translate(1.f, 1.f, 0.f);
		m_SceneContext.pInput->AddInputAction(InputAction(player3PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, gamepadIndex));
	}
	else if (gamepadIndex == GamepadIndex::playerFour)
	{
		pArmsAndLegsMaterial = m_pSkinMaterial;
		pFaceMaterial = m_pSkinMaterial;
		pBodyMaterial = m_pBlueMaterial;
		pBeltMaterial = MaterialManager::Get()->CreateMaterial<ColorMaterial_Shadow_Skinned>();
		pBeltMaterial->SetColor(XMFLOAT4(Colors::SaddleBrown));
		pHeadMaterial = m_pBlueMaterial;
		pCharacter->GetTransform()->Translate(2.f, 1.f, 0.f);
		m_SceneContext.pInput->AddInputAction(InputAction(player4PlantBomb, InputState::pressed, -1, -1, XINPUT_GAMEPAD_A, gamepadIndex));
	}

	pModel->SetMaterial(m_pBlackMaterial , 0u); //eyebrows
	pModel->SetMaterial(pBodyMaterial, 1u); //body
	pModel->SetMaterial(m_pRedMaterial, 2u); //hands
	pModel->SetMaterial(m_pRedMaterial, 3u); //feet
	pModel->SetMaterial(m_pWhiteMaterial, 4u); //stick on head
	pModel->SetMaterial(pBeltMaterial, 5u); //belt
	pModel->SetMaterial(m_pBlackMaterial, 6u); //eyes
	pModel->SetMaterial(pHeadMaterial, 7u); //head
	pModel->SetMaterial(pArmsAndLegsMaterial, 8u); //arms
	pModel->SetMaterial(pArmsAndLegsMaterial, 9u); //legs
	pModel->SetMaterial(m_pRedMaterial, 10u); //head ball
	pModel->SetMaterial(pFaceMaterial, 11u); //face
	pModel->SetMaterial(m_pYellowMaterial, 12u); //belt buckle
	pCharacter->SetModelAnimator(pModel->GetAnimator());
	pCharacter->SetPChild(pChildObject);

	m_Characters[static_cast<int>(gamepadIndex)] = pCharacter;
}

void ExamScene::StartRound()
{
	//check if at least 2 players have joined if not don't start the round
	if (!(m_Characters[0] && (m_Characters[1] || m_Characters[2] || m_Characters[3]) //if player1 and another player spawned
		|| (m_Characters[1] && (m_Characters[2] || m_Characters[3])) //if player1 did not spawn but player2 and another player did
		|| (m_Characters[2] && m_Characters[3]) //if player1 and player2 did not spawn and player3 and player4 did
		))
	{
		return;
	}

	m_TimeLeft = m_CountDownStart;
	m_CountDown = true;

	//create the grid
	constexpr int amountOfRows{ 15 };
	constexpr int amountOfColumns{ 15 };
	m_pGrid = new Grid(amountOfRows, amountOfColumns, this, m_pDefaultMaterial);

	//move all the players to their starting position
	if (m_Characters[0])
	{
		auto pPlayer1StartCell{ m_pGrid->GetCell(1, 1) };
		m_Characters[0]->GetTransform()->Translate(pPlayer1StartCell->GetMiddlePos());
	}

	if (m_Characters[1])
	{
		auto pPlayer2StartCell{ m_pGrid->GetCell(amountOfColumns - 2, 1) };
		m_Characters[1]->GetTransform()->Translate(pPlayer2StartCell->GetMiddlePos());
	}

	if (m_Characters[2])
	{
		auto pPlayer3StartCell{ m_pGrid->GetCell(amountOfColumns - 2, amountOfRows - 2) };
		m_Characters[2]->GetTransform()->Translate(pPlayer3StartCell->GetMiddlePos());
	}

	if (m_Characters[3])
	{
		auto pPlayer4StartCell{ m_pGrid->GetCell(1, amountOfRows - 2) };
		m_Characters[3]->GetTransform()->Translate(pPlayer4StartCell->GetMiddlePos());
	}

	//navigate to the inGameUI
	NavigateToMenu(Menus::inGameUI);
}