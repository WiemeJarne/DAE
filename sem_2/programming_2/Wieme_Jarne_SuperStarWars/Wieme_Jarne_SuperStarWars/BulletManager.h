#pragma once
#include <vector>
#include "Vector2f.h"
#include "Explosion.h"
#include "Bullet.h"

class TextureManager;
class Level;
class Avatar;
class PowerUpManager;
class Enemy;
class ExplosionManager;
class SoundEffect;

class BulletManager
{
public:
	explicit BulletManager(TextureManager& textureManager);
	
	virtual ~BulletManager( );
	BulletManager(const BulletManager& bullet) = delete;
	BulletManager& operator=(const BulletManager& rhs) = delete;
	BulletManager(BulletManager&& bullet) = delete;
	BulletManager& operator=(BulletManager&& rhs) = delete;

	void Update(float elapsedSec, const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar, PowerUpManager& powerUpManager);
	virtual void Draw( ) const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, Bullet::Type bulletType);
	
private:
	TextureManager& m_TextureManager;
	std::vector<Bullet*> m_pBullets;
	ExplosionManager* m_pExplosionManager;
	SoundEffect* m_ExplosionSound;

	void DeleteBullet(int index);
	void BulletIsOutOfBoundaries(int bulletIndex);
	float DetermineExplosionSize(int bulletIndex) const;
	Explosion::ExplosionType DetermineExplosionType(int bulletIndex) const;
	void HandleCollision(const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar, PowerUpManager& powerUpManager);
	void HandleCollisionWithEnemies(int bulletIndex, std::vector<Enemy*>& enemies, PowerUpManager& powerUpManager);
	void HandleCollisionWithAvatar(int bulletIndex, Avatar& avatar);
	void HandleCollisionWithLevel(const Level& level);
	Point2f DetermineExplosionPos(int bulletIndex);
};