#pragma once
#include "Vector2f.h"

class Texture;
class Level;
class Sprite;
class TextureManager;

class Bullet
{
public:
	enum class BulletType
	{
		playerNormal,
		playerHeavy,
		Enemy,
		boss
	};

	explicit Bullet(const Point2f& pos, const Vector2f& velocity, TextureManager& pTextureManager, float scale = 1, BulletType bulletType = BulletType::playerNormal);
	Bullet(const Bullet& bullet) = delete;
	Bullet(Bullet&& bullet) = delete;
	virtual ~Bullet( );
	
	Bullet& operator=(const Bullet& rhs) = delete;
	Bullet& operator=(Bullet&& rhs) = delete;

	virtual void Update(float elapsedSec);
	virtual void Draw( ) const;
	bool IsBulletOutOfBoundaries( ) const;
	bool DidBulletHitGround(const Level& level) const;
	Rectf GetShape( ) const;
	BulletType GetBulletType( ) const;

private:
	Rectf m_Shape;
	Vector2f m_Velocity;
	float m_Scale;
	const Point2f m_StartPos;
	const Texture* m_pTexture;
	BulletType m_BulletType;
	Vector2f m_Acceleration;
	Sprite* m_pSprite;
	Rectf m_Boundaries;
};