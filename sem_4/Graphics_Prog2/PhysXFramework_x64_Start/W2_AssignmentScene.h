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
	GameObject* m_pSphere1{ nullptr };
	GameObject* m_pSphere2{ nullptr };
	GameObject* m_pSphere3{ nullptr };
	GameObject* m_pLevelTriangle{ nullptr };

	PxRigidStatic* m_pBlueTrigger{ nullptr };
	PxRigidStatic* m_pRedTrigger{ nullptr };

	GameObject* m_pBlueBox{ nullptr };
	GameObject* m_pRedBox{ nullptr };

	bool m_IsBlueTriggered{};
	bool m_IsRedTriggered{};

	PxRevoluteJoint* m_pBlueJoint{ nullptr };
	PxRevoluteJoint* m_pRedJoint{ nullptr };

	bool m_OpenBlueHatch{};
	bool m_OpenRedHatch{};

	FMOD::Channel* m_pChannel2D{ nullptr };
	FMOD::Sound* m_pSound{ nullptr };
};