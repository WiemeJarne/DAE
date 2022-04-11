#pragma once
#include "Vector2f.h"
#include "Sprite.h"

class Texture;

class Bullet
{
public:
	enum class BulletType
	{
		normal,
		heavy
	};

	explicit Bullet(const Vector2f& velocity, const float scale, const Point2f& startPos); // constructor used in EnemyBullet class
	explicit Bullet(const Point2f& pos, const Vector2f& velocity, const float scale = 1, BulletType bulletType = BulletType::normal);	
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
	float m_Scale;
	const Point2f m_StartPos;
	Rectf m_Boundaries;

private:
	const Texture* m_pTexture;
	Sprite* m_pHeavyLaser;
	Sprite* m_pHeavyLaserDiagonal;
	BulletType m_BulletType;

	static Texture* m_pLaserTexture;
	static Texture* m_pDiagonalLaserTexture;
	static int m_AmountOfBullets;
};