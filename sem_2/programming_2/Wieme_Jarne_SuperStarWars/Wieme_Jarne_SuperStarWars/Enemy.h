#pragma once
#include "Vector2f.h"

class Level;
class Texture;
class Sprite;

class Enemy final
{
public:
	explicit Enemy(const Point2f& bottomLeftStartPoint);
	Enemy(const Enemy& other) = delete;
	Enemy(Enemy&& other) = delete;
	~Enemy( );

	Enemy& operator=(const Enemy& rhs) = delete;
	Enemy& operator=(Enemy&& rhs) = delete;

	void Update(float elapsedSec, const Level& level);
	void Draw( ) const;

private:
	Rectf m_Shape;
	Vector2f m_Velocity;
	Vector2f m_Acceleration;
	float m_LeftBoundary;
	float m_RightBoundary;
	Sprite* m_Sprite;
	float m_Delay;
};

