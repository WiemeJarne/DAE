#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground();

	SetColor(255 / 255.f, 0.f, 0.f);
	DrawLine(2.f, 2.f, 498.f, 298.f);
	DrawLine(2.f, 298.f, 498.f, 2.f);

	SetColor(255 / 255.f, 255 / 255.f, 255 / 255.f);
	DrawLine(2.f, g_WindowHeight - 200, g_WindowWidth - 2, g_WindowHeight - 200);
	DrawLine(2.f, g_WindowHeight - 100, g_WindowWidth - 2, g_WindowHeight - 100);
	DrawLine(g_WindowWidth / 3, 2.f, g_WindowWidth / 3, g_WindowHeight);
	DrawLine((g_WindowWidth / 3 ) * 2, 2.f, ( g_WindowWidth / 3 ) * 2, g_WindowHeight);

	SetColor(0.f, 0.f, 255 / 255.f);
	FillEllipse(250.f, 150.f, 3.f, 3.f);

	SetColor(0.0f, 255 / 255.0f, 0.0f);
	DrawRect(1.f, 1.f, g_WindowWidth - 2.0f, g_WindowHeight - 2.0f);


	FillRect(10, 10, 100, 25);
	// Put your own draw statements here
	std::cout << "Draw uitgevoerd." << std::endl;


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

#pragma endregion ownDefinitions