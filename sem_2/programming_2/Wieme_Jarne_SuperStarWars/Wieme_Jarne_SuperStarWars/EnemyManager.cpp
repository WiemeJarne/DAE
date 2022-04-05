#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "Level.h"
#include <iostream>

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

void EnemyManager::Update(float elapsecSec, const Level& level)
{
	int index{};

	for (Enemy* enemy : m_pEnemies)
	{
		enemy->Update(elapsecSec, level);

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

void EnemyManager::AddEnemy(const Point2f& bottomLeftStartPoint, float scale, int health)
{
	m_pEnemies.push_back(new Enemy{ bottomLeftStartPoint, scale, health });
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