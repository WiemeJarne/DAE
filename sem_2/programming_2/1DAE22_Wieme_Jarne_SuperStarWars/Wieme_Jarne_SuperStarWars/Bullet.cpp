#include "pch.h"
#include "Bullet.h"
#include "Texture.h"
#include "Level.h"
#include "Sprite.h"
#include "TextureManager.h"

Bullet::Bullet(const Vector2f& velocity, float scale, const Point2f& startPos)
	: m_Shape{ }
	, m_Velocity{ velocity }
	, m_Scale{ scale }
	, m_StartPos{ startPos }
	, m_pTexture{ }
	, m_BulletType{ }
	, m_Acceleration{ }
	, m_pSprite{ }
{
}

Bullet::Bullet(const Point2f& pos, const Vector2f& velocity, TextureManager& pTextureManager, float scale, BulletType bulletType)
	: Bullet(velocity, scale, pos)
{
	m_BulletType = bulletType;

	m_Boundaries.left = m_StartPos.x - 250.f;
	m_Boundaries.bottom = m_StartPos.y - 250.f;
	m_Boundaries.width = 500.f;
	m_Boundaries.height = 500.f;

	m_Shape.left = pos.x;
	m_Shape.bottom = pos.y;

	switch (m_BulletType)
	{
	case Bullet::BulletType::playerNormal:
		if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
			|| ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
		{
			m_pTexture = pTextureManager.GetTexture("Resources/Lasers/LaserRight.png");
		}
		else
		{
			m_pTexture = pTextureManager.GetTexture("Resources/Lasers/LaserUpRight.png");
		}
		break;

	case Bullet::BulletType::playerHeavy:
		m_Scale = scale * 1.5f;

		if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
			|| ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
		{
			m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/Lasers/HeavyLaserRight.png"), Sprite::AnimType::dontRepeat, 2, 1, 7.f };
		}
		else
		{
			m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/Lasers/HeavyLaserUpRight.png"), Sprite::AnimType::dontRepeat, 2, 1, 7.f };
		}
		break;

	case Bullet::BulletType::Enemy:
		m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/Lasers/EnemyLaser.png"), Sprite::AnimType::loop, 2, 1, 10.f };
		m_Acceleration.y = -981.f;
		break;

	case Bullet::BulletType::boss:
		m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/PitMonster/AttackRock.png"), Sprite::AnimType::loop, 4, 1, 2.f };
		break;
	}

	if (m_BulletType == BulletType::playerNormal)
	{
		m_Shape.width = m_pTexture->GetWidth();
		m_Shape.height = m_pTexture->GetHeight();
	}
	else
	{
		m_Shape.width = m_pSprite->GetFrameWidth();
		m_Shape.height = m_pSprite->GetFrameHeight();
	}
}

Bullet::~Bullet( )
{
	if (m_BulletType != BulletType::playerNormal)
	{
		delete m_pSprite;
	}
}

void Bullet::Update(float elapsedSec)
{
	m_Shape.left += elapsedSec * m_Velocity.x;
	m_Shape.bottom += elapsedSec * m_Velocity.y;

	m_Velocity.y += elapsedSec * m_Acceleration.y;

	if (m_BulletType != BulletType::playerNormal)
	{
		m_pSprite->Update(elapsedSec);
	}
}

void Bullet::Draw( ) const
{
	glPushMatrix( );

		glTranslatef(m_Shape.left, m_Shape.bottom, 0);

		if (m_Velocity.y > 0 && m_Velocity.x == 0)
		{
			glRotatef(90, 0.f, 0.f, 1.f);

			glScalef(m_Scale, m_Scale, 1.f);
		}
		else if (m_Velocity.y > 0 && m_Velocity.x < 0 )
		{
			glScalef(-m_Scale, m_Scale, 1.f);
		}
		else if (m_Velocity.y > 0 && m_Velocity.x > 0)
		{
			glScalef(m_Scale, m_Scale, 1.f);
		}
		else if (m_Velocity.y < 0 && m_Velocity.x < 0)
		{
			glScalef(-m_Scale, -m_Scale, 1.f);
		}
		else if (m_Velocity.y < 0 && m_Velocity.x > 0)
		{
			glScalef(m_Scale, -m_Scale, 1.f);
		}
		else if (m_Velocity.y == 0 && m_Velocity.x < 0)
		{
			glScalef(-m_Scale, m_Scale, 1.f);
		}
		else if (m_Velocity.y == 0 && m_Velocity.x > 0)
		{
			glScalef(m_Scale, m_Scale, 1.f);
		}
		
		if (m_BulletType == BulletType::playerNormal)
		{
			m_pTexture->Draw( );
		}
		else
		{
			m_pSprite->Draw( );
		}

	glPopMatrix( );
}

bool Bullet::IsBulletOutOfBoundaries() const
{
	if ( m_Shape.left + m_Shape.width < m_Boundaries.left 
		 || m_Shape.left > m_Boundaries.left + m_Boundaries.width
		 || m_Shape.bottom + m_Shape.height < m_Boundaries.bottom
		 || m_Shape.bottom > m_Boundaries.bottom + m_Boundaries.height )
	{
		return true;
	}
	return false;
}

bool Bullet::DidBulletHitGround(const Level& level) const
{
	if (level.IsOnGround(m_Shape, m_Velocity))
	{
		return true;
	}
	
	return false;
}

Rectf Bullet::GetShape( ) const
{
	return m_Shape;
}

Bullet::BulletType Bullet::GetBulletType( ) const
{
	return m_BulletType;
}