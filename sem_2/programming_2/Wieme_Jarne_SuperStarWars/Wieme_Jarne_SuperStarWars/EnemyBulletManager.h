#pragma once
#include "Vector2f.h"
#include "EnemyBullet.h"
#include "BulletManager.h"

class Avatar;

class EnemyBulletManager final : public BulletManager
{
public:
	explicit EnemyBulletManager( );

	void Update(float elapsedSec, Avatar& avatar, const Level& level);
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, EnemyBullet::BulletType bulletType);
	void DeleteAllEnemyBullets( );

private:
	void HandleCollisionWithAvatar(Avatar& avatar);
};