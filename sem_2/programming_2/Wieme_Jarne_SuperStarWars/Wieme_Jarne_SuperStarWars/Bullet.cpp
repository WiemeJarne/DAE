#include "pch.h"
#include "Bullet.h"
#include "Texture.h"
#include <iostream>

Texture* Bullet::m_pLaserTexture{ nullptr };
Texture* Bullet::m_pDiagonalLaserTexture{ nullptr };
int Bullet::m_AmountOfBullets{};

Bullet::Bullet(const Point2f& pos, const Vector2f& velocity, const float scale)
	:m_Shape{pos.x, pos.y, 0.f, 0.f}
	,m_Velocity{velocity}
	,m_Scale{scale}
	,m_StartPos{pos}
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

	m_Boundaries.left = m_StartPos.x - 250.f;
	m_Boundaries.bottom = m_StartPos.y - 250.f;
	m_Boundaries.width = 500.f;
	m_Boundaries.height = 500.f;

	if (    (m_Velocity.x == 0 && (m_Velocity.y < 0 || m_Velocity.y > 0)) 
		 || ((m_Velocity.x > 0 || m_Velocity.x < 0)) && m_Velocity.y == 0 )
	{
		m_pTexture = m_pLaserTexture;
	}
	else
	{
		m_pTexture = m_pDiagonalLaserTexture;
	}

	m_Shape.width = m_pTexture->GetWidth();
	m_Shape.height = m_pTexture->GetHeight();
}

Bullet::~Bullet()
{
	--m_AmountOfBullets;

	if (m_AmountOfBullets == 0)
	{
		delete m_pLaserTexture;
		m_pLaserTexture = nullptr;

		delete m_pDiagonalLaserTexture;
		m_pDiagonalLaserTexture = nullptr;
	}
}

void Bullet::Update(float elapsedSec)
{
	m_Shape.left += elapsedSec * m_Velocity.x;
	m_Shape.bottom += elapsedSec * m_Velocity.y;
}

void Bullet::Draw() const
{
	glPushMatrix();

		glTranslatef(m_Shape.left + m_Shape.width / 2.f, m_Shape.bottom + m_Shape.height / 2.f, 0);

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

		m_pTexture->Draw();

	glPopMatrix();
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