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
	std::cout << "+: Add a number at the end of the vector\n";
	std::cout << "-: Remove last number from the vector\n";
	std::cout << "^: Increment all numbers in the vector\n";
	std::cout << "v: Decrement all numbers in the vector\n";

	InitializeCards();
}

void Game::Cleanup( )
{
	for (int index{}; index < m_Cards.size(); ++index)
	{
		delete m_Cards[index];
	}
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

	Game::DrawCards( );
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch (e.keysym.sym)
	{
	case SDLK_EQUALS:
		m_IntNumbers.push_back( rand() % 31 );
		PrintIntVectorElements(m_IntNumbers);
		break;

	case SDLK_MINUS:
		m_IntNumbers.pop_back();
		PrintIntVectorElements(m_IntNumbers);
		break;

	case SDLK_UP:
		for (int index{}; index < m_IntNumbers.size(); ++index)
		{
			++m_IntNumbers[index];
		}
		PrintIntVectorElements(m_IntNumbers);
		break;

	case SDLK_DOWN:
		for (int index{}; index < m_IntNumbers.size(); ++index)
		{
			--m_IntNumbers[index];
		}
		PrintIntVectorElements(m_IntNumbers);
		break;

	case SDLK_s:
		for (int index{}; index < m_Cards.size(); ++index)
		{
			delete m_Cards[index];
		}
		m_Cards.clear();
		InitializeCards();
		break;
	}
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

void Game::PrintIntVectorElements(std::vector<int> vector)
{
	for (int index : vector)
	{
		std::cout << index << " ";
	}

	std::cout << "\n";
}

void Game::DrawCards() const
{
	const float scaleFactor{ 0.5f };
	const int amountOfRows{ 4 };
	const int amountOfColumns{ 13 };
	int cardNumber{ };

	Rectf destRect{};
	destRect.bottom = 0;
	destRect.left = 0;
	destRect.width = m_Cards[0]->GetWidth() * scaleFactor;
	destRect.height = m_Cards[0]->GetHeight() * scaleFactor;

	for (int rowNumber{}; rowNumber < amountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < amountOfColumns; ++columnNumber)
		{
			m_Cards[cardNumber]->Draw(destRect);

			++cardNumber;

			destRect.left += m_Cards[1]->GetWidth() * scaleFactor / 2;
		}
		destRect.left = 0;
		destRect.bottom += m_Cards[1]->GetHeight() * scaleFactor;
	}
}

void Game::InitializeCards()
{
	for (int suit{ 1 }; suit <= m_AmountOfSuits; ++suit)
	{
		for (int rank{ 1 }; rank <= m_AmountOfRanks; ++rank)
		{
			m_Cards.push_back( new Card{Card::Suit{suit}, rand() % 13 + 1});
		}
	}
}