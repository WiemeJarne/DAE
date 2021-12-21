#include "pch.h"
#include "Game.h"
#include "Sprite.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	int index{};

	const std::string knightFileLocation{ "Resources/RunningKnight.png"};
	const std::string tiboFileLocation{ "Resources/Tibo.png" };

	const int framesPerSecond{ 20 };
	const float secondsPerFrame{ 1.f / framesPerSecond };

	const int knightAmountOfRows{ 1 }, knightAmountOfColumns{ 8 };
	const int tiboAmountOfRows  { 5 }, tiboAmountOfColumns  { 5 };

	g_MySpritesArr[index++] = new Sprite(knightFileLocation, knightAmountOfColumns, knightAmountOfRows, framesPerSecond, 1.f);
	g_MySpritesArr[index++] = new Sprite(knightFileLocation, knightAmountOfColumns, knightAmountOfRows, framesPerSecond, 0.5f);
	g_MySpritesArr[index++] = new Sprite(knightFileLocation, knightAmountOfColumns, knightAmountOfRows, framesPerSecond, 0.33f);
	g_MySpritesArr[index++] = new Sprite(tiboFileLocation, 	 tiboAmountOfColumns,   tiboAmountOfRows,   framesPerSecond, 1.f);
	g_MySpritesArr[index++] = new Sprite(tiboFileLocation,	 tiboAmountOfColumns,   tiboAmountOfRows,   framesPerSecond, 1.f);
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	for (int index{}; index < g_AmountOfSprites; ++index)
	{
		g_MySpritesArr[index]->Draw(g_MySpritesLocationArr[index]);
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	for (int index{}; index < g_AmountOfSprites; ++index)
	{
		g_MySpritesArr[index]->Update(elapsedSec);
	}

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