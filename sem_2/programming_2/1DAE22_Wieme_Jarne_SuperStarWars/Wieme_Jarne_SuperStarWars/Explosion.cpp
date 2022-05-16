#include "pch.h"
#include "Explosion.h"
#include "Sprite.h"
#include "TextureManager.h"

Explosion::Explosion(const Point2f& bottomLeftPos, float scale, ExplosionType explosionType, TextureManager& pTextureManager)
	: m_bottomLeftPos{ bottomLeftPos }
	, m_Scale{ scale }
	, m_ExplosionType{ explosionType }
	, m_pSprite{ }
{
	if (m_ExplosionType == ExplosionType::AvatarBulletExplosion)
	{
		m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/Explosions/Explosion3.png"), Sprite::AnimType::dontRepeat, 6, 1, 7.f };
	}
	else if (m_ExplosionType == ExplosionType::EnemyBulletExplosion)
	{
		m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/Explosions/Explosion1.png"), Sprite::AnimType::dontRepeat, 5, 1, 7.f };
	}
}

Explosion::~Explosion( )
{
	delete m_pSprite;
}

void Explosion::Update(float elapsedSec)
{
	m_pSprite->Update(elapsedSec);
}

void Explosion::Draw( ) const
{
	glPushMatrix( );
		glTranslatef(m_bottomLeftPos.x, m_bottomLeftPos.y, 0.f);
		glScalef(m_Scale, m_Scale, 1.f);
		m_pSprite->Draw( );
	glPopMatrix( );
}

Sprite* Explosion::GetSprite( ) const
{
	return m_pSprite;
}