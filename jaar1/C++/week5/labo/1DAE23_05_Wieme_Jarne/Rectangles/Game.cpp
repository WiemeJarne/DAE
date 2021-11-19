#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	//ClearBackground();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	const int amountOfRectangles{ 100 };
	for (int rectangleNumber{}; rectangleNumber <= amountOfRectangles; ++rectangleNumber)
	{
		RandomRectangles();
	}

	Sleep(500);
}


void RandomRectangles()
{
	const int border{ 10 };

	const float rectWidth{ float(rand() % (771 - 2 * border) ) + 10 };
	const float rectHeight{ float(rand() % (471 - 2 * border) ) + 10 };
	const float spaceLeftFromRectangle{ float(rand() % int(g_WindowWidth - rectWidth - 2 * border)) + border };
	const float spaceBelowRectangle{ float(rand() % int(g_WindowHeight - rectHeight - 2 * border)) + border };

	const float rValue{ float(rand() % 255) / 255.f };
	const float gValue{ float(rand() % 255) / 255.f };
	const float bValue{ float(rand() % 255) / 255.f };

	SetColor(rValue, gValue, bValue);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectWidth, rectHeight);

	SetColor(0.f, 0.f, 0.f);
	DrawRect(spaceLeftFromRectangle, spaceBelowRectangle, rectWidth, rectHeight);
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
