#include "pch.h"
#include "Game.h"
#include "Tower.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	CreateTowers( );

	CreateDisks( );
}

void Game::Cleanup( )
{
	for (Tower* tower : m_Towers)
	{
		delete tower;
	}
}

void Game::Update( float elapsedSec )
{
	/* Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_RIGHT] )
	{
		std::cout << "Right arrow key is down\n";
	}
	if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	{
		std::cout << "Left and up arrow keys are down\n";
	}*/
}

void Game::Draw( ) const
{
	ClearBackground( );

	for (Tower* tower : m_Towers)
	{
		tower->Draw();
	}

	for (Tower* tower : m_Towers)
	{
		tower->DrawDisks();
	}
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	//std::cout << "KEYDOWN event: " << e.keysym.sym << std::endl;
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
	Point2f mousePos{ float(e.x), float(e.y) };

	for (Tower* tower : m_Towers)
	{
		tower->OnMouseMotion(mousePos);
	}
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		Point2f mousePos{ float(e.x), float(e.y) };

		for (Tower* tower : m_Towers)
		{
			tower->CheckMousePos(mousePos);
		}
		break;
	}
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		Point2f mousePos{ float(e.x), float(e.y) };

		for (Tower* tower : m_Towers)
		{
			tower->OnMouseRelease();
		}
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 1.f, 1.f, 1.f, 1.f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::CreateTowers( )
{
	const float spaceBetweenTowers{ 10.f };

	Rectf towerShape{};
	towerShape.left = spaceBetweenTowers;
	towerShape.bottom = 10.f;
	towerShape.width = 150.f;
	towerShape.height = 200.f;

	Color4f towerColor{ 1.f, 128 / 255.f, 51 / 255.f, 1.f };

	m_Towers.push_back(new Tower{ towerShape, towerColor });

	towerShape.left += towerShape.width + spaceBetweenTowers;
	m_Towers.push_back(new Tower{ towerShape, towerColor });

	towerShape.left += towerShape.width + spaceBetweenTowers;
	m_Towers.push_back(new Tower{ towerShape, towerColor });
}

void Game::CreateDisks( )
{
	const float diskHeight{ 20.f };
	float diskWidth{ m_Towers[0]->GetShape().width - 20.f };

	m_Towers[0]->AddDisk(diskWidth, diskHeight, Color4f{ 1.f, 0.f, 0.f, 1.f });
	
	diskWidth -= 20.f;
	m_Towers[0]->AddDisk(diskWidth, diskHeight, Color4f{ 1.f, 1.f, 0.f, 1.f });

	diskWidth -= 20.f;
	m_Towers[0]->AddDisk(diskWidth, diskHeight, Color4f{ 0.f, 1.f, 0.f, 1.f });
}