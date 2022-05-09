#pragma once
#include "Enemy.h"

class JumpingEnemy final : public Enemy
{
public:
	explicit JumpingEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager* pTextureManager);

	virtual void Update(float elapsedSec, const Level& level, Avatar& avatar) override;
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

