#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

double Sin1(double hoek) // hoek tussen 0.0 en 1.0
{
	return sin(2.0 * hoek * M_PI);
}

float Sin1f(float hoek) // hoek tussen 0.0 en 1.0
{
	return float(sin(2.0 * hoek * M_PI));
}

void Draw()
{
	ClearBackground();
	const int maxFrames{ 300 };
	// Put your own draw statements here
	GrowingBar();
	//std::cout << "Sin van: " << g_NrFrames << " op " << maxFrames << ": " << Sin1( double(g_NrFrames) / maxFrames ) << std::endl;

	const int lijnLengte{ 100 };

	switch (g_Direction)
	{
	case Direction::left:
		DrawLine( g_WindowWidth  / 2,
			      g_WindowHeight / 2,
			      g_WindowWidth  / 2 - lijnLengte,
			      g_WindowHeight / 2                );
		break;
	case Direction::right:
		DrawLine( g_WindowWidth  / 2,
			      g_WindowHeight / 2,
			      g_WindowWidth  / 2 + lijnLengte,
			      g_WindowHeight / 2                );
		break;
	case Direction::up:
		DrawLine( g_WindowWidth  / 2,
				  g_WindowHeight / 2,
				  g_WindowWidth  / 2,
				  g_WindowHeight / 2 + lijnLengte   );
		break;
	case Direction::down:
		DrawLine( g_WindowWidth  / 2,
				  g_WindowHeight / 2,
				  g_WindowWidth  / 2,
				  g_WindowHeight / 2 - lijnLengte   );
		break;
	}
}

void Update(float elapsedSec)
{
	g_NrFrames++;
	
	// process input, do physics 

	// e.g. Check keyboard state
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

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	switch (key)
	{
	case SDLK_LEFT:
		//std::cout << "Left arrow key released\n";
		g_Direction = Direction::left;
		break;
	case SDLK_RIGHT:
		//std::cout << "Right arrow key released\n";
		g_Direction = Direction::right;
		break;
	case SDLK_UP:
		//std::cout << "Key 1 released\n";
		g_Direction = Direction::up;
		break;
	case SDLK_DOWN:
		//std::cout << "Key 1 released\n";
		g_Direction = Direction::down;
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		std::cout << "Left mouse button released\n";
		//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		break;
	}
	case SDL_BUTTON_RIGHT:
		std::cout << "Right mouse button released\n";
		break;
	case SDL_BUTTON_MIDDLE:
		std::cout << "Middle mouse button released\n";
		break;
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions

void GrowingBar()
{
	const float spaceLeftFromRectangle{20.f};
	float spaceBelowRectangle{ ( g_WindowHeight / 2.f ) + 50 };
	const float rectangleWidth{ 460.f };
	const float rectangleHeight{ 70.f };
	const float lineWidth{ 3.f };

	float yellowProgresBarx{ float(g_NrFrames % 460) };
	float redProgresBarx{ float((( 15 + g_NrFrames ) / 2 ) % 460) };
	float redValue{ 120.f / 255.f + g_NrFrames / 7.5f / 255.f };

	SetColor(1.f, 1.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, yellowProgresBarx, rectangleHeight);

	spaceBelowRectangle = (g_WindowHeight / 2) - 125;

	SetColor(redValue, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, redProgresBarx, rectangleHeight);

	spaceBelowRectangle = (g_WindowHeight / 2.f) + 50;

	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWidth, rectangleHeight, lineWidth);

	spaceBelowRectangle = (g_WindowHeight / 2) - 125;

	DrawRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWidth, rectangleHeight, lineWidth);
}