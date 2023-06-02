#include "stdafx.h"
#include "Cell.h"
#include "Materials/DiffuseMaterial.h"
#include "Grid.h"
#include "Prefabs/Character.h"
#include "Components/ParticleEmitterComponent.h"
#include <iostream>

Grid* Cell::m_spOwnerGrid;
GameScene* Cell::m_spGameScene{};
DiffuseMaterial_Shadow* Cell::m_spBombMaterial{};
DiffuseMaterial_Shadow* Cell::m_spFlameMaterial{};
DiffuseMaterial_Shadow* Cell::m_spBombUpBonusMaterial{};
DiffuseMaterial_Shadow* Cell::m_spBombDownBonusMaterial{};
DiffuseMaterial_Shadow* Cell::m_spFireUpBonusMaterial{};
DiffuseMaterial_Shadow* Cell::m_spFireDownBonusMaterial{};
DiffuseMaterial_Shadow* Cell::m_spFullFireBonusMaterial{};
DiffuseMaterial_Shadow* Cell::m_spPierceBombBonusMaterial{};
DiffuseMaterial_Shadow* Cell::m_spSkateUpBonusMaterial{};
DiffuseMaterial_Shadow* Cell::m_spSkateDownBonusMaterial{};
PxMaterial* Cell::m_spPhysxMaterial{};
float Cell::m_sSecUntilExplotion{ 2.f };
float Cell::m_sSecFireBurn{ 1.f };
GameObject::PhysicsCallback Cell::m_sBombCallBack;
GameObject::PhysicsCallback Cell::m_sFireCallBack;
GameObject::PhysicsCallback Cell::m_sBombUpBonusCallBack;
GameObject::PhysicsCallback Cell::m_sBombDownBonusCallBack;
GameObject::PhysicsCallback Cell::m_sFireUpBonusCallBack;
GameObject::PhysicsCallback Cell::m_sFireDownBonusCallBack;
GameObject::PhysicsCallback Cell::m_sFullFireBonusCallBack;
GameObject::PhysicsCallback Cell::m_sPierceBombBonusCallBack;
GameObject::PhysicsCallback Cell::m_sSkateUpBonusCallBack;
GameObject::PhysicsCallback Cell::m_sSkateDownBonusCallBack;
FMOD::System* Cell::m_spFmod;
FMOD::Sound* Cell::m_spBombExplodeSound;
FMOD::Channel* Cell::m_spSoundChannel;
ParticleEmitterSettings Cell::m_sExplosionParticleEmitterSettings;

