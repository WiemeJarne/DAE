#pragma once
#include "Enemy.h"
class Boss final : public Enemy
{
public:
	explicit Boss(const Point2f& bottomLeftStartPoint, float scale, int health);
	Boss(const Boss& other) = delete;
	Boss(Boss&& other) = delete;
	~Boss( );

	Boss& operator=(const Boss& rhs) = delete;
	Boss& operator=(const Boss&& rhs) = delete;

	virtual void Update(float elapsedSec, const Level& level, Avatar& avatar) override;
	virtual void Draw( ) const override;

private:
	enum class ActionState
	{
		inground = -1,
		tentacles,
		summon,
		attack
	};

	ActionState m_ActionState;
	bool m_HasBeenSummoned;
	float m_TentaclesDelay;

	virtual void ChangeShapeDimensions( ) override;
	virtual void CheckActionState(const Avatar& avatar) override;
	virtual void Attack( ) override;
};