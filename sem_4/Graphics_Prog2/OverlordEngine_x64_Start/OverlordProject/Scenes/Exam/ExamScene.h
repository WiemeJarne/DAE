#pragma once
#include <vector>

class DiffuseMaterial;
class Character;
class Grid;

class ExamScene final : public GameScene
{
public:
	ExamScene() : GameScene(L"ExamScene") {}
	~ExamScene() override = default;

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

	void Reset();
};