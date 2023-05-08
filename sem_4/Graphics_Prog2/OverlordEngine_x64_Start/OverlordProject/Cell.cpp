#include "stdafx.h"
#include "Cell.h"
#include "Materials/DiffuseMaterial.h"
#include "Grid.h"
#include "Prefabs/Character.h"
#include <iostream>

GameScene* Cell::m_spGameScene{};
DiffuseMaterial* Cell::m_spBombMaterial{};
DiffuseMaterial* Cell::m_spFlameMaterial{};
PxMaterial* Cell::m_spPhysxMaterial{};
float Cell::m_sSecUntilExplotion{ 2.f };
float Cell::m_sSecFireBurn{ 1.f };

Cell::Cell(GameScene* pGameScene, Grid* pOwnerGrid, XMFLOAT3 middlePos, int rowNr, int colNr, State state)
	: m_pOwnerGrid{ pOwnerGrid }
	, m_MiddlePos{ middlePos }
	, m_RowNr{ rowNr }
	, m_ColNr{ colNr }
	, m_State{ state }
{
	if (!m_spBombMaterial)
	{
		m_spBombMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spBombMaterial->SetDiffuseTexture(L"Textures/Bomb/Bomb.png");
	}

	if (!m_spFlameMaterial)
	{
		m_spFlameMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spFlameMaterial->SetDiffuseTexture(L"Textures/Fire.png");
	}

	if (!m_spPhysxMaterial)
	{
		auto& pPhysX{ PxGetPhysics() };
		m_spPhysxMaterial = pPhysX.createMaterial(0.5f, 0.5f, 0.5f);
	}

	if (!m_spGameScene)
	{
		m_spGameScene = pGameScene;
	}	
}

Cell::Cell(GameScene* pGameScene, Grid* pOwnerGrid, XMFLOAT3 middlePos, int rowNr, int colNr, State state, GameObject* pGameObjectInCell)
	: Cell(pGameScene, pOwnerGrid, middlePos, rowNr, colNr, state)
{
	m_pGameObjectInCell = pGameObjectInCell;
}

void Cell::Update()
{
	if (m_ShouldAddColliderToGameObjectInCell)
	{
		AddColliderToGameObjectInCell();
		m_ShouldAddColliderToGameObjectInCell = false;
	}

	if (m_State == State::bomb)
	{
		m_TimeSinceItemPlaceOnCell += m_spGameScene->GetSceneContext().pGameTime->GetElapsed();

		if (m_TimeSinceItemPlaceOnCell >= m_sSecUntilExplotion)
		{
			if (m_pGameObjectInCell)
			{
				DestroyObjectInCell();
				m_pGameObjectInCell = nullptr;
				m_State = State::empty;
				m_TimeSinceItemPlaceOnCell = 0.f;
				ExplodeBomb();
			}
		}
	}

	if (m_State == State::fire)
	{
		m_TimeSinceItemPlaceOnCell += m_spGameScene->GetSceneContext().pGameTime->GetElapsed();

		if (m_TimeSinceItemPlaceOnCell >= m_sSecFireBurn)
		{
			if (m_pGameObjectInCell)
			{
				DestroyObjectInCell();
				m_pGameObjectInCell = nullptr;
				m_State = State::empty;
				m_TimeSinceItemPlaceOnCell = 0.f;
			}
		}
	}
}

void Cell::PlaceBomb(int range)
{
	m_TimeSinceItemPlaceOnCell = 0.f;

	m_BombRange = range;

	m_State = State::bomb;

	auto pBomb{ m_spGameScene->AddChild(new GameObject()) };
	auto pModel{ pBomb->AddComponent(new ModelComponent(L"Meshes/Bomb.ovm")) };
	pModel->SetMaterial(m_spBombMaterial);
	auto pRigidBody = pBomb->AddComponent(new RigidBodyComponent(true));
	pRigidBody->AddCollider(PxBoxGeometry(0.75f / 2.f, 0.75f / 2.f, 0.75f / 2.f), *m_spPhysxMaterial, true);

	auto callBack
	{
		[&](GameObject*, GameObject* , PxTriggerAction action)
		{
			if (action == PxTriggerAction::LEAVE)
				m_ShouldAddColliderToGameObjectInCell = true;
		}
	};
	pBomb->SetOnTriggerCallBack(callBack);

	pBomb->GetTransform()->Translate(m_MiddlePos);
	pBomb->GetTransform()->Scale(0.01f);

	DestroyObjectInCell();
	m_pGameObjectInCell = pBomb;
}

