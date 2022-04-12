#pragma once
#include <vector>
#include "Vector2f.h"
#include "EnemyBullet.h"
#include "BulletManager.h"

class Avatar;
class ExplosionManager;

class EnemyBulletManager final : public BulletManager
{
public:
	explicit EnemyBulletManager(const float bulletScale);

	void Update(const float elapsedSec, Avatar& avatar, const Level& level);
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, EnemyBullet::BulletType bulletType);
	void DeleteAllEnemyBullets( );

private:
	void HandleCollisionWithAvatar(Avatar& avatar);
};