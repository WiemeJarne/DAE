#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_MousePos{ }
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

	std::vector<Point2f> points{ Point2f{37.f, 46.f},
								 Point2f{37.f, 356.f},
								 Point2f{m_Window.width / 2.f, 465.f},
								 Point2f{786.f, 379},
								 Point2f{786.f, 47.f},
								 Point2f{m_Window.width / 2.f, 12} };

	DrawPolygon( points );
	DrawRay( points );
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
	m_MousePos = Point2f{ float(e.x), float(e.y) };
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
	glClearColor( 100/255.f, 100/255.f, 100/255.f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DrawPolygon(const std::vector<Point2f>& points) const
{
	utils::SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	utils::FillPolygon(points);

	utils::SetColor(Color4f{ 1.f, 0.5, 0.f, 1.f });
	utils::DrawPolygon(points, true, 2.f);
}

void Game::DrawRay(const std::vector<Point2f>& points) const
{
	Point2f rayStartPoint{ m_Window.width / 2.f, m_Window.height / 2.f };
	Point2f rayEndPoint{ m_MousePos };

	utils::SetColor(Color4f{ 1.f, 1.f, 0.f, 1.f });
	utils::DrawLine(rayStartPoint, rayEndPoint);

	utils::HitInfo hitInfo{};

	if (utils::Raycast(points, rayStartPoint, rayEndPoint, hitInfo))
	{
		//draw circle on intersecting point
		const float radius{ 4.f };
		utils::DrawEllipse(hitInfo.intersectPoint, radius, radius);

		//draw normal
		const float normalLenght{ 30.f };
		utils::SetColor(Color4f{ 0.f, 1.f, 0.f, 1.f });
		DrawVector(hitInfo.normal * normalLenght, hitInfo.intersectPoint);

		//draw reflection
		Vector2f rayVector{ rayStartPoint, m_MousePos };
		Vector2f relectedVector{ rayVector.Reflect(hitInfo.normal) };
		utils::SetColor(Color4f{ 1.f, 1.f, 1.f, 1.f });
		DrawVector(relectedVector * (1 - hitInfo.lambda), hitInfo.intersectPoint);
	}
}

void Game::DrawVector(const Vector2f& vector, const Point2f& startPoint) const
{
	Point2f endPoint{ startPoint + vector };
	utils::DrawLine(startPoint, endPoint);
}