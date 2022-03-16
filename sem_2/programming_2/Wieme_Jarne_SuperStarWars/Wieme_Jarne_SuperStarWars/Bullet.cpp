#include "pch.h"
#include "Bullet.h"
#include "Texture.h"
#include <iostream>

Texture* Bullet::m_pLaserTexture{ nullptr };
Texture* Bullet::m_pDiagonalLaserTexture{ nullptr };
int Bullet::m_AmountOfBullets{};

Bullet::Bullet(const Rectf& avatarShape, const Vector2f& velocity, const Bullet::BulletState& bulletState, const int direction, const float scale)
	:m_Shape{avatarShape}
	,m_AvatarShape{avatarShape}
	,m_Velocity{velocity}
	,m_BulletState{bulletState}
	,m_Direction{direction}
	,m_Scale{scale}
	,m_StartPos{avatarShape.left, avatarShape.bottom}
{
	++m_AmountOfBullets;
	std::cout << m_AmountOfBullets << "\n";
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

	if (m_BulletState == BulletState::vertical || m_BulletState == BulletState::horizontal)
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
	m_Shape.left += elapsedSec * m_Velocity.x * m_Direction;

	switch (m_BulletState)
	{
	case BulletState::vertical:
	case BulletState::upDiagonal:
	case BulletState::downDiagonal:
		m_Shape.bottom += elapsedSec * m_Velocity.y;
		break;

	default:
		m_Shape.bottom += elapsedSec * m_Velocity.y * m_Direction;
		break;
	}
}

void Bullet::Draw() const
{
	glPushMatrix();
		glTranslatef( m_Shape.left + m_AvatarShape.width / 2.f - m_Shape.width / 2.f,
					  m_Shape.bottom + m_AvatarShape.bottom / 2.f - m_Shape.height / 2.f, 0 );

		switch (m_BulletState)
		{
		case BulletState::vertical:

			glRotatef(90, 0.f, 0.f, 1.f);

			glScalef(m_Scale, m_Scale, 1.f);

			if (m_Direction == 1)
			{
				glTranslatef(m_AvatarShape.height, -m_AvatarShape.width * 1.4f, 0.f);
			}
			else
			{
				glTranslatef(m_AvatarShape.height, -m_AvatarShape.width * 1.4f, 0.f);
			}

			break;

		case BulletState::upDiagonal:

			glScalef(m_Scale * m_Direction, m_Scale, 1.f);

			if (m_Direction == 1)
			{
				glTranslatef(m_AvatarShape.width, m_AvatarShape.height * 1.2f, 0.f);
			}
			else
			{
				glTranslatef(-m_AvatarShape.width / 1.2f, m_AvatarShape.height * 1.2f, 0.f);
			}

			break;

		case BulletState::downDiagonal:

			glScalef(m_Scale * m_Direction, -m_Scale, 1.f);

			if (m_Direction == 1)
			{
				glTranslatef(m_AvatarShape.width, -m_AvatarShape.height, 0.f);
			}
			else
			{
				glTranslatef(-m_AvatarShape.width / 1.5f, -m_AvatarShape.height, 0.f);
			}

			break;

		case BulletState::horizontal:

			glScalef(m_Scale * m_Direction, m_Scale, 1.f);

			if (m_Direction == 1)
			{
				glTranslatef(m_AvatarShape.width, m_AvatarShape.height / 1.5f, 0.f);
			}
			else
			{
				glTranslatef(-m_AvatarShape.width / 2.f, m_AvatarShape.height / 1.5f, 0.f);
			}

			break;
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