/*=============================================================================*/
// Copyright 2020-2021 Elite Engine


//-----------------------------------------------------------------
// Includes & Forward Declarations
//-----------------------------------------------------------------
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

	BehaviorState GrabMedkit(Blackboard* pBlackboard)
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

			if (itemInfo.Type == eItemType::MEDKIT)
			{
				pInterface->Item_Grab(entity, itemInfo);
				pInterface->Inventory_AddItem(2, itemInfo);
				return BehaviorState::Success;
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState GrabFood(Blackboard* pBlackboard)
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

			if (itemInfo.Type == eItemType::FOOD)
			{
				pInterface->Item_Grab(entity, itemInfo);
				pInterface->Inventory_AddItem(3, itemInfo);
				return BehaviorState::Success;
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState DestroyPistolInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::PISTOL)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					pInterface->Item_Destroy(entity);
					return BehaviorState::Success;
				}
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState DestroyEquipedPistol(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		pInterface->Inventory_RemoveItem(0); //pistol is always saved in slot 0

		return BehaviorState::Success;
	}

	BehaviorState DestroyShotgunInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::SHOTGUN)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					pInterface->Item_Destroy(entity);
					return BehaviorState::Success;
				}
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState DestroyEquipedShotgun(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		pInterface->Inventory_RemoveItem(1); //shotgun is always saved in slot 1

		return BehaviorState::Success;
	}

	BehaviorState DestroyMedkitInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::MEDKIT)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					pInterface->Item_Destroy(entity);
					return BehaviorState::Success;
				}
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState DestroyEquipedMedkit(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		pInterface->Inventory_RemoveItem(2); //shotgun is always saved in slot 2

		return BehaviorState::Success;
	}

	BehaviorState DestroyFoodInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntetiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::FOOD)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					pInterface->Item_Destroy(entity);
					return BehaviorState::Success;
				}
			}
		}

		return BehaviorState::Failure;
	}

	BehaviorState DestroyEquipedFood(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		pInterface->Inventory_RemoveItem(3); //food is always saved in slot 3

		return BehaviorState::Success;
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

		float desiredAngle{ acos(toTarget.Dot({ 1.f, 0.f })) };

		float cross{ toTarget.Cross({1.f, 0.f}) };

		if (cross > 0) //toTarget ligt rechts van unitX vector
		{
			desiredAngle *= -1;
		}

		if (desiredAngle - 0.02f <= pInterface->Agent_GetInfo().Orientation && desiredAngle + 0.02f >= pInterface->Agent_GetInfo().Orientation) // can be about 1 radians off
		{			
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

	BehaviorState ShootShotgun(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		ItemInfo itemInfo;
		pInterface->Inventory_GetItem(1, itemInfo);

		if (itemInfo.Type != eItemType::SHOTGUN)
			return BehaviorState::Failure;

		pInterface->Inventory_UseItem(1);

		return BehaviorState::Success;
	}

	BehaviorState GoInHouse(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		if (!pInterface->Agent_GetInfo().IsInHouse)
		{
			pBlackboard->ChangeData("posBeforeEnteredHouse", pInterface->Agent_GetInfo().Position);
		}

		HouseInfo houseInfo;
		pInterface->Fov_GetHouseByIndex(0, houseInfo);

		pBlackboard->ChangeData("Target", pInterface->NavMesh_GetClosestPathPoint(houseInfo.Center));

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::seek);

		if (pInterface->Agent_GetInfo().Position.x - 0.1 <= houseInfo.Center.x && pInterface->Agent_GetInfo().Position.x + 0.1 >= houseInfo.Center.x)
		{
			std::list<std::pair<Vector2, float>>* pvHousesEntered;
			if (!pBlackboard->GetData("HousesEntered", pvHousesEntered) || !pvHousesEntered)
				return BehaviorState::Failure;

			//check if the house where the agent is now in was already visited before if so set the amount of time since last visit to zero else push the house the the pvHousesEntered vector
			for (auto& enteredHouse : *pvHousesEntered)
			{
				if (houseInfo.Center == enteredHouse.first)
				{
					enteredHouse.second = 0.f;
					return BehaviorState::Success;
				}
			}

			pvHousesEntered->push_back(std::pair<Vector2, float>(houseInfo.Center, 0.f));

			return BehaviorState::Success;
		}

		return BehaviorState::Running;
	}

	BehaviorState GoOutHouse(Blackboard* pBlackboard)
	{
		Vector2 posBeforeEnteredHouse;
		if (!pBlackboard->GetData("posBeforeEnteredHouse", posBeforeEnteredHouse))
			return BehaviorState::Failure;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		SteeringBehaviorType pSteeringBehaviorType;
		if (!pBlackboard->GetData("SteeringBehaviorType", pSteeringBehaviorType))
			return BehaviorState::Failure;

		pBlackboard->ChangeData("Target", pInterface->NavMesh_GetClosestPathPoint(posBeforeEnteredHouse));

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::seek);

		if (pInterface->Agent_GetInfo().Position.x - 0.1 <= posBeforeEnteredHouse.x && pInterface->Agent_GetInfo().Position.x + 0.1 >= posBeforeEnteredHouse.x)
		{
			return BehaviorState::Success;
		}

		return BehaviorState::Running;
	}

	BehaviorState Rotate180(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		SteeringBehaviorType pSteeringBehaviorType;
		if (!pBlackboard->GetData("SteeringBehaviorType", pSteeringBehaviorType))
			return BehaviorState::Failure;

		bool isDoing180;
		if (!pBlackboard->GetData("isDoing180", isDoing180))
			return BehaviorState::Failure;

		float startRotationFor180;
		if (!pBlackboard->GetData("StartRotationFor180", startRotationFor180))
			return BehaviorState::Failure;

		if (!isDoing180)
		{
			startRotationFor180 = pInterface->Agent_GetInfo().Orientation;
		}

		Vector2 point;

		if (startRotationFor180 < 0 && startRotationFor180 > -(M_PI / 2.f))
		{
			point = { 1.f, -1.f };
		}
		else if (startRotationFor180 < M_PI / 2.f)
		{
			point = { -1.f, -1.f };
		}
		else if (startRotationFor180 > 0 && startRotationFor180 < M_PI / 2.f)
		{
			point = { 1.f, 1.f };
		}
		else
		{
			point = { 1.f, 1.f };
		}

		float desiredAngle{ acos(point.Dot({ 1.f, 0.f })) };

		if (!isDoing180)
		{
			pBlackboard->ChangeData("isDoing180", true);
			startRotationFor180 = pInterface->Agent_GetInfo().Orientation;

			Vector2 target;
			target = point * (-desiredAngle);
			target.x += pInterface->Agent_GetInfo().Position.x;
			target.y += pInterface->Agent_GetInfo().Position.y;

			pBlackboard->ChangeData("Target", target);
		}

		if (desiredAngle - M_PI / 2.f - 0.02f <= pInterface->Agent_GetInfo().Orientation && desiredAngle - M_PI / 2.f + 0.02f >= pInterface->Agent_GetInfo().Orientation) // can be about 1 radians off
		{
			pBlackboard->ChangeData("isDoing180", false);
			return BehaviorState::Success;
		}

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::face);

		return BehaviorState::Running;
	}

	BehaviorState StopRotate180(Blackboard* pBlackboard)
	{
		if (pBlackboard->ChangeData("isDoing180", false))
		{
			return BehaviorState::Success;
		}

		return BehaviorState::Failure;
	}

	BehaviorState ChangeToFlee(Blackboard* pBlackboard)
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

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::flee);

		Vector2 target;

		if (!pvEntetiesInFOV->empty())
		{
			for (const auto& entity : *pvEntetiesInFOV)
			{
				if ((entity.Type == eEntityType::ENEMY))
				{
					target = entity.Location;
				}
			}
		}
		else //if no enemy in vision then flee from own position
		{
			target = pInterface->Agent_GetInfo().Position;
		}

		pBlackboard->ChangeData("Target", target);

		return BehaviorState::Success;
	}

	BehaviorState ChangeToSprintFlee(Blackboard* pBlackboard)
	{
		SteeringBehaviorType pSteeringBehaviorType;
		if (!pBlackboard->GetData("SteeringBehaviorType", pSteeringBehaviorType))
			return BehaviorState::Failure;

		std::vector<EntityInfo>* pvEntetiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntetiesInFOV) || !pvEntetiesInFOV)
			return BehaviorState::Failure;

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::flee);

		if (!pvEntetiesInFOV->empty())
		{
			Vector2 target;

			for (const auto& entity : *pvEntetiesInFOV)
			{
				if ((entity.Type == eEntityType::ENEMY))
				{
					target = entity.Location;
				}
			}

			pBlackboard->ChangeData("Target", target);
		}


		return BehaviorState::Success;
	}

	BehaviorState SeekLoot(Blackboard* pBlackboard) //seeks to the location saved in the blackboard as posItemToSeek
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		Vector2 posItemToSeek;
		if (!pBlackboard->GetData("posItemToSeek", posItemToSeek))
			return BehaviorState::Failure;

		pBlackboard->ChangeData("Target", posItemToSeek);

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::seek);

		if (pInterface->Agent_GetInfo().Position.x - 0.1f <= posItemToSeek.x && pInterface->Agent_GetInfo().Position.x + 0.1f >= posItemToSeek.x)
		{
			return BehaviorState::Success;
		}

		return BehaviorState::Running;
	}

	BehaviorState UseMedkit(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		pInterface->Inventory_UseItem(2); //medkit is always saved in slot 2

		return BehaviorState::Success;
	}

	BehaviorState EatFood(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		pInterface->Inventory_UseItem(3); //food is always saved in slot 3

		return BehaviorState::Success;
	}

	BehaviorState GoToNextPosToVisit(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		std::list<Vector2>* lPositionsToVisit;
		if (!pBlackboard->GetData("positionsToVisit", lPositionsToVisit) || !lPositionsToVisit)
			return BehaviorState::Failure;

		//check if the agent reach a position
		if (pInterface->Agent_GetInfo().Position.x - 0.1f <= lPositionsToVisit->front().x && pInterface->Agent_GetInfo().Position.x + 0.1f >= lPositionsToVisit->front().x)
		{
			//remove the reached pos from the queue
			lPositionsToVisit->remove(lPositionsToVisit->front());
			return BehaviorState::Success;
		}

		pBlackboard->ChangeData("Target", pInterface->NavMesh_GetClosestPathPoint(lPositionsToVisit->front()));

		pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::seek);

		return BehaviorState::Running;
	}

	BehaviorState FleePurgeZoneAgentIsIn(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return BehaviorState::Failure;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return BehaviorState::Failure;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (entity.Type == eEntityType::PURGEZONE)
			{
				PurgeZoneInfo purgZoneInfo;
				pInterface->PurgeZone_GetInfo(entity, purgZoneInfo);

				if ((purgZoneInfo.Center - pInterface->Agent_GetInfo().Position).Magnitude() > purgZoneInfo.Radius)
				{
					return BehaviorState::Success;
				}

				pBlackboard->ChangeData("SteeringBehaviorType", SteeringBehaviorType::flee);
				pBlackboard->ChangeData("Target", purgZoneInfo.Center);
			}
		}

		return BehaviorState::Running;
	}
}

