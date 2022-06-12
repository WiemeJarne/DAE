#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "Bullet.h"
#include "Texture.h"
#include "utils.h"
#include "TextureManager.h"
#include "BulletManager.h"
#include "PowerUp.h"
#include <iostream>

Game::Game( const Window& window )
	: m_Window{ window }
	, m_TextureManager{ TextureManager{} }
	, m_Camera{ m_Window.width, m_Window.height }
	, m_BulletManager{ m_TextureManager }
	, m_Avatar{ m_TextureManager }
	, m_EnemyManager{ m_TextureManager, m_BulletManager }
	, m_HUD{ Point2f{0.f, m_Window.height}, m_Avatar.GetAmountOfLives(), m_Avatar.GetHealth(), m_TextureManager }
	, m_StartScreenMusic{ "Resources/Sound/StartScreen.mp3" }
	, m_BackgroundMusic{ "Resources/Sound/DesertJourney.mp3" }
	, m_GameOverMusic{ "Resources/Sound/GameOver.mp3" }
	, m_GameHasStarted{ }
	, m_GameOver{ }
{	
	std::cout << "Press space to start the game\n";
	std::cout << "Press i for more info\n";
	m_Camera.SetLevelBoundaries(m_Level.GetBoundaries());
	m_StartScreenMusic.SetVolume(15);
	m_StartScreenMusic.Play(true);
	m_GameOverMusic.SetVolume(15);
	Initialize( );
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
	if (m_Avatar.GetAmountOfLives() == 0 && m_Avatar.GetHealth() == 0 && !m_GameOver)
	{
		std::cout << "Press space to retry\n";
		m_BackgroundMusic.Stop();
		m_GameOverMusic.Play(0);
		m_GameOver = true;
	}

	if (m_GameHasStarted && !m_GameOver)
	{
		m_Avatar.Update(elapsedSec, m_Level, m_EnemyManager.GetEnemies(), m_BulletManager);
		m_EnemyManager.Update(elapsedSec, m_Level, m_Avatar);
		m_BulletManager.Update(elapsedSec, m_Level, m_EnemyManager.GetEnemies(), m_Avatar, m_PowerupManager);
		m_PowerupManager.Update(elapsedSec, m_Level);

		PowerUp::Type powerUpType{};

		if (m_PowerupManager.HitItem(m_Avatar.GetShape(), powerUpType))
		{
			m_Avatar.PowerupHit(powerUpType);
		}
	}

	m_HUD.Update(m_Avatar.GetHealth(), m_Avatar.GetAmountOfLives(), m_GameOver, m_GameHasStarted);
}

void Game::Draw( ) const
{
	ClearBackground( );
	Point2f cameraTransformation{};

	if(m_GameHasStarted && !m_GameOver)
	{
		float scale{ 2.f };

		glPushMatrix();
			m_Camera.Transform(m_Avatar.GetShape(), scale, cameraTransformation);
			m_Level.DrawBackground(cameraTransformation);
			m_Avatar.Draw();
			m_EnemyManager.Draw();
			m_PowerupManager.Draw();
			m_BulletManager.Draw();
			m_Level.DrawForeground();
		glPopMatrix();
	}
		m_HUD.Draw();
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch (e.keysym.sym)
	{
	case SDLK_i:
		PrintInfo( );
		break;
	case SDLK_SPACE:
		if (!m_GameHasStarted)
		{
			m_GameHasStarted = true;
			m_StartScreenMusic.Stop();
			m_BackgroundMusic.Play(true);
		}
		if (m_GameOver)
		{
			m_GameOver = false;
			m_GameOverMusic.StopAll( );
			m_BackgroundMusic.Play(true);
			m_Avatar.Restart( );
			m_PowerupManager.Reset( );
		}
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
	std::cout << "It is also possible to shoot while in the air using the same shoot controls.\n";
}