void Cell::AddColliderToGameObjectInCell()
{
	auto pRigidBody = m_pGameObjectInCell->AddComponent(new RigidBodyComponent(true));
	pRigidBody->AddCollider(PxBoxGeometry(0.75f / 2.f, 0.75f / 2.f, 0.75f / 2.f), *m_spPhysxMaterial);
	m_pGameObjectInCell->SetOnTriggerCallBack(nullptr);
}

void Cell::DestroyObjectInCell()
{
	if (m_pGameObjectInCell)
	{
		m_spGameScene->RemoveChild(m_pGameObjectInCell, true);
	}
}

void Cell::ExplodeBomb()
{
	PlaceFire(GetMiddlePos());

	for (int index{ 1 }; index <= m_BombRange; ++index)
	{
		auto bottomNeigbor{ m_pOwnerGrid->GetCell(m_RowNr - index, m_ColNr) };
		if (bottomNeigbor && bottomNeigbor->GetState() != State::wall && bottomNeigbor->GetState() != State::fire)
		{
			if (bottomNeigbor->GetState() == State::bomb)
			{
				bottomNeigbor->ExplodeBomb();
				break;
			}

			if (bottomNeigbor->GetState() == State::crackedWall)
			{
				bottomNeigbor->PlaceFire(bottomNeigbor->GetMiddlePos());
				break;
			}

			bottomNeigbor->PlaceFire(bottomNeigbor->GetMiddlePos());
		}
	}

	for (int index{ 1 }; index <= m_BombRange; ++index)
	{
		auto leftNeighbor{ m_pOwnerGrid->GetCell(m_RowNr, m_ColNr - index) };
		if (leftNeighbor && leftNeighbor->GetState() != State::wall && leftNeighbor->GetState() != State::fire)
		{
			if (leftNeighbor->GetState() == State::bomb)
			{
				leftNeighbor->ExplodeBomb();
				break;
			}

			if (leftNeighbor->GetState() == State::crackedWall)
			{
				leftNeighbor->PlaceFire(leftNeighbor->GetMiddlePos());
				break;	
			}

			leftNeighbor->PlaceFire(leftNeighbor->GetMiddlePos());
		}
	}
	for (int index{ 1 }; index <= m_BombRange; ++index)
	{
		auto topNeigbor{ m_pOwnerGrid->GetCell(m_RowNr + index, m_ColNr) };
		if (topNeigbor && topNeigbor->GetState() != State::wall && topNeigbor->GetState() != State::fire)
		{
			if (topNeigbor->GetState() == State::bomb)
			{
				topNeigbor->ExplodeBomb();
				break;
			}

			if (topNeigbor->GetState() == State::crackedWall)
			{
				topNeigbor->PlaceFire(topNeigbor->GetMiddlePos());
				break;
			}

			topNeigbor->PlaceFire(topNeigbor->GetMiddlePos());
		}
	}

	for (int index{ 1 }; index <= m_BombRange; ++index)
	{
		auto rightNeighbor{ m_pOwnerGrid->GetCell(m_RowNr, m_ColNr + index) };
		if (rightNeighbor && rightNeighbor->GetState() != State::wall && rightNeighbor->GetState() != State::fire)
		{
			if (rightNeighbor->GetState() == State::bomb)
			{
				rightNeighbor->ExplodeBomb();
				break;
			}

			if (rightNeighbor->GetState() == State::crackedWall)
			{
				rightNeighbor->PlaceFire(rightNeighbor->GetMiddlePos());
				break;
			}

			rightNeighbor->PlaceFire(rightNeighbor->GetMiddlePos());
		}
	}
}

void Cell::PlaceFire(XMFLOAT3 pos)
{
	m_TimeSinceItemPlaceOnCell = 0.f;

	m_State = State::fire;

	auto callBack
	{
		[&](GameObject*, GameObject* pOtherObject, PxTriggerAction action)
		{
			if (action == PxTriggerAction::ENTER && reinterpret_cast<Character*>(pOtherObject))
				std::cout << "player in flame\n";
			//else if(pOtherObject)
			//{
			//	m_spGameScene->RemoveChild(pOtherObject, true);
			//}
		}
	};

	auto pFlame = m_spGameScene->AddChild(new GameObject());
	auto pModel{ pFlame->AddComponent(new ModelComponent(L"Meshes/Fire.ovm")) };
	pModel->SetMaterial(m_spFlameMaterial);
	auto pRigidBody{ pFlame->AddComponent(new RigidBodyComponent(true)) };
	pRigidBody->AddCollider(PxBoxGeometry(0.5f, 0.5f, 0.5f), *m_spPhysxMaterial, true);
	pFlame->SetOnTriggerCallBack(callBack);
	pFlame->GetTransform()->Translate(pos);
	pFlame->GetTransform()->Scale(0.01f);

	DestroyObjectInCell();
	m_pGameObjectInCell = pFlame;
}