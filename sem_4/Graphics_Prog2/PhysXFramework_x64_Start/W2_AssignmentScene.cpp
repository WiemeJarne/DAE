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

	//SPHERES
	const float radius{ 1.f };

	//SPHERE1
	m_pSphere1 = new SpherePosColorNorm(radius, 20, 20, XMFLOAT4(Colors::Gray));
	m_pSphere1->Translate(0.f, 10.f, 0.f);
	AddGameObject(m_pSphere1);

	//sphere actor
	PxRigidDynamic* pSphereActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	pSphereActor->setMass(3.f);

	//sphere shape
	PxRigidActorExt::createExclusiveShape(*pSphereActor, PxSphereGeometry(radius), *pSphereMat);

	//link sphere with sphere actor
	m_pSphere1->AttachRigidActor(pSphereActor);

	//SPHERE2
	m_pSphere2 = new SpherePosColorNorm(radius, 20, 20, XMFLOAT4(Colors::Gray));
	m_pSphere2->Translate(-5.f, 25.f, 0.f);
	AddGameObject(m_pSphere2);

	//sphere actor
	pSphereActor = pPhysX->createRigidDynamic(PxTransform(PxIdentity));
	pSphereActor->setMass(3.f);

	//sphere shape
	PxRigidActorExt::createExclusiveShape(*pSphereActor, PxSphereGeometry(radius), *pSphereMat);

	//link sphere with sphere actor
	m_pSphere2->AttachRigidActor(pSphereActor);

	//SPHERE3
	m_pSphere3 = new SpherePosColorNorm(radius, 20, 20, XMFLOAT4(Colors::Gray));
	m_pSphere3->Translate(5.f, 25.f, 0.f);
	AddGameObject(m_pSphere3);

	//sphere actor
	pSphereActor = pPhysX->createRigidDynamic(PxTransform(PxIdentity));
	pSphereActor->setMass(3.f);

	//sphere shape
	PxRigidActorExt::createExclusiveShape(*pSphereActor, PxSphereGeometry(radius), *pSphereMat);

	//link sphere with sphere actor
	m_pSphere3->AttachRigidActor(pSphereActor);

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

	//BOXES
	XMFLOAT3 actorDimension{ 1.5f, 1.5f, 1.5f };

	//BLUE BOX
	m_pBlueBox = new CubePosColorNorm(actorDimension.x, actorDimension.y, actorDimension.z, XMFLOAT4(Colors::Blue));
	AddGameObject(m_pBlueBox);
	m_pBlueBox->Translate(-4.f, 5.f, 0.f);

	PxRigidDynamic* pCubeActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	pCubeActor->setMass(0.1f);
	PxRigidActorExt::createExclusiveShape(*pCubeActor, PxBoxGeometry(actorDimension.x / 2.f, actorDimension.y / 2.f, actorDimension.z / 2.f), *pCubeMat);

	m_pBlueBox->AttachRigidActor(pCubeActor);

	//RED BOX
	m_pRedBox = new CubePosColorNorm(actorDimension.x, actorDimension.y, actorDimension.z, XMFLOAT4(Colors::Red));
	AddGameObject(m_pRedBox);
	m_pRedBox->Translate(3.5f, 5.f, 0.f);

	pCubeActor = pPhysX->createRigidDynamic(PxTransform(PxIdentity));
	pCubeActor->setMass(0.1f);
	PxRigidActorExt::createExclusiveShape(*pCubeActor, PxBoxGeometry(actorDimension.x / 2.f, actorDimension.y / 2.f, actorDimension.z / 2.f), *pCubeMat);

	m_pRedBox->AttachRigidActor(pCubeActor);
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
		m_pSphere1->GetRigidActor()->is<PxRigidDynamic>()->addTorque({ 0,0,force });
	}
	else if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::down, VK_RIGHT))
	{
		m_pSphere1->GetRigidActor()->is<PxRigidDynamic>()->addTorque({ 0,0,-force });
	}

	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R')) //reset the scene
	{
		m_pSphere1->Translate(0.f, 10.f, 0.f);
		m_pSphere2->Translate(-5.f, 25.f, 0.f);
		m_pSphere3->Translate(5.f, 25.f, 0.f);

		m_pBlueBox->Translate(-4.f, 5.f, 0.f);
		m_pBlueBox->RotateDegrees(0.f, 0.f, 0.f);
		m_pRedBox->Translate(3.5f, 5.f, 0.f);
		m_pRedBox->RotateDegrees(0.f, 0.f, 0.f);

		m_IsBlueTriggered = false;
		m_IsRedTriggered = false;
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
				if (pair.otherActor == static_cast<PxRigidBody*>(m_pBlueBox->GetRigidActor()))
				{
					m_IsBlueTriggered = true;
				}
			}
		}
		else if (pair.triggerActor == m_pRedTrigger)
		{
			if (pair.status == PxPairFlag::eNOTIFY_TOUCH_FOUND) //ENTERED
			{
				if (pair.otherActor == static_cast<PxRigidBody*>(m_pRedBox->GetRigidActor()))
				{
					m_IsRedTriggered = true;
				}
			}
		}
	}
}