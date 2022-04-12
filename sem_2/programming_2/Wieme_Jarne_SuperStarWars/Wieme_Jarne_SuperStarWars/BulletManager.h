#pragma once
#include <vector>
#include "Vector2f.h"

class Level;
class Enemy;
class Bullet;
class ExplosionManager;

class BulletManager final
{
public:
	explicit BulletManager(const float bulletScale);
	BulletManager(const BulletManager& bullet) = delete;
	BulletManager(BulletManager&& bullet) = delete;
	~BulletManager( );

	BulletManager& operator=(const BulletManager& rhs) = delete;
	BulletManager& operator=(BulletManager&& rhs) = delete;

	void UpdateBullets(const float elapsedSec, const Level& level);
	void DrawBullets( ) const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, bool BlasterPowerUpActive);
	void HandleCollisionWithEnemies(std::vector<Enemy*> enemies);
	
private:
	std::vector<Bullet*> m_pBullets;
	const float m_BulletScale;
	ExplosionManager* m_pExplosionManager;

	void DeleteBullet(int index);
	float DetermineExplosionSize(int bulletIndex) const;
};