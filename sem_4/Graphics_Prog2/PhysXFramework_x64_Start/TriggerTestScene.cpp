#include "stdafx.h"
#include "TriggerTestScene.h"
#include "PhysxManager.h"

#include "SpherePosColorNorm.h"
#include "Logger.h"

void TriggerTestScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const auto pDefaultMat{ pPhysX->createMaterial(0.5f, 0.5f, 0.2f) };

	//ground plane
	const auto pGroundActor = pPhysX->createRigidStatic(PxTransform({ PxPiDivTwo, {0, 0, 1} }));

	PxRigidActorExt::createExclusiveShape(*pGroundActor, PxPlaneGeometry(), *pDefaultMat);
	m_pPhysxScene->addActor(*pGroundActor);

	//Sphere
	m_pSphere = new SpherePosColorNorm(1.f, 10, 10, XMFLOAT4{Colors::Gray});
	AddGameObject(m_pSphere);

	const auto pSphereActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	PxRigidActorExt::createExclusiveShape(*pSphereActor, PxSphereGeometry(1.f), *pDefaultMat);
	m_pSphere->AttachRigidActor(pSphereActor);

	m_pSphere->Translate(0.f, 2.f, 0.f);

	//TRIGGER LEFT
	m_pTriggerLeft = pPhysX->createRigidStatic(PxTransform(-8.f, 0.5f, 0.f));
	auto pShape = PxRigidActorExt::createExclusiveShape(*m_pTriggerLeft, PxBoxGeometry(0.5f, 0.5f, 0.5f), *pDefaultMat);

	pShape->setFlag(PxShapeFlag::eSIMULATION_SHAPE, false);
	pShape->setFlag(PxShapeFlag::eTRIGGER_SHAPE, true);

	m_pPhysxScene->addActor(*m_pTriggerLeft);

	//TRIGGER RIGHT
	m_pTriggerRight = pPhysX->createRigidStatic(PxTransform(8.f, 0.5f, 0.f));
	pShape = PxRigidActorExt::createExclusiveShape(*m_pTriggerRight, PxBoxGeometry(0.5f, 0.5f, 0.5f), *pDefaultMat);

	pShape->setFlag(PxShapeFlag::eSIMULATION_SHAPE, false);
	pShape->setFlag(PxShapeFlag::eTRIGGER_SHAPE, true);

	m_pPhysxScene->addActor(*m_pTriggerRight);
}

void TriggerTestScene::Update()
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

	if (m_IsTriggeredLeft)
	{
		m_IsTriggeredLeft = false;
		m_pSphere->GetRigidActor()->is<PxRigidDynamic>()->addForce({ 0.f, 10.f, 0.f }, PxForceMode::eIMPULSE);
	}

	if (m_IsTriggeredRight)
	{
		m_IsTriggeredRight = false;
		m_pSphere->GetRigidActor()->is<PxRigidDynamic>()->addForce({ 0.f, 10.f, 0.f }, PxForceMode::eIMPULSE);
	}
}

void TriggerTestScene::Draw() const
{

}

void TriggerTestScene::OnSceneActivated()
{

}

void TriggerTestScene::OnSceneDeactivated()
{
}

void TriggerTestScene::onTrigger(PxTriggerPair* pairs, PxU32 count)
{
	for (auto index{ 0 }; index < count; ++index)
	{
		//ignore deleted shapes
		if (pairs[index].flags & (PxTriggerPairFlag::eREMOVED_SHAPE_TRIGGER | PxTriggerPairFlag::eREMOVED_SHAPE_OTHER))
			continue;

		const PxTriggerPair& pair{ pairs[index] };

		if (pair.triggerActor == m_pTriggerLeft)
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
		else if (pair.triggerActor == m_pTriggerRight)
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