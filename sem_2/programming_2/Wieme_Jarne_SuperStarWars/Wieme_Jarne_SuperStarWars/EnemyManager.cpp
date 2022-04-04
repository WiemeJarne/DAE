#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"

EnemyManager::EnemyManager( )
{
}

EnemyManager::~EnemyManager()
{
	for (Enemy* enemy : m_Enemies)
	{
		delete enemy;
	}
}