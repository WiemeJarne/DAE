#include "stdafx.h"
#include "StatesAndTransitions.h"

using namespace Elite;
using namespace FSMStates;
using namespace FSMConditions;

void WanderState::OnEnter(Elite::Blackboard* pBlackboard)
{
	AgarioAgent* pAgent;
	bool isValid{ pBlackboard->GetData("Agent", pAgent) };

	if (!isValid || pAgent == nullptr) return;

	pAgent->SetToWander();
}

void SeekFoodState::OnEnter(Elite::Blackboard* pBlackboard)
{
	AgarioAgent* pAgent;
	bool isValid{ pBlackboard->GetData("Agent", pAgent) };

	if (!isValid || pAgent == nullptr) return;

	AgarioFood* nearestFood;
	if (!pBlackboard->GetData("NearestFood", nearestFood) || nearestFood == nullptr) return;

	pAgent->SetToSeek(nearestFood->GetPosition());
}

bool FoodNearbyCondition::Evaluate(Elite::Blackboard* pBlackboard) const
{
	AgarioAgent* pAgent;
	if (!pBlackboard->GetData("Agent", pAgent) || pAgent == nullptr) return true;

	std::vector<AgarioFood*>* pFoodVector{};
	if (!pBlackboard->GetData("Agent", pAgent) || pFoodVector == nullptr) return true;
	
	const float radius{ 10.f };
	const Vector2 agentPos{ pAgent->GetPosition() };

	auto isCloser
	{ 
		[agentPos](AgarioFood* pFood1, AgarioFood* pFood2)
		{
			float distToFood1{pFood1->GetPosition().DistanceSquared(agentPos)};
			float distToFood2{ pFood2->GetPosition().DistanceSquared(agentPos) };

			return distToFood1 < distToFood2;
		} 
	};

	auto closestElementIt{ std::min_element(pFoodVector->begin(), pFoodVector->end(), isCloser) };
	if (closestElementIt == pFoodVector->end()) return false;

	if ((*closestElementIt)->GetPosition().DistanceSquared(agentPos) < radius * radius)
	{
		pBlackboard->ChangeData("NearestFood", *closestElementIt);
		return true;
	}

	return false;
}