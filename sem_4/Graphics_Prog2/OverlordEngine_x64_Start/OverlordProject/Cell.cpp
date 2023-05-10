#include "stdafx.h"
#include "Cell.h"
#include "Materials/DiffuseMaterial.h"
#include "Grid.h"
#include "Prefabs/Character.h"
#include <iostream>

GameScene* Cell::m_spGameScene{};
DiffuseMaterial* Cell::m_spBombMaterial{};
DiffuseMaterial* Cell::m_spFlameMaterial{};
DiffuseMaterial* Cell::m_spBombUpBonusMaterial{};
DiffuseMaterial* Cell::m_spBombDownBonusMaterial{};
DiffuseMaterial* Cell::m_spFireUpBonusMaterial{};
DiffuseMaterial* Cell::m_spFireDownBonusMaterial{};
DiffuseMaterial* Cell::m_spFullFireBonusMaterial{};
DiffuseMaterial* Cell::m_spPierceBombBonusMaterial{};
DiffuseMaterial* Cell::m_spSkateUpBonusMaterial{};
DiffuseMaterial* Cell::m_spSkateDownBonusMaterial{};
PxMaterial* Cell::m_spPhysxMaterial{};
float Cell::m_sSecUntilExplotion{ 2.f };
float Cell::m_sSecFireBurn{ 1.f };
GameObject::PhysicsCallback Cell::m_sBombUpBonusCallBack;
GameObject::PhysicsCallback Cell::m_sBombDownBonusCallBack;
GameObject::PhysicsCallback Cell::m_sFireUpBonusCallBack;
GameObject::PhysicsCallback Cell::m_sFireDownBonusCallBack;
GameObject::PhysicsCallback Cell::m_sFullFireBonusCallBack;
GameObject::PhysicsCallback Cell::m_sPierceBombBonusCallBack;
GameObject::PhysicsCallback Cell::m_sSkateUpBonusCallBack;
GameObject::PhysicsCallback Cell::m_sSkateDownBonusCallBack;

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

	if (!m_spBombUpBonusMaterial)
	{
		m_spBombUpBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spBombUpBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/BombUp.png");

		m_sBombUpBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				++characterDesc.amountOfBombsAllowedToBePlacedAtOnce;

				if (characterDesc.amountOfBombsAllowedToBePlacedAtOnce > characterDesc.maxAmountOfBombsAllowedToBePlacedAtOnce)
					characterDesc.amountOfBombsAllowedToBePlacedAtOnce = characterDesc.maxAmountOfBombsAllowedToBePlacedAtOnce;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if(pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
	}

	if (!m_spBombDownBonusMaterial)
	{
		m_spBombDownBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spBombDownBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/BombDown.png");

		m_sBombDownBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				--characterDesc.amountOfBombsAllowedToBePlacedAtOnce;

				if (characterDesc.amountOfBombsAllowedToBePlacedAtOnce < 1)
					characterDesc.amountOfBombsAllowedToBePlacedAtOnce = 1;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if (pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
	}

	if (!m_spFireUpBonusMaterial)
	{
		m_spFireUpBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spFireUpBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/FireUp.png");

		m_sFireUpBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				++characterDesc.bombBlastRadius;

				if (characterDesc.bombBlastRadius > characterDesc.maxBombBlastRadius)
					characterDesc.bombBlastRadius = characterDesc.maxBombBlastRadius;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if (pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
	}

	if (!m_spFireDownBonusMaterial)
	{
		m_spFireDownBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spFireDownBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/FireDown.png");

		m_sFireDownBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				--characterDesc.bombBlastRadius;

				if (characterDesc.bombBlastRadius < 1)
					characterDesc.bombBlastRadius = 1;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if (pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
	}

	if (!m_spFullFireBonusMaterial)
	{
		m_spFullFireBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spFullFireBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/FullFire.png");

		m_sFullFireBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				characterDesc.bombBlastRadius = characterDesc.maxBombBlastRadius;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if (pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
	}

	if (!m_spPierceBombBonusMaterial)
	{
		m_spPierceBombBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spPierceBombBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/PierceBomb.png");

		m_sPierceBombBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				characterDesc.hasPierceBomb = true;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if (pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
	}

	if (!m_spSkateUpBonusMaterial)
	{
		m_spSkateUpBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spSkateUpBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/SkateUp.png");

		m_sSkateUpBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				characterDesc.currentMaxMoveSpeed += 3.f;

				if (characterDesc.currentMaxMoveSpeed > characterDesc.maxMoveSpeed)
					characterDesc.currentMaxMoveSpeed = characterDesc.maxMoveSpeed;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if (pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
	}

	if (!m_spSkateDownBonusMaterial)
	{
		m_spSkateDownBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial>();
		m_spSkateDownBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/SkateDown.png");

		m_sSkateDownBonusCallBack =
			[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
		{
			auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
			if (action == PxTriggerAction::ENTER && pCharacter)
			{
				auto& characterDesc{ pCharacter->GetCharacterDescription() };

				characterDesc.currentMaxMoveSpeed -= 3.f;

				if (characterDesc.currentMaxMoveSpeed < characterDesc.minMoveSpeed)
					characterDesc.currentMaxMoveSpeed = characterDesc.minMoveSpeed;

				auto pCell{ m_pOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

				if (pCell)
					pCell->SetShouldDestroyGameObjectInCell(true);
			}
		};
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
	if (m_ShouldDestroyGameObjectInCell)
	{
		DestroyObjectInCell();
		m_ShouldDestroyGameObjectInCell = false;
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
				m_pCharacterDescPlacedBomb = nullptr;
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

				if(m_ShouldPlacePickUp)
					PlaceRandomPickUp(m_MiddlePos);
			}
		}
	}
}

void Cell::PlaceBomb(CharacterDesc* pCharacterDesc)
{
	if (pCharacterDesc->amountOfBombsCurrentlyOnGrid == pCharacterDesc->amountOfBombsAllowedToBePlacedAtOnce)
		return;

	m_pCharacterDescPlacedBomb = pCharacterDesc;

	m_BombBlastRadius = pCharacterDesc->bombBlastRadius;

	pCharacterDesc->amountOfBombsCurrentlyOnGrid += 1;

	m_TimeSinceItemPlaceOnCell = 0.f;

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
	--m_pCharacterDescPlacedBomb->amountOfBombsCurrentlyOnGrid;

	PlaceFire(m_MiddlePos);

	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto bottomNeigbor{ m_pOwnerGrid->GetCell(m_RowNr - index, m_ColNr) };
		if (bottomNeigbor && bottomNeigbor->GetState() != State::wall && bottomNeigbor->GetState() != State::fire)
		{
			if (bottomNeigbor->GetState() == State::bomb)
			{
				bottomNeigbor->ExplodeBomb();
				break;
			}

			if (bottomNeigbor->GetState() == State::wall)
				break;

			if (bottomNeigbor->GetState() == State::crackedWall)
			{
				bottomNeigbor->SetShouldPlacePickUp(true);
				bottomNeigbor->PlaceFire(bottomNeigbor->GetMiddlePos());
				break;
			}

			bottomNeigbor->PlaceFire(bottomNeigbor->GetMiddlePos());
		}
	}

	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto leftNeighbor{ m_pOwnerGrid->GetCell(m_RowNr, m_ColNr - index) };
		if (leftNeighbor && leftNeighbor->GetState() != State::fire)
		{
			if (leftNeighbor->GetState() == State::bomb)
			{
				leftNeighbor->ExplodeBomb();
				break;
			}

			if (leftNeighbor->GetState() == State::wall)
				break;

			if (leftNeighbor->GetState() == State::crackedWall)
			{
				leftNeighbor->SetShouldPlacePickUp(true);
				leftNeighbor->PlaceFire(leftNeighbor->GetMiddlePos());
				break;
			}

			leftNeighbor->PlaceFire(leftNeighbor->GetMiddlePos());
		}
	}
	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto topNeigbor{ m_pOwnerGrid->GetCell(m_RowNr + index, m_ColNr) };
		if (topNeigbor && topNeigbor->GetState() != State::fire)
		{
			if (topNeigbor->GetState() == State::bomb)
			{
				topNeigbor->ExplodeBomb();
				break;
			}

			if (topNeigbor->GetState() == State::wall)
				break;

			if (topNeigbor->GetState() == State::crackedWall)
			{
				topNeigbor->SetShouldPlacePickUp(true);
				topNeigbor->PlaceFire(topNeigbor->GetMiddlePos());
				break;
			}

			topNeigbor->PlaceFire(topNeigbor->GetMiddlePos());
		}
	}

	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto rightNeighbor{ m_pOwnerGrid->GetCell(m_RowNr, m_ColNr + index) };
		if (rightNeighbor && rightNeighbor->GetState() != State::fire)
		{
			if (rightNeighbor->GetState() == State::bomb)
			{
				rightNeighbor->ExplodeBomb();
				break;
			}

			if (rightNeighbor->GetState() == State::wall)
				break;

			if (rightNeighbor->GetState() == State::crackedWall)
			{
				rightNeighbor->SetShouldPlacePickUp(true);
				rightNeighbor->PlaceFire(rightNeighbor->GetMiddlePos());
				break;
			}

			rightNeighbor->PlaceFire(rightNeighbor->GetMiddlePos());
		}
	}
}

void Cell::PlaceFire(XMFLOAT3 pos)
{
	DestroyObjectInCell();

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
	
	m_pGameObjectInCell = pFlame;
}

void Cell::PlaceRandomPickUp(XMFLOAT3 pos)
{
	m_ShouldPlacePickUp = false;

	m_TimeSinceItemPlaceOnCell = 0.f;

	m_State = State::pickUp;

	auto pBonus = m_spGameScene->AddChild(new GameObject());
	auto pModel{ pBonus->AddComponent(new ModelComponent(L"Meshes/Bonus.ovm")) };

	//const int randomInt{ std::rand() % 8 };
	const int randomInt{ 0 };

	switch (randomInt)
	{
	case 0:
		pModel->SetMaterial(m_spBombUpBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sBombUpBonusCallBack);
		break;
	case 1:
		pModel->SetMaterial(m_spBombDownBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sBombDownBonusCallBack);
		break;
	case 2:
		pModel->SetMaterial(m_spFireUpBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sFireUpBonusCallBack);
		break;
	case 3:
		pModel->SetMaterial(m_spFireDownBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sFireDownBonusCallBack);
		break;
	case 4:
		pModel->SetMaterial(m_spFullFireBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sFullFireBonusCallBack);
		break;
	case 5:
		pModel->SetMaterial(m_spPierceBombBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sPierceBombBonusCallBack);
		break;
	case 6:
		pModel->SetMaterial(m_spSkateUpBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sSkateUpBonusCallBack);
		break;
	case 7:
		pModel->SetMaterial(m_spSkateDownBonusMaterial);
		pBonus->SetOnTriggerCallBack(m_sSkateDownBonusCallBack);
		break;
	}

	auto pRigidBody{ pBonus->AddComponent(new RigidBodyComponent(true)) };
	pRigidBody->AddCollider(PxBoxGeometry(0.5f, 0.5f, 0.5f), *m_spPhysxMaterial, true);
	pBonus->GetTransform()->Translate(pos);
	pBonus->GetTransform()->Scale(0.007f);

	DestroyObjectInCell();
	m_pGameObjectInCell = pBonus;
}