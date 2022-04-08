#pragma once
#include "Bullet.h"

class Sprite;

class EnemyBullet final : public Bullet
{
public:
	explicit EnemyBullet(const Point2f& pos, const Vector2f& velocity, const float scale);
	EnemyBullet(const EnemyBullet& other) = delete;
	EnemyBullet(EnemyBullet&& other) = delete;
	~EnemyBullet( );

	EnemyBullet& operator=(const EnemyBullet& rhs) = delete;
	EnemyBullet&& operator=(EnemyBullet&& rhs) = delete;

	virtual void Update(float elapsedSec) override;
	virtual void Draw( ) const override;

private:
	const Vector2f m_Acceleration;

	static Sprite* m_pEnemyBullet;
	static int m_AmountOfEnemyBullets;
};