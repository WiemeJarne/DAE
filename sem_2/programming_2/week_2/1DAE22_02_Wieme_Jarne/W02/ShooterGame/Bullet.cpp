#include "pch.h"
#include "Bullet.h"
#include "Enemy.h"

Bullet::Bullet()
	:m_Center{ }
	,m_Boundaries{0.f, 0.f, 500.f, 500.f}
	,m_Velocity{ 0.f, 35.f }
	,m_IsActivated{ }
{
	ChangeBulletRect(5.f, 25.f);
}

Bullet::Bullet(float width, float height)
	:Bullet()
{
	ChangeBulletRect(width, height);
}

void Bullet::Update(float elapsedSec, std::vector<Enemy*>& pEnemies)
{
	if (m_IsActivated)
	{
		if (std::signbit(elapsedSec) == 1) elapsedSec *= -1;
		m_Center.x += elapsedSec * m_Velocity.x;
		m_Center.y += elapsedSec * m_Velocity.y;

		ChangeBulletRect(m_BulletRect.width, m_BulletRect.height);

		CheckEnemiesHit(pEnemies);

		CheckBoundaries();
	}
}

void Bullet::Draw() const
{
	if (m_IsActivated)
	{
		Color4f red{ 1.f, 0.f, 0.f, 1.f };
		utils::SetColor(red);
		utils::FillRect(m_BulletRect);
	}
}

void Bullet::Shoot(const Point2f& center, const Vector2f& velocity)
{
	if (m_IsActivated == false)
	{
		m_Center = center;
		m_Velocity = velocity;
		m_IsActivated = true;

		ChangeBulletRect(m_BulletRect.width, m_BulletRect.height);
	}
}

void Bullet::SetDimensions(float width, float height)
{
	ChangeBulletRect(width, height);
}

void Bullet::SetBoundaries(const Rectf& boundaries)
{
	m_Boundaries = boundaries;
}

void Bullet::CheckBoundaries( )
{
	if (m_BulletRect.bottom > m_Boundaries.bottom + m_Boundaries.height) m_IsActivated = false;
}

void Bullet::ChangeBulletRect(float width, float height)
{
	m_BulletRect.width = width;
	m_BulletRect.height = height;
	m_BulletRect.left = m_Center.x - m_BulletRect.width / 2.f;
	m_BulletRect.bottom = m_Center.y - m_BulletRect.height / 2.f;
}

void Bullet::CheckEnemiesHit(std::vector<Enemy*> pEnemies)
{
	for (Enemy* enemy : pEnemies)
	{
		if (m_IsActivated)
		{
			if (enemy->DoHitTest(m_BulletRect)) m_IsActivated = false;
		}
	}
}