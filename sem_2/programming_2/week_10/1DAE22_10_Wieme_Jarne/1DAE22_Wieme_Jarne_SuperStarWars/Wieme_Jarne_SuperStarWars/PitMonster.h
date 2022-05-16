#pragma once
#include "Enemy.h"

class PitMonster final : public Enemy
{
public:
	explicit PitMonster(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager* pTextureManager);

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