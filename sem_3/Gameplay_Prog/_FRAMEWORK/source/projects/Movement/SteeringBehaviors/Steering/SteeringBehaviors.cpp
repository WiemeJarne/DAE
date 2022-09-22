//Precompiled Header [ALWAYS ON TOP IN CPP]
#include "stdafx.h"

//Includes
#include "SteeringBehaviors.h"
#include "../SteeringAgent.h"
#include "../Obstacle.h"
#include "framework\EliteMath\EMatrix2x3.h"
#include <iostream>

using namespace Elite;

//SEEK
//****
SteeringOutput Seek::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	SteeringOutput steering{};

	steering.LinearVelocity = m_Target.Position - pAgent->GetPosition();
	steering.LinearVelocity.Normalize();
	steering.LinearVelocity *= pAgent->GetMaxLinearSpeed();

	return steering;
}

SteeringOutput Flee::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	SteeringOutput steering{};

	steering.LinearVelocity = m_Target.Position - pAgent->GetPosition();
	steering.LinearVelocity.Normalize();
	steering.LinearVelocity *= -pAgent->GetMaxLinearSpeed();

	return steering;
}

SteeringOutput Arrive::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	SteeringOutput steering{};
	steering.LinearVelocity = m_Target.Position - pAgent->GetPosition();
	
	float distanceToTarget{ steering.LinearVelocity.Magnitude() };
	
	steering.LinearVelocity.Normalize();

	const float slowRadius{ 15.f };
	const float arrivalRadius{ 1.f };

	if (distanceToTarget <= arrivalRadius)
	{
		steering.LinearVelocity = { 0.f, 0.f };
		steering.AngularVelocity = 0.f;
	}
	else if (distanceToTarget < slowRadius)
	{
		steering.LinearVelocity *= pAgent->GetMaxLinearSpeed() * (distanceToTarget / slowRadius);
	}
	else
	{
		steering.LinearVelocity *= pAgent->GetMaxLinearSpeed();
	}

	return steering;
}

SteeringOutput Face::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	pAgent->SetAutoOrient(false);
	SteeringOutput steering{};

	pAgent->GetDirection().Normalize();

	Vector2 toTarget{ m_Target.Position - pAgent->GetPosition() };
	Vector2 rotationVector{ cosf(pAgent->GetRotation()), sinf(pAgent->GetRotation()) };
	DEBUGRENDERER2D->DrawDirection(pAgent->GetPosition(), toTarget, 5.f, {1,0,0});
	DEBUGRENDERER2D->DrawDirection(pAgent->GetPosition(), rotationVector, 15.f, { 0.f, 1.f, 0.f });
	rotationVector.Normalize();

	//const float dotProdruct{ pAgent->GetDirection().Dot(rotationVector)};


	if (AngleBetween(toTarget, rotationVector) < 0)
	{
		steering.AngularVelocity = 50.f;
	}
	else if (AngleBetween(toTarget, rotationVector) > 0)
	{
		steering.AngularVelocity = -50.f;
	}
	else if(AngleBetween(toTarget, rotationVector) == 0)
	{
		steering.AngularVelocity = 0.f;
	}

	return steering;
}