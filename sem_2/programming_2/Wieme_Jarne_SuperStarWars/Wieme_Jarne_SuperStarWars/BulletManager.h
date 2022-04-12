#pragma once
#include <vector>
#include "Vector2f.h"

class Level;
class Enemy;
class Bullet;
class ExplosionManager;

class BulletManager
{
public:
	explicit BulletManager(const float bulletScale);
	BulletManager(const BulletManager& bullet) = delete;
	BulletManager(BulletManager&& bullet) = delete;
	~BulletManager( );

	BulletManager& operator=(const BulletManager& rhs) = delete;
	BulletManager& operator=(BulletManager&& rhs) = delete;

	void Update(const float elapsedSec, const Level& level);
	virtual void Draw( ) const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, bool BlasterPowerUpActive);
	void HandleCollisionWithEnemies(std::vector<Enemy*> enemies);
	
protected:
	const float m_BulletScale;
	std::vector<Bullet*> m_pBullets;
	ExplosionManager* m_pExplosionManager;

	virtual void DeleteBullet(int index);
	
private:
	float DetermineExplosionSize(int bulletIndex) const;
};