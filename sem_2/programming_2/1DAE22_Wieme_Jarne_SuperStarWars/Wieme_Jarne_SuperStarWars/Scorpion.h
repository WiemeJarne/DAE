#pragma once
#include "Enemy.h"

class BulletManager;

class Scorpion final : public Enemy
{
public:
	Scorpion(const Point2f& bottomLeftStartPoint, float scale, int health, TextureManager& textureManager, BulletManager& bulletManager);

	Scorpion(const Scorpion& other) = delete;
	Scorpion(Scorpion&& other) = delete;
	Scorpion& operator=(const Scorpion& rhs) = delete;
	Scorpion& operator=(Scorpion&& rhs) = delete;


	virtual void Update(float elapsedSec, const Level& level, Avatar& avatar) override;
	virtual void Draw( ) const override;

private:
	enum class ActionState
	{
		moving,
		attacking
	};

	ActionState m_ActionState;
	BulletManager& m_pBulletManager;

	virtual void Attack( ) override;
	virtual void CheckActionState(const Avatar& avatar) override;
	virtual void ChangeShapeDimensions( ) override;
};

