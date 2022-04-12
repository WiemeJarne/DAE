#include "pch.h"
#include "BulletManager.h"
#include "Bullet.h"
#include "Enemy.h"
#include "utils.h"
#include "Level.h"
#include "ExplosionManager.h"
#include "Explosion.h"

BulletManager::BulletManager(const float bulletScale)
	: m_pBullets{ }
	, m_BulletScale{ bulletScale }
	, m_pExplosionManager{ new ExplosionManager{} }
{
}

BulletManager::~BulletManager( )
{
	for (Bullet* bullet : m_pBullets)
	{
		delete bullet;
	}

	m_pBullets.clear();

	delete m_pExplosionManager;
}

void BulletManager::UpdateBullets(const float elapsedSec, const Level& level)
{
	int index{};

	for (Bullet* bullet : m_pBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Update(elapsedSec);

			if (bullet->IsBulletOutOfBoundaries( ) || bullet->DidBulletHitGround(level))
			{
				float explosionScale{};

				if (bullet->GetBulletType() == Bullet::BulletType::normal)
				{
					explosionScale = 0.75f;
				}
				else
				{
					explosionScale = 1.25f;
				}

				m_pExplosionManager->AddExplosion(Point2f{ bullet->GetShape().left, bullet->GetShape().bottom }, DetermineExplosionSize(index), Explosion::ExplosionType::AvatarBulletExplosion);
				DeleteBullet(index);
			}
		}
		++index;
	}

	m_pExplosionManager->Update(elapsedSec);
}

void BulletManager::DrawBullets( ) const
{
	for (Bullet* bullet : m_pBullets)
	{
		if (bullet != nullptr)
		{
			bullet->Draw();
		}
	}

	m_pExplosionManager->Draw( );
}

void BulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, bool BlasterPowerUpActive)
{
	if (BlasterPowerUpActive)
	{
		m_pBullets.push_back(new Bullet{ bulletPos, bulletVelocity, m_BulletScale, Bullet::BulletType::heavy });
	}
	else
	{
		m_pBullets.push_back(new Bullet{bulletPos, bulletVelocity, m_BulletScale, Bullet::BulletType::normal });
	}
}

void BulletManager::HandleCollisionWithEnemies(std::vector<Enemy*> enemies)
{
	for (Enemy* enemy : enemies)
	{
		int index{};

		for (Bullet* bullet : m_pBullets)
		{
			if (utils::IsOverlapping(enemy->GetShape(), bullet->GetShape())
				&& enemy->GetHeath( ) > 0                                    )
			{
				int damage{ };

				m_pExplosionManager->AddExplosion(Point2f{ bullet->GetShape().left, bullet->GetShape().bottom }, DetermineExplosionSize(index), Explosion::ExplosionType::AvatarBulletExplosion);
				DeleteBullet(index);

				if (bullet->GetBulletType() == Bullet::BulletType::normal)
				{
					damage = 1;
				}
				else
				{
					damage = 2;
				}

				enemy->Hit(damage);
			}

			++index;
		}
	}
}

void BulletManager::DeleteBullet(int index)
{
	if (index < m_pBullets.size() && m_pBullets[index] != nullptr)
	{
		delete m_pBullets[index];

		m_pBullets[index] = m_pBullets.back();
		m_pBullets.pop_back();
	}
}

float BulletManager::DetermineExplosionSize(int index) const
{
	float explosionScale{};

	if (index < m_pBullets.size( ))
	{
		if (m_pBullets[index]->GetBulletType() == Bullet::BulletType::normal)
		{
			explosionScale = 0.75f;
		}
		else
		{
			explosionScale = 1.25f;
		}
	}

	return explosionScale;
}