#pragma once
#include <vector>
#include "Vector2f.h"

class Enemy;
class Texture;

class Bullet final
{
public:
	explicit Bullet(const Point2f& pos, const Vector2f& velocity, const float scale);	
	Bullet(const Bullet& bullet) = delete;
	Bullet(Bullet&& bullet) = delete;
	~Bullet();
	
	Bullet& operator=(const Bullet& rhs) = delete;
	Bullet& operator=(Bullet&& rhs) = delete;

	void Update(float elapsedSec);
	void Draw( ) const;
	bool IsBulletOutOfBoundaries( ) const;
	Rectf GetShape( );

private:
	Rectf m_Shape;
	const Vector2f m_Velocity;
	const Texture* m_pTexture;
	const float m_Scale;
	const Point2f m_StartPos;
	Rectf m_Boundaries;
	
	static Texture* m_pLaserTexture;
	static Texture* m_pDiagonalLaserTexture;
	static int m_AmountOfBullets;
};