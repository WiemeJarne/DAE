//Precompiled Header [ALWAYS ON TOP IN CPP]
#include "stdafx.h"

//Includes
#include "SteeringBehaviors.h"
#include <iostream>

using namespace Elite;

//SEEK
//****
SteeringPlugin_Output Seek::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	SteeringPlugin_Output steering{};
	
	const Vector2 toTarget{ m_Target - agentInfo.Position };

	steering.LinearVelocity = toTarget;
	steering.LinearVelocity.Normalize();
	steering.LinearVelocity *= agentInfo.MaxLinearSpeed;

	//if ()
	//{
	//	const Vector2 agentDirection{ pAgent->GetDirection() };
	//
	//	//draws the current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, agentDirection, pAgent->GetLinearVelocity().Magnitude(), {1.f, 0.f, 1.f});
	//
	//	//draws the desired velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget, pAgent->GetMaxLinearSpeed(), {0.f, 1.f, 0.f});
	//
	//	//draws the desired velocity vector - current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget.GetNormalized() - agentDirection, pAgent->GetMaxLinearSpeed() - pAgent->GetLinearVelocity().Magnitude(), {0.f, 1.f, 1.f});
	//}

	return steering;
}

SteeringPlugin_Output Flee::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	SteeringPlugin_Output steering{};

	const Vector2 toTarget{ m_Target - agentInfo.Position };

	steering.LinearVelocity = toTarget;
	steering.LinearVelocity.Normalize();
	steering.LinearVelocity *= agentInfo.MaxLinearSpeed * -1;

	//if ()
	//{
	//	const Vector2 agentDirection{ pAgent->GetDirection() };
	//
	//	//draws the current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, agentDirection, pAgent->GetLinearVelocity().Magnitude(), { 1.f, 0.f, 1.f });
	//
	//	//draws the desired velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget, pAgent->GetMaxLinearSpeed(), { 0.f, 1.f, 0.f });
	//
	//	//draws the desired velocity vector - current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget.GetNormalized() - agentDirection, pAgent->GetMaxLinearSpeed() - pAgent->GetLinearVelocity().Magnitude(), { 0.f, 1.f, 1.f });
	//
	//	//draws the opposite desired velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, -toTarget, pAgent->GetMaxLinearSpeed(), { 0.f, 1.f, 0.f });
	//}

	return steering;
}

SteeringPlugin_Output SprintFlee::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	SteeringPlugin_Output steering{};

	const Vector2 toTarget{ m_Target - agentInfo.Position };

	steering.LinearVelocity = toTarget;
	steering.LinearVelocity.Normalize();
	steering.LinearVelocity *= agentInfo.MaxLinearSpeed * -1;
	steering.RunMode = true;

	//if ()
	//{
	//	const Vector2 agentDirection{ pAgent->GetDirection() };
	//
	//	//draws the current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, agentDirection, pAgent->GetLinearVelocity().Magnitude(), { 1.f, 0.f, 1.f });
	//
	//	//draws the desired velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget, pAgent->GetMaxLinearSpeed(), { 0.f, 1.f, 0.f });
	//
	//	//draws the desired velocity vector - current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget.GetNormalized() - agentDirection, pAgent->GetMaxLinearSpeed() - pAgent->GetLinearVelocity().Magnitude(), { 0.f, 1.f, 1.f });
	//
	//	//draws the opposite desired velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, -toTarget, pAgent->GetMaxLinearSpeed(), { 0.f, 1.f, 0.f });
	//}

	return steering;
}

SteeringPlugin_Output Arrive::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	SteeringPlugin_Output steering{};

	Vector2 toTarget{ m_Target - agentInfo.Position };
	
	float distanceToTarget{ toTarget.Magnitude() };
	
	steering.LinearVelocity = toTarget;
	steering.LinearVelocity.Normalize();

	const float slowRadius{ 10.f };
	const float arrivalRadius{ 2.f };

	if (distanceToTarget <= arrivalRadius)
	{
		steering.LinearVelocity = {0.f, 0.f};
		steering.AngularVelocity = 0.f;
	}
	else if (distanceToTarget <= slowRadius && distanceToTarget > arrivalRadius)
	{
		steering.LinearVelocity *= agentInfo.MaxLinearSpeed * (distanceToTarget / slowRadius);
	}
	else 
	{
		steering.LinearVelocity *= agentInfo.MaxLinearSpeed;
	}

	//if (pAgent->CanRenderBehavior())
	//{
	//	Vector2 agentDirection{ pAgent->GetDirection() };
	//
	//	//draws the current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, agentDirection, pAgent->GetLinearVelocity().Magnitude(), { 1.f, 0.f, 1.f });
	//
	//	//draws the desired velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget, pAgent->GetMaxLinearSpeed(), { 0.f, 1.f, 0.f });
	//
	//	//draws the desired velocity vector - current velocity vector
	//	DEBUGRENDERER2D->DrawDirection(agentPosition, toTarget.GetNormalized() - agentDirection, pAgent->GetMaxLinearSpeed() - pAgent->GetLinearVelocity().Magnitude(), { 0.f, 1.f, 1.f });
	//
	//	//draws the slow circle (if the target is in this circle the agent will slow down
	//	DEBUGRENDERER2D->DrawCircle(agentPosition, slowRadius, { 0.f, 0.f, 1.f }, 0.f);
	//
	//	//draws the arrival circle (if the target is in this circle the agent will stop
	//	DEBUGRENDERER2D->DrawCircle(agentPosition, arrivalRadius, { 1.f, 0.f, 0.f }, 0.f);
	//}
	
	return steering;
}

SteeringPlugin_Output Face::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	SteeringPlugin_Output steering{};
	steering.AutoOrient = false;

	Vector2 toTarget{ m_Target - agentInfo.Position };
	Vector2 rotationVector{ cosf(agentInfo.Orientation), sinf(agentInfo.Orientation) };

	if (AngleBetween(toTarget, rotationVector) < 0.1f && AngleBetween(toTarget, rotationVector) > -0.1f)
	{
		steering.AngularVelocity = 0.f;
	}
	else if (AngleBetween(toTarget, rotationVector) < 0)
	{
		steering.AngularVelocity = agentInfo.MaxAngularSpeed;
	}
	else if (AngleBetween(toTarget, rotationVector) > 0)
	{
		steering.AngularVelocity = -agentInfo.MaxAngularSpeed;
	}
	return steering;
}

SteeringPlugin_Output Wander::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	Vector2 circleOrigin{};
	circleOrigin.x = agentInfo.Position.x + cosf(agentInfo.Orientation) * m_OffsetDistance;
	circleOrigin.y =agentInfo.Position.y + sinf(agentInfo.Orientation) * m_OffsetDistance;

	const int maxWanderAngle{ int(m_WanderAngle + m_MaxAngleChange) + 360 };
	const int minWanderAngle{ int(m_WanderAngle - m_MaxAngleChange) + 360 };

	m_WanderAngle = static_cast<float>(rand() % (maxWanderAngle - minWanderAngle) + minWanderAngle);
	
	while (m_WanderAngle > 360)
	{
		m_WanderAngle -= 360;
	}

	Vector2 randomPointOnCircle{};
	randomPointOnCircle.x = circleOrigin.x + cosf(ToRadians(m_WanderAngle)) * m_Radius;
	randomPointOnCircle.y = circleOrigin.y + sinf(ToRadians(m_WanderAngle)) * m_Radius;
	
	m_Target = randomPointOnCircle;

	//if (pAgent->CanRenderBehavior())
	//{
	//	//draws a circle in front of the agent
	//	DEBUGRENDERER2D->DrawCircle(circleOrigin, m_Radius, { 0.f, 0.f, 1.f }, 0);
	//
	//	//draws the random point on the circle
	//	DEBUGRENDERER2D->DrawPoint(randomPointOnCircle, 5.f, { 0.f, 1.f, 1.f });
	//}

	return Seek::CalculateSteering(deltaT, agentInfo);
}

SteeringPlugin_Output Pursuit::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	Vector2 toTarget{ m_Target - agentInfo.Position };
	float t{toTarget.Magnitude() / agentInfo.MaxLinearSpeed}; // number of update cycles
	
	//m_Target += m_Target.LinearVelocity.GetNormalized() * agentInfo.LinearVelocity.Magnitude() * t;

	//if (pAgent->CanRenderBehavior())
	//{
	//	DEBUGRENDERER2D->DrawPoint(m_Target.Position, 5.f, { 1.f, 0.f, 1.f });
	//}

	return Seek::CalculateSteering(deltaT, agentInfo);
}

SteeringPlugin_Output Evade::CalculateSteering(float deltaT, AgentInfo& agentInfo)
{
	Vector2 toTarget{ m_Target - agentInfo.Position };

	if (m_EvadeRadius <= toTarget.Magnitude())
	{
		SteeringPlugin_Output steering{};
		return steering;
	}

	float t{ toTarget.Magnitude() / agentInfo.MaxLinearSpeed }; // number of update cycles

	//m_Target += m_Target.LinearVelocity.GetNormalized() * agentInfo.LinearVelocity.Magnitude() * t;

	//if (pAgent->CanRenderBehavior())
	//{
	//	DEBUGRENDERER2D->DrawPoint(m_Target.Position, 5.f, { 1.f, 0.f, 1.f });
	//}

	return Flee::CalculateSteering(deltaT, agentInfo);
}