//-----------------------------------------------------------------
// Conditions
//-----------------------------------------------------------------

namespace BT_Conditions
{
	bool IsItemInFOV(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return false;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (entity.Type == eEntityType::ITEM)
			{
				pBlackboard->ChangeData("posItemToSeek", entity.Location);
				return true;
			}
		}

		return false;
	}

	bool IsItemInGrabrange(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (entity.Type == eEntityType::ITEM)
			{
				ItemInfo itemInfo;
				pInterface->Item_GetInfo(entity, itemInfo);

				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					return true;
				}
			}
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

	bool IsMedkitInGrabRange(Blackboard* pBlackboard)
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

			if (itemInfo.Type == eItemType::MEDKIT)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					return true;
				}
			}
		}

		return false;
	}

	bool IsFoodInGrabRange(Blackboard* pBlackboard)
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

			if (itemInfo.Type == eItemType::FOOD)
			{
				if ((itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
				{
					return true;
				}
			}
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

	bool IsInHouse(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		return pInterface->Agent_GetInfo().IsInHouse;
	}

	bool IsOutside(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		return !pInterface->Agent_GetInfo().IsInHouse;
	}

	bool HasNotEnteredHouseInFOVInlast30Sec(Blackboard* pBlackboard)
	{
		std::vector<HouseInfo>* pvHousesInFOV;
		if (!pBlackboard->GetData("HousesInFOV", pvHousesInFOV) || !pvHousesInFOV)
			return false;

		std::list<std::pair<Vector2, float>>* pvHousesEntered;
		if (!pBlackboard->GetData("HousesEntered", pvHousesEntered) || !pvHousesEntered)
			return false;

		for (const auto& enteredHouse : *pvHousesEntered)
		{
			for (const auto& house : *pvHousesInFOV)
			{
				if (house.Center == enteredHouse.first && enteredHouse.second <= 30.f)
				{
					return false;
				}
			}
		}

		return true;
	}

	bool HasBeenInHouseFor5Seconds(Blackboard* pBlackboard)
	{
		float* pAmountOfTimeInhouse;
		if (!pBlackboard->GetData("AmountOfTimeInHouse", pAmountOfTimeInhouse) || !pAmountOfTimeInhouse)
			return false;

		if (*pAmountOfTimeInhouse >= 5)
		{
			return true;
		}

		return false;
	}

	bool HasTakenDamage(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		if (pInterface->Agent_GetInfo().WasBitten)
		{
			return true;
		}

		return false;
	}

	bool IsDoing180(Blackboard* pBlackboard)
	{
		bool isDoing180;
		if (!pBlackboard->GetData("isDoing180", isDoing180))
			return false;

		return isDoing180;
	}

	bool IsNotDoing180(Blackboard* pBlackboard)
	{
		bool isDoing180;
		if (!pBlackboard->GetData("isDoing180", isDoing180))
			return false;

		return !isDoing180;
	}

	bool HasPistol(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo itemInfo;
		pInterface->Inventory_GetItem(0, itemInfo); //pistol is always saved to slot 0

		if (itemInfo.Type == eItemType::PISTOL)
		{
			return true;
		}

		return false;
	}

	bool HasShotGun(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo itemInfo;
		pInterface->Inventory_GetItem(1, itemInfo); //shotgun is always saved to slot 1

		if (itemInfo.Type == eItemType::SHOTGUN)
		{
			return true;
		}

		return false;
	}

	bool HasMedkit(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo itemInfo;
		pInterface->Inventory_GetItem(2, itemInfo); //medkit is always saved to slot 2

		if (itemInfo.Type == eItemType::MEDKIT)
		{
			return true;
		}

		return false;
	}

	bool HasFood(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo itemInfo;
		pInterface->Inventory_GetItem(3, itemInfo); //food is always saved to slot 3

		if (itemInfo.Type == eItemType::FOOD)
		{
			return true;
		}

		return false;
	}

	bool CanSprint(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		if (pInterface->Agent_GetInfo().Stamina > 0)
		{
			return true;
		}

		return true;
	}

	bool HasEquipedPistolMoreAmmoThenPistolInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return false;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::PISTOL
				&& (itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
			{
				//get the equiped pistol
				ItemInfo equipedPistol;
				pInterface->Inventory_GetItem(0, equipedPistol);

				if (pInterface->Weapon_GetAmmo(itemInfo) < pInterface->Weapon_GetAmmo(equipedPistol))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool HasEquipedShotgunMoreAmmoThenShotgunInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return false;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::SHOTGUN
				&& (itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
			{
				//get the equiped pistol
				ItemInfo equipedPistol;
				pInterface->Inventory_GetItem(1, equipedPistol); //shotgun always saved in slot 1

				if (pInterface->Weapon_GetAmmo(itemInfo) < pInterface->Weapon_GetAmmo(equipedPistol))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool HasEquipedMedkitMoreHPThenMedkitInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return false;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::MEDKIT
				&& (itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
			{
				//get the equiped pistol
				ItemInfo equipedMedkit;
				pInterface->Inventory_GetItem(2, equipedMedkit); //medkit always saved in slot 2

				if (pInterface->Medkit_GetHealth(itemInfo) < pInterface->Medkit_GetHealth(equipedMedkit))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool HasEquipedFoodMoreEnergyThenFoodInGrabrange(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return false;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (!(entity.Type == eEntityType::ITEM)) continue;

			ItemInfo itemInfo;
			pInterface->Item_GetInfo(entity, itemInfo);

			if (itemInfo.Type == eItemType::FOOD
				&& (itemInfo.Location - pInterface->Agent_GetInfo().Position).Magnitude() <= pInterface->Agent_GetInfo().GrabRange)
			{
				//get the equiped food
				ItemInfo equipedFood;
				pInterface->Inventory_GetItem(2, equipedFood); //medkit always saved in slot 2

				if (pInterface->Food_GetEnergy(itemInfo) < pInterface->Food_GetEnergy(equipedFood))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool HasEquipedPistolAmmo(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo equipedPistol;
		pInterface->Inventory_GetItem(0, equipedPistol); //pistol always saved in slot 0

		if (pInterface->Weapon_GetAmmo(equipedPistol) > 0)
			return true;

		return false;
	}

	bool HasEquipedShotgunAmmo(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo equipedShotgun;
		pInterface->Inventory_GetItem(1, equipedShotgun); //shotgun always saved in slot 1

		if (pInterface->Weapon_GetAmmo(equipedShotgun) > 0)
			return true;

		return false;
	}

	bool HasEquipedMedkitHealth(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo equipedMedkit;
		pInterface->Inventory_GetItem(2, equipedMedkit); //medkit always saved in slot 2

		if (pInterface->Medkit_GetHealth(equipedMedkit) > 0)
			return true;

		return false;
	}

	bool HasEquipedFoodEnergy(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		ItemInfo equipedFood;
		pInterface->Inventory_GetItem(3, equipedFood); //food always saved in slot 3

		if (pInterface->Medkit_GetHealth(equipedFood) > 0)
			return true;

		return false;
	}

	bool NotMaxHealth(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		if (pInterface->Agent_GetInfo().Health < 10.f)
			return true;

		return false;
	}

	bool AlmostOutOfEnergy(Blackboard* pBlackboard)
	{
		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		if (pInterface->Agent_GetInfo().Energy <= 1.f)
			return true;

		return false;
	}

	bool HasNotExploreFullWorld(Blackboard* pBlackboard)
	{
		std::list<Vector2>* plPositionsToVisit;
		if (!pBlackboard->GetData("positionsToVisit", plPositionsToVisit) || !plPositionsToVisit)
			return false;

		if (!plPositionsToVisit->empty())
			return true;

		return false;
	}

	bool IsInPergeZone(Blackboard* pBlackboard)
	{
		std::vector<EntityInfo>* pvEntitiesInFOV;
		if (!pBlackboard->GetData("EntitiesInFOV", pvEntitiesInFOV) || !pvEntitiesInFOV)
			return false;

		IExamInterface* pInterface;
		if (!pBlackboard->GetData("Interface", pInterface) || !pInterface)
			return false;

		for (const auto& entity : *pvEntitiesInFOV)
		{
			if (entity.Type == eEntityType::PURGEZONE)
			{
				PurgeZoneInfo purgZoneInfo;
				pInterface->PurgeZone_GetInfo(entity, purgZoneInfo);

				if ((purgZoneInfo.Center - pInterface->Agent_GetInfo().Position).Magnitude() < purgZoneInfo.Radius)
				{
					return true;
				}
			}
		}
		return false;
	}
}