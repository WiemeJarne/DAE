/*=============================================================================*/
// Copyright 2020-2021 Elite Engine
/*=============================================================================*/
// Behaviors.h: Implementation of certain reusable behaviors for the BT version of the Agario Game
/*=============================================================================*/
#ifndef ELITE_APPLICATION_BEHAVIOR_TREE_BEHAVIORS
#define ELITE_APPLICATION_BEHAVIOR_TREE_BEHAVIORS
//-----------------------------------------------------------------
// Includes & Forward Declarations
//-----------------------------------------------------------------
#include "framework/EliteMath/EMath.h"
#include "framework/EliteAI/EliteDecisionMaking/EliteBehaviorTree/EBehaviorTree.h"
#include "projects/Shared/Agario/AgarioAgent.h"
#include "projects/Shared/Agario/AgarioFood.h"
#include "projects/Movement/SteeringBehaviors/Steering/SteeringBehaviors.h"

//-----------------------------------------------------------------
// Behaviors
//-----------------------------------------------------------------

namespace BT_Actions
{
	Elite::BehaviorState ChangeToWander(Elite::Blackboard* pBlackboard)
	{
		AgarioAgent* pAgent;
		
		if (pBlackboard->GetData("Agent", pAgent) == false || pAgent == nullptr)
			return Elite::BehaviorState::Failure;

		pAgent->SetToWander();

		return Elite::BehaviorState::Success;
	}

	Elite::BehaviorState ChangeToSeekFood(Elite::Blackboard* pBlackboard)
	{
		AgarioAgent* pAgent;
		Elite::Vector2 targetPos;

		if (pBlackboard->GetData("Agent", pAgent) == false || pAgent == nullptr)
			return Elite::BehaviorState::Failure;

		if (pBlackboard->GetData("Target", targetPos) == false)
			return Elite::BehaviorState::Failure;

		pAgent->SetToSeek(targetPos);

		return Elite::BehaviorState::Success;
	}
}

//-----------------------------------------------------------------
// Conditions
//-----------------------------------------------------------------

namespace BT_Conditions
{
	bool IsFoodNearby(Elite::Blackboard* pBlackboard)
	{
		AgarioAgent* pAgent;
		std::vector<AgarioFood*>* pFoodVec;

		if (pBlackboard->GetData("Agent", pAgent) == false || pAgent == nullptr)
			return false;

		if (pBlackboard->GetData("FoodVec", pFoodVec) == false || pFoodVec == nullptr)
			return false;

		if (pFoodVec->empty())
			return false;

		const float searchRadius{ pAgent->GetRadius() + 20.f };
		float closestDistanceSqr{ searchRadius * searchRadius };
		AgarioFood* pClosestFood{ nullptr };
		Elite::Vector2 agentPos{ pAgent->GetPosition() };

		for (auto& pFood : *pFoodVec)
		{
			float distSqr{ pFood->GetPosition().DistanceSquared(agentPos) };

			if (distSqr < closestDistanceSqr)
			{
				closestDistanceSqr = distSqr;
				pClosestFood = pFood;
			}
		}

		if (pClosestFood == nullptr)
			return false;

		pBlackboard->ChangeData("Target", pClosestFood->GetPosition());
		return true;
	}
}










#endif