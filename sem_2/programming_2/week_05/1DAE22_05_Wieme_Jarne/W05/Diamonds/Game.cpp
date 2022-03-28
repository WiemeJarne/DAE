#include "pch.h"
#include "Game.h"
#include "Diamond.h"

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
	const int amountOfDiamonds{ 10 };
	Point2f randomPos;
	for (int index{}; index < amountOfDiamonds; ++index)
	{
		CalculateRandomPos(randomPos);
		m_Diamonds.push_back(new Diamond{ randomPos });
	}
}

void Game::Cleanup( )
{
	for (Diamond* index : m_Diamonds)
	{
		delete index;
		index = nullptr;
	}
}

void Game::Update( float elapsedSec )
{
	const Uint8* pStates = SDL_GetKeyboardState(nullptr);
	if (pStates[SDL_SCANCODE_A])
	{
		for (Diamond* index : m_Diamonds)
		{
			float newAngle{ index->GetAngle() + 60 * elapsedSec };
			index->SetAngle(newAngle);
		}
	}

	if (pStates[SDL_SCANCODE_D])
	{
		for (Diamond* index : m_Diamonds)
		{
			float newAngle{ index->GetAngle() - 60 * elapsedSec };
			index->SetAngle(newAngle);
		}
	}

	if (pStates[SDL_SCANCODE_W])
	{
		for (Diamond* index : m_Diamonds)
		{
			float newScale{ index->GetScale() * (1 + 3 * elapsedSec) };
			index->SetScale(newScale);
		}
	}

	if (pStates[SDL_SCANCODE_S])
	{
		for (Diamond* index : m_Diamonds)
		{
			float newScale{ index->GetScale() / (1 + 3 * elapsedSec) };
			index->SetScale(newScale);
		}
	}

	if (pStates[SDL_SCANCODE_LEFT])
	{
		for (Diamond* index : m_Diamonds)
		{
			Vector2f newPosition{ index->GetPosition()};
			newPosition.x -= 120 * elapsedSec;
			index->SetPosition(newPosition);
		}
	}

	if (pStates[SDL_SCANCODE_RIGHT])
	{
		for (Diamond* index : m_Diamonds)
		{
			Vector2f newPosition{ index->GetPosition() };
			newPosition.x += 120 * elapsedSec;
			index->SetPosition(newPosition);
		}
	}

	if (pStates[SDL_SCANCODE_UP])
	{
		for (Diamond* index : m_Diamonds)
		{
			Vector2f newPosition{ index->GetPosition() };
			newPosition.y += 120 * elapsedSec;
			index->SetPosition(newPosition);
		}
	}

	if (pStates[SDL_SCANCODE_DOWN])
	{
		for (Diamond* index : m_Diamonds)
		{
			Vector2f newPosition{ index->GetPosition() };
			newPosition.y -= 120 * elapsedSec;
			index->SetPosition(newPosition);
		}
	}

	if (pStates[SDL_SCANCODE_R])
	{
		for (Diamond* index : m_Diamonds)
		{
			index->Reset();
		}
	}
}

void Game::Draw( ) const
{
	ClearBackground( );
	
	for (Diamond* index : m_Diamonds)
	{
		index->Draw();
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
	
	switch ( e.button )
	{
	case SDL_BUTTON_LEFT:

		Point2f mousePos{ float(e.x), float(e.y) };

		for (Diamond* index : m_Diamonds)
		{
			if (index->IsPointInDiamond(mousePos))
			{
				index->SetIsSelected(!index->GetIsSelected());
			}
		}
		break;
	}
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.f, 0.f, 0.f, 1.f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::CalculateRandomPos(Point2f& randomPos)
{
	randomPos.x = float(rand() % (int(m_Window.width - sqrtf(powf(48, 2) + powf(48, 2)))) + sqrtf(powf(48, 2) + powf(48, 2) / 2.f));
	randomPos.y = float(rand() % (int(m_Window.height - sqrtf(powf(48, 2) + powf(48, 2)))) + sqrtf(powf(48, 2) + powf(48, 2) / 2.f));
}