#pragma once
#include <vector>
#include "Vector2f.h"
#include "EnemyBullet.h"

class Avatar;

class EnemyBulletManager final
{
public:
	explicit EnemyBulletManager(const float bulletScale);
	EnemyBulletManager(const EnemyBulletManager& other) = delete;
	EnemyBulletManager(EnemyBulletManager&& other) = delete;
	~EnemyBulletManager( );

	EnemyBulletManager& operator=(const EnemyBulletManager& rhs) = delete;
	EnemyBulletManager& operator=(EnemyBulletManager&& rhs) = delete;

	void UpdateBullets(const float elapsedSec, Avatar& avatar);
	void DrawBullets() const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, EnemyBullet::BulletType bulletType);
	void HandleCollision(Avatar& avatar);

private:
	std::vector<EnemyBullet*> m_pEnemyBullets;
	const float m_BulletScale;

	virtual void DeleteBullet(const int index);
};