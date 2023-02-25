#pragma once
#include "GameScene.h"
class BouncingBallScene final : public GameScene
{
public:
	BouncingBallScene() :GameScene(L"BouncingBallScene") {}
	~BouncingBallScene() override = default;
	BouncingBallScene(const BouncingBallScene& other) = delete;
	BouncingBallScene(BouncingBallScene&& other) noexcept = delete;
	BouncingBallScene& operator=(const BouncingBallScene& other) = delete;
	BouncingBallScene& operator=(BouncingBallScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() const override;
	void OnSceneActivated() override;
	void OnSceneDeactivated() override;

private:
	GameObject* m_pSphere1{ nullptr };
	GameObject* m_pSphere2{ nullptr };
	GameObject* m_pSphere3{ nullptr };
};

