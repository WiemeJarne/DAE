#include "stdafx.h"
#include "W2_AssignmentScene.h"

#include "SpherePosColorNorm.h"
#include "CubePosColorNorm.h"
#include "MeshObject.h"
#include "ContentManager.h"

enum InputIDs
{
	Forwards,
	Backwards,
	Left,
	Right
};

void W2_AssignmentScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const PxMaterial* pFloorMat{ pPhysX->createMaterial(0.7f, 0.7f, 0.5f) };
	const PxMaterial* pCubeMat{ pPhysX->createMaterial(0.1f, 0.1f, 0.5f) };
	const PxMaterial* pSphereMat{ pPhysX->createMaterial(0.5f, 0.5f, 0.5f) };

	//FLOOR
	const auto pGroundActor = pPhysX->createRigidStatic(PxTransform({ PxPiDivTwo, {0, 0, 1} }));

	PxRigidActorExt::createExclusiveShape(*pGroundActor, PxPlaneGeometry(), *pFloorMat);
	m_pPhysxScene->addActor(*pGroundActor);

	//SPHERE
	const float radius{ 1.f };
	m_pSphere = new SpherePosColorNorm(radius, 20, 20, XMFLOAT4(Colors::Gray));
	m_pSphere->Translate(0.f, 10.f, 0.f);
	AddGameObject(m_pSphere);

	//sphere actor
	PxRigidDynamic* pSphereActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };

	//sphere shape
	PxRigidActorExt::createExclusiveShape(*pSphereActor, PxSphereGeometry(radius), *pSphereMat);

	//link sphere with sphere actor
	m_pSphere->AttachRigidActor(pSphereActor);

	//LEVEL
	m_pLevelTriangle = new MeshObject{ L"Resources/Meshes/Level.ovm" };
	AddGameObject(m_pLevelTriangle);

	const auto pTriangleMesh{ ContentManager::GetInstance()->Load<PxTriangleMesh>(L"Resources/Meshes/Level.ovpt") };
	const auto pTriangleActor{ pPhysX->createRigidStatic(PxTransform(PxIdentity)) };
	PxRigidActorExt::createExclusiveShape(*pTriangleActor, PxTriangleMeshGeometry(pTriangleMesh), *pFloorMat);
	m_pLevelTriangle->AttachRigidActor(pTriangleActor);

	//TRIGGERS
	XMFLOAT3 actorDimensions{ 1.5f, 0.5f, 6.f };

	//BLUE TRIGGER	
	auto cube = new CubePosColorNorm( actorDimensions.x, actorDimensions.y, actorDimensions.z, XMFLOAT4(Colors::DarkBlue));
	cube->Translate(-7.25f, 2.3f, 0.f);
	m_pBlueTrigger = pPhysX->createRigidStatic(PxTransform(PxIdentity));
	auto pShape{ PxRigidActorExt::createExclusiveShape(*m_pBlueTrigger, PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pFloorMat) };
	pShape->setFlag(PxShapeFlag::eSIMULATION_SHAPE, false);
	pShape->setFlag(PxShapeFlag::eTRIGGER_SHAPE, true);
	cube->AttachRigidActor(m_pBlueTrigger);
	AddGameObject(cube);

	//RED TRIGGER
	cube = new CubePosColorNorm(actorDimensions.x, actorDimensions.y, actorDimensions.z, XMFLOAT4(Colors::DarkRed));
	cube->Translate(6.75f, 2.3f, 0.f);
	m_pRedTrigger = pPhysX->createRigidStatic(PxTransform(PxIdentity));
	pShape = { PxRigidActorExt::createExclusiveShape(*m_pRedTrigger, PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pFloorMat) };
	pShape->setFlag(PxShapeFlag::eSIMULATION_SHAPE, false);
	pShape->setFlag(PxShapeFlag::eTRIGGER_SHAPE, true);
	cube->AttachRigidActor(m_pRedTrigger);
	AddGameObject(cube);
}

inline PxVec3 ToPxVec3(XMFLOAT3 v)
{
	return (PxVec3(v.x, v.y, v.z));
}

void W2_AssignmentScene::Update()
{
	constexpr float force{ 5.f };

	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::down, VK_LEFT))
	{
		m_pSphere->GetRigidActor()->is<PxRigidDynamic>()->addTorque({ 0,0,force });
	}
	else if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::down, VK_RIGHT))
	{
		m_pSphere->GetRigidActor()->is<PxRigidDynamic>()->addTorque({ 0,0,-force });
	}

	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R')) //reset the scene
	{
		
	}
}

void W2_AssignmentScene::Draw() const
{

}

void W2_AssignmentScene::OnSceneActivated()
{

}

void W2_AssignmentScene::OnSceneDeactivated()
{
}

void W2_AssignmentScene::onTrigger(PxTriggerPair* pairs, PxU32 count)
{
	for (auto index{ 0 }; index < count; ++index)
	{
		//ignore deleted shapes
		if (pairs[index].flags & (PxTriggerPairFlag::eREMOVED_SHAPE_TRIGGER | PxTriggerPairFlag::eREMOVED_SHAPE_OTHER))
			continue;

		const PxTriggerPair& pair{ pairs[index] };

		if (pair.triggerActor == m_pBlueTrigger)
		{
			if (pair.status == PxPairFlag::eNOTIFY_TOUCH_FOUND) //ENTERED
			{
				Logger::GetInstance()->LogInfo(L"Sphere FOUND trigger box LEFT");
				m_IsTriggeredLeft = true;
			}
			else if (pair.status == PxPairFlag::eNOTIFY_TOUCH_LOST) //LEFT
			{
				Logger::GetInstance()->LogInfo(L"Sphere LOST trigger box LEFT");
			}
		}
		else if (pair.triggerActor == m_pRedTrigger)
		{
			if (pair.status == PxPairFlag::eNOTIFY_TOUCH_FOUND) //ENTERED
			{
				Logger::GetInstance()->LogInfo(L"Sphere FOUND trigger box RIGHT");
				m_IsTriggeredRight = true;
			}
			else if (pair.status == PxPairFlag::eNOTIFY_TOUCH_LOST) //LEFT
			{
				Logger::GetInstance()->LogInfo(L"Sphere LOST trigger box RIGHT");
			}
		}
	}
}