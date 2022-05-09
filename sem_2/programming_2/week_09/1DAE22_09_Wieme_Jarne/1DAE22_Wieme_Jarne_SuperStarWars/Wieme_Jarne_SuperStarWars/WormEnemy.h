#pragma once
#include "Enemy.h"

class WormEnemy final : public Enemy
{
public:
	explicit WormEnemy(const Point2f& bottomLeftStartPoint, float scale, int health);

	virtual void Update(float elapsedSec, const Level& level, Avatar& avatar) override;
	virtual void Draw( ) const override;

private:
	enum class ActionState
	{
		inGround,
		summon,
		idle,
		attacking
	};

	ActionState m_ActionState;

	virtual void CheckActionState(const Avatar& avatar) override;
	virtual void ChangeShapeDimensions( ) override;
};