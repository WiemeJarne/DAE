#pragma once
#include "Vector2f.h"
#include "Bullet.h"
#include "BulletManager.h"

class Avatar;

class EnemyBulletManager final : public BulletManager
{
public:
	explicit EnemyBulletManager(TextureManager& pTextureManager);

	void Update(float elapsedSec, Avatar& avatar, const Level& level);
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, Bullet::BulletType bulletType);
	void DeleteAllEnemyBullets( );

private:
	void HandleCollisionWithAvatar(Avatar& avatar);
};