#include "pch.h"
#include "BulletManager.h"
#include "Level.h"
#include "Enemy.h"
#include "ExplosionManager.h"
#include "utils.h"
#include "TextureManager.h"
#include "Avatar.h"

BulletManager::BulletManager(TextureManager& pTextureManager)
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

void BulletManager::Update(float elapsedSec, const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar)
{
	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (m_pBullets[index] != nullptr)
		{
			m_pBullets[index]->Update(elapsedSec);

			if (m_pBullets[index]->IsBulletOutOfBoundaries())
			{
				BulletIsOutOfBoundaries(index);
			}
		}
	}

	m_pExplosionManager->Update(elapsedSec);
	HandleCollision(level, enemies, avatar);
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

void BulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, Bullet::BulletType bulletType)
{
	m_pBullets.push_back(new Bullet{ bulletPos, bulletVelocity, m_pTextureManager, scale, bulletType });
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

void BulletManager::BulletIsOutOfBoundaries(int bulletIndex)
{
	Point2f bulletPos{ m_pBullets[bulletIndex]->GetShape().left,
					   m_pBullets[bulletIndex]->GetShape().bottom };

	m_pExplosionManager->AddExplosion(bulletPos, DetermineExplosionSize(bulletIndex), DetermineExplosionType(bulletIndex), m_pTextureManager);
	DeleteBullet(bulletIndex);
}

float BulletManager::DetermineExplosionSize(int bulletIndex) const
{
	if (m_pBullets[bulletIndex]->GetBulletType( ) == Bullet::BulletType::playerNormal)
	{
		return 0.75f;
	}
	else if (m_pBullets[bulletIndex]->GetBulletType( ) == Bullet::BulletType::playerHeavy)
	{
		return 1.25f;
	}

	return 1.f;
}

Explosion::ExplosionType BulletManager::DetermineExplosionType(int bulletIndex) const
{
	if (m_pBullets[bulletIndex]->GetBulletType() == Bullet::BulletType::playerNormal
		|| m_pBullets[bulletIndex]->GetBulletType() == Bullet::BulletType::playerHeavy)
	{
		return Explosion::ExplosionType::AvatarBulletExplosion;
	}

	return Explosion::ExplosionType::EnemyBulletExplosion;
}

void BulletManager::HandleCollision(const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar)
{
	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (m_pBullets[index]->GetBulletType() == Bullet::BulletType::playerNormal
			|| m_pBullets[index]->GetBulletType() == Bullet::BulletType::playerHeavy)
		{
			HandleCollisionWithAvatar(index, avatar);
		}
		else
		{
			HandleCollisionWithEnemies(index, enemies);
		}

		if (m_pBullets[index]->DidBulletHitGround(level))
		{
			Point2f bulletPos{ m_pBullets[index]->GetShape().left,
							   m_pBullets[index]->GetShape().bottom };

			m_pExplosionManager->AddExplosion(bulletPos, DetermineExplosionSize(index), DetermineExplosionType(index), m_pTextureManager);
		}
	}
}

void BulletManager::HandleCollisionWithEnemies(int bulletIndex, std::vector<Enemy*>& enemies)
{
	for (int index{}; index < enemies.size(); ++index)
	{
		if ( utils::IsOverlapping(enemies[index]->GetShape(), m_pBullets[index]->GetShape())
			 && enemies[index]->GetHeath() > 0                                               )
		{
			int damage{ };
			Point2f bulletPos{ m_pBullets[bulletIndex]->GetShape().left,
							   m_pBullets[bulletIndex]->GetShape().bottom };

			m_pExplosionManager->AddExplosion(bulletPos, DetermineExplosionSize(bulletIndex), Explosion::ExplosionType::AvatarBulletExplosion, m_pTextureManager);
			DeleteBullet(index);

			if (m_pBullets[index]->GetBulletType() == Bullet::BulletType::playerNormal)
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

void BulletManager::HandleCollisionWithAvatar(int bulletIndex, Avatar& avatar)
{
	if (utils::IsOverlapping(avatar.GetShape(), m_pBullets[bulletIndex]->GetShape( )))
	{
		Point2f bulletPos{ m_pBullets[bulletIndex]->GetShape().left,
						   m_pBullets[bulletIndex]->GetShape().bottom };
		avatar.Hit( );
		m_pExplosionManager->AddExplosion(bulletPos, 1.f, Explosion::ExplosionType::EnemyBulletExplosion, m_pTextureManager);
	}
}