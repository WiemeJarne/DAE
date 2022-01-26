#include "pch.h"
#include "Game.h"
#include <iostream>
#include <iomanip>
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawRedDecagon();
	DrawCrosier();
}																																								   

void Update(float elapsedSec)
{
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
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
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
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawRedDecagon()
{
	SetColor(1.f, 0.f, 0.f);

	const int numberOfPoints{ 10 };
	float angle{};
	for (int pointNumber{ 1 }; pointNumber <= numberOfPoints; ++pointNumber)
	{
		DrawLine(100 * cosf(float(angle + pointNumber * (M_PI / 5))) + 125, 125 * sinf(float(angle + pointNumber * (M_PI / 5))) + 150,
			100 * cosf(float(angle + (pointNumber + 1) * (M_PI / 5))) + 125, 125 * sinf(float(angle + (pointNumber + 1) * (M_PI / 5))) + 150);
	}
}

void DrawCrosier()
{
	SetColor(0.f, 0.f, 1.f);
	float angle{ float(M_PI / 2) };
	float opening{ g_WindowWidth / 4 };
	float numberOfWindings{ 8 };
	for (float radius{opening/sqrt(angle)}; angle <= ( numberOfWindings * (2*M_PI) + (M_PI/2) ); angle += 0.01f)
	{
		DrawLine(radius * cosf(angle) + 350, radius * sinf(angle) + 150, radius * cosf(angle + 0.01f) + 350, radius * sinf(angle + 0.01f) + 150);
		radius = opening / sqrt(angle);
	}
}

#pragma endregion ownDefinitions