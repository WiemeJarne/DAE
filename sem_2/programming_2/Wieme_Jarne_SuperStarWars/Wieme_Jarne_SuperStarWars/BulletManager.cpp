#include "pch.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "EnemyManager.h"
#include "utils.h"
#include <iostream>

BulletManager::BulletManager(const float bulletScale)
	:m_pBullets{}
	,m_BulletScale{bulletScale}
{
}

BulletManager::~BulletManager()
{
	for (Bullet* bullet : m_pBullets)
	{
		delete bullet;
	}

	m_pBullets.clear();
}

void BulletManager::UpdateBullets(const float elapsedSec)
{
	int index{};

	for (Bullet* bullet : m_pBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Update(elapsedSec);

			if (bullet->IsBulletOutOfBoundaries())
			{
				DeleteBullet(index);
			}
		}
		++index;
	}
}

void BulletManager::DrawBullets() const
{
	for (Bullet* bullet : m_pBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Draw();
		}
	}
}

void BulletManager::DeleteBullet(const int index)
{
	if (m_pBullets[index] != nullptr)
	{
		delete m_pBullets[index];

		m_pBullets[index] = m_pBullets.back();
		m_pBullets.pop_back();
	}
}

void BulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity)
{
	m_pBullets.push_back(new Bullet{bulletPos, bulletVelocity, m_BulletScale });
}

void BulletManager::HandleCollision(std::vector<Enemy*> enemies)
{
	for (Enemy* enemy : enemies)
	{
		int index{};

		for (Bullet* bullet : m_pBullets)
		{
			if (utils::IsOverlapping(enemy->GetShape(), bullet->GetShape()))
			{
				DeleteBullet(index);
				enemy->Hit();
			}

			++index;
		}
	}
}