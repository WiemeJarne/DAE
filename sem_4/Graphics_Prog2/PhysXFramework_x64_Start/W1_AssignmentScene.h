#pragma once
#include "GameScene.h"

class W1_AssignmentScene final : public GameScene
{
public:
	W1_AssignmentScene() :GameScene(L"W1_AssignmentScene") {}
	~W1_AssignmentScene() override = default;
	W1_AssignmentScene(const W1_AssignmentScene& other) = delete;
	W1_AssignmentScene(W1_AssignmentScene&& other) noexcept = delete;
	W1_AssignmentScene& operator=(const W1_AssignmentScene& other) = delete;
	W1_AssignmentScene& operator=(W1_AssignmentScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() const override;
	void OnSceneActivated() override;

private:
	GameObject* m_pSphere{ nullptr };
	std::vector<GameObject*> m_Cubes;
	const int m_AmountOfRows{ 10 };
	const int m_AmountOfCollumns{ 10 };
	float m_XStartPos{ };
	const float m_HorizontalSpaceBetweenCubes{ 0.3f };
	const float m_VerticalSpaceBetweenCubes{ 0.2f };
	const XMFLOAT3 m_CubeActorDimensions{ 2.f, 2.f, 2.f };

	void Reset();
};



