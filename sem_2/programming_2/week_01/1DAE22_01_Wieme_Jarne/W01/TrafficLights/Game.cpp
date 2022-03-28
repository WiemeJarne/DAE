#include "pch.h"
#include "Game.h"
#include "TrafficLight.h"

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
	InitTraficlights(2, 5);
}

void Game::Cleanup( )
{
	DeleteTrafficLights();
}

void Game::Update( float elapsedSec )
{
	UpdateTrafficLights(elapsedSec);
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawTrafficLights( );
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
	std::cout << "MOUSEBUTTONUP event: ";
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:
		DoHitTestTrafficLights(Point2f( float(e.x), float(e.y) ));
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor(204 / 255.f, 204 / 255.f, 204 / 255.f, 1.f);
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::InitTraficlights(const int amountOfRows, const int amountOfcolumns)
{
	Point2f position{};
	position.x = 10.f;
	position.y = 10.f;
	const float spaceBetweenTrafficLights{ 10.f };

	for (int rowNr{}; rowNr < amountOfRows; ++rowNr)
	{
		for (int columnNr{}; columnNr < amountOfcolumns; ++columnNr)
		{
			m_TrafficLights.push_back(new TrafficLight{position});
			position.x += m_TrafficLights[0]->GetWidth() + spaceBetweenTrafficLights;
		}
		position.x = 10.f;
		position.y += m_TrafficLights[0]->GetHeight() + spaceBetweenTrafficLights;
	}
}

void Game::DeleteTrafficLights()
{
	for (TrafficLight* index : m_TrafficLights)
	{
		delete index;
	}
}

void Game::DrawTrafficLights() const
{
	for (TrafficLight* index : m_TrafficLights)
	{
		index->Draw();
	}
}

void Game::UpdateTrafficLights(float elapsedSec)
{
	for (TrafficLight* index : m_TrafficLights)
	{
		index->Update(elapsedSec);
	}
}

void Game::DoHitTestTrafficLights(const Point2f& mousePos)
{
	for (TrafficLight* index : m_TrafficLights)
	{
		index->DoHitTest(mousePos);
	}
}