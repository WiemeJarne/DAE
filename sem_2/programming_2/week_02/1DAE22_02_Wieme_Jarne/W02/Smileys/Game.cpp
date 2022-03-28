#include "pch.h"
#include "Game.h"
#include "Smiley.h"
#include <iostream>

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_SafeZoneBorder{ 30.f }
	,m_SafezoneBorderRect{ }
	,m_PreviousHighestSmileyIndex{ }
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

	m_SafezoneBorderRect.left = m_SafeZoneBorder;
	m_SafezoneBorderRect.bottom = m_SafeZoneBorder;
	m_SafezoneBorderRect.width = m_Window.width - 2 * m_SafeZoneBorder;
	m_SafezoneBorderRect.height = m_Window.height - 2 * m_SafeZoneBorder;
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
	switch ( e.keysym.sym )
	{
	case SDLK_UP:
		IncreaseSmileysSpeed( );
		break;
	case SDLK_DOWN:
		DecreaseSmileySpeed( );
		break;
	case SDLK_DELETE:
		DeleteSleepingSmileys( );
		break;
	}
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
	//std::cout << "MOUSEMOTION event: " << e.x << ", " << e.y << std::endl;
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
	const Point2f mousePos{ float(e.x), float(e.y) };

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
	const float spaceBetweenSmileys{ 80.f };
	Point2f position{ 30.f, m_Window.height / 2 };

	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		m_pSmileys[index] = new Smiley{position};

		position.x += spaceBetweenSmileys;
	}
}

void Game::DeleteSmileys( )
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		if (m_pSmileys[index] != nullptr) delete m_pSmileys[index];
	}
}

void Game::DrawSmileys() const
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		if(m_pSmileys[index] != nullptr) m_pSmileys[index]->Draw();
	}
}

void Game::UpdateSmileys( float elapsedSec )
{
	int highestSmileyIndex{};
	Rectf boundingRect{};
	boundingRect.width = m_Window.width;
	boundingRect.height = m_Window.height;

	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		if (m_pSmileys[index] != nullptr && m_pSmileys[index]->IsSleeping() == false)
		{
			m_pSmileys[index]->Update(elapsedSec, boundingRect, m_SafezoneBorderRect);

			if (m_pSmileys[highestSmileyIndex] != nullptr && m_pSmileys[highestSmileyIndex]->IsSleeping() == false)
			{
				highestSmileyIndex = DetermineHighestSmiley(highestSmileyIndex, index);
			}
			else
			{
				highestSmileyIndex = index;
			}
		}
	}

	if (m_pSmileys[m_PreviousHighestSmileyIndex] != nullptr && m_pSmileys[highestSmileyIndex] != nullptr)
	{
		m_pSmileys[m_PreviousHighestSmileyIndex]->SetHighest(false);
		m_pSmileys[highestSmileyIndex]->SetHighest(true);
	}

	m_PreviousHighestSmileyIndex = highestSmileyIndex;
}

int Game::DetermineHighestSmiley(const int highestSmileyIndex, const int index) const
{
	if (m_pSmileys[highestSmileyIndex]->GetPosition().y < m_pSmileys[index]->GetPosition().y) return index;

	return highestSmileyIndex;
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
		if(m_pSmileys[index] != nullptr) m_pSmileys[index]->HitTest( mousePos );
	}
}

void Game::IncreaseSmileysSpeed( )
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		if(m_pSmileys[index] != nullptr) m_pSmileys[index]->IncreaseSpeed();
	}
}

void Game::DecreaseSmileySpeed( )
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		if (m_pSmileys[index] != nullptr) m_pSmileys[index]->DecreaseSpeed();
	}
}

void Game::DeleteSleepingSmileys( )
{
	for (int index{}; index < m_AmountOfSmileys; ++index)
	{
		if( m_pSmileys[index] != nullptr )
		{
			if (m_pSmileys[index]->IsSleeping() == true)
			{
				delete m_pSmileys[index];
				m_pSmileys[index] = nullptr;
			}
		}
	}
}