Cell::Cell(GameScene* pGameScene, XMFLOAT3 middlePos, int rowNr, int colNr, State state)
	: m_MiddlePos{ middlePos }
	, m_RowNr{ rowNr }
	, m_ColNr{ colNr }
	, m_State{ state }
{
	if (!m_spBombMaterial)
	{
		m_spBombMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spBombMaterial->SetDiffuseTexture(L"Textures/Bomb/Bomb.png");
	}

	if (!m_spFlameMaterial)
	{
		m_spFlameMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spFlameMaterial->SetDiffuseTexture(L"Textures/Fire.png");
	}

	if (!m_spBombUpBonusMaterial)
	{
		m_spBombUpBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spBombUpBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/BombUp.png");
	}

	if (!m_spBombDownBonusMaterial)
	{
		m_spBombDownBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spBombDownBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/BombDown.png");
	}

	if (!m_spFireUpBonusMaterial)
	{
		m_spFireUpBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spFireUpBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/FireUp.png");
	}

	if (!m_spFireDownBonusMaterial)
	{
		m_spFireDownBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spFireDownBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/FireDown.png");
	}

	if (!m_spFullFireBonusMaterial)
	{
		m_spFullFireBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spFullFireBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/FullFire.png");
	}

	if (!m_spPierceBombBonusMaterial)
	{
		m_spPierceBombBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spPierceBombBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/PierceBomb.png");
	}

	if (!m_spSkateUpBonusMaterial)
	{
		m_spSkateUpBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spSkateUpBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/SkateUp.png");
	}

	if (!m_spSkateDownBonusMaterial)
	{
		m_spSkateDownBonusMaterial = MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>();
		m_spSkateDownBonusMaterial->SetDiffuseTexture(L"Textures/Bonus/SkateDown.png");
	}

	if (!m_spPhysxMaterial)
	{
		auto& pPhysX{ PxGetPhysics() };
		m_spPhysxMaterial = pPhysX.createMaterial(0.5f, 0.5f, 0.5f);
	}

	if (!m_spGameScene)
	{
		m_spGameScene = pGameScene;

		m_sExplosionParticleEmitterSettings.minVelocity = { -2.f,2.f,-2.f };
		m_sExplosionParticleEmitterSettings.maxVelocity = { 2.f,2.f,2.f };
		m_sExplosionParticleEmitterSettings.minSize = 0.75f;
		m_sExplosionParticleEmitterSettings.maxSize = 0.75f;
		m_sExplosionParticleEmitterSettings.minEnergy = 0.25f;
		m_sExplosionParticleEmitterSettings.maxEnergy = 0.5f;
		m_sExplosionParticleEmitterSettings.minScale = 1.f;
		m_sExplosionParticleEmitterSettings.maxScale = 1.5f;
		m_sExplosionParticleEmitterSettings.minEmitterRadius = 0.1f;
		m_sExplosionParticleEmitterSettings.maxEmitterRadius = 0.1f;
		m_sExplosionParticleEmitterSettings.color = { 1.f,1.f,1.f, .6f };
	}	

	if (!m_spFmod)
	{
		m_spFmod = SoundManager::Get()->GetSystem();
		m_spFmod->createStream("Resources/Sounds/bombExplosion.wav", FMOD_2D, nullptr, &m_spBombExplodeSound);
	}
}

Cell::Cell(GameScene* pGameScene, XMFLOAT3 middlePos, int rowNr, int colNr, State state, GameObject* pGameObjectInCell)
	: Cell(pGameScene, middlePos, rowNr, colNr, state)
{
	m_pGameObjectInCell = pGameObjectInCell;
}

Cell::~Cell()
{
	DestroyObjectInCell();
}

