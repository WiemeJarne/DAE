#pragma once
#include "Bullet.h"

class Sprite;

class EnemyBullet final : public Bullet
{
public:
	enum class BulletType
	{
		Enemy,
		boss
	};

	explicit EnemyBullet(const Point2f& pos, const Vector2f& velocity, float scale, BulletType bulletType, TextureManager* pTextureManager);
	EnemyBullet(const EnemyBullet& other) = delete;
	EnemyBullet(EnemyBullet&& other) = delete;
	~EnemyBullet( );

	EnemyBullet& operator=(const EnemyBullet& rhs) = delete;
	EnemyBullet&& operator=(EnemyBullet&& rhs) = delete;

	virtual void Update(float elapsedSec) override;
	virtual void Draw( ) const override;

private:
	const Vector2f m_Acceleration;
	const BulletType m_BulletType;
	Sprite* m_pEnemyBullet;
	Sprite* m_pBossBullet;
};