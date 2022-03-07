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

	Rectf m_Shape;
	float m_HorizontalSpeed;
	float m_JumpSpeed;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	ActionState m_ActionState;
	float m_AccuTransFormSec;
	float m_MaxTransFormSec;
	int m_Power;

	void Waiting(float elapsedSec);
	void Moving(float elapsedSec, const Level& level);
	void UpdatePos(float elapsedSec);
	void MoveHorizontal(float elapsedSec);
	void Transforming(float elapsedSec, const Level& level);
};

