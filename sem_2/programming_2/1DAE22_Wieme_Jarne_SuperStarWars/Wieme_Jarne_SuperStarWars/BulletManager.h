#pragma once
#include <vector>
#include "Vector2f.h"
#include "Explosion.h"
#include "Bullet.h"

class Level;
class Enemy;
class ExplosionManager;
class TextureManager;
class Avatar;
class SoundEffect;

class BulletManager
{
public:
	explicit BulletManager(TextureManager& pTextureManager);
	BulletManager(const BulletManager& bullet) = delete;
	BulletManager(BulletManager&& bullet) = delete;
	virtual ~BulletManager( );

	BulletManager& operator=(const BulletManager& rhs) = delete;
	BulletManager& operator=(BulletManager&& rhs) = delete;

	void Update(float elapsedSec, const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar);
	virtual void Draw( ) const;
	void AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, Bullet::Type bulletType);
	
	
protected:
	std::vector<Bullet*> m_pBullets;
	ExplosionManager* m_pExplosionManager;
	TextureManager& m_pTextureManager;
	SoundEffect* m_ExplosionSound;

	virtual void DeleteBullet(int index);
	
private:
	void BulletIsOutOfBoundaries(int bulletIndex);
	float DetermineExplosionSize(int bulletIndex) const;
	Explosion::ExplosionType DetermineExplosionType(int bulletIndex) const;
	void HandleCollision(const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar);
	void HandleCollisionWithEnemies(int bulletIndex, std::vector<Enemy*>& enemies);
	void HandleCollisionWithAvatar(int bulletIndex, Avatar& avatar);
	void HandleCollisionWithLevel(const Level& level);
	Point2f DetermineExplosionPos(int bulletIndex);
};