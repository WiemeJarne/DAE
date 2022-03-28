#include "pch.h"
#include "Game.h"
#include "utils.h"
#include "Matrix2x3.h"
#include "Texture.h"
#include <iostream>

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_Angle{ }
	,m_Scale{ 1.f }
	,m_Position{ }
	,m_DiamondWidth{ 48.f }
	,m_DiamondHeight{ 48.f }
	,m_DiamondTexture{ new Texture{"Resources/Diamond.png"} }
{
	Initialize( );
	std::cout << "a: Rotate ccw\n";
	std::cout << "d: Rotate cw\n";
	std::cout << "w: Zoom in\n";
	std::cout << "s: Zoom out\n";
	std::cout << "Arrows: Translate\n";
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	m_Position.x = m_DiamondTexture->GetWidth() / 2.f;
	m_Position.y = m_DiamondTexture->GetHeight() / 2.f;

	m_Vertices.push_back(Point2f{ m_DiamondWidth / 2.f, 0.f });
	m_Vertices.push_back(Point2f{ m_DiamondWidth, m_DiamondHeight / 2.f });
	m_Vertices.push_back(Point2f{ m_DiamondWidth / 2.f, m_DiamondHeight });
	m_Vertices.push_back(Point2f{ 0, m_DiamondHeight / 2.f });
}

void Game::Cleanup( )
{
	delete m_DiamondTexture;
}

void Game::Update( float elapsedSec )
{
	 //Check keyboard state
	const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	if ( pStates[SDL_SCANCODE_A] )
	{
		m_Angle += 60 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_D])
	{
		m_Angle -= 60 * elapsedSec;
	}

	if ( pStates[SDL_SCANCODE_W])
	{
		m_Scale *= 1 + 3 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_S])
	{
		m_Scale /= 1 + 3 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_LEFT])
	{
		m_Position.x -= 120 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		m_Position.x += 120 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_UP])
	{
		m_Position.y += 120 * elapsedSec;
	}

	if (pStates[SDL_SCANCODE_DOWN])
	{
		m_Position.y -= 120 * elapsedSec;
	}
}

void Game::Draw( ) const
{
	ClearBackground( );

	m_DiamondTexture->Draw();

	utils::SetColor(Color4f{ 0.f, 0.f, 1.f, 1.f });
	utils::DrawPolygon(m_Vertices);
	
	//how to transform a texture
	glPushMatrix();
		glTranslatef(m_Position.x, m_Position.y, 0);
		glRotatef(m_Angle, 0.f, 0.f, 1.f);
		glScalef(m_Scale, m_Scale, 1.f);
		glTranslatef(-m_DiamondTexture->GetWidth() / 2.f, -m_DiamondTexture->GetHeight() / 2.f, 0.f);
		m_DiamondTexture->Draw();
	glPopMatrix();

	//how to transform a vector of points
	Matrix2x3 maTranslate{}, matRotate{}, matScale{}, matCenter{};
	maTranslate.SetAsTranslate(m_Position);
	matRotate.SetAsRotate(m_Angle);
	matScale.SetAsScale(m_Scale, m_Scale);
	matCenter.SetAsTranslate(-m_DiamondWidth / 2.f, -m_DiamondHeight / 2.f);

	Matrix2x3 matWorld = maTranslate * matRotate * matScale * matCenter;
	std::vector<Point2f> transformedVertices;
	transformedVertices = matWorld.Transform(m_Vertices);

	utils::DrawPolygon(transformedVertices);
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
	glClearColor( 0.f, 0.f, 0.f, 1.f );
	glClear( GL_COLOR_BUFFER_BIT );
}
