#include "stdafx.h"
#include "W1_AssignmentScene.h"

#include "SpherePosColorNorm.h"
#include "CubePosColorNorm.h"

enum InputIDs
{
	Forwards,
	Backwards,
	Left,
	Right
};

void W1_AssignmentScene::Initialize()
{
	EnablePhysxDebugRendering(true);

	const auto pPhysX{ PhysxManager::GetInstance()->GetPhysics() };
	const PxMaterial* pFloorMat{ pPhysX->createMaterial(0.7f, 0.7f, 0.5f) };
	const PxMaterial* pCubeMat{ pPhysX->createMaterial(0.1f, 0.1f, 0.1f) };
	const PxMaterial* pSphereMat{ pPhysX->createMaterial(0.5f, 0.5f, 0.5f) };

	//FLOOR
	XMFLOAT3 actorDimensions{ 150.f, 0.1f, 150.f };
	auto floor{ new CubePosColorNorm(actorDimensions.x, actorDimensions.y, actorDimensions.z, XMFLOAT4(Colors::LightGray)) };
	AddGameObject(floor);

	floor->Translate(0.f, -0.1f, 0.f);

	auto pGroundActor{ pPhysX->createRigidStatic(PxTransform(PxQuat(PxPiDivTwo, PxVec3(0, 0, 1)))) };
	PxBoxGeometry boxGeometry{ PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f) };
	PxRigidActorExt::createExclusiveShape(*pGroundActor, boxGeometry, *pFloorMat);
	floor->AttachRigidActor(pGroundActor);

	//SPHERE
	const float radius{ 2.f };
	m_pSphere = new SpherePosColorNorm(radius, 20, 20, XMFLOAT4(Colors::Yellow));
	m_pSphere->Translate(0.f, 0.f, -50.f);
	AddGameObject(m_pSphere);
	
	//sphere actor
	PxRigidDynamic* pSphereActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
	pSphereActor->setMass(3.f);

	//sphere shape
	PxRigidActorExt::createExclusiveShape(*pSphereActor, PxSphereGeometry(radius), *pSphereMat);

	//link sphere with sphere actor
	m_pSphere->AttachRigidActor(pSphereActor);

	//CUBES
	m_XStartPos = { -(m_CubeActorDimensions.x / 2.f) * m_AmountOfRows };
	float xTranslation{ m_XStartPos };
	float yTranslation{};

	for (int rowNr{}; rowNr < m_AmountOfRows; ++rowNr)
	{
		for (int colNr{}; colNr < m_AmountOfCollumns; ++colNr)
		{
			auto cube = new CubePosColorNorm(m_CubeActorDimensions.x, m_CubeActorDimensions.y, m_CubeActorDimensions.z);
			AddGameObject(cube);
			cube->Translate(xTranslation, yTranslation, 0.f);
			const int randomRotation(std::rand() % 20 - 10);
			cube->RotateDegrees(0.f, randomRotation, 0.f);

			PxRigidDynamic* pCubeActor{ pPhysX->createRigidDynamic(PxTransform(PxIdentity)) };
			pCubeActor->setMass(0.1f);
			auto boxGeometry{ PxBoxGeometry(m_CubeActorDimensions.x / 2.f, m_CubeActorDimensions.y / 2.f, m_CubeActorDimensions.z / 2.f) };

			PxRigidActorExt::createExclusiveShape(*pCubeActor, boxGeometry, *pCubeMat);

			cube->AttachRigidActor(pCubeActor);
			xTranslation += m_CubeActorDimensions.x + m_HorizontalSpaceBetweenCubes;

			m_Cubes.push_back(cube);
		}
		xTranslation = m_XStartPos;
		yTranslation += m_CubeActorDimensions.y + m_VerticalSpaceBetweenCubes;
	}
	
	//CAMERA
	m_SceneContext.GetCamera()->SetPosition(XMFLOAT3(-15.f, 20.f, -75.f));
	m_SceneContext.GetCamera()->SetForward(XMFLOAT3(0.5f, -0.5f, 1.f));

	//INPUT
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Backwards, InputTriggerState::down, VK_DOWN, -1, XINPUT_GAMEPAD_DPAD_DOWN));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Left, InputTriggerState::down, VK_LEFT, -1, XINPUT_GAMEPAD_DPAD_LEFT));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Right, InputTriggerState::down, VK_RIGHT, -1, XINPUT_GAMEPAD_DPAD_RIGHT));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Forwards, InputTriggerState::down, VK_UP, -1, XINPUT_GAMEPAD_DPAD_UP));
}

inline PxVec3 ToPxVec3(XMFLOAT3 v)
{
	return (PxVec3(v.x, v.y, v.z));
}

void W1_AssignmentScene::Update()
{
	const float amountOfTorque{ 10.f };

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Left))
	{
		static_cast<PxRigidBody*>(m_pSphere->GetRigidActor())->addTorque(ToPxVec3(m_SceneContext.GetCamera()->GetForward()).getNormalized() * amountOfTorque, PxForceMode::eACCELERATION);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Right))
	{
		static_cast<PxRigidBody*>(m_pSphere->GetRigidActor())->addTorque(-ToPxVec3(m_SceneContext.GetCamera()->GetForward()).getNormalized() * amountOfTorque, PxForceMode::eACCELERATION);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Forwards))
	{
		static_cast<PxRigidBody*>(m_pSphere->GetRigidActor())->addTorque(ToPxVec3(m_SceneContext.GetCamera()->GetRight()).getNormalized() * amountOfTorque, PxForceMode::eACCELERATION);
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Backwards))
	{
		static_cast<PxRigidBody*>(m_pSphere->GetRigidActor())->addTorque(-ToPxVec3(m_SceneContext.GetCamera()->GetRight()).getNormalized() * amountOfTorque, PxForceMode::eACCELERATION);
	}

	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R')) //reset the scene
	{
		//reposition SPHERE
		m_pSphere->Translate(0.f, 0.f, -50.f);

		//stop SHPERE rotating
		static_cast<PxRigidBody*>(m_pSphere->GetRigidActor())->setForceAndTorque(PxVec3(0.f, 0.f, 0.f), PxVec3(0.f, 0.f, 0.f));

		//reposition CUBES
		float xTranslation{ m_XStartPos };
		float yTranslation{};

		for (int rowNr{}; rowNr < m_AmountOfRows; ++rowNr)
		{
			for (int colNr{}; colNr < m_AmountOfCollumns; ++colNr)
			{
				m_Cubes[rowNr * m_AmountOfCollumns + colNr]->Translate(xTranslation, yTranslation, 0.f);

				const int randomRotation(std::rand() % 20 - 10);
				m_Cubes[rowNr * m_AmountOfCollumns + colNr]->RotateDegrees(0.f, randomRotation, 0.f);

				xTranslation += m_CubeActorDimensions.x + m_HorizontalSpaceBetweenCubes;
			}
			xTranslation = m_XStartPos;
			yTranslation += m_CubeActorDimensions.y + m_VerticalSpaceBetweenCubes;
		}

		//reposition CAMERA
		m_SceneContext.GetCamera()->SetPosition(XMFLOAT3(-15.f, 20.f, -75.f));
		m_SceneContext.GetCamera()->SetForward(XMFLOAT3(0.5f, -0.5f, 1.f));
	}
}

void W1_AssignmentScene::Draw() const
{

}

void W1_AssignmentScene::OnSceneActivated()
{

}

void W1_AssignmentScene::OnSceneDeactivated()
{
}