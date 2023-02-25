#include "stdafx.h"
#include "FrictionTestScene.h"

#include "CubePosColorNorm.h"

void FrictionTestScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const PxMaterial* pDefaultMaterial{ pPhysX->createMaterial(0.5f, 0.5f, 0.5f) };
	const PxMaterial* pNoFrictionMaterial{ pPhysX->createMaterial(0.f, 0.f, 0.f) };
	const PxMaterial* pHalfFrictionMaterial{ pPhysX->createMaterial(0.5f, 0.5f, 0.f) };
	const PxMaterial* pFllFrictionMaterial{ pPhysX->createMaterial(1.f, 1.f, 0.f) };

	//GROUND PLANE
	auto pGroundActor{ pPhysX->createRigidStatic(PxTransform(PxQuat(PxPiDivTwo, PxVec3(0, 0, 1)))) };
	PxRigidActorExt::createExclusiveShape(*pGroundActor, PxPlaneGeometry{}, *pDefaultMaterial);
	m_pPhysxScene->addActor(*pGroundActor);

	//C BES
	const float cubeZRotation{ -30.f }; //in degrees

	//DYNAMIC CUBES
	const XMFLOAT3 dynamicCubeDimensions{ 1.f, 1.f, 1.f };
	const float cubeDropHeight{ 5.f };
	PxBoxGeometry dynamicCubesGeometry{ PxBoxGeometry(dynamicCubeDimensions.x / 2.f, dynamicCubeDimensions.y / 2.f, dynamicCubeDimensions.z / 2.f) };

	//dynamicCube1
	m_pDynamicCube1 = new CubePosColorNorm(dynamicCubeDimensions.x, dynamicCubeDimensions.y, dynamicCubeDimensions.z);
	m_pDynamicCube1->Translate(-8.f, cubeDropHeight, 0.f);
	m_pDynamicCube1->RotateDegrees(0.f, 0.f, cubeZRotation);
	AddGameObject(m_pDynamicCube1);

	//dynamicCube1 actor
	PxRigidDynamic* pDynamicCube1Actor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	
	//dynamicCube1 shape
	PxRigidActorExt::createExclusiveShape(*pDynamicCube1Actor, dynamicCubesGeometry, *pNoFrictionMaterial);

	//link dynamicCube1 with dynamicCube1 actor
	m_pDynamicCube1->AttachRigidActor(pDynamicCube1Actor);

	//dynamicCube2
	m_pDynamicCube2 = new CubePosColorNorm(dynamicCubeDimensions.x, dynamicCubeDimensions.y, dynamicCubeDimensions.z);
	m_pDynamicCube2->Translate(-1.f, cubeDropHeight, 0.f);
	m_pDynamicCube2->RotateDegrees(0.f, 0.f, cubeZRotation);
	AddGameObject(m_pDynamicCube2);

	//dynamicCube2 actor
	PxRigidDynamic* pDynamicCube2Actor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };

	//dynamicCube2 shape
	PxRigidActorExt::createExclusiveShape(*pDynamicCube2Actor, dynamicCubesGeometry, *pHalfFrictionMaterial);

	//link dynamicCube2 with dynamicCube2 actor
	m_pDynamicCube2->AttachRigidActor(pDynamicCube2Actor);

	//dynamicCube3
	m_pDynamicCube3 = new CubePosColorNorm(dynamicCubeDimensions.x, dynamicCubeDimensions.y, dynamicCubeDimensions.z);
	m_pDynamicCube3->Translate(6.f, cubeDropHeight, 0.f);
	m_pDynamicCube3->RotateDegrees(0.f, 0.f, cubeZRotation);
	AddGameObject(m_pDynamicCube3);

	//dynamicCube3 actor
	PxRigidDynamic* pDynamicCube3Actor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };

	//dynamicCube3 shape
	PxRigidActorExt::createExclusiveShape(*pDynamicCube3Actor, dynamicCubesGeometry, *pFllFrictionMaterial);

	//link dynamicCube3 with dynamicCube3 actor
	m_pDynamicCube3->AttachRigidActor(pDynamicCube3Actor);

	//STATIC CUBES
	const XMFLOAT3 staticCubesDimensions{ 5.f, 1.f, 1.5f };
	float staticCubeYTranslation{(staticCubesDimensions.x / 2.f) * XMScalarSin(XMConvertToRadians(cubeZRotation))}; //the amount of Y needed to place the static cubes on the plane
	if (staticCubeYTranslation < 0)
	{
		staticCubeYTranslation *= -1;
	}
	staticCubeYTranslation += staticCubesDimensions.y / 2.f;
	PxBoxGeometry staticCubesGeometry{ PxBoxGeometry(staticCubesDimensions.x / 2.f, staticCubesDimensions.y / 2.f, staticCubesDimensions.z / 2.f) };

	//staticCube1
	m_pStaticCube1 = new CubePosColorNorm(staticCubesDimensions.x, staticCubesDimensions.y, staticCubesDimensions.z);
	m_pStaticCube1->Translate(-7.f, staticCubeYTranslation, 0.f);
	m_pStaticCube1->RotateDegrees(0.f, 0.f, cubeZRotation);
	AddGameObject(m_pStaticCube1);

	//staticCube1 actor
	PxRigidStatic* pStaticCube1Actor{ pPhysX->createRigidStatic(PxTransform(PxIdentity)) };

	//staticCube1 shape
	PxRigidActorExt::createExclusiveShape(*pStaticCube1Actor, staticCubesGeometry, *pNoFrictionMaterial);

	//link staticCube1 with staticCube1 actor
	m_pStaticCube1->AttachRigidActor(pStaticCube1Actor);

	//staticCube2
	m_pStaticCube2 = new CubePosColorNorm(staticCubesDimensions.x, staticCubesDimensions.y, staticCubesDimensions.z);
	m_pStaticCube2->Translate(0.f, staticCubeYTranslation, 0.f);
	m_pStaticCube2->RotateDegrees(0.f, 0.f, cubeZRotation);
	AddGameObject(m_pStaticCube2);

	//staticCube2 actor
	PxRigidStatic* pStaticCube2Actor{ pPhysX->createRigidStatic(PxTransform(PxIdentity)) };

	//staticCube2 shape
	PxRigidActorExt::createExclusiveShape(*pStaticCube2Actor, staticCubesGeometry, *pNoFrictionMaterial);

	//link staticCube2 with staticCube2 actor
	m_pStaticCube2->AttachRigidActor(pStaticCube2Actor);

	//staticCube3
	m_pStaticCube3 = new CubePosColorNorm(staticCubesDimensions.x, staticCubesDimensions.y, staticCubesDimensions.z);
	m_pStaticCube3->Translate(7.f, staticCubeYTranslation, 0.f);
	m_pStaticCube3->RotateDegrees(0.f, 0.f, cubeZRotation);
	AddGameObject(m_pStaticCube3);

	//staticCube3 actor
	PxRigidStatic* pStaticCube3Actor{ pPhysX->createRigidStatic(PxTransform(PxIdentity)) };

	//staticCube3 shape
	PxRigidActorExt::createExclusiveShape(*pStaticCube3Actor, staticCubesGeometry, *pNoFrictionMaterial);

	//link staticCube3 with staticCube3 actor
	m_pStaticCube3->AttachRigidActor(pStaticCube3Actor);
}

void FrictionTestScene::Update()
{
	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R')) //resets the scene
	{
		const float cubeDropHeight{ 5.f };
		const float cubeZRotation{ -30.f }; //in degrees
		m_pDynamicCube1->Translate(-8.f, cubeDropHeight, 0.f);
		m_pDynamicCube1->RotateDegrees(0.f, 0.f, cubeZRotation);
		m_pDynamicCube2->Translate(-1.f, cubeDropHeight, 0.f);
		m_pDynamicCube2->RotateDegrees(0.f, 0.f, cubeZRotation);
		m_pDynamicCube3->Translate(6.f, cubeDropHeight, 0.f);
		m_pDynamicCube3->RotateDegrees(0.f, 0.f, cubeZRotation);
	}
}

void FrictionTestScene::Draw() const
{

}

void FrictionTestScene::OnSceneActivated()
{

}

void FrictionTestScene::OnSceneDeactivated()
{
}
