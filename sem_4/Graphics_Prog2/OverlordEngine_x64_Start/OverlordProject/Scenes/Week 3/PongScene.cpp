#include "stdafx.h"
#include "PongScene.h"

#include "Prefabs/CubePrefab.h"
#include "Prefabs/SpherePrefab.h"

enum InputIDs
{
	StartGame,
	ResetGame,
	PeddleLeftUp,
	PeddleLeftDown,
	PeddleRightUp,
	PeddleRightDown
};

void PongScene::Initialize()
{
	m_SceneContext.settings.drawGrid = false;
	m_SceneContext.settings.drawPhysXDebug = false;
	m_SceneContext.settings.clearColor = XMFLOAT4(0.f, 0.f, 0.f, 1.f);
	
	//CAMERA
	m_pFixedCamera = new FixedCamera();
	m_pFixedCamera->GetTransform()->Translate(0.f, 50.f, 0.f);
	m_pFixedCamera->GetTransform()->Rotate(90.f, 0.f, 0.f);
	AddChild(m_pFixedCamera);
	SetActiveCamera(m_pFixedCamera->GetComponent<CameraComponent>());
	
	auto& pPhysX{ PxGetPhysics() };
	auto pMat{ pPhysX.createMaterial(0.f, 0.f, 1.f) };

	//ground plane
	//GameSceneExt::CreatePhysXGroundPlane(*this, pMat);

	//BALL
	const float radius{ 1.f };
	m_pBall = new SpherePrefab(radius, 10, XMFLOAT4(Colors::Red));
	AddChild(m_pBall);
	auto pRigidBody{ m_pBall->AddComponent(new RigidBodyComponent()) };
	pRigidBody->AddCollider(PxSphereGeometry(radius), *pMat);
	pRigidBody->SetConstraint(RigidBodyConstraint::TransY, false);

	//PEDDLES
	XMFLOAT3 actorDimensions{ 1.f, 1.f, m_PeddleLenght };

	//PEDDLE LEFT
	m_pPeddleLeft = new CubePrefab(actorDimensions, XMFLOAT4(Colors::White));
	AddChild(m_pPeddleLeft);
	m_pPeddleLeft->GetTransform()->Translate(-33.f, 0.f, 0.f);
	pRigidBody = m_pPeddleLeft->AddComponent(new RigidBodyComponent());
	pRigidBody->AddCollider(PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pMat);
	pRigidBody->SetKinematic(true);

	//PEDDLE RIGHT
	m_pPeddleRight = new CubePrefab(actorDimensions, XMFLOAT4(Colors::White));
	AddChild(m_pPeddleRight);
	m_pPeddleRight->GetTransform()->Translate(33.f, 0.f, 0.f);
	pRigidBody = m_pPeddleRight->AddComponent(new RigidBodyComponent());
	pRigidBody->AddCollider(PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pMat);
	pRigidBody->SetKinematic(true);

	//BORDERS
	actorDimensions = { 75.f, 1.f, 1.f };
	
	//BORDER TOP
	auto pCube{ new CubePrefab(actorDimensions, XMFLOAT4(Colors::Transparent)) };
	AddChild(pCube);
	pCube->GetTransform()->Translate(0.f, 0.f, 21.f);
	pRigidBody = pCube->AddComponent(new RigidBodyComponent(true));
	pRigidBody->AddCollider(PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pMat);

	//BORDER BOTTOM
	pCube = new CubePrefab(actorDimensions, XMFLOAT4(Colors::Transparent));
	AddChild(pCube);
	pCube->GetTransform()->Translate(0.f, 0.f, -21.f);
	pRigidBody = pCube->AddComponent(new RigidBodyComponent(true));
	pRigidBody->AddCollider(PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pMat);

	//TRIGGERS
	actorDimensions = { 1.f, 1.f, 40.f };
	auto callBack
	{
		[&](GameObject*, GameObject*, PxTriggerAction action)
		{
			if (action == PxTriggerAction::ENTER)
				Reset();
		}
	};

	//LEFT TRIGGER
	pCube = new CubePrefab(actorDimensions, XMFLOAT4(Colors::Transparent));
	AddChild(pCube);
	pCube->GetTransform()->Translate(-37.f, 0.f, 0.f);
	pRigidBody = pCube->AddComponent(new RigidBodyComponent(true));
	pRigidBody->AddCollider(PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pMat, true);
	pCube->SetOnTriggerCallBack(callBack);

	//RIGHT TRIGGER
	pCube = new CubePrefab(actorDimensions, XMFLOAT4(Colors::Transparent));
	AddChild(pCube);
	pCube->GetTransform()->Translate(37.f, 0.f, 0.f);
	pRigidBody = pCube->AddComponent(new RigidBodyComponent(true));
	pRigidBody->AddCollider(PxBoxGeometry(actorDimensions.x / 2.f, actorDimensions.y / 2.f, actorDimensions.z / 2.f), *pMat, true);
	pCube->SetOnTriggerCallBack(callBack);

	//INPUT
	m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::StartGame, InputState::down, VK_SPACE));
	m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::ResetGame, InputState::down, 'R'));
	m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::PeddleLeftUp, InputState::down, 'W'));
	m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::PeddleLeftDown, InputState::down, 'S'));
	m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::PeddleRightUp, InputState::down, VK_UP));
	//m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::PeddleRightUp, InputState::down, 'I'));
	m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::PeddleRightDown, InputState::down, VK_DOWN));
	//m_SceneContext.pInput->AddInputAction(InputAction(InputIDs::PeddleRightDown, InputState::down, 'K'));
}

