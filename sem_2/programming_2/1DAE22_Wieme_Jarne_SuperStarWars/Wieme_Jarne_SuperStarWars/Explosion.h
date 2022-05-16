#pragma once
class Sprite;
class TextureManager;

class Explosion final
{
public:
	enum class ExplosionType
	{
		AvatarBulletExplosion,
		EnemyBulletExplosion
	};

	explicit Explosion(const Point2f& bottomLeftPos, float scale, ExplosionType explosionType, TextureManager& pTextureManager);
	Explosion(const Explosion& other) = delete;
	Explosion(Explosion&& other) = delete;
	~Explosion( );

	Explosion& operator=(const Explosion& rhs) = delete;
	Explosion& operator=(Explosion&& rhs) = delete;

	void Update(float elapsedSec);
	void Draw( ) const;
	Sprite* GetSprite( ) const;

private:
	const Point2f m_bottomLeftPos;
	const float m_Scale;
	Sprite* m_pSprite;
	ExplosionType m_ExplosionType;
};

