#include "pch.h"
#include "EnemyManager.h"
#include "Level.h"
#include "Avatar.h"
#include "Scorpion.h"
#include "FlyingEnemy.h"
#include "WormEnemy.h"
#include "JumpingEnemy.h"
#include "PitMonster.h"

EnemyManager::EnemyManager(TextureManager& textureManager, BulletManager& bulletManager)
{
	InitializeEnemies(textureManager, bulletManager);
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

void EnemyManager::InitializeEnemies(TextureManager& textureManager, BulletManager& bulletManager)
{
	const float ScorpionSize{ 1.2f };
	const float flyingEnemySize{ 1.f };
	const float wormEnemySize{ 1.f };
	const float jumpingEnemySize{ 1.f };

	int ScorpionHealth{ 3 };
	int flyingEnemyHealth{ 4 };
	int wormEnemyHealth{ 6 };
	int jumpingEnemyHealth{ 6 };

	m_pEnemies.push_back(new Scorpion{ Point2f{76.f,84.f}, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 76.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 325.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 420.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 680.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 800.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 900.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	ScorpionHealth += 1;
	flyingEnemyHealth += 1;
	m_pEnemies.push_back(new Scorpion{ Point2f{ 1140.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 1320.f, 84.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 1200.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager, });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 1450.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 1530.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	ScorpionHealth += 1;
	flyingEnemyHealth += 1;
	m_pEnemies.push_back(new Scorpion{ Point2f{ 1800.f, 80.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 1860.f, 120.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new WormEnemy{ Point2f{ 1950.f, 260.f }, wormEnemySize, wormEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 2050.f, 140.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	ScorpionHealth += 1;
	flyingEnemyHealth += 1;
	m_pEnemies.push_back(new Scorpion{ Point2f{ 2140.f, 70.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 2332.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 2490.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 2500.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 2540.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 2620.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 2735.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	ScorpionHealth += 2;
	flyingEnemyHealth += 2;
	wormEnemyHealth += 4;
	jumpingEnemyHealth += 2;
	m_pEnemies.push_back(new WormEnemy{ Point2f{ 2900.f, 40.f }, wormEnemySize, wormEnemyHealth, textureManager });
	m_pEnemies.push_back(new WormEnemy{ Point2f{ 2989.f, 40.f }, wormEnemySize, wormEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3004.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 3000.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 3130.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 3194.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 3200.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3203.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	ScorpionHealth += 2;
	flyingEnemyHealth += 2;
	jumpingEnemyHealth += 2;
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 3260.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 3350.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3453.f, 40.f }, ScorpionSize, ScorpionHealth,  textureManager, bulletManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 3500.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3509.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3675.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3734.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3839.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 3982.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	wormEnemyHealth += 4;
	m_pEnemies.push_back(new WormEnemy{ Point2f{ 4245.f, 260.f }, wormEnemySize, wormEnemyHealth, textureManager });
	ScorpionHealth += 2;
	flyingEnemyHealth += 2;
	jumpingEnemyHealth += 2;
	m_pEnemies.push_back(new Scorpion{ Point2f{ 4439.f, 60.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 4498.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 4528.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 4789.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 4794.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 4829.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 4853.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 4892.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 4938.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 5032.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new FlyingEnemy{ Point2f{ 5390.f, 200.f }, flyingEnemySize, flyingEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 5230.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 5303.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 5343.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 5394.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 5463.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 5564.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 5629.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 5753.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new JumpingEnemy{ Point2f{ 5792.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, textureManager });
	m_pEnemies.push_back(new WormEnemy{ Point2f{ 6040.f, 270.f }, wormEnemySize, wormEnemyHealth, textureManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6102.f, 200.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6193.f, 100.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6294.f, 60.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6363.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6403.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6537.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6594.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6684.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6774.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });
	m_pEnemies.push_back(new Scorpion{ Point2f{ 6943.f, 40.f }, ScorpionSize, ScorpionHealth, textureManager, bulletManager });

	const float pitMonsterSize{ 1.f };

	const int minXPos{ 7950 };
	const int maxXPos{ 8015 };

	Point2f PitMonsterSpawnPos{};
	PitMonsterSpawnPos.x = float(rand() % (maxXPos - minXPos + 1) + minXPos);

	m_pEnemies.push_back(new PitMonster{ PitMonsterSpawnPos, pitMonsterSize, 100, textureManager, bulletManager });
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