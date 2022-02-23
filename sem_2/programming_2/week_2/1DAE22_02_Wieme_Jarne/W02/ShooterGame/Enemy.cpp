#include "pch.h"
#include "Enemy.h"
#include "utils.h"

Enemy::Enemy()
	:m_Center{}
	,m_IsDead{}
{
	m_EnemyRect.width = 25.f;
	m_EnemyRect.height = 25.f;
	m_EnemyRect.left = m_Center.x - m_EnemyRect.width / 2.f;
	m_EnemyRect.bottom = m_Center.y - m_EnemyRect.height / 2.f;
}

Enemy::Enemy(const Point2f& center, float width, float height)
	:m_Center{center}
	,m_IsDead{}
{
	m_EnemyRect.width = width;
	m_EnemyRect.height = height;
	m_EnemyRect.left = m_Center.x - m_EnemyRect.width / 2.f;
	m_EnemyRect.bottom = m_Center.y - m_EnemyRect.height / 2.f;
}

void Enemy::Draw() const
{
	if (!m_IsDead)
	{
	Color4f red{ 1.f, 0.f, 0.f, 1.f };
	utils::SetColor(red);
	const float lineWidth{ 4.f };
	utils::DrawRect(m_EnemyRect, lineWidth);
	}
}

void Enemy::SetCenter(const Point2f& center)
{
	m_Center = center;
	m_EnemyRect.left = m_Center.x - m_EnemyRect.width / 2.f;
	m_EnemyRect.bottom = m_Center.y - m_EnemyRect.height / 2.f;
}

void Enemy::SetDimensions(float width, float height)
{
	m_EnemyRect.width = width;
	m_EnemyRect.height = height;
	m_EnemyRect.left = m_Center.x - m_EnemyRect.width / 2.f;
	m_EnemyRect.bottom = m_Center.y - m_EnemyRect.height / 2.f;
}

bool Enemy::DoHitTest(const Rectf& other)
{
	if (utils::IsOverlapping(m_EnemyRect, other))
	{
		m_IsDead = true;
		return true;
	}
	return false;
}

bool Enemy::IsDead()
{
	return m_IsDead;
}