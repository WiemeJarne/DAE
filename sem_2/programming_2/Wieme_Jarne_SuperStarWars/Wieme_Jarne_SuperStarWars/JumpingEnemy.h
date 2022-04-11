#pragma once
#include "Enemy.h"
class JumpingEnemy final : public Enemy
{
public:
	explicit JumpingEnemy(const Point2f& bottomLeftStartPoint, float scale, int health);
	JumpingEnemy(const JumpingEnemy& other) = delete;
	JumpingEnemy(JumpingEnemy&& other) = delete;
	~JumpingEnemy();

	JumpingEnemy& operator=(const JumpingEnemy& rhs) = delete;
	JumpingEnemy& operator=(JumpingEnemy&& rhs) = delete;

	virtual void Update(float elapsedSec, const Level& level, Avatar& avatar) override;
	virtual void Draw() const override;

private:
	enum class ActionState
	{
		idle,
		jumping
	};

	ActionState m_ActionState;

	virtual void CheckActionState(const Avatar& avatar) override;
	virtual void ChangeShapeDimensions( ) override;
};

