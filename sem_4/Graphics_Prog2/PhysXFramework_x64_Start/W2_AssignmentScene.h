#pragma once
#include "GameScene.h"

class W2_AssignmentScene final : public GameScene
{
public:
	W2_AssignmentScene() :GameScene(L"W2_AssignmentScene") {}
	~W2_AssignmentScene() override = default;
	W2_AssignmentScene(const W2_AssignmentScene& other) = delete;
	W2_AssignmentScene(W2_AssignmentScene&& other) noexcept = delete;
	W2_AssignmentScene& operator=(const W2_AssignmentScene& other) = delete;
	W2_AssignmentScene& operator=(W2_AssignmentScene&& other) noexcept = delete;

protected:
	void Initialize() override;
	void Update() override;
	void Draw() const override;
	void OnSceneActivated() override;
	void OnSceneDeactivated() override;

	void onTrigger(PxTriggerPair* pairs, PxU32 count) override;

private:
	GameObject* m_pSphere{ nullptr };
	GameObject* m_pLevelTriangle{ nullptr };

	PxRigidStatic* m_pBlueTrigger{ nullptr };
	PxRigidStatic* m_pRedTrigger{ nullptr };

	bool m_IsTriggeredLeft{};
	bool m_IsTriggeredRight{};
};