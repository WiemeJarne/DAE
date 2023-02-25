#include "stdafx.h"
#include "BouncingBallScene.h"

#include "SpherePosColorNorm.h"

void BouncingBallScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const PxMaterial* pBouncingMaterial{ pPhysX->createMaterial(0.5f, 0.5f, 1.f) };
	const PxMaterial* pHalfBouncingMaterial{ pPhysX->createMaterial(0.5f, 0.5f, 0.5f) };
	const PxMaterial* pNotBoucingMaterial{ pPhysX->createMaterial(0.5f, 0.5f, 0.f) };

	//GROUND PLANE
	auto pGroundActor{ pPhysX->createRigidStatic(PxTransform(PxQuat(PxPiDivTwo, PxVec3(0, 0, 1)))) };
	PxRigidActorExt::createExclusiveShape(*pGroundActor, PxPlaneGeometry{}, *pBouncingMaterial);
	m_pPhysxScene->addActor(*pGroundActor);

	//spheres
	const float sphereRadius{ 1.f };
	const XMFLOAT4 sphereColor{ 0.f, 0.5f, 0.f, 1.f };
	const float sphereStartY{ 10.f };
	PxSphereGeometry sphereGeometry{ PxSphereGeometry(sphereRadius) };

	//sphere1
	m_pSphere1 = new SpherePosColorNorm(sphereRadius, 20, 20, sphereColor);
	m_pSphere1->Translate(-5.f, sphereStartY, 0.f);
	AddGameObject(m_pSphere1);

	//sphere1 actor
	PxRigidDynamic* pSphere1Actor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };

	//sphere1 shape
	PxRigidActorExt::createExclusiveShape(*pSphere1Actor, sphereGeometry, *pBouncingMaterial);

	//link sphere1 with sphere1 actor
	m_pSphere1->AttachRigidActor(pSphere1Actor);

	//sphere2
	m_pSphere2 = new SpherePosColorNorm(sphereRadius, 20, 20, sphereColor);
	m_pSphere2->Translate(0.f, sphereStartY, 0.f);
	AddGameObject(m_pSphere2);

	//sphere2 actor
	PxRigidDynamic* pSphere2Actor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };

	//sphere2 shape
	PxRigidActorExt::createExclusiveShape(*pSphere2Actor, sphereGeometry, *pHalfBouncingMaterial);

	//link sphere2 with sphere2 actor
	m_pSphere2->AttachRigidActor(pSphere2Actor);
	
	//sphere3
	m_pSphere3 = new SpherePosColorNorm(sphereRadius, 20, 20, sphereColor);
	m_pSphere3->Translate(5.f, sphereStartY, 0.f);
	AddGameObject(m_pSphere3);
	
	//sphere3 actor
	PxRigidDynamic* pShpere3Actor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };

	//sphere3 shape
	PxRigidActorExt::createExclusiveShape(*pShpere3Actor, sphereGeometry, *pNotBoucingMaterial);

	//link sphere3 with sphere3 actor
	m_pSphere3->AttachRigidActor(pShpere3Actor);
	
}

void BouncingBallScene::Update()
{
	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R')) //resets the scene
	{
		m_pSphere1->Translate(-5.f, 10.f, 0.f);
		m_pSphere2->Translate(0.f, 10.f, 0.f);
		m_pSphere3->Translate(5.f, 10.f, 0.f);
	}
}

void BouncingBallScene::Draw() const
{

}

void BouncingBallScene::OnSceneActivated()
{

}

void BouncingBallScene::OnSceneDeactivated()
{
}
