#include "stdafx.h"
#include "TestScene.h"

#include "CubePosColorNorm.h"
#include "TorusPosColorNorm.h"
#include "CylinderPosColorNorm.h"
#include "Logger.h"

enum InputIDs
{
	Up,
	Down,
	Left,
	Right
};

void TestScene::Initialize()
{
	//CUBE
	m_pBox = new CubePosColorNorm(5.f, 2.f, 1.f);
	AddGameObject(m_pBox);

	m_pBox->Translate(0.f, 1.f, 0.f);
	m_pBox->RotateDegrees(0.f, 45.f, 0.f);

	//CAMERA
	m_SceneContext.GetCamera()->SetPosition(XMFLOAT3(0.f, 10.f, -25.f));
	m_SceneContext.GetCamera()->SetForward(XMFLOAT3(0.f, -0.3f, 1.f));

	//TORUS
	const auto pTorus{ new TorusPosColorNorm(8.f, 50, 1.f, 10, XMFLOAT4(Colors::Red)) };
	AddGameObject(pTorus);

	//CYLINDER
	const auto pCylinder{ new CylinderPosColorNorm(1.5f, 10, 4.f) };
	pTorus->AddChild(pCylinder);
	pCylinder->Translate(0.f, 8.f, 0.f);

	//INPUT
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Down, InputTriggerState::down, VK_DOWN, -1, XINPUT_GAMEPAD_DPAD_DOWN));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Left, InputTriggerState::down, VK_LEFT, -1, XINPUT_GAMEPAD_DPAD_LEFT));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Right, InputTriggerState::down, VK_RIGHT, -1, XINPUT_GAMEPAD_DPAD_RIGHT));
	m_SceneContext.GetInput()->AddInputAction(InputAction(InputIDs::Up, InputTriggerState::down, VK_UP, -1, XINPUT_GAMEPAD_DPAD_UP));
}

void TestScene::Update()
{
	const float totalTime{ m_SceneContext.GetGameTime()->GetTotal() };
	m_pBox->RotateDegrees(0.f, 90.f * totalTime, 0.f);

	XMFLOAT3 translation{};
	const float movementSpeed{ 10.f * m_SceneContext.GetGameTime()->GetElapsed() };

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Left))
	{
		translation.x -= movementSpeed;
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Right))
	{
		translation.x += movementSpeed;
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Up))
	{
		translation.y += movementSpeed;
	}

	if (m_SceneContext.GetInput()->IsActionTriggered(InputIDs::Down))
	{
		translation.y -= movementSpeed;
	}

	XMStoreFloat3(&translation, XMVectorAdd(XMLoadFloat3(&translation), XMLoadFloat3(&m_pBox->GetPosition())));
	m_pBox->Translate(translation.x, translation.y, translation.z);
}

void TestScene::Draw() const
{

}

void TestScene::OnSceneActivated()
{
	Logger::GetInstance()->LogFormat(LogLevel::Info, L"Scene Activated > \"%ls\"", GetName().c_str());
}

void TestScene::OnSceneDeactivated()
{
}
