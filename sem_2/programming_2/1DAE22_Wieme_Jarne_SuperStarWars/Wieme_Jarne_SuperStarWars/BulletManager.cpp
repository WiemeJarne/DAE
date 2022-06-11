#include "pch.h"
#include "BulletManager.h"
#include "Level.h"
#include "Enemy.h"
#include "ExplosionManager.h"
#include "utils.h"
#include "TextureManager.h"
#include "Avatar.h"
#include "SoundEffect.h"

BulletManager::BulletManager(TextureManager& pTextureManager)
	: m_pBullets{ }
	, m_pExplosionManager{ new ExplosionManager{} }
	, m_pTextureManager{ pTextureManager }
	, m_ExplosionSound{ new SoundEffect{"Resources/Sound/Explosion.mp3"} }
{
	m_ExplosionSound->SetVolume(15);
}

BulletManager::~BulletManager( )
{
	for (Bullet* bullet : m_pBullets)
	{
		delete bullet;
	}

	m_pBullets.clear();

	delete m_pExplosionManager;
	delete m_ExplosionSound;
}

void BulletManager::Update(float elapsedSec, const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar)
{
	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (m_pBullets[index] != nullptr)
		{
			m_pBullets[index]->Update(elapsedSec);

			if (m_pBullets[index]->IsOutOfBoundaries())
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

void BulletManager::AddBullet(const Point2f& bulletPos, const Vector2f& bulletVelocity, float scale, Bullet::Type bulletType)
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
	if (m_pBullets[bulletIndex]->GetType( ) == Bullet::Type::playerNormal)
	{
		return 0.75f;
	}
	else if (m_pBullets[bulletIndex]->GetType( ) == Bullet::Type::playerHeavy)
	{
		return 1.25f;
	}

	return 1.f;
}

Explosion::ExplosionType BulletManager::DetermineExplosionType(int bulletIndex) const
{
	if (m_pBullets[bulletIndex]->GetType() == Bullet::Type::playerNormal
		|| m_pBullets[bulletIndex]->GetType() == Bullet::Type::playerHeavy)
	{
		return Explosion::ExplosionType::AvatarBulletExplosion;
	}

	return Explosion::ExplosionType::EnemyBulletExplosion;
}

void BulletManager::HandleCollision(const Level& level, std::vector<Enemy*>& enemies, Avatar& avatar)
{
	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (m_pBullets[index]->GetType() == Bullet::Type::playerNormal
			|| m_pBullets[index]->GetType() == Bullet::Type::playerHeavy)
		{
			HandleCollisionWithEnemies(index, enemies);
		}
		else
		{
			HandleCollisionWithAvatar(index, avatar);
		}
	}

	HandleCollisionWithLevel(level);
}

void BulletManager::HandleCollisionWithEnemies(int bulletIndex, std::vector<Enemy*>& enemies)
{
	for (int index{}; index < enemies.size(); ++index)
	{
		if ( utils::IsOverlapping(enemies[index]->GetShape(), m_pBullets[bulletIndex]->GetShape())
			 && enemies[index]->GetHeath() > 0                                                     )
		{
			int damage{ };
			
			if (m_pBullets[bulletIndex]->GetType() == Bullet::Type::playerNormal)
			{
				damage = 1;
			}
			else
			{
				damage = 2;
			}

			m_ExplosionSound->Play(0);
			m_pExplosionManager->AddExplosion(DetermineExplosionPos(bulletIndex), DetermineExplosionSize(bulletIndex), Explosion::ExplosionType::AvatarBulletExplosion, m_pTextureManager);
			DeleteBullet(bulletIndex);

			enemies[index]->Hit(damage);
			return;
		}
	}
}

void BulletManager::HandleCollisionWithAvatar(int bulletIndex, Avatar& avatar)
{
	if (utils::IsOverlapping(avatar.GetShape(), m_pBullets[bulletIndex]->GetShape( )))
	{
		avatar.Hit( );
		m_ExplosionSound->Play(0);
		m_pExplosionManager->AddExplosion(DetermineExplosionPos(bulletIndex), 1.f, Explosion::ExplosionType::EnemyBulletExplosion, m_pTextureManager);
		DeleteBullet(bulletIndex);
	}
}

void BulletManager::HandleCollisionWithLevel(const Level& level)
{
	for (int index{}; index < m_pBullets.size(); ++index)
	{
		if (m_pBullets[index]->HitGround(level))
		{			
			m_ExplosionSound->Play(0);
			m_pExplosionManager->AddExplosion(DetermineExplosionPos(index), DetermineExplosionSize(index), DetermineExplosionType(index), m_pTextureManager);
			DeleteBullet(index);
		}
	}
}

Point2f BulletManager::DetermineExplosionPos(int bulletIndex)
{
	if (m_pBullets[bulletIndex]->GetVelocity().x > 0)
	{
		if (m_pBullets[bulletIndex]->GetVelocity().y > 0)
		{
			return Point2f{ m_pBullets[bulletIndex]->GetShape().left + m_pBullets[bulletIndex]->GetShape().width,
							m_pBullets[bulletIndex]->GetShape().bottom + m_pBullets[bulletIndex]->GetShape().height };
		}
		else if (m_pBullets[bulletIndex]->GetVelocity().y < 0)
		{
			return Point2f{ m_pBullets[bulletIndex]->GetShape().left + m_pBullets[bulletIndex]->GetShape().width / 2.f,
							m_pBullets[bulletIndex]->GetShape().bottom - m_pBullets[bulletIndex]->GetShape().height };
		}
		
		return Point2f{ m_pBullets[bulletIndex]->GetShape().left,
						m_pBullets[bulletIndex]->GetShape().bottom };
	}

	if (m_pBullets[bulletIndex]->GetVelocity().x < 0)
	{
		if (m_pBullets[bulletIndex]->GetVelocity().y > 0)
		{
			return Point2f{ m_pBullets[bulletIndex]->GetShape().left - m_pBullets[bulletIndex]->GetShape().width,
							m_pBullets[bulletIndex]->GetShape().bottom };
		}
		else if (m_pBullets[bulletIndex]->GetVelocity().y < 0)
		{
			return Point2f{ m_pBullets[bulletIndex]->GetShape().left - m_pBullets[bulletIndex]->GetShape().width,
							m_pBullets[bulletIndex]->GetShape().bottom - m_pBullets[bulletIndex]->GetShape().height };
		}

		return Point2f{ m_pBullets[bulletIndex]->GetShape().left,
						m_pBullets[bulletIndex]->GetShape().bottom };
	}

	if (m_pBullets[bulletIndex]->GetVelocity().y > 0)
	{
		return Point2f{ m_pBullets[bulletIndex]->GetShape().left - m_pBullets[bulletIndex]->GetShape().height * 2,
						m_pBullets[bulletIndex]->GetShape().bottom + m_pBullets[bulletIndex]->GetShape().width };
	}

	return Point2f{};
}