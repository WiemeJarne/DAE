#include "pch.h"
#include "Bullet.h"
#include "Texture.h"
#include "Level.h"
#include "Sprite.h"
#include "TextureManager.h"

Bullet::Bullet(const Point2f& pos, const Vector2f& velocity, TextureManager& pTextureManager, float scale, Type bulletType)
	: m_Shape{ }
	, m_Velocity{ velocity }
	, m_Scale{ scale }
	, m_StartPos{ pos }
	, m_pTexture{ }
	, m_Type{ bulletType }
	, m_Acceleration{ }
	, m_pSprite{ }
{
	m_Boundaries.left = m_StartPos.x - 250.f;
	m_Boundaries.bottom = m_StartPos.y - 250.f;
	m_Boundaries.width = 500.f;
	m_Boundaries.height = 500.f;

	m_Shape.left = pos.x;
	m_Shape.bottom = pos.y;

	switch (m_Type)
	{
	case Bullet::Type::playerNormal:
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

	case Bullet::Type::playerHeavy:
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

	case Bullet::Type::Enemy:
		m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/Lasers/EnemyLaser.png"), Sprite::AnimType::loop, 2, 1, 10.f };
		m_Acceleration.y = -981.f;
		break;

	case Bullet::Type::boss:
		m_pSprite = new Sprite{ pTextureManager.GetTexture("Resources/PitMonster/AttackRock.png"), Sprite::AnimType::loop, 4, 1, 2.f };
		m_Acceleration.y = -981.f;
		break;
	}

	if (m_Type == Type::playerNormal)
	{
		m_Shape.width = m_pTexture->GetWidth( ) * m_Scale;
		m_Shape.height = m_pTexture->GetHeight( ) * m_Scale;
	}
	else
	{
		m_Shape.width = m_pSprite->GetFrameWidth( ) * m_Scale;
		m_Shape.height = m_pSprite->GetFrameHeight( ) * m_Scale;
	}
}

Bullet::~Bullet( )
{
	if (m_Type != Type::playerNormal)
	{
		delete m_pSprite;
	}
}

void Bullet::Update(float elapsedSec)
{
	m_Shape.left += elapsedSec * m_Velocity.x;
	m_Shape.bottom += elapsedSec * m_Velocity.y;

	m_Velocity.y += elapsedSec * m_Acceleration.y;

	if (m_Type != Type::playerNormal)
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
		
		if (m_Type == Type::playerNormal)
		{
			m_pTexture->Draw( );
		}
		else
		{
			m_pSprite->Draw( );
		}

	glPopMatrix( );
}

bool Bullet::IsOutOfBoundaries() const
{
	if (    m_Shape.left + m_Shape.width < m_Boundaries.left 
		 || m_Shape.left > m_Boundaries.left + m_Boundaries.width
		 || m_Shape.bottom + m_Shape.height < m_Boundaries.bottom
		 || m_Shape.bottom > m_Boundaries.bottom + m_Boundaries.height )
	{
		return true;
	}
	return false;
}

bool Bullet::HitGround(const Level& level) const
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

Bullet::Type Bullet::GetType( ) const
{
	return m_Type;
}

Vector2f Bullet::GetVelocity( ) const
{
	return m_Velocity;
}