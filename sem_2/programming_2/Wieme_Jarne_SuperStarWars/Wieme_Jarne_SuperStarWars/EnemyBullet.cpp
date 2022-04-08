#include "pch.h"
#include "EnemyBullet.h"
#include "Texture.h"
#include "Vector2f.h"
#include "Sprite.h"
#include <iostream>

Sprite* EnemyBullet::m_pEnemyBullet{ nullptr };
int EnemyBullet::m_AmountOfEnemyBullets{ };

EnemyBullet::EnemyBullet(const Point2f& pos, const Vector2f& velocity, const float scale)
	: Bullet(pos, velocity, scale)
	, m_Acceleration{ 0.f, -981.f }
{
	++m_AmountOfEnemyBullets;

	if (m_pEnemyBullet == nullptr)
	{
		m_pEnemyBullet = new Sprite{"Resources/Lasers/EnemyLaser.png", Sprite::animType::loop, 2, 1, 1, 1};
	}

	m_Boundaries.left = m_StartPos.x - 250.f;
	m_Boundaries.bottom = m_StartPos.y - 250.f;
	m_Boundaries.width = 500.f;
	m_Boundaries.height = 500.f;
}

EnemyBullet::~EnemyBullet( )
{
	--m_AmountOfEnemyBullets;

	if (m_AmountOfEnemyBullets == 0)
	{
		delete m_pEnemyBullet;
		m_pEnemyBullet = nullptr;
	}
}

void EnemyBullet::Update(float elapsedSec)
{
	m_pEnemyBullet->Update(elapsedSec);

	m_Shape.left += elapsedSec * m_Velocity.x;
	m_Shape.bottom += elapsedSec * m_Velocity.y;

	m_Velocity.y += elapsedSec * m_Acceleration.y;
}

void EnemyBullet::Draw( ) const
{
	glPushMatrix( );
		glTranslatef(m_Shape.left, m_Shape.bottom, 0);
		glScalef(m_Scale, m_Scale, 1.f);
		m_pEnemyBullet->Draw( );
	glPopMatrix( );
}