#include "pch.h"
#include <iostream>
#include "Game.h"
#include "utils.h"

Game::Game( const Window& window )
	:m_Window{ window }
	,m_Camera{m_Window.width, m_Window.height}
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
	
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
	// Update game objects
	m_Avatar.Update( elapsedSec, m_Level );
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