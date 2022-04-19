#include "pch.h"
#include "Game.h"
#include <iostream>
#include "Ball.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_Kinect{ window.width, window.height }
	,m_Health{ 10 }
	,m_HeartTexture{ Texture{"Resources/Heart.png"} }
	,m_ScoreTexture{ Texture{"0", "Resources/DIN-Light.otf", 50, Color4f{1.f, 1.f, 1.f, 1.f}} }
	,m_GameOverTexture{ Texture{"Resources/GameOver.png"} }
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
	if (m_Health > 0)
	{
		m_ScoreTexture = Texture{ std::to_string(m_Score), "Resources/DIN-Light.otf", 50, Color4f{1.f, 1.f, 1.f, 1.f} };

		for (size_t index{}; index < m_Balls.size(); ++index)
		{
			m_Balls[index].Update(elapsedSec);
			HandleCollision(index);
		}

		AddBall(elapsedSec);
		m_Kinect.Update(elapsedSec);
	}
}

void Game::Draw( )
{
	ClearBackground( );
	m_Kinect.Draw( );
	for (Ball& ball : m_Balls)
	{
		ball.Draw( );
	}

	float x{ };
	const float scale{ 0.15f };

	for (int index{}; index < m_Health; ++index)
	{
		glPushMatrix();
		 glTranslatef(x, 0.f, 0.f);
		 glScalef(scale, scale, 0.f);
		 m_HeartTexture.Draw();
		glPopMatrix();

		x += m_HeartTexture.GetWidth() * scale;
	}

	if (m_Health <= 0)
	{
		m_GameOverTexture.Draw(Rectf{0.f, 0.f, m_Window.width, m_Window.height});
	}

	m_ScoreTexture.Draw(Point2f{ m_Window.width - m_ScoreTexture.GetWidth(), m_Window.height - m_ScoreTexture.GetHeight() });
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch (e.keysym.sym)
	{
	case SDLK_r:
		m_Health = 10;
		m_Score = 0;

		for (Ball& ball : m_Balls)
		{
			m_Balls.pop_back( );
		}

		break;
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
	//std::cout << "KEYUP event: " << e.keysym.sym << std::endl;
	switch ( e.keysym.sym )
	{
	case SDLK_p:
		m_Kinect.ToggleSeatMode();
		break;
	case SDLK_RIGHT:
		//std::cout << "`Right arrow key released\n";
		break;
	case SDLK_1:
	case SDLK_KP_1:
		//std::cout << "Key 1 released\n";
		break;
	}
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
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::AddBall(float elapsedSec)
{
	m_AccuSec += elapsedSec;

	float BallSpawnDelay{ 2.f - (m_Score / 5) * 0.2f };

	if (m_AccuSec >= BallSpawnDelay)
	{
		m_AccuSec = 0.f;
		const float radius{ float(rand() % (20 - 5 + 1) + 5) };
		float velocity{ float(rand() % 101 + 100) + (m_Score / 5) * 50.f };
		m_Balls.push_back(Ball{ Point2f{float(rand() % int(m_Window.width)), m_Window.height + radius}, radius,  velocity });
	}
}

void Game::HandleCollision(int index)
{
	if (m_Balls[index].IsOverlapping(m_Kinect.GetLeftHand()) || m_Balls[index].IsOverlapping(m_Kinect.GetRightHand()))
	{
		if (m_Balls[index].GetType() == Ball::Type::danger)
		{
			--m_Health;
		}
		else if (m_Balls[index].GetType() == Ball::Type::growHand)
		{
			m_Kinect.SetRigtHand(3.f);
			m_Kinect.SetLeftHand(3.f);
		}
		else
		{
			++m_Score;
		}

		m_Balls[index] = m_Balls[m_Balls.size() - 1];
		m_Balls.pop_back();
	}
	else if(m_Balls[index].IsOutOfWindow())
	{
		m_Balls[index] = m_Balls[m_Balls.size() - 1];
		m_Balls.pop_back();

		--m_Health;
	}
}