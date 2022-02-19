#include "pch.h"
#include "Game.h"
#include "Card.h"

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
	m_Circle.center.x = m_Window.width / 2.f;
	m_Circle.center.y = m_Window.height / 2.f;
	m_Circle.radius = 100.f;
	InitCards( );
}

void Game::Cleanup( )
{
	DeleteCards( );
}

void Game::Update( float elapsedSec )
{
	UpdateCards(elapsedSec);
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawCards();
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
	glClearColor( 0.f, 0.f, 0.f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::InitCards( )
{
	const Card::Suit suit{ 1 };
	float angle{ 0 };

	for (int rank{ Card::m_MinRank }; rank <= Card::m_MaxRank; ++rank)
	{
		m_Cards.push_back(new Card{ suit, rank, angle, m_Circle });
		angle += 27.6923077f;
	}
}

void Game::DeleteCards( )
{
	for (Card* index : m_Cards)
	{
		delete index;
	}
}

void Game::UpdateCards( float elapsedSec )
{
	for (Card* index : m_Cards)
	{
		index->Update(elapsedSec);
	}
}

void Game::DrawCards( ) const
{
	for (Card* index : m_Cards)
	{
		index->Draw();
	}
}