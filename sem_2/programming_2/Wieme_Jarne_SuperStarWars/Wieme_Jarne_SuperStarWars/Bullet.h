#pragma once
#include <vector>
#include "Vector2f.h"

class Enemy;
class Texture;

class Bullet
{
public:
	explicit Bullet(const Vector2f& velocity, const float scale, const Point2f& startPos);
	explicit Bullet(const Point2f& pos, const Vector2f& velocity, const float scale = 1);	
	Bullet(const Bullet& bullet) = delete;
	Bullet(Bullet&& bullet) = delete;
	~Bullet( );
	
	Bullet& operator=(const Bullet& rhs) = delete;
	Bullet& operator=(Bullet&& rhs) = delete;

	virtual void Update(float elapsedSec);
	virtual void Draw( ) const;
	bool IsBulletOutOfBoundaries( ) const;
	Rectf GetShape( );

protected:
	Rectf m_Shape;
	Vector2f m_Velocity;
	const float m_Scale;
	const Point2f m_StartPos;
	Rectf m_Boundaries;

private:
	const Texture* m_pTexture;

	static Texture* m_pLaserTexture;
	static Texture* m_pDiagonalLaserTexture;
	static int m_AmountOfBullets;
};