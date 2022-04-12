#include "pch.h"
#include "EnemyBulletManager.h"
#include "EnemyBullet.h"
#include "utils.h"
#include "Avatar.h"
#include "ExplosionManager.h"
#include "Explosion.h"

EnemyBulletManager::EnemyBulletManager(const float bulletScale)
	: m_pEnemyBullets{ }
	, m_BulletScale{ bulletScale }
	, m_pExplosionManager{ new ExplosionManager{} }
{
}

EnemyBulletManager::~EnemyBulletManager( )
{
	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		delete enemyBullet;
	}

	m_pEnemyBullets.clear( );

	delete m_pExplosionManager;
}

void EnemyBulletManager::UpdateBullets(const float elapsedSec, Avatar& avatar, const Level& level)
{
	int index{};

	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		if (enemyBullet != nullptr)
		{
			enemyBullet->Update(elapsedSec);

			if (enemyBullet->IsBulletOutOfBoundaries( ) || enemyBullet->DidBulletHitGround(level))
			{
				m_pExplosionManager->AddExplosion(Point2f{ enemyBullet->GetShape().left, enemyBullet->GetShape().bottom }, 1.f, Explosion::ExplosionType::EnemyBulletExplosion);
				DeleteBullet(index);
			}
		}
		++index;
	}
	
	m_pExplosionManager->Update(elapsedSec);

	HandleCollision(avatar);
}

void EnemyBulletManager::Draw( ) const
{
	for (EnemyBullet* bullet : m_pEnemyBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Draw();
		}
	}

	m_pExplosionManager->Draw( );
}

void EnemyBulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, EnemyBullet::BulletType bulletType)
{
	m_pEnemyBullets.push_back(new EnemyBullet{ bulletPos, bulletVelocity, m_BulletScale, bulletType });
}

void EnemyBulletManager::HandleCollision(Avatar& avatar)
{
	int index{};

	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		if (utils::IsOverlapping(avatar.GetShape( ), enemyBullet->GetShape( )))
		{
			avatar.Hit( );
			m_pExplosionManager->AddExplosion(Point2f{ enemyBullet->GetShape().left, enemyBullet->GetShape().bottom }, 1.f, Explosion::ExplosionType::EnemyBulletExplosion);
			DeleteBullet(index);
		}

		++index;
	}
}

void EnemyBulletManager::DeleteBullet(const int index)
{
	if (m_pEnemyBullets[index] != nullptr && m_pEnemyBullets.size() > 0)
	{
		delete m_pEnemyBullets[index];

		m_pEnemyBullets[index] = m_pEnemyBullets.back();
		m_pEnemyBullets.pop_back();
	}
}

void EnemyBulletManager::DeleteAllEnemyBullets( )
{
	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		if (enemyBullet != nullptr)
		{
			delete enemyBullet;
		}
	}

	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		m_pEnemyBullets.pop_back( );
	}

	m_pEnemyBullets.clear( );
}