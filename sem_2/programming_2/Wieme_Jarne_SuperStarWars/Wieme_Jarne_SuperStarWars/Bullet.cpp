#include "pch.h"
#include "Bullet.h"
#include "Texture.h"
#include "Level.h"
#include "Sprite.h"

Texture* Bullet::m_pLaserTexture{ nullptr };
Texture* Bullet::m_pDiagonalLaserTexture{ nullptr };
int Bullet::m_AmountOfBullets{};

Bullet::Bullet(const Vector2f& velocity, const float scale, const Point2f& startPos)
	: m_Shape{ }
	, m_Velocity{ velocity }
	, m_Scale{ scale }
	, m_StartPos{ startPos }
	, m_pTexture{ }
	, m_pHeavyLaser{ }
	, m_pHeavyLaserDiagonal{ }
	, m_BulletType{ }
{
}

Bullet::Bullet(const Point2f& pos, const Vector2f& velocity, const float scale, BulletType bulletType)
	: Bullet(velocity, scale, pos)
{
	m_BulletType = bulletType;

	if (m_BulletType == BulletType::normal)
	{
		++m_AmountOfBullets;

		if (m_pLaserTexture == nullptr)
		{
			m_pLaserTexture = new Texture{ "Resources/Lasers/LaserRight.png" };
		}

		if (m_pDiagonalLaserTexture == nullptr)
		{
			m_pDiagonalLaserTexture = new Texture{ "Resources/Lasers/LaserUpRight.png" };
		}

		if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
			|| ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
		{
			m_pTexture = m_pLaserTexture;
		}
		else
		{
			m_pTexture = m_pDiagonalLaserTexture;
		}
	}
	else
	{
		m_Scale = scale * 1.5f;

		if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
			|| ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
		{
			m_pHeavyLaser = new Sprite{ "Resources/Lasers/HeavyLaserRight.png", Sprite::AnimType::dontRepeat, 2, 1, 7.f };
		}
		else
		{
			m_pHeavyLaserDiagonal = new Sprite{ "Resources/Lasers/HeavyLaserUpRight.png", Sprite::AnimType::dontRepeat, 2, 1, 7.f };
		}
	}
		
	m_Boundaries.left = m_StartPos.x - 250.f;
	m_Boundaries.bottom = m_StartPos.y - 250.f;
	m_Boundaries.width = 500.f;
	m_Boundaries.height = 500.f;

	m_Shape.left = pos.x;
	m_Shape.bottom = pos.y;

	if (m_BulletType == BulletType::normal)
	{
		m_Shape.width = m_pTexture->GetWidth() * m_Scale;
		m_Shape.height = m_pTexture->GetHeight() * m_Scale;
	}
	else
	{
		if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
			|| ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
		{
			m_Shape.width = m_pHeavyLaser->GetFrameWidth( );
			m_Shape.height = m_pHeavyLaser->GetFrameHeight( );
		}
		else
		{
			m_Shape.width = m_pHeavyLaserDiagonal->GetFrameWidth( );
			m_Shape.height = m_pHeavyLaserDiagonal->GetFrameHeight( );
		}
	}
}

Bullet::~Bullet()
{
	if (m_BulletType == BulletType::normal)
	{
		--m_AmountOfBullets;

		if (m_AmountOfBullets == 0)
		{
			if (m_pLaserTexture != nullptr)
			{
				delete m_pLaserTexture;
				m_pLaserTexture = nullptr;
			}

			if (m_pDiagonalLaserTexture)
			{
				delete m_pDiagonalLaserTexture;
				m_pDiagonalLaserTexture = nullptr;
			}
		}
	}
	else if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
		     || ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
	{
		delete m_pHeavyLaser;
	}
	else
	{
		delete m_pHeavyLaserDiagonal;
	}
}

void Bullet::Update(float elapsedSec)
{
	m_Shape.left += elapsedSec * m_Velocity.x;
	m_Shape.bottom += elapsedSec * m_Velocity.y;

	if (m_BulletType == BulletType::heavy)
	{
		if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
			|| ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
		{
			m_pHeavyLaser->Update(elapsedSec);
		}
		else
		{
			m_pHeavyLaserDiagonal->Update(elapsedSec);
		}
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
		
		if (m_BulletType == BulletType::normal)
		{
			m_pTexture->Draw( );
		}
		else if (m_BulletType == BulletType::heavy)
		{
			if ((m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0))
				|| ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0)
			{
				m_pHeavyLaser->Draw( );
			}
			else
			{
				m_pHeavyLaserDiagonal->Draw( );
			}
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