void Cell::InitializeGridAndCallBacks(Grid* pGrid)
{
	m_spOwnerGrid = pGrid;

	m_sBombCallBack =
		[&](GameObject* pTriggerObject, GameObject*, PxTriggerAction action)
	{
		if (action == PxTriggerAction::LEAVE)
			m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition())->SetShouldAddColliderToGameObjectInCell(true);
	};

	m_sFireCallBack =
		[&](GameObject*, GameObject* pOtherObject, PxTriggerAction action)
	{
		auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
		if (action == PxTriggerAction::ENTER && pCharacter)
		{
			pCharacter->GetCharacterDescription().isDead = true;
		}
	};

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

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};

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

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};

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

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};

	m_sFireDownBonusCallBack =
		[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
	{
		auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
		if (action == PxTriggerAction::ENTER && pCharacter)
		{
			auto& characterDesc{ pCharacter->GetCharacterDescription() };

			--characterDesc.bombBlastRadius;

			if (characterDesc.bombBlastRadius < 2)
				characterDesc.bombBlastRadius = 2;

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};

	m_sFullFireBonusCallBack =
		[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
	{
		auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
		if (action == PxTriggerAction::ENTER && pCharacter)
		{
			auto& characterDesc{ pCharacter->GetCharacterDescription() };

			characterDesc.bombBlastRadius = characterDesc.maxBombBlastRadius;

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};

	m_sPierceBombBonusCallBack =
		[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
	{
		auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
		if (action == PxTriggerAction::ENTER && pCharacter)
		{
			auto& characterDesc{ pCharacter->GetCharacterDescription() };

			characterDesc.hasPierceBomb = true;

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};

	m_sSkateUpBonusCallBack =
		[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
	{
		auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
		if (action == PxTriggerAction::ENTER && pCharacter)
		{
			auto& characterDesc{ pCharacter->GetCharacterDescription() };

			++characterDesc.speedLevel;

			characterDesc.CalculateMoveSpeedMultiplier();

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};

	m_sSkateDownBonusCallBack =
		[&](GameObject* pTriggerObject, GameObject* pOtherObject, PxTriggerAction action)
	{
		auto pCharacter{ reinterpret_cast<Character*>(pOtherObject) };
		if (action == PxTriggerAction::ENTER && pCharacter)
		{
			auto& characterDesc{ pCharacter->GetCharacterDescription() };

			--characterDesc.speedLevel;

			characterDesc.CalculateMoveSpeedMultiplier();

			auto pCell{ m_spOwnerGrid->GetCell(pTriggerObject->GetTransform()->GetWorldPosition()) };

			if (pCell)
				pCell->SetShouldDestroyGameObjectInCell(true);
		}
	};
}

void Cell::Update()
{
	if (m_ShouldAddColliderToGameObjectInCell)
	{
		AddColliderToGameObjectInCell();
		m_ShouldAddColliderToGameObjectInCell = false;
	}

	if (m_ShouldDestroyGameObjectInCell)
	{
		DestroyObjectInCell();
		m_ShouldDestroyGameObjectInCell = false;
		m_State = State::empty;
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

	//this is code to make the pick-up move up and down this is commented because when it is enabled it causes the callbacks of the triggers attached not to trigger
	//if (m_State == State::pickUp)
	//{
	//	if (!m_pGameObjectInCell)
	//		return;
	//
	//	if (m_PickUpYOffsetTime < 0.f)
	//		m_IsPickUpGoingUp = true;
	//	else if (m_PickUpYOffsetTime > 1.f)
	//		m_IsPickUpGoingUp = false;
	//
	//	if(m_IsPickUpGoingUp)
	//		m_PickUpYOffsetTime += m_spGameScene->GetSceneContext().pGameTime->GetElapsed() * m_PickUpHoverSpeed;
	//	else
	//		m_PickUpYOffsetTime -= m_spGameScene->GetSceneContext().pGameTime->GetElapsed() * m_PickUpHoverSpeed;
	//	
	//	m_pGameObjectInCell->GetTransform()->Translate(m_MiddlePos.x, m_MiddlePos.y + EaseInOutBack(m_PickUpYOffsetTime) - 0.5f, m_MiddlePos.z);
	//}
}

//source: https://easings.net/#easeInOutBack
float Cell::EaseInOutBack(float time)
{
	constexpr float c1{ 1.70158f };
	constexpr float c2{ c1 * 1.525f };
	
	if (time < 0.5f)
		return (powf(2 * time, 2) * ((c2 + 1) * 2 * time - c2)) / 2;
	else
		return (powf(2 * time - 2, 2) * ((c2 + 1) * (time * 2 - 2) + c2) + 2) / 2;
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

	pBomb->SetOnTriggerCallBack(m_sBombCallBack);

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
		m_pGameObjectInCell->GetScene()->RemoveChild(m_pGameObjectInCell, true);
		m_pGameObjectInCell = nullptr;
	}
}

void Cell::ExplodeBomb()
{
	m_spFmod->playSound(m_spBombExplodeSound, nullptr, false, &m_spSoundChannel);

	--m_pCharacterDescPlacedBomb->amountOfBombsCurrentlyOnGrid;

	PlaceFire(m_MiddlePos);
	--m_BombBlastRadius;

	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto bottomNeigbor{ m_spOwnerGrid->GetCell(m_RowNr - index, m_ColNr) };
		if (bottomNeigbor && bottomNeigbor->GetState() != State::fire)
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

				if(!m_pCharacterDescPlacedBomb->hasPierceBomb)
					break;

				continue;
			}

			if (bottomNeigbor->GetState() == State::empty || bottomNeigbor->GetState() == State::pickUp)
			{
				bottomNeigbor->PlaceFire(bottomNeigbor->GetMiddlePos());
			}
		}
	}

	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto leftNeighbor{ m_spOwnerGrid->GetCell(m_RowNr, m_ColNr - index) };
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

				if (!m_pCharacterDescPlacedBomb->hasPierceBomb)
					break;

				continue;
			}

			if (leftNeighbor->GetState() == State::empty || leftNeighbor->GetState() == State::pickUp)
			{
				leftNeighbor->PlaceFire(leftNeighbor->GetMiddlePos());
			}
		}
	}
	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto topNeigbor{ m_spOwnerGrid->GetCell(m_RowNr + index, m_ColNr) };
		if (topNeigbor && topNeigbor->GetState() != State::fire)
		{
			if (topNeigbor->GetState() == State::bomb)
			{
				topNeigbor->ExplodeBomb();
				break;

				continue;
			}

			if (topNeigbor->GetState() == State::wall)
				break;

			if (topNeigbor->GetState() == State::crackedWall)
			{
				topNeigbor->SetShouldPlacePickUp(true);
				topNeigbor->PlaceFire(topNeigbor->GetMiddlePos());

				if (!m_pCharacterDescPlacedBomb->hasPierceBomb)
					break;

				continue;
			}

			if (topNeigbor->GetState() == State::empty || topNeigbor->GetState() == State::pickUp)
			{
				topNeigbor->PlaceFire(topNeigbor->GetMiddlePos());
			}
		}
	}

	for (int index{ 1 }; index <= m_BombBlastRadius; ++index)
	{
		auto rightNeighbor{ m_spOwnerGrid->GetCell(m_RowNr, m_ColNr + index) };
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

				if (!m_pCharacterDescPlacedBomb->hasPierceBomb)
					break;

				continue;
			}

			if (rightNeighbor->GetState() == State::empty || rightNeighbor->GetState() == State::pickUp)
			{
				rightNeighbor->PlaceFire(rightNeighbor->GetMiddlePos());
			}
		}
	}
}

void Cell::PlaceFire(XMFLOAT3 pos)
{
	DestroyObjectInCell();

	m_TimeSinceItemPlaceOnCell = 0.f;

	m_State = State::fire;

	auto pFlame = m_spGameScene->AddChild(new GameObject());
	auto pModel{ pFlame->AddComponent(new ModelComponent(L"Meshes/Fire.ovm")) };
	pModel->SetMaterial(m_spFlameMaterial);
	pFlame->AddComponent(new ParticleEmitterComponent(L"Textures/FireBall.png", m_sExplosionParticleEmitterSettings));
	auto pRigidBody{ pFlame->AddComponent(new RigidBodyComponent(true)) };
	pRigidBody->AddCollider(PxBoxGeometry(0.5f, 0.5f, 0.5f), *m_spPhysxMaterial, true);
	pFlame->SetOnTriggerCallBack(m_sFireCallBack);
	pFlame->GetTransform()->Translate(pos);
	pFlame->GetTransform()->Scale(0.01f);
	m_pGameObjectInCell = pFlame;
}

void Cell::PlaceRandomPickUp(XMFLOAT3 pos)
{
	m_ShouldPlacePickUp = false;

	m_TimeSinceItemPlaceOnCell = 0.f;

	DestroyObjectInCell();
	m_State = State::empty;

	m_State = State::pickUp;

	int randomInt{ std::rand() % 2 };

	if (randomInt == 0)
		return;

	auto pBonus = m_spGameScene->AddChild(new GameObject());
	auto pModel{ pBonus->AddComponent(new ModelComponent(L"Meshes/Bonus.ovm")) };

	randomInt = std::rand() % 8;

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

	m_pGameObjectInCell = pBonus;
}