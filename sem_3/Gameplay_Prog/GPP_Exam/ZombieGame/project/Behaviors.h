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
	BehaviorState ChangeToWander(Blackboard* pBlackBoard)
	{
		ISteeringBehavior* pSteeringBehavior;

		if (!pBlackBoard->GetData("SteeringBehavior", pSteeringBehavior))
			return BehaviorState::Failure;

		//delete the current SteeringBehavior
		delete pSteeringBehavior;
		
		//make Wander behavior
		pSteeringBehavior = new Wander();

		//set the new behavior
		pBlackBoard->ChangeData("SteeringBehavior", pSteeringBehavior);

		return BehaviorState::Success;
	}


}

//-----------------------------------------------------------------
// Conditions
//-----------------------------------------------------------------

namespace BT_Conditions
{
	
}