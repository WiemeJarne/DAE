#include "pch.h"
#include "Game.h"

Game::Game( const Window& window ) 
	:m_Window{ window }
	,m_StreamMenuText{ "Resources/Images/StreamsMenu.png" }
	,m_EffectMenuText { "Resources/Images/EffectsMenu.png" }
	,m_StreamTest {true}
	// TODO: 1. Create the DonkeyKong and Mario SoundStream objects
	
	// TODO: 4. Create the Laser and Jingles SoundEffect objects

{
	Initialize( );
}

Game::~Game( )
{
	Cleanup( );
}

void Game::Initialize( )
{
	TestContainer( );
}

void Game::Cleanup( )
{
}

void Game::Update( float elapsedSec )
{
}

void Game::Draw( ) const
{
	ClearBackground( );
	DrawMenu( );
}

void Game::ProcessKeyDownEvent( const SDL_KeyboardEvent & e )
{
	switch ( e.keysym.sym )
	{
	case SDLK_RIGHT:
	case SDLK_LEFT:
		SwitchTest( );
		break;
	default:
		// Handle user request
		if ( m_StreamTest )
		{
			TestStreams( e );
		}
		else
		{
			TestEffects( e );
		}
	}
}

void Game::ProcessKeyUpEvent( const SDL_KeyboardEvent& e )
{
}

void Game::ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e )
{
}

void Game::ProcessMouseDownEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ProcessMouseUpEvent( const SDL_MouseButtonEvent& e )
{
}

void Game::ClearBackground( ) const
{
	glClearColor( 0.0f, 0.0f, 0.0f, 1.0f );
	glClear( GL_COLOR_BUFFER_BIT );
}

void Game::DrawMenu( ) const
{
	if ( m_StreamTest )
	{
		m_StreamMenuText.Draw( );
	}
	else
	{
		m_EffectMenuText.Draw( );
	}
}

void Game::SwitchTest( )
{
	if ( m_StreamTest )
	{
		// TODO: 3. User switches to the "Effect test", stop the music
	}
	else
	{
		// TODO: 6. User switches to the "Stream test", stop the effects
	}
	m_StreamTest = !m_StreamTest;
}

void Game::TestStreams( const SDL_KeyboardEvent& e )
{
	// TODO: 2. Handle the user requests in the "Stream test" menu 
	switch ( e.keysym.sym )
	{
	case SDLK_1:
	case SDLK_KP_1:
		// Play Donkey Kong (repeated)
		break;
	case SDLK_2:
	case SDLK_KP_2:
		// Play Mario (not repeated)
		break;
	case SDLK_p:
		// Pause the SoundStream
		break;
	case SDLK_r:
		// Resume the SoundStream
		break;
	case SDLK_s:
		// Stop the SoundStream
		break;
	case SDLK_UP:
		// Increase volume of SoundStream
		break;
	case SDLK_DOWN:
		// Decrease volume of SoundStream
		break;
	}
}

void Game::TestEffects( const SDL_KeyboardEvent& e )
{
	// TODO: 5. Handle the user requests in the "Effect test" menu 
	switch ( e.keysym.sym )
	{
	case SDLK_1:
	case SDLK_KP_1:
		// Play laser (repeated)
		break;
	case SDLK_2:
	case SDLK_KP_2:
		// Play jingles (a number of times)
		break;
	case SDLK_p:
		// Pause all soundEffects
		break;
	case SDLK_r:
		// Resume all soundEffects
		break;
	case SDLK_s:
		// Stop  all soundEffects
		break;
	case SDLK_UP:
		// Increase volume of all SoundEffects
		break;
	case SDLK_DOWN:
		// Decrease volume of all SoundEffects
		break;
	}
}

void Game::AddValues(Container& c, int nr, int min, int max)
{
	for (int index{}; index < nr; ++index)
	{
		c.PushBack(rand() % (max - min + 1) + min);
	}
}

void Game::TestContainer( )
{
	Container c1{};
	AddValues(c1, 3, 1, 10);

	Container c2{ c1 };
	c1[0] = 20;

	Container c3{ 3 };
	AddValues(c3, 3, 10, 20);
	c3 = c1;

	c3 = c3;

	//c3 = 4;

	Container c4 = c1;

	c4 = c2;

	c4 = CreateMultiplied(c1, 2);
}

Container Game::CreateMultiplied(Container c, int factor)
{
	for (int index{}; index < c.Size( ); ++index)
	{
		c[index] *= factor;
	}
	
	return c;
}