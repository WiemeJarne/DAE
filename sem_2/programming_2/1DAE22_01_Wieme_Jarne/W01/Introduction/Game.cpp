#include "pch.h"
#include "Game.h"
#include "Ball.h"
#include "Texture.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_pLogo{new Texture{"DAE.png"}}
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	for (size_t i = 0; i < m_BallSize; i++)
	{
		m_pBalls[i] = new Ball(Point2f{ float(rand() % 300 + 20), 100.f }, Vector2f{ 80.0,80.0 }, Color4f{ 0.f,1.f,0.f,1.f }, 50.f);
	}
}

void Game::Cleanup( )
{
	for (size_t i = 0; i < m_BallSize; i++)
	{
		delete m_pBalls[i];
	}

	delete m_pLogo;
}

void Game::Update( float elapsedSec )
{
	for (size_t i = 0; i < m_BallSize; i++)
	{
		m_pBalls[i]->Update(elapsedSec, Rectf{0.f, 0.f, 846.f , 500.f});
	}
}

void Game::Draw( ) const
{
	ClearBackground( );

	for (size_t i = 0; i < m_BallSize; i++)
	{
		m_pBalls[i]->Draw();
	}

	m_pLogo->Draw(Rectf{ 100.f, 100.f, m_pLogo->GetWidth(), m_pLogo->GetHeight()});
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
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
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
	//std::cout << "MOUSEBUTTONUP event: ";
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

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}
