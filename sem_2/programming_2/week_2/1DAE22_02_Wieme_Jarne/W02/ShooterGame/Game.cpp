#include "pch.h"
#include "Game.h"
#include "Enemy.h"
#include "utils.h"
#include "Avatar.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_AmountOfEnemies{40}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	InitEnemies( );
	InitAvatar( );

	Rectf boundaries{};
	boundaries.width = m_Window.width;
	boundaries.height = m_Window.height;

	m_Avatar->SetBoundaries(boundaries);
}

void Game::Cleanup( )
{
	DeleteEnemies( );
	DeleteAvatar( );
}

void Game::Update( float elapsedSec )
{
	 //Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		m_Avatar->Update(elapsedSec, m_Enemies, true);
	}
	else if ( pStates[SDL_SCANCODE_LEFT] )
	{
		m_Avatar->Update(-elapsedSec, m_Enemies, true);
	}
	else m_Avatar->Update(-elapsedSec, m_Enemies, false);
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawEnemies( );
	DrawAvatar( );
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	m_Avatar->ProcessKeyDownEvent(e);
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	//switch ( e.keysym.sym )
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "`Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	//std::cout << "MOUSEBUTTONDOWN event: ";
	//switch ( e.button )
	//{
	//case SDL_BUTTON_LEFT:
	//	std::cout << " left button " << std::endl;
	//	break;
	//case SDL_BUTTON_RIGHT:
	//	std::cout << " right button " << std::endl;
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	std::cout << " middle button " << std::endl;
	//	break;
	//}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.f, 0.f, 0.f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::InitEnemies( )
{
	const float enemyWidth{ 25.f };
	const float enemyHeight{ 25.f };
	const float spaceBetweenEnemies{ 10.f };
	Point2f enemyCenter{ spaceBetweenEnemies + enemyWidth / 2.f, m_Window.height - spaceBetweenEnemies - enemyHeight / 2.f};
	const int amountOfRows{ 4 };
	const int amountOfColumns{ m_AmountOfEnemies / amountOfRows };

	for (int rowNr{}; rowNr < amountOfRows; ++rowNr)
	{
		for (int columnNr{}; columnNr < amountOfColumns; ++columnNr)
		{
			m_Enemies.push_back(new Enemy{ enemyCenter, enemyWidth, enemyHeight });
			enemyCenter.x += spaceBetweenEnemies + enemyWidth;
		}
		enemyCenter.x = spaceBetweenEnemies + enemyWidth / 2.f;
		enemyCenter.y += spaceBetweenEnemies - 2 * enemyHeight;
	}
}

void Game::DeleteEnemies( )
{
	for (Enemy* index : m_Enemies)
	{
		if (index != nullptr)
		{
			delete index;
			index = nullptr;
		}
	}
	m_Enemies.clear( );
}

void Game::DrawEnemies( ) const
{
	for (Enemy* index : m_Enemies)
	{
		if (index != nullptr)
		{
			index->Draw();
		}
	}
}

void Game::InitAvatar( )
{
	m_Avatar = new Avatar{ Point2f{m_Window.width / 2.f, 30.f}, 50.f, 50.f };
}

void Game::DeleteAvatar( )
{
	delete m_Avatar;
}

void Game::DrawAvatar( ) const
{
	m_Avatar->Draw( );
}