#include "pch.h"
#include "EnemyBullet.h"
#include "Sprite.h"

EnemyBullet::EnemyBullet(const Point2f& pos, const Vector2f& velocity, float scale, BulletType bulletType)
	: Bullet(pos, velocity, scale)
	, m_Acceleration{ 0.f, -981.f }
	, m_BulletType{ bulletType }
	, m_pEnemyBullet{ }
	, m_pBossBullet{ }
{
	if (m_BulletType == BulletType::Enemy)
	{
		m_pEnemyBullet = new Sprite{ "Resources/Lasers/EnemyLaser.png", Sprite::AnimType::loop, 2, 1, 10.f };
	}
	else
	{
		m_pBossBullet = new Sprite{ "Resources/PitMonster/AttackRock.png", Sprite::AnimType::loop, 4, 1, 2.f };
	}
	
	m_Boundaries.left = m_StartPos.x - 250.f;
	m_Boundaries.bottom = m_StartPos.y - 250.f;
	m_Boundaries.width = 500.f;
	m_Boundaries.height = 500.f;
}

EnemyBullet::~EnemyBullet( )
{
	if (m_BulletType == BulletType::Enemy)
	{
		delete m_pEnemyBullet;
	}
	else
	{
		delete m_pBossBullet;
	}
}

void EnemyBullet::Update(float elapsedSec)
{
	if (m_BulletType == BulletType::Enemy)
	{
		m_pEnemyBullet->Update(elapsedSec);
	}
	else
	{
		m_pBossBullet->Update(elapsedSec);
	}

	m_Shape.left += elapsedSec * m_Velocity.x;
	m_Shape.bottom += elapsedSec * m_Velocity.y;

	m_Velocity.y += elapsedSec * m_Acceleration.y;
}

void EnemyBullet::Draw( ) const
{
	glPushMatrix( );
		glTranslatef(m_Shape.left, m_Shape.bottom, 0);
		glScalef(m_Scale, m_Scale, 1.f);
		if (m_BulletType == BulletType::Enemy)
		{
			m_pEnemyBullet->Draw( );
		}
		else
		{
			m_pBossBullet->Draw( );
		}
	glPopMatrix( );
}