#include "pch.h"
#include "BulletManager.h"
#include "Level.h"
#include "Enemy.h"
#include "Bullet.h"
#include "ExplosionManager.h"
#include "utils.h"
#include "TextureManager.h"

BulletManager::BulletManager(TextureManager* pTextureManager)
	: m_pBullets{ }
	, m_pExplosionManager{ new ExplosionManager{} }
	, m_pTextureManager{ pTextureManager }
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

void BulletManager::Update(float elapsedSec, const Level& level)
{
	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (m_pBullets[index] != nullptr)
		{
			m_pBullets[index]->Update(elapsedSec);

			if (m_pBullets[index]->IsBulletOutOfBoundaries() || m_pBullets[index]->DidBulletHitGround(level))
			{
				float explosionScale{};

				if (m_pBullets[index]->GetBulletType() == Bullet::BulletType::playerNormal)
				{
					explosionScale = 0.75f;
				}
				else
				{
					explosionScale = 1.25f;
				}

				m_pExplosionManager->AddExplosion(Point2f{ m_pBullets[index]->GetShape().left, m_pBullets[index]->GetShape().bottom }, DetermineExplosionSize(index), Explosion::ExplosionType::AvatarBulletExplosion, m_pTextureManager);
				DeleteBullet(index);
			}
		}
	}

	m_pExplosionManager->Update(elapsedSec);
}

void BulletManager::Draw( ) const
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

void BulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, bool BlasterPowerUpActive)
{
	if (BlasterPowerUpActive)
	{
		m_pBullets.push_back(new Bullet{ bulletPos, bulletVelocity, m_pTextureManager, scale, Bullet::BulletType::playerHeavy });
	}
	else
	{
		m_pBullets.push_back(new Bullet{bulletPos, bulletVelocity, m_pTextureManager, scale, Bullet::BulletType::playerNormal });
	}
}

void BulletManager::HandleCollisionWithEnemies(std::vector<Enemy*> enemies)
{
	for (int index{}; index < enemies.size(); ++index)
	{
		for (Bullet* bullet : m_pBullets)
		{
			if (utils::IsOverlapping(enemies[index]->GetShape(), bullet->GetShape())
				&& enemies[index]->GetHeath( ) > 0                                    )
			{
				int damage{ };

				m_pExplosionManager->AddExplosion(Point2f{ bullet->GetShape().left, bullet->GetShape().bottom }, DetermineExplosionSize(index), Explosion::ExplosionType::AvatarBulletExplosion, m_pTextureManager);
				DeleteBullet(index);

				if (bullet->GetBulletType() == Bullet::BulletType::playerNormal)
				{
					damage = 1;
				}
				else
				{
					damage = 2;
				}

				enemies[index]->Hit(damage);
			}
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
		if (m_pBullets[index]->GetBulletType() == Bullet::BulletType::playerNormal)
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