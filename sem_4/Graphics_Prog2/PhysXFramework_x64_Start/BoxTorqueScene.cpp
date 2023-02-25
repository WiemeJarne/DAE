#include "stdafx.h"
#include "BoxTorqueScene.h"

#include "CubePosColorNorm.h"

enum InputIDs
{
	Forwards,
	Backwards,
	Left,
	Right
};

void BoxTorqueScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const PxMaterial* pDefaultMaterial{ pPhysX->createMaterial(0.5f, 0.5f, 0.5f) };

	//CUBE
	const XMFLOAT3 actorDimensions{ 1.5f, 1.5f, 1.5f };
	m_pCube = new CubePosColorNorm(actorDimensions.x, actorDimensions.y, actorDimensions.z);
	m_pCube->Translate(0.f, actorDimensions.y / 2.f, 0.f);
	AddGameObject(m_pCube);

	//CUBE ACTOR
	PxRigidBody* pCubeActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	PxBoxGeometry boxGeometry{ PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f) };

	//CUBE SHAPE
	PxRigidActorExt::createExclusiveShape(*pCubeActor, boxGeometry, *pDefaultMaterial);

	//link CUBE with CUBE SHAPE
	m_pCube->AttachRigidActor(pCubeActor);

	//GROUND PLANE
	auto pGroundActor{ pPhysX->createRigidStatic(PxTransform(PxQuat(PxPiDivTwo, PxVec3(0, 0, 1)))) };
	PxRigidActorExt::createExclusiveShape(*pGroundActor, PxPlaneGeometry{}, *pDefaultMaterial);
	m_pPhysxScene->addActor(*pGroundActor);

	//INPUT
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Backwards, InputTriggerState::down, VK_DOWN, -1, XINPUT_GAMEPAD_DPAD_DOWN));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Left, InputTriggerState::down, VK_LEFT, -1, XINPUT_GAMEPAD_DPAD_LEFT));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Right, InputTriggerState::down, VK_RIGHT, -1, XINPUT_GAMEPAD_DPAD_RIGHT));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Forwards, InputTriggerState::down, VK_UP, -1, XINPUT_GAMEPAD_DPAD_UP));
}

void BoxTorqueScene::Update()
{
	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R')) //resets the scene
	{
		const XMFLOAT3 actorDimensions{ 1.f, 1.f, 1.f };
		m_pCube->Translate(0.f, actorDimensions.y / 2.f, 0.f);
	}

	const float amountOfForce{ 10.f };

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Left))
	{
		static_cast<PxRigidBody*>(m_pCube->GetRigidActor())->addTorque(PxVec3(0.f, 0.f, amountOfForce), PxForceMode::eACCELERATION);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Right))
	{
		static_cast<PxRigidBody*>(m_pCube->GetRigidActor())->addTorque(PxVec3(0.f, 0.f, -amountOfForce), PxForceMode::eACCELERATION);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Forwards))
	{
		static_cast<PxRigidBody*>(m_pCube->GetRigidActor())->addTorque(PxVec3(amountOfForce, 0.f, 0.f), PxForceMode::eACCELERATION);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Backwards))
	{
		static_cast<PxRigidBody*>(m_pCube->GetRigidActor())->addTorque(PxVec3(-amountOfForce, 0.f, 0.f), PxForceMode::eACCELERATION);
	}
}

void BoxTorqueScene::Draw() const
{

}

void BoxTorqueScene::OnSceneActivated()
{

}

void BoxTorqueScene::OnSceneDeactivated()
{
}
