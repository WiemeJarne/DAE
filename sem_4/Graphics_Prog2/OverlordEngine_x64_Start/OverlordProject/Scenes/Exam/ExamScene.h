#pragma once
#include <vector>

class DiffuseMaterial;
class Character;
class Grid;

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
		inGameMenu,
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

	const float m_SelectedButtonXOffset{ -20.f };
	float m_DeselectedButtonXPos{};
	float m_SecSinceSelectedButton{};

	SpriteFont* m_pFont{};

	XMFLOAT3 m_VsSymbolPosWhenBattleButtonSelected{};
	XMFLOAT3 m_StopSymbolPosWhenBattleButtonSelected{};

	void Reset();

	void NavigateToMenu(Menus menuToNavigateTo);
	void SelectButton(Buttons button, bool skipDelayTime = false);
	void DeselectButton(Buttons button);
};