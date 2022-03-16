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

	Bullet(const Rectf& avatarShape, const Vector2f& velocity, const Bullet::BulletState& bulletState, const int direction, const float scale);
	~Bullet();

	void Update(float elapsedSec);
	void Draw() const;
	bool IsBulletOutOfBoundaries() const;

private:
	Rectf m_Shape;
	Rectf m_AvatarShape;
	const Vector2f m_Velocity;
	const Texture* m_pTexture;
	const BulletState m_BulletState;
	const int m_Direction;
	const float m_Scale;
	const Point2f m_StartPos;
	Rectf m_Boundaries;
	
	static Texture* m_pLaserTexture;
	static Texture* m_pDiagonalLaserTexture;
	static int m_AmountOfBullets;

	//void CheckEnemiesHit(std::vector<Enemy*> pEnemies);
};