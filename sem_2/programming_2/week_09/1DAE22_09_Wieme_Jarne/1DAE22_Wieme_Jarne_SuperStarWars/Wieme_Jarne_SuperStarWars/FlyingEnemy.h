#pragma once
#include "Enemy.h"

class FlyingEnemy final : public Enemy
{
public:
	explicit FlyingEnemy(const Point2f& bottomLeftStartPoint, float scale, int health);

	virtual void Update(float elapsedSec, const Level& level, Avatar& avatar) override;
	virtual void Draw( ) const override;

private:
	enum class ActionState
	{
		flying,
		attacking
	};

	ActionState m_ActionState;
	const float m_BottomBoundary;

	virtual void CheckActionState(const Avatar& avatar) override;
	virtual void ChangeShapeDimensions( ) override;
};