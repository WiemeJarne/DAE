#include "stdafx.h"
#include "FlockingSteeringBehaviors.h"
#include "Flock.h"
#include "../SteeringAgent.h"
#include "../SteeringHelpers.h"

#include <iostream>

using namespace Elite;

//*******************
//COHESION (FLOCKING)
SteeringOutput Cohesion::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	if (m_pFlock->GetNrOfNeighbors() == 0)
	{
		return SteeringOutput{};
	}

	Vector2 averageNeighborPos{ m_pFlock->GetAverageNeighborPos() };

	m_Target = averageNeighborPos;

	return Seek::CalculateSteering(deltaT, pAgent);
}

//*********************
//SEPARATION (FLOCKING)
SteeringOutput Separation::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	if (m_pFlock->GetNrOfNeighbors() == 0)
	{
		return SteeringOutput{};
	}

	std::vector<SteeringAgent*> neighbors{ m_pFlock->GetNeighbors() };

	Vector2 velocity{};
	const int nrOfNeightbors{ m_pFlock->GetNrOfNeighbors() };

	for (int index{}; index < nrOfNeightbors; ++index)
	{
		Vector2 fromNeighbor{ pAgent->GetPosition() - neighbors[index]->GetPosition() };
		
		velocity += fromNeighbor;
	}
	
	m_Target.LinearVelocity = velocity;

	return Flee::CalculateSteering(deltaT, pAgent);
}

//*************************
//VELOCITY MATCH (FLOCKING)
SteeringOutput VelocityMatch::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	m_pFlock->RegisterNeighbors(pAgent);

	if (m_pFlock->GetNrOfNeighbors() == 0)
	{
		return SteeringOutput{};
	}

	pAgent->SetLinearVelocity(m_pFlock->GetAverageNeighborVelocity() );
	
	return SteeringOutput{};
}