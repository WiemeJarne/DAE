#include "pch.h"
#include <iostream>
#include "Game.h"
#include "utils.h"
#include "Bullet.h"
#include "Texture.h"

Game::Game( const Window& window )
	:m_Window{ window }
	,m_Camera{m_Window.width, m_Window.height}
{	 
	m_Camera.SetLevelBoundaries(m_Level.GetBoundaries());
	Initialize( );
	AddEnemies( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	// Update game objects
	m_Avatar.Update( elapsedSec, m_Level, m_EnemyManager.GetEnemies() );
	m_EnemyManager.Update(elapsedSec, m_Level, m_Avatar);
}

void Game::Draw( ) const
{
	ClearBackground( );

	const float scaleFactor{ 2 };
	Point2f cameraTransformation{};

	glPushMatrix();
		m_Camera.Transform(m_Avatar.GetShape(), scaleFactor, cameraTransformation);
		m_Level.DrawBackground(cameraTransformation);
		m_Level.DrawLevel( );
		m_Avatar.Draw( );
		m_EnemyManager.Draw( );
		m_Level.DrawPitTexture(Point2f{ 571, 14 });
		m_Level.DrawPitTexture(Point2f{ 6966, 6 });
		m_Level.DrawPitMonsterPitTexture(Point2f{ 7828, 0 });
	glPopMatrix();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
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
	m_EnemyManager.AddEnemy(Point2f{ 76.f, 84.f }, 1.5f, 5, EnemyManager::EnemyKind::normal);
	m_EnemyManager.AddEnemy(Point2f{ 76.f, 200.f }, 1.f, 5, EnemyManager::EnemyKind::flying);
	m_EnemyManager.AddEnemy(Point2f{ 130.f, 50.f }, 1.f, 5, EnemyManager::EnemyKind::worm);

	const int minXPos{ 7950 };
	const int maxXPos{ 8015 };

	Point2f bossSpawnPos{};
	bossSpawnPos.x = float(rand() % (maxXPos - minXPos + 1) + minXPos);

	m_EnemyManager.AddEnemy(bossSpawnPos, 1.f, 15, EnemyManager::EnemyKind::boss);
}