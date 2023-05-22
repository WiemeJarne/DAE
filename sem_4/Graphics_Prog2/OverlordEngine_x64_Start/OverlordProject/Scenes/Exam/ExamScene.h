#pragma once
#include <vector>

class DiffuseMaterial;
class ColorMaterial_Shadow_Skinned;
class Character;
class Grid;
class PostFilmGrain;

class ExamScene final : public GameScene
{
public:
	ExamScene() : GameScene(L"ExamScene") {}
	~ExamScene() override;

	ExamScene(const ExamScene& other) = delete;
	ExamScene(ExamScene&& other) noexcept = delete;
	ExamScene& operator=(const ExamScene& other) = delete;
	ExamScene& operator=(ExamScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;

private:
	enum InputIds
	{
		player1PlantBomb,
		player2PlantBomb,
		player3PlantBomb,
		player4PlantBomb
	};

	std::vector<Character*> m_Characters{};

	DiffuseMaterial* m_pFireMaterial{};

	Grid* m_pGrid{};

	//menus
	enum class Buttons
	{
		battle,
		exit,
		restart,
		toMainMenu,
		Continue,
		none
	};

	enum class Menus
	{
		mainMenu,
		joinMenu,
		inGameUI,
		pauseMenu,
		endMenu,
		none
	};

	Buttons m_SelectedButton{ Buttons::none };
	Menus m_CurrentMenu{ Menus::none };
	GameObject* m_pMenuBackground{};
	GameObject* m_pBattleButton{};
	GameObject* m_pExitButton{};
	GameObject* m_pContinueButton{};
	GameObject* m_pRestartButton{};
	GameObject* m_pToMainMenuButton{};
	GameObject* m_pTerrain{};

	const float m_SelectedButtonXOffset{ -20.f };
	float m_DeselectedButtonXPos{};
	float m_SecSinceSelectedButton{};

	SpriteFont* m_pFont{};

	XMFLOAT3 m_VsSymbolPosWhenBattleButtonSelected{};
	XMFLOAT3 m_StopSymbolPosWhenBattleButtonSelected{};

	std::string m_JoinScreenText{ "press start to join and A to start the game" };

	PxMaterial* m_pDefaultMaterial{};

	ColorMaterial_Shadow_Skinned* m_pRedMaterial{};
	ColorMaterial_Shadow_Skinned* m_pSkinMaterial{};
	ColorMaterial_Shadow_Skinned* m_pBlueMaterial{};
	ColorMaterial_Shadow_Skinned* m_pBlackMaterial{};
	ColorMaterial_Shadow_Skinned* m_pYellowMaterial{};
	ColorMaterial_Shadow_Skinned* m_pWhiteMaterial{};

	bool m_IsPaused{ true };
	bool m_CountDown{ false };

	const float m_RoundDurationSec{ 180.f };
	float m_TimeLeft{};
	float m_CountDownStart{ 3.f };

	PostFilmGrain* m_pPostFilmGrain{};

	void Reset();

	void InitializeSprites();
	void UpdateButtons();
	void UpdateMenus();
	void JoinGame(GamepadIndex gamepadIndex);
	void NavigateToMenu(Menus menuToNavigateTo);
	void SelectButton(Buttons button, bool skipDelayTime = false);
	void DeselectButton(Buttons button);
	void StartRound();
};