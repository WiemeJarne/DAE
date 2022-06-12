#pragma once
#include "Enemy.h"

class TextureManager;

class JumpingEnemy final : public Enemy
{
public:
	explicit JumpingEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& textureManager);

	JumpingEnemy(const JumpingEnemy& other) = delete;
	JumpingEnemy& operator=(const JumpingEnemy& rhs) = delete;
	JumpingEnemy(JumpingEnemy&& other) = delete;
	JumpingEnemy& operator=(JumpingEnemy&& rhs) = delete;

	virtual void Update(float elapsedSec, const Level& level, const Avatar& avatar) override;
	virtual void Draw( ) const override;

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

