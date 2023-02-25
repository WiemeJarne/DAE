#include "stdafx.h"
#include "W1_AssignmentScene.h"
#include "stdafx.h"

#include "SpherePosColorNorm.h"
#include "CubePosColorNorm.h"

void W1_AssignmentScene::Initialize()
{
	//FLOOR
	const XMFLOAT3 actorDimensions{ 100.f, 0.1f, 100.f };
	m_pFloor = new CubePosColorNorm(actorDimensions.x, actorDimensions.y, actorDimensions.z);
	AddGameObject(m_pFloor);

}

void W1_AssignmentScene::Update()
{
	if (m_SceneContext.GetInput()->IsKeyboardKey(InputTriggerState::pressed, 'R')) //reset the scene
	{

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
