#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_MousePos{}
{
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
	// Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void Game::Draw( ) const
{
	ClearBackground( );

	//Sufrace
	Point2f surfaceP1{ 350.f, 50.f };
	Point2f surfaceP2{ 150.f, 250.f };
	utils::SetColor(Color4f{ 1.f, 0.f, 0.f, 1.f });
	utils::DrawLine(surfaceP1, surfaceP2, 4.f);

	//the ray
	Point2f rayP1{ 100.f, 40.f };
	//Point2f rayP2{ 380.f, 180.f };
	utils::SetColor(Color4f{ 0.f, 1.f, 0.f, 1.f });
	utils::DrawLine(rayP1, m_MousePos, 2.f);

	//raycast
	utils::HitInfo hitInfo{};
	std::vector<Point2f> surface{ surfaceP1, surfaceP2 };

	if (utils::Raycast(surface, rayP1, m_MousePos, hitInfo))
	{
		utils::SetColor(Color4f{ 0.f, 0.f, 1.f, 1.f });
		utils::FillEllipse(hitInfo.intersectPoint, 4.f, 4.f);

		//Normal
		utils::SetColor(Color4f{ 1.f, 1.f, 0.f, 1.f });
		DrawVector(hitInfo.normal * 50.f, hitInfo.intersectPoint);

		//Reflection vector
		utils::SetColor(Color4f{ 1.f, 1.f, 1.f, 1.f });
		Vector2f rayVector{ rayP1, m_MousePos };
		Vector2f relectedVector{ rayVector.Reflect(hitInfo.normal) };
		DrawVector(relectedVector * (1 - hitInfo.lambda), hitInfo.intersectPoint);
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
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
	m_MousePos.x = float(e.x);
	m_MousePos.y = float(e.y);
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
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DrawVector(const Vector2f& vector, const Point2f& startPoint) const
{
	Point2f endPoint{startPoint + vector};
	utils::DrawLine(startPoint, endPoint);
}