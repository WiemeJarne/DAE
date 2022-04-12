#pragma once
#include <vector>
#include "Vector2f.h"
#include "EnemyBullet.h"

class Avatar;
class ExplosionManager;

class EnemyBulletManager final
{
public:
	explicit EnemyBulletManager(const float bulletScale);
	EnemyBulletManager(const EnemyBulletManager& other) = delete;
	EnemyBulletManager(EnemyBulletManager&& other) = delete;
	~EnemyBulletManager( );

	EnemyBulletManager& operator=(const EnemyBulletManager& rhs) = delete;
	EnemyBulletManager& operator=(EnemyBulletManager&& rhs) = delete;

	void UpdateBullets(const float elapsedSec, Avatar& avatar, const Level& level);
	void Draw( ) const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, EnemyBullet::BulletType bulletType);
	void HandleCollision(Avatar& avatar);
	void DeleteAllEnemyBullets( );

private:
	std::vector<EnemyBullet*> m_pEnemyBullets;
	const float m_BulletScale;
	ExplosionManager* m_pExplosionManager;

	virtual void DeleteBullet(const int index);
};