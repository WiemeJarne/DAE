#include "pch.h"
#include "EnemyBulletManager.h"
#include "Avatar.h"
#include "ExplosionManager.h"
#include "utils.h"
#include "TextureManager.h"

EnemyBulletManager::EnemyBulletManager(TextureManager& pTextureManager)
	: BulletManager(pTextureManager)
{
}

void EnemyBulletManager::Update(float elapsedSec, Avatar& avatar, const Level& level)
{
	int index{};

	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (m_pBullets[index] != nullptr)
		{
			m_pBullets[index]->Update(elapsedSec);

			if (m_pBullets[index]->IsOutOfBoundaries( ) || m_pBullets[index]->HitGround(level))
			{
				m_pExplosionManager->AddExplosion(Point2f{ m_pBullets[index]->GetShape().left, m_pBullets[index]->GetShape().bottom }, 1.f, Explosion::ExplosionType::EnemyBulletExplosion, m_pTextureManager);
				DeleteBullet(index);
			}
		}
	}
	
	m_pExplosionManager->Update(elapsedSec);

	HandleCollisionWithAvatar(avatar);
}

void EnemyBulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, Bullet::Type bulletType)
{
	m_pBullets.push_back(new Bullet{ bulletPos, bulletVelocity, m_pTextureManager, scale, bulletType });
}

void EnemyBulletManager::HandleCollisionWithAvatar(Avatar& avatar)
{
	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (utils::IsOverlapping(avatar.GetShape( ), m_pBullets[index]->GetShape()))
		{
			avatar.Hit( );
			m_pExplosionManager->AddExplosion(Point2f{ m_pBullets[index]->GetShape().left, m_pBullets[index]->GetShape().bottom }, 1.f, Explosion::ExplosionType::EnemyBulletExplosion, m_pTextureManager);
			DeleteBullet(index);
		}
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