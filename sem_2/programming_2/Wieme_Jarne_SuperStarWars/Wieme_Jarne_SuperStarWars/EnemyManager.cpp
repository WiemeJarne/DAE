#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "Level.h"
#include "Avatar.h"
#include "FlyingEnemy.h"
#include "WormEnemy.h"
#include "Boss.h"

EnemyManager::EnemyManager( )
{
}

EnemyManager::~EnemyManager( )
{
	for (Enemy* enemy : m_pEnemies)
	{
		delete enemy;
	}

	m_pEnemies.clear();
}

void EnemyManager::Update(float elapsecSec, const Level& level, Avatar& avatar)
{
	int index{};

	for (Enemy* enemy : m_pEnemies)
	{
		enemy->Update(elapsecSec, level, avatar);

		++index;
	}
}

void EnemyManager::Draw( ) const
{
	for (Enemy* enemy : m_pEnemies)
	{
		enemy->Draw( );
	}
}

void EnemyManager::AddEnemy(const Point2f& bottomLeftStartPoint, float scale, int health, EnemyKind enemyKind)
{
	switch (enemyKind)
	{
	case EnemyKind::normal:
		m_pEnemies.push_back(new Enemy{ bottomLeftStartPoint, scale, health });
		break;

	case EnemyKind::flying:
		m_pEnemies.push_back(new FlyingEnemy{ bottomLeftStartPoint, scale, health });
		break;

	case EnemyKind::worm:
		m_pEnemies.push_back(new WormEnemy{ bottomLeftStartPoint, scale, health });
		break;

	case EnemyKind::boss:
		m_pEnemies.push_back(new Boss{ bottomLeftStartPoint, scale, health });
		break;
	}
}

void EnemyManager::DeleteEnemy(const int index)
{
	delete m_pEnemies[index];

	m_pEnemies[index] = m_pEnemies.back();
	m_pEnemies.pop_back();
}

std::vector<Enemy*> EnemyManager::GetEnemies()
{
	return m_pEnemies;
}