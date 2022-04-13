#pragma once
#include "Vector2f.h"

class Texture;
class Level;
class Sprite;

class Bullet
{
public:
	enum class BulletType
	{
		normal,
		heavy
	};

	explicit Bullet(const Vector2f& velocity, float scale, const Point2f& startPos); // constructor used in EnemyBullet class
	explicit Bullet(const Point2f& pos, const Vector2f& velocity, float scale = 1, BulletType bulletType = BulletType::normal);	
	Bullet(const Bullet& bullet) = delete;
	Bullet(Bullet&& bullet) = delete;
	~Bullet( );
	
	Bullet& operator=(const Bullet& rhs) = delete;
	Bullet& operator=(Bullet&& rhs) = delete;

	virtual void Update(float elapsedSec);
	virtual void Draw( ) const;
	bool IsBulletOutOfBoundaries( ) const;
	bool DidBulletHitGround(const Level& level) const;
	Rectf GetShape( ) const;
	BulletType GetBulletType( ) const;

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