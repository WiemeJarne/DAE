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

	if (AngleBetween(toTarget, rotationVector) < 0.1f && AngleBetween(toTarget, rotationVector) > -0.1f)
	{
		steering.AngularVelocity = 0.f;
	}
	else if (AngleBetween(toTarget, rotationVector) < 0)
	{
		steering.AngularVelocity = pAgent->GetMaxAngularSpeed();
	}
	else if (AngleBetween(toTarget, rotationVector) > 0)
	{
		steering.AngularVelocity = -pAgent->GetMaxAngularSpeed();
	}
	return steering;
}

SteeringOutput Wander::CalculateSteering(float deltaT, SteeringAgent* pAgent)
{
	Vector2 circleOrigin{};
	circleOrigin.x = pAgent->GetPosition().x + cosf(pAgent->GetRotation()) * m_OffsetDistance;
	circleOrigin.y = pAgent->GetPosition().y + sinf(pAgent->GetRotation()) * m_OffsetDistance;

	const int maxWanderAngle{ int(m_WanderAngle + m_MaxAngleChange )};
	const int minWanderAngle{ int(m_WanderAngle - m_MaxAngleChange )};

	m_WanderAngle = float(rand() % (maxWanderAngle - minWanderAngle) + minWanderAngle);
	
	std::cout << m_WanderAngle << '\n';

	Vector2 randomPointOnCircle{};
	randomPointOnCircle.x = circleOrigin.x + cosf(ToRadians( m_WanderAngle)) * m_Radius;
	randomPointOnCircle.y = circleOrigin.y + sinf(ToRadians(m_WanderAngle)) * m_Radius;

	DEBUGRENDERER2D->DrawCircle(circleOrigin, m_Radius, { 1,0,0 }, 0);
	DEBUGRENDERER2D->DrawPoint(randomPointOnCircle, 10.f, { 0,0,1 }, 0);
	DEBUGRENDERER2D->DrawDirection(pAgent->GetPosition(), randomPointOnCircle - pAgent->GetPosition(), 10, {0,1,0});
	
	SteeringOutput steering{};
	steering.LinearVelocity = randomPointOnCircle - pAgent->GetPosition();
	steering.LinearVelocity.Normalize();
	steering.LinearVelocity *= pAgent->GetMaxLinearSpeed();

	return steering;
}