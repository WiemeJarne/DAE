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

void Cell::Update()
{
	if (m_State == State::bomb)
	{
		m_TimeSinceItemPlaceOnCell += m_spGameScene->GetSceneContext().pGameTime->GetElapsed();

		if (m_TimeSinceItemPlaceOnCell >= m_sSecUntilExplotion)
		{
			m_spGameScene->RemoveChild(m_pGameObjectsInCell[0], true);
			m_TimeSinceItemPlaceOnCell = 0.f;
			m_pGameObjectsInCell[0] = nullptr;
			ExplodeBomb();

			m_pGameObjectsInCell.erase(std::remove(m_pGameObjectsInCell.begin(), m_pGameObjectsInCell.end(), nullptr), m_pGameObjectsInCell.end());
		}
	}

	if (m_State == State::fire)
	{
		m_TimeSinceItemPlaceOnCell += m_spGameScene->GetSceneContext().pGameTime->GetElapsed();

		if (m_TimeSinceItemPlaceOnCell >= m_sSecFireBurn)
		{
			for (auto pFire : m_pGameObjectsInCell)
			{
				m_spGameScene->RemoveChild(pFire, true);
				pFire = nullptr;
				m_State = State::empty;
				m_TimeSinceItemPlaceOnCell = 0.f;
			}
			m_pGameObjectsInCell.erase(std::remove(m_pGameObjectsInCell.begin(), m_pGameObjectsInCell.end(), nullptr), m_pGameObjectsInCell.end());
		}
	}
}

void Cell::PlaceBomb(int range)
{
	m_BombRange = range;

	m_State = State::bomb;

	auto pBomb{ m_spGameScene->AddChild(new GameObject()) };
	auto pModel{ pBomb->AddComponent(new ModelComponent(L"Meshes/Bomb.ovm")) };
	pModel->SetMaterial(m_spBombMaterial);

	pBomb->GetTransform()->Translate(m_MiddlePos);
	pBomb->GetTransform()->Scale(0.01f);

	m_pGameObjectsInCell.push_back(pBomb);
}

void Cell::ExplodeBomb()
{
	for (int index{1}; index <= m_BombRange; ++index)
	{
		auto bottomNeigbor{ m_pOwnerGrid->GetCell(m_RowNr - index, m_ColNr) };
		if (bottomNeigbor && bottomNeigbor->GetState() != State::wall && bottomNeigbor->GetState() != State::fire)
		{
			PlaceFire(bottomNeigbor->GetMiddlePos());
		}

		auto leftNeighbor{ m_pOwnerGrid->GetCell(m_RowNr, m_ColNr - index) };
		if (leftNeighbor && leftNeighbor->GetState() != State::wall && leftNeighbor->GetState() != State::fire)
		{
			PlaceFire(leftNeighbor->GetMiddlePos());
		}

		auto topNeigbor{ m_pOwnerGrid->GetCell(m_RowNr + index, m_ColNr) };
		if (topNeigbor && topNeigbor->GetState() != State::wall && topNeigbor->GetState() != State::fire)
		{
			PlaceFire(topNeigbor->GetMiddlePos());
		}

		auto rightNeighbor{ m_pOwnerGrid->GetCell(m_RowNr, m_ColNr + index) };
		if (rightNeighbor && rightNeighbor->GetState() != State::wall && rightNeighbor->GetState() != State::fire)
		{
			PlaceFire(rightNeighbor->GetMiddlePos());
		}
	}
}

void Cell::PlaceFire(XMFLOAT3 pos)
{
	m_State = State::fire;

	auto callBack
	{
		[&](GameObject*, GameObject* pOtherObject, PxTriggerAction action)
		{
			if (action == PxTriggerAction::ENTER && reinterpret_cast<Character*>(pOtherObject))
				std::cout << "player in flame\n";
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

	m_pGameObjectsInCell.push_back(pFlame);
}