#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "Bullet.h"
#include "Texture.h"
#include "utils.h"
#include "TextureManager.h"
#include "BulletManager.h"
#include <iostream>

Game::Game( const Window& window )
	: m_Window{ window }
	, m_TextureManager{ TextureManager{} }
	, m_Camera{ m_Window.width, m_Window.height }
	, m_BulletManager{ m_TextureManager }
	, m_Avatar{ m_TextureManager }
	, m_EnemyManager{ }
{	 
	m_Camera.SetLevelBoundaries(m_Level.GetBoundaries());
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	AddEnemies( );
	AddPowerups( );
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	// Update game objects
	m_Avatar.Update( elapsedSec, m_Level, m_EnemyManager.GetEnemies( ), m_BulletManager );
	m_EnemyManager.Update(elapsedSec, m_Level, m_Avatar);
	m_BulletManager.Update(elapsedSec, m_Level, m_EnemyManager.GetEnemies(), m_Avatar);

	if (m_PowerupManager.HitItem( m_Avatar.GetShape( ) ))
	{
		m_Avatar.PowerupHit( );
	}
}

void Game::Draw( ) const
{
	ClearBackground( );

	const float scaleFactor{ 2 };
	Point2f cameraTransformation{};

	glPushMatrix();
		m_Camera.Transform(m_Avatar.GetShape(), scaleFactor, cameraTransformation);
		m_Level.DrawBackground(cameraTransformation);
		m_Avatar.Draw( );
		m_EnemyManager.Draw( );
		m_PowerupManager.Draw( );
		m_BulletManager.Draw( );
		m_Level.DrawForeground( );
	glPopMatrix();

}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch (e.keysym.sym)
	{
	case SDLK_r:

		if (m_PowerupManager.GetAmountOfPowerUps() == 0)
		{
			AddPowerups( );
		}

		break;
	case SDLK_i:
		PrintInfo( );
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::AddEnemies( )
{
	const float normalEnemySize{ 1.2f };
	const float flyingEnemySize{ 1.f };
	const float wormEnemySize{ 1.f };
	const float jumpingEnemySize{ 1.f };

	int normalEnemyHealth{ 3 };
	int flyingEnemyHealth{ 4 };
	int jumpingEnemyHealth{ 6 };
	int wormEnemyHealth{ 6 };

	m_EnemyManager.AddEnemy(Point2f{ 76.f, 84.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 76.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 325.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 420.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 680.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 800.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 900.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	normalEnemyHealth += 1;
	flyingEnemyHealth += 1;
	m_EnemyManager.AddEnemy(Point2f{ 1140.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 1320.f, 84.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 1200.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 1450.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 1530.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	normalEnemyHealth += 1;
	flyingEnemyHealth += 1;
	m_EnemyManager.AddEnemy(Point2f{ 1800.f, 80.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 1860.f, 120.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 1950.f, 260.f }, wormEnemySize, wormEnemyHealth, EnemyManager::EnemyKind::worm, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2050.f, 140.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	normalEnemyHealth += 1;
	flyingEnemyHealth += 1;
	m_EnemyManager.AddEnemy(Point2f{ 2140.f, 70.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2332.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2490.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2500.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2540.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2620.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2735.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	normalEnemyHealth += 2;
	flyingEnemyHealth += 2;
	wormEnemyHealth += 4;
	jumpingEnemyHealth += 2;
	m_EnemyManager.AddEnemy(Point2f{ 2900.f, 40.f }, wormEnemySize, wormEnemyHealth, EnemyManager::EnemyKind::worm, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 2989.f, 40.f }, wormEnemySize, wormEnemyHealth, EnemyManager::EnemyKind::worm, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3004.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3000.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3130.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3194.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3200.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3203.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	normalEnemyHealth += 2;
	flyingEnemyHealth += 2;
	jumpingEnemyHealth += 2;
	m_EnemyManager.AddEnemy(Point2f{ 3260.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3350.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3453.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3500.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3509.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3675.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3734.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3839.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 3982.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	wormEnemyHealth += 4;
	m_EnemyManager.AddEnemy(Point2f{ 4245.f, 260.f }, wormEnemySize, wormEnemyHealth, EnemyManager::EnemyKind::worm, m_TextureManager, m_BulletManager);
	normalEnemyHealth += 2;
	flyingEnemyHealth += 2;
	jumpingEnemyHealth += 2;
	m_EnemyManager.AddEnemy(Point2f{ 4439.f, 60.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4498.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4528.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4789.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4794.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4829.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4853.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4892.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 4938.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5032.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5390.f, 200.f }, flyingEnemySize, flyingEnemyHealth, EnemyManager::EnemyKind::flying, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5230.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5303.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5343.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5394.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5463.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5564.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5629.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5753.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 5792.f, 0.f }, jumpingEnemySize, jumpingEnemyHealth, EnemyManager::EnemyKind::jumping, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6040.f, 270.f }, wormEnemySize, wormEnemyHealth, EnemyManager::EnemyKind::worm, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6102.f, 200.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6193.f, 100.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6294.f, 60.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6363.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6403.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6537.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6594.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6684.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6774.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);
	m_EnemyManager.AddEnemy(Point2f{ 6943.f, 40.f }, normalEnemySize, normalEnemyHealth, EnemyManager::EnemyKind::Scorpion, m_TextureManager, m_BulletManager);

	const float pitMonsterSize{ 1.f };

	const int minXPos{ 7950 };
	const int maxXPos{ 8015 };

	Point2f PitMonsterSpawnPos{};
	PitMonsterSpawnPos.x = float(rand() % (maxXPos - minXPos + 1) + minXPos);

	m_EnemyManager.AddEnemy(PitMonsterSpawnPos, pitMonsterSize, 100, EnemyManager::EnemyKind::boss, m_TextureManager, m_BulletManager);
}

void Game::AddPowerups( )
{
	m_PowerupManager.AddPowerUp(Point2f{ 2925.f, 100.f });
}

void Game::PrintInfo( ) const
{
	std::cout << "A: walk to the left\n D: walk to the right\n";
	std::cout << "Space: jump\n";
	std::cout << "S: slide\n";
	std::cout << "left shift: shoot in the direction the avatar is facing\n";
	std::cout << "left shift + W: shoot up\n";
	std::cout << "left shift + S: shoot diagonally down in the direction the avatar is facing\n";
	std::cout << "left shift + W + D: shoot diagonally up to the right\n";
	std::cout << "left shift + W + A: shoot diagonally up to the left\n";
	std::cout << "R: reset\n";
	std::cout << "It is also possible to shoot while in the air using the same shoot controls.\n";
}