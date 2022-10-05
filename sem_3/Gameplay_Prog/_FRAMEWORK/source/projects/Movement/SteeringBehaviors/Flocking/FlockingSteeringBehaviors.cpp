#include "stdafx.h"
#include "FlockingSteeringBehaviors.h"
#include "Flock.h"
#include "../SteeringAgent.h"
#include "../SteeringHelpers.h"

using namespace Elite;

//*******************
//COHESION (FLOCKING)
SteeringOutput Cohesion::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	SteeringOutput steering{};

	if (m_pFlock->GetNrOfNeighbors() == 0)
	{
		steering.IsValid = false;
		return steering;
	}

	const Vector2 averageNeighborPos{ m_pFlock->GetAverageNeighborPos() };

	m_Target = averageNeighborPos;

	return Seek::CalculateSteering(deltaT, pAgent);
}

//*********************
//SEPARATION (FLOCKING)
SteeringOutput Separation::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	SteeringOutput steering{};

	if (m_pFlock->GetNrOfNeighbors() == 0)
	{
		steering.IsValid = false;
		return steering;
	}

	const Vector2 averageNeighborPos{ m_pFlock->GetAverageNeighborPos() };

	m_Target = averageNeighborPos;

	return Flee::CalculateSteering(deltaT, pAgent);
}

//*************************
//VELOCITY MATCH (FLOCKING)
SteeringOutput VelocityMatch::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	SteeringOutput steering{};

	if (m_pFlock->GetNrOfNeighbors() == 0)
	{
		steering.IsValid = false;
		return steering;
	}

	pAgent->SetLinearVelocity(m_pFlock->GetAverageNeighborVelocity() );
	
	return SteeringOutput{};
}