#include "pch.h"
#include <iostream>
#include "Game.h"
#include "utils.h"

Game::Game( const Window& window )
	:m_Window{ window }
	, m_ActorVelocity{}
	, m_InAirColor{ 0, 1.0f, 0, 1.0f }
	, m_OnGroundColor{ 1.0f, 0, 0, 1.0f }
	, m_GravityAccelaration{ 0,-981 }
	, m_ActorShape{ window.width/4, window.height - 30, 20, 30 }
	, m_IsOnGround{ false }
{	 
	Initialize( );
}

Game::~Game( )
{
	Cleanup();
}

void Game::Initialize( )
{
	ShowTestMessage( );
	AddPowerUps( );
}

void Game::Cleanup()
{
}

void Game::Update( float elapsedSec )
{
	// Actor
	UpdateActor( elapsedSec );

	// Power ups
	m_PowerUpManager.Update( elapsedSec );
}

void Game::Draw( ) const
{
	ClearBackground( );

	// Level's backGround
	m_Level.DrawBackground( );

	// Actor
	DrawActor( );

	// PowerUps
	m_PowerUpManager.Draw( );

	// Level's foreground
	m_Level.DrawForeground( );
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
	PositionActor( float( e.x ) );
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::ShowTestMessage( ) const
{
	std::cout << "--> Level test <--\n";
	std::cout << "Verify that:\n";
	std::cout << "- The background is drawn ( DrawBackground ).\n";
	std::cout << "- The actor stops falling when it collides ( HandleCollision ) with the level.\n";
	std::cout << "- The actor is green when it doesn't touch the level and red when it does ( IsOnGround ).\n";
	std::cout << "- The actor is drawn behind the fence ( DrawForeground ).\n";
	std::cout << "- When the actor hits a power up, this power up disappears.\n\n";
	std::cout << "Clicking with the mouse on the window, repositions the actor at:\n";
	std::cout << "- the top of the window\n";
	std::cout << "- a horizontal distance corresponding with the mouse click.\n";
}

void Game::AddPowerUps( )
{
	m_PowerUpManager.AddItem( Point2f{ 185.0f, 500 - 183.0f }, PowerUp::Type::brown );
	m_PowerUpManager.AddItem( Point2f{ 435.0f, 500 - 133.0f }, PowerUp::Type::green );
	m_PowerUpManager.AddItem( Point2f{ 685.0f, 500 - 183.0f }, PowerUp::Type::brown );
}

void Game::UpdateActor( float elapsedSec )
{
	// Update actor's position
	m_ActorVelocity += m_GravityAccelaration * elapsedSec;
	m_ActorShape.left += m_ActorVelocity.x * elapsedSec;
	m_ActorShape.bottom += m_ActorVelocity.y * elapsedSec;

	// Handle level collision
	m_Level.HandleCollision( m_ActorShape, m_ActorVelocity );
	m_IsOnGround = m_Level.IsOnGround( m_ActorShape );

	// Handling powerup hit
	m_PowerUpManager.HitItem( m_ActorShape );

}

void Game::DrawActor( ) const
{
	if ( m_IsOnGround )
	{
		utils::SetColor( m_OnGroundColor );
	}
	else
	{
		utils::SetColor( m_InAirColor );
	}
	utils::FillRect( m_ActorShape );
}

void Game::PositionActor( float newCenterX )
{
	m_ActorShape.left = newCenterX - m_ActorShape.width / 2;
	m_ActorShape.bottom = m_Window.height - m_ActorShape.height;
	m_IsOnGround = false;
}
