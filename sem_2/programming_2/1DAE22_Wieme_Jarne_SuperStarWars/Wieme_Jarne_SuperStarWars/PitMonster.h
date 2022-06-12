#pragma once
#include "Enemy.h"

class TextureManager;
class BulletManager;

class PitMonster final : public Enemy
{
public:
	explicit PitMonster(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& textureManager, BulletManager& bulletManager);

	PitMonster(const PitMonster& other) = delete;
	PitMonster& operator=(const PitMonster& rhs) = delete;
	PitMonster(PitMonster&& other) = delete;
	PitMonster& operator=(PitMonster&& rhs) = delete;

	virtual void Update(float elapsedSec, const Level& level, const Avatar& avatar) override;
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
	float m_SecondsSinceLastTentacle;
	BulletManager& m_BulletManager;

	void Attack( );
	virtual void ChangeShapeDimensions( ) override;
	virtual void CheckActionState(const Avatar& avatar) override;
};