void PongScene::Update()
{
	if (m_SceneContext.pInput->IsActionTriggered(StartGame))
	{
		m_pBall->GetComponent<RigidBodyComponent>()->AddForce(XMFLOAT3(0.7f, 0.f, 1.2f), PxForceMode::eIMPULSE);
	}

	if (m_SceneContext.pInput->IsActionTriggered(ResetGame))
	{
		Reset();
	}

	const float peddleMoveSpeed{ 30.f };
	const float peddleMaxZPos{ 21.f - m_PeddleLenght / 2.f };
	const float peddleMinZPos{ -21.f + m_PeddleLenght / 2.f };
	if (m_SceneContext.pInput->IsActionTriggered(PeddleLeftUp))
	{
		auto pRigidBody{ m_pPeddleLeft->GetComponent<RigidBodyComponent>() };
		XMFLOAT3 newPos{ pRigidBody->GetPosition() };
		newPos.z += peddleMoveSpeed * m_SceneContext.pGameTime->GetElapsed();
		if(newPos.z < peddleMaxZPos)
			pRigidBody->Translate(newPos);
	}

	if (m_SceneContext.pInput->IsActionTriggered(PeddleLeftDown))
	{
		auto pRigidBody{ m_pPeddleLeft->GetComponent<RigidBodyComponent>() };
		XMFLOAT3 newPos{ pRigidBody->GetPosition() };
		newPos.z += -peddleMoveSpeed * m_SceneContext.pGameTime->GetElapsed();
		if (newPos.z > peddleMinZPos)
			pRigidBody->Translate(newPos);
	}

	if (m_SceneContext.pInput->IsActionTriggered(PeddleRightUp))
	{
		auto pRigidBody{ m_pPeddleRight->GetComponent<RigidBodyComponent>() };
		XMFLOAT3 newPos{ pRigidBody->GetPosition() };
		newPos.z += peddleMoveSpeed * m_SceneContext.pGameTime->GetElapsed();
		if (newPos.z < peddleMaxZPos)
			pRigidBody->Translate(newPos);
	}

	if (m_SceneContext.pInput->IsActionTriggered(PeddleRightDown))
	{
		auto pRigidBody{ m_pPeddleRight->GetComponent<RigidBodyComponent>() };
		XMFLOAT3 newPos{ pRigidBody->GetPosition() };
		newPos.z += -peddleMoveSpeed * m_SceneContext.pGameTime->GetElapsed();
		if (newPos.z > peddleMinZPos)
			pRigidBody->Translate(newPos);
	}
}

void PongScene::Reset()
{
	m_pBall->GetTransform()->Translate(0.f, 0.f, 0.f);
	m_pPeddleLeft->GetTransform()->Translate(-33.f, 0.f, 0.f);
	m_pPeddleRight->GetTransform()->Translate(33.f, 0.f, 0.f);
}