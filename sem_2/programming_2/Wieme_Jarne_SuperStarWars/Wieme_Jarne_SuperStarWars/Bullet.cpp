#include "pch.h"
#include "Bullet.h"
#include "Texture.h"
#include <iostream>

Bullet::Bullet(const Point2f& bottomLeftPoint, const Vector2f& velocity, const Bullet::BulletState& bulletState)
	:m_Shape{bottomLeftPoint.x, bottomLeftPoint.y, 0, 0}
	,m_Velocity{velocity}
	,m_BulletState{bulletState}
{
	if (m_BulletState == BulletState::vertical || m_BulletState == BulletState::horizontal)
	{
		m_pTexture = new Texture{ "Resources/Lasers/LaserRight.png" };
	}
	else
	{
		m_pTexture = new Texture{ "Resources/Lasers/LaserUpRight.png" };
	}

	m_Shape.width = m_pTexture->GetWidth();
	m_Shape.height = m_pTexture->GetHeight();
}

Bullet::~Bullet()
{
	delete m_pTexture;
}

void Bullet::Update(float elapsedSec)
{
	m_Shape.left += elapsedSec * m_Velocity.x;
	m_Shape.bottom += elapsedSec * m_Velocity.y;
}

void Bullet::Draw() const
{
	Rectf srcRect{};
	srcRect.width = m_pTexture->GetWidth() / 2.f;
	glPushMatrix();
		glTranslatef(m_Shape.left + m_Shape.width / 2.f, m_Shape.bottom + m_Shape.height / 2.f, 0);
		switch (m_BulletState)
		{
		case BulletState::vertical:
			glRotatef(90, 0.f, 0.f, 1.f);
			break;

		case BulletState::downDiagonal:
			glScalef(1.f, -1.f, 1.f);
			break;
		}
		glScalef(0.75f, 0.75f, 1.f);
		glTranslatef(-m_Shape.width * 2, 0.f, 0.f);
		m_pTexture->Draw(Rectf{}, srcRect);
	glPopMatrix();
}

bool Bullet::IsBulletInBoundaries(const Rectf& boundaries) const
{
	if (m_Shape.left < boundaries.left
		|| m_Shape.left > boundaries.left + boundaries.width
		|| m_Shape.bottom < boundaries.bottom
		|| m_Shape.bottom > boundaries.bottom + boundaries.height)
	{
		return false;
	}
	return true;
}