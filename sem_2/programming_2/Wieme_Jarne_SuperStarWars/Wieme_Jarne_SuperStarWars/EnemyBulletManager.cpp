#include "pch.h"
#include "EnemyBulletManager.h"
#include "EnemyBullet.h"
#include "utils.h"
#include "Avatar.h"

EnemyBulletManager::EnemyBulletManager(const float bulletScale)
	: m_pEnemyBullets{ }
	, m_BulletScale{ bulletScale }
{
}

EnemyBulletManager::~EnemyBulletManager( )
{
	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		delete enemyBullet;
	}

	m_pEnemyBullets.clear();
}

void EnemyBulletManager::UpdateBullets(const float elapsedSec, Avatar& avatar)
{
	int index{};

	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		if (enemyBullet != nullptr)
		{
			enemyBullet->Update(elapsedSec);

			if (enemyBullet->IsBulletOutOfBoundaries())
			{
				DeleteBullet(index);
			}
		}
		++index;
	}

	HandleCollision(avatar);
}

void EnemyBulletManager::DrawBullets( ) const
{
	for (EnemyBullet* bullet : m_pEnemyBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Draw();
		}
	}
}

void EnemyBulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity)
{
	m_pEnemyBullets.push_back(new EnemyBullet{ bulletPos, bulletVelocity, m_BulletScale });
}

void EnemyBulletManager::HandleCollision(Avatar& avatar)
{
	int index{};

	for (EnemyBullet* enemyBullet : m_pEnemyBullets)
	{
		if (utils::IsOverlapping(avatar.GetShape( ), enemyBullet->GetShape( )))
		{
			avatar.Hit();
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