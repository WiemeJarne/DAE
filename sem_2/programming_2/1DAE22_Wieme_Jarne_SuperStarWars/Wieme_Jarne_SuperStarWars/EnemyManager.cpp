#include "pch.h"
#include "EnemyManager.h"
#include "Level.h"
#include "Avatar.h"
#include "Scorpion.h"
#include "FlyingEnemy.h"
#include "WormEnemy.h"
#include "JumpingEnemy.h"
#include "PitMonster.h"

EnemyManager::EnemyManager( )
{
}

EnemyManager::~EnemyManager( )
{
	for (Enemy* enemy : m_pEnemies)
	{
		if (enemy != nullptr)
		{
			delete enemy;;
		}
	}

	m_pEnemies.clear();
}

void EnemyManager::Update(float elapsecSec, const Level& level, Avatar& avatar)
{
	for (int index{}; index < m_pEnemies.size(); ++index)
	{
		m_pEnemies[index]->Update(elapsecSec, level, avatar);
	}
}

void EnemyManager::Draw( ) const
{
	for (Enemy* enemy : m_pEnemies)
	{
		enemy->Draw( );
	}
}

void EnemyManager::AddEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, EnemyKind enemyKind, TextureManager& textureManager, BulletManager& bulletManager)
{
	switch (enemyKind)
	{
	case EnemyKind::Scorpion:
		m_pEnemies.push_back(new Scorpion{ bottomLeftStartPoint, scale, health, textureManager, bulletManager });
		break;

	case EnemyKind::flying:
		m_pEnemies.push_back(new FlyingEnemy{ bottomLeftStartPoint, scale, health, textureManager });
		break;

	case EnemyKind::worm:
		m_pEnemies.push_back(new WormEnemy{ bottomLeftStartPoint, scale, health, textureManager });
		break;

	case EnemyKind::jumping:
		m_pEnemies.push_back(new JumpingEnemy{ bottomLeftStartPoint, scale, health, textureManager });

	case EnemyKind::boss:
		m_pEnemies.push_back(new PitMonster{ bottomLeftStartPoint, scale, health, textureManager, bulletManager });
		break;
	}
}

std::vector<Enemy*>& EnemyManager::GetEnemies( )
{
	return m_pEnemies;
}

void EnemyManager::DeleteEnemy(int index)
{
	delete m_pEnemies[index];

	m_pEnemies[index] = m_pEnemies.back();
	m_pEnemies.pop_back();
}