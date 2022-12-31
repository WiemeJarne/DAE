/*=============================================================================*/
// Copyright 2020-2021 Elite Engine


//-----------------------------------------------------------------
// Includes & Forward Declarations
//-----------------------------------------------------------------
//#include "framework/EliteMath/EMath.h"
#include "EBehaviorTree.h"
#include "SteeringBehaviors.h"

using namespace Elite;

//-----------------------------------------------------------------
// Behaviors
//-----------------------------------------------------------------

namespace BT_Actions
{
	BehaviorState ChangeToWander(Blackboard* pBlackboard)
	{
		SteeringBehaviorType pSteeringBehaviorType;
		if (!pBlackboard->GetData("SteeringBehaviorType", pSteeringBehaviorType))
			return BehaviorState::Failure;

		if (pSteeringBehaviorType == SteeringBehaviorType::wander)
			return BehaviorState::Success;

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::wander);

		return BehaviorState::Success;
	}

	BehaviorState GrabPistol(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::PISTOL)
			{
				pInterface->Item_Grab(entity, itemInfo);
				pInterface->Inventory_AddItem(0, itemInfo);
				return BehaviorState::Success;
			}
		}
		
		return BehaviorState::Failure;
	}

	BehaviorState GrabShotGun(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::SHOTGUN)
			{
				pInterface->Item_Grab(entity, itemInfo);
				pInterface->Inventory_AddItem(1, itemInfo);
				return BehaviorState::Success;
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState DestroyGarbage(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::GARBAGE)
			{
				pInterface->Item_Destroy(entity);
				return BehaviorState::Success;
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState FaceEnemy(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		SteeringBehaviorType pSteeringBehaviorType;
		if (!pBlackboard->GetData("SteeringBehaviorType", pSteeringBehaviorType))
			return BehaviorState::Failure;

		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		Vector2 target;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if ((entity.Type == eEntityType::ENEMY))
			{
				target = entity.Location;
			}
		}

		pBlackboard->ChangeData("Target", target);

		Vector2 toTarget{ target - pInterface->Agent_GetInfo().Position };
		toTarget.Normalize();

		//the desired angle
		float angle{ acos(toTarget.Dot({ 1.f, 0.f })) };

		float cross{ toTarget.Cross({1.f, 0.f}) };

		if (cross > 0) //toTarget ligt rechts van unitX vector
		{
			angle *= -1;
		}

		if (angle - 0.1f <= pInterface->Agent_GetInfo().Orientation && angle + 0.1f >= pInterface->Agent_GetInfo().Orientation)
		{
			std::cout << angle << " ";
			std::cout << pInterface->Agent_GetInfo().Orientation << '\n';
			
			return BehaviorState::Success;
		}

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::face);

		return BehaviorState::Running;
	}

	BehaviorState ShootPistol(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		ItemInfo itemInfo;
		pInterface->Inventory_GetItem(0, itemInfo);

		if (itemInfo.Type != eItemType::PISTOL)
			return BehaviorState::Failure;

		pInterface->Inventory_UseItem(0);
		
		return BehaviorState::Success;
	}

	BehaviorState GoInHouse(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		SteeringBehaviorType pSteeringBehaviorType;
		if (!pBlackboard->GetData("SteeringBehaviorType", pSteeringBehaviorType))
			return BehaviorState::Failure;

		HouseInfo houseInfo;
		pInterface->Fov_GetHouseByIndex(0, houseInfo);

		pBlackboard->ChangeData("Target", pInterface->NavMesh_GetClosestPathPoint(houseInfo.Center));

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::seek);

		if (pInterface->Agent_GetInfo().Position.x - 0.1 <= houseInfo.Center.x && pInterface->Agent_GetInfo().Position.x + 0.1 >= houseInfo.Center.x)
		{
			std::list<std::pair<Vector2, float>>* pvHouesesEnteredCenter;
			if (!pBlackboard->GetData("HousesEntered", pvHouesesEnteredCenter) || !pvHouesesEnteredCenter)
				return BehaviorState::Failure;

			pvHouesesEnteredCenter->push_back(std::pair<Vector2, float>(houseInfo.Center, 0.f));

			return BehaviorState::Success;
		}

		return BehaviorState::Running;
	}

	BehaviorState LootHouse(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		SteeringBehaviorType pSteeringBehaviorType;
		if (!pBlackboard->GetData("SteeringBehaviorType", pSteeringBehaviorType))
			return BehaviorState::Failure;

		HouseInfo houseInfo;
		pInterface->Fov_GetHouseByIndex(0, houseInfo);

		pBlackboard->ChangeData("Target", pInterface->NavMesh_GetClosestPathPoint(houseInfo.Center));
	}
}

//-----------------------------------------------------------------
// Conditions
//-----------------------------------------------------------------

namespace BT_Conditions
{
	bool IsPistolInFOV(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::PISTOL)
				return true;
		}

		return false;
	}

	bool IsPistolInGrabRange(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::PISTOL)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool IsShotgunInFOV(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::SHOTGUN)
				return true;
		}

		return false;
	}

	bool IsShotgunInGrabRange(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::SHOTGUN)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool IsGarbageInFOV(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::GARBAGE)
				return true;
		}

		return false;
	}

	bool IsGarbageInGrabRange(Blackboard* pBlackBoard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackBoard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackBoard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::GARBAGE)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool IsEnemyInFOV(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if ((entity.Type == eEntityType::ENEMY))
				return true;
		}

		return false;
	}

	bool IsOutSide(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		if (!pInterface->Agent_GetInfo().IsInHouse)
			return true;

		return false;
	}

	bool IsHouseInFOV(Blackboard* pBlackboard)
	{
		std::vector<HouseInfo>* pvHousesInFOV;
		if (!pBlackboard->GetData("HousesInFOV", pvHousesInFOV) || !pvHousesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		if (!pvHousesInFOV->empty())
			return true;

		return false;
	}

	bool HasHouseNotBeenEnteredBefore(Blackboard* pBlackboard)
	{
		std::list<std::pair<Vector2, float>>* pvHouesesEnteredCenter;
		if (!pBlackboard->GetData("HousesEntered", pvHouesesEnteredCenter) || !pvHouesesEnteredCenter)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		HouseInfo houseInfo;
		pInterface->Fov_GetHouseByIndex(0, houseInfo);

		bool houseHasBeenEnteredBefore{};
		for (const auto& houseEntered : *pvHouesesEnteredCenter)
		{
			if (houseEntered.first == houseInfo.Center)
			{
				return false; //house has been entered before
			}
		}

		return true; //house has not been entered before
	}
}