#include "pch.h"
#include "EnemyBulletManager.h"
#include "Avatar.h"
#include "ExplosionManager.h"
#include "utils.h"

EnemyBulletManager::EnemyBulletManager( )
	: BulletManager( )
{
}

void EnemyBulletManager::Update(float elapsedSec, Avatar& avatar, const Level& level)
{
	int index{};

	for (Bullet* enemyBullet : m_pBullets)
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

	HandleCollisionWithAvatar(avatar);
}

void EnemyBulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, EnemyBullet::BulletType bulletType)
{
	m_pBullets.push_back(new EnemyBullet{ bulletPos, bulletVelocity, scale, bulletType });
}

void EnemyBulletManager::HandleCollisionWithAvatar(Avatar& avatar)
{
	int index{};

	for (Bullet* enemyBullet : m_pBullets)
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

void EnemyBulletManager::DeleteAllEnemyBullets( )
{
	for (Bullet* enemyBullet : m_pBullets)
	{
		if (enemyBullet != nullptr)
		{
			delete enemyBullet;
		}
	}

	for (Bullet* enemyBullet : m_pBullets)
	{
		m_pBullets.pop_back( );
	}

	m_pBullets.clear( );
}