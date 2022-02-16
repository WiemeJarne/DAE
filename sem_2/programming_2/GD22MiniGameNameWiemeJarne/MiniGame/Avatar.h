#pragma once
#include "utils.h"

class Level;

class Avatar
{
public:
	Avatar();
	void Update(float elapsedSec, const Level& level);
	void Draw() const;
	void PowerUpHit();
	Rectf GetShape() const;

private:
	enum class ActionState
	{
		waiting,
		moving,
		transforming
	};
	const Rectf m_Shape;
	float m_HorSpeed;
	float m_JumpSpeed;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	ActionState m_ActionState;
	float m_AccuTransformSec;
	const float m_MaxTransformSec;
	int m_Power;
};

