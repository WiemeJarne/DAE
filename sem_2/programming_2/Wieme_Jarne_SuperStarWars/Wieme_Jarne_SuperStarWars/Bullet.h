#pragma once
#include <vector>
#include "Vector2f.h"

class Enemy;
class Texture;

class Bullet
{
public:
	enum class BulletState
	{
		vertical,
		upDiagonal,
		horizontal,
		downDiagonal
	};

	Bullet(const Point2f& bottomLeftPoint, const Vector2f& velocity, const Bullet::BulletState& bulletState);
	~Bullet();

	void Update(float elapsedSec);
	void Draw() const;
	bool IsBulletInBoundaries(const Rectf& boundaries) const;

private:
	Rectf m_Shape;
	Vector2f m_Velocity;
	Texture* m_pTexture;
	BulletState m_BulletState;

	
	//void CheckEnemiesHit(std::vector<Enemy*> pEnemies);
};