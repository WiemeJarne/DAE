#include "pch.h"
#include "Game.h"
#include "Sprite.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	int index{};

	g_MySpritesArr[index++] = new Sprite(g_KnightFileLocation, g_KnightAmountOfColumns, g_KnightAmountOfRows, g_SecondsPerFrame, 1.f);
	g_MySpritesArr[index++] = new Sprite(g_KnightFileLocation, g_KnightAmountOfColumns, g_KnightAmountOfRows, g_SecondsPerFrame, 0.5f);
	g_MySpritesArr[index++] = new Sprite(g_KnightFileLocation, g_KnightAmountOfColumns, g_KnightAmountOfRows, g_SecondsPerFrame, 0.33f);
	g_MySpritesArr[index++] = new Sprite(g_TiboFileLocation, 	 g_TiboAmountOfColumns,   g_TiboAmountOfRows,	g_SecondsPerFrame, 1.f);
	g_MySpritesArr[index++] = new Sprite(g_TiboFileLocation,	 g_TiboAmountOfColumns,   g_TiboAmountOfRows,	g_SecondsPerFrame, 1.f);
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	for (int index{}; index < g_AmountOfSprites; ++index)
	{
		if (g_MySpritesArr[index] != nullptr)
			g_MySpritesArr[index]->Draw(g_MySpritesLocationArr[index]);
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	for (int index{}; index < g_AmountOfSprites; ++index)
	{
		if(g_MySpritesArr[index] != nullptr)
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
	for (int index{}; index < g_AmountOfSprites; ++index)
	{
		delete g_MySpritesArr[index];
	}
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