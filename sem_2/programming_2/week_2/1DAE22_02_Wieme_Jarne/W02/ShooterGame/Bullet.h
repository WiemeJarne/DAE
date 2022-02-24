#pragma once
#include <vector>
#include "utils.h"

class Enemy;

class Bullet
{
public:
	Bullet( );
	Bullet(float width, float height);

	void Draw( );
	void Update(float elapesedSec, std::vector<Enemy*> pEnemies, int numEnemies);
	void Shoot(const Point2f& center, const Vector2f& velocity);
	void SetDimensions(float width, float height);
	void SetBoundaries(const Rectf& boundaries);

private:
	Point2f m_Center;
	Rectf m_BulletRect;
	Rectf m_Boundaries;
	Vector2f m_Velocity;
	bool m_IsActivated;
};

