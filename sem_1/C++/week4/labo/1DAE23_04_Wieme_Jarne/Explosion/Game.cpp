#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	SetColor(g_Black);

	g_TransparentBlack.a = 0.5f;

	g_Red.r = 1.f;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	

	if (g_BombsWasClicked == true)
	{
		SetColor(g_TransparentBlack);
		FillRect(g_SpaceLeftFromBomb, g_SpaceBelowBomb, g_RectAndBombWidth, g_RectAndBombHeight);

		SetColor(g_Red);
		DrawExplosion();
	}
	else
	{
		SetColor(g_Black);
		FillRect(g_SpaceLeftFromBomb, g_SpaceBelowBomb, g_RectAndBombWidth, g_RectAndBombHeight);
	}

	if ((g_SpaceLeftFromRect1 + g_RectAndBombWidth) == -5)
	{
		g_ExplosionIsOver = true;
		g_BombsWasClicked = false;
	}

	if (g_ExplosionIsOver == true)
	{
		g_SpaceLeftFromRect1 =  g_SpaceLeftFromBomb;
		g_SpaceBelowRect1 = g_SpaceBelowBomb;

		g_SpaceLeftFromRect2 = g_SpaceLeftFromBomb;
		g_SpaceBelowRect2 =  g_SpaceBelowBomb;

		g_SpaceLeftFromRect3 =  g_SpaceLeftFromBomb;
		g_SpaceBelowRect3 = g_SpaceBelowBomb;

		g_SpaceLeftFromRect4 = g_SpaceLeftFromBomb;
		g_SpaceBelowRect4 = g_SpaceBelowBomb;

		g_ExplosionIsOver = false;
	}
}

void Update(float elapsedSec)
{
	// process input, do physics
	if (g_BombsWasClicked == true)
	{
		UpdateExplosion();
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		g_MousePos.x = float(e.x);
		g_MousePos.y = float(g_WindowHeight - e.y);
		ProcessMouseClick();
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions

void ProcessMouseClick()
{
	if ((g_MousePos.x > g_SpaceLeftFromBomb)
		&& (g_MousePos.x < g_RectAndBombWidth + g_SpaceLeftFromBomb)
		&& (g_MousePos.y > g_SpaceBelowBomb)
		&& (g_MousePos.y < g_RectAndBombHeight + g_SpaceBelowBomb))
	{
		g_BombsWasClicked = true;
	}
}

void UpdateExplosion()
{
	//rectangle 1
	--g_SpaceLeftFromRect1;
	++g_SpaceBelowRect1;

	//rectangle 2
	++g_SpaceLeftFromRect2;
	++g_SpaceBelowRect2;

	//rectangle 3
	++g_SpaceLeftFromRect3;
	--g_SpaceBelowRect3;

	//rectangle 4
	--g_SpaceLeftFromRect4;
	--g_SpaceBelowRect4;
}

void DrawExplosion()
{
	//rectangle 1
	FillRect(g_SpaceLeftFromRect1, g_SpaceBelowRect1, g_RectAndBombWidth, g_RectAndBombHeight);

	//rectangle 2
	FillRect(g_SpaceLeftFromRect2, g_SpaceBelowRect2, g_RectAndBombWidth, g_RectAndBombHeight);

	//rectangle 3
	FillRect(g_SpaceLeftFromRect3, g_SpaceBelowRect3, g_RectAndBombWidth, g_RectAndBombHeight);

	//rectangle 4
	FillRect(g_SpaceLeftFromRect4, g_SpaceBelowRect4, g_RectAndBombWidth, g_RectAndBombHeight);
}