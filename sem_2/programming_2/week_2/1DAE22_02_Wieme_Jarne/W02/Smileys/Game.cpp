#include "pch.h"
#include "Game.h"
#include "Smiley.h"

const int Game::m_AmountOfSmileys{ 10 };
Smiley* Game::m_AmountOfSmileys[Game::m_AmountOfSmileys]{};

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_SafeZoneBorder{ 30.f }
	,m_SafezoneBorderRect{ m_SafeZoneBorder,
						   m_SafeZoneBorder,
						   m_Window.width - 2 * m_SafeZoneBorder,
						   m_Window.height - 2 * m_SafeZoneBorder }
{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	CreateSmileys();
}

void Game::Cleanup( )
{
	DeleteSmileys();
}

void Game::Update( float elapsedSec )
{
	UpdateSmileys( elapsedSec );
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawSmileys( );
	DrawSafeZoneBorder( );
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
	const Point2f mousePos{ e.x, e.y };

	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		HitTestSmileys( mousePos );
		break;
	}
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
	glClearColor( 76 / 255.f, 76 / 255.f, 76 / 255.f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::CreateSmileys( )
{
	const float spaceBetweenSmileys{ m_Window.width / 10 };
	Point2f position{ spaceBetweenSmileys, m_Window.height / 2 };

	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		m_pSmileys[index] = new Smiley(position);

		position.x += spaceBetweenSmileys;
	}
}

void Game::DeleteSmileys( )
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		delete m_pSmileys[index];
	}

	delete[] m_pSmileys;
	m_pSmileys = nullptr;
}

void Game::DrawSmileys() const
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		delete m_pSmileys[index]->Draw();
	}
}

void Game::UpdateSmileys( float elapsedSec )
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		delete m_pSmileys[index]->Update( elapsedSec, m_Window, m_SafezoneBorderRect);
	}
}

void Game::DrawSafeZoneBorder( ) const
{
	Color4f black{ 0.f, 0.f, 0.f, 1.f };

	utils::SetColor(black);
	utils::DrawRect(m_SafezoneBorderRect);
}

void Game::HitTestSmileys( const Point2f& mousePos ) const
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		delete m_pSmileys[index]->HitTest( mousePos );
	}
}