#include "stdafx.h"
#include "PhysXTextScene.h"

#include "CubePosColorNorm.h"

void PhysXTestScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const PxMaterial* pDefaultMaterial{ pPhysX->createMaterial(0.5f, 0.5f, 0.5f) };

	//CUBE
	const XMFLOAT3 actorDimensions{ 1.f, 1.f, 1.f };
	m_pCube = new CubePosColorNorm(actorDimensions.x, actorDimensions.y, actorDimensions.z);
	AddGameObject(m_pCube);
	
	//CUBE ACTOR
	PxRigidDynamic* pCubeActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	PxBoxGeometry boxGeometry{ PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f) };

	//PxShape* pCubeShape{ pPhysX->createShape(boxGeometry, *pDefaultMaterial, true) };
	//pCubeActor->attachShape(*pCubeShape);
	//m_pPhysxScene->addActor(*pCubeActor);
	//OR
	PxRigidActorExt::createExclusiveShape(*pCubeActor, boxGeometry, *pDefaultMaterial);

	//Link CUBE with CUBE_ACTOR
	m_pCube->AttachRigidActor(pCubeActor);

	m_pCube->Translate(0.f, 10.f, 0.f);
	m_pCube->RotateDegrees(25.f, 45.f, 25.f);

	//GROUND PLANE
	auto pGroundActor{ pPhysX->createRigidStatic(PxTransform(PxQuat(PxPiDivTwo, PxVec3(0, 0, 1)))) };
	PxRigidActorExt::createExclusiveShape(*pGroundActor, PxPlaneGeometry{}, *pDefaultMaterial);
	m_pPhysxScene->addActor(*pGroundActor);
}

void PhysXTestScene::Update()
{
	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R'))
	{
		m_pCube->Translate(0.f, 10.f, 0.f);
		m_pCube->RotateDegrees(25.f, 45.f, 25.f);
	}
}

void PhysXTestScene::Draw() const
{

}

void PhysXTestScene::OnSceneActivated()
{
	
}

void PhysXTestScene::OnSceneDeactivated()
{
}
