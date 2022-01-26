#include "pch.h"
#include "Game.h"
#include <iostream>
//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	int number{ rand() % 11 };
	if (number < 5)
	{
		std::cout << "Number is smaller then 5. \n ";
	}
	else
	{
		std::cout << "Number is bigger then 4. \n";
	}

	g_Position.x = g_WindowWidth / 2;
	g_Position.y = g_WindowHeight / 2;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	SetColor(1.f, 0.f, 0.f, 1.f);
	FillEllipse(g_Position, 10, 10);
}

void Update(float elapsedSec)
{
	// process input, do physics 
	const int speed{ 1 };
	switch (g_CircleState)
	{
	case CircleState::left:
		g_Displacement.x = -speed;
		g_Displacement.y = 0;
		break;
	case CircleState::right:
		g_Displacement.x = +speed;
		g_Displacement.y = 0;
		break;
	case CircleState::up:
		g_Displacement.y = +speed;
		g_Displacement.x = 0;
		break;
	case CircleState::down:
		g_Displacement.y = -speed;
		g_Displacement.x = 0;
		break;
	case CircleState::nothing:
		break;
	}
	
	if (g_Position.x > g_WindowWidth)
	{
		g_CircleState = CircleState::left;
	}

	if (g_Position.x < 0)
	{
		g_CircleState = CircleState::right;
	}

	if (g_Position.y > g_WindowHeight)
	{
		g_CircleState = CircleState::down;
	}

	if (g_Position.y < 0)
	{
		g_CircleState = CircleState::up;
	}
	g_Position.x += g_Displacement.x;
	g_Position.y += g_Displacement.y;
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
	const int speed{ 1 };
	switch (key)
	{
	case SDLK_LEFT:
		//std::cout << "Left arrow key released\n";
		g_CircleState = CircleState::left;
		break;
	case SDLK_RIGHT:
		//std::cout << "Right arrow key released\n";
		g_CircleState = CircleState::right;
		break;
	case SDLK_UP:
		//std::cout << "Up arrow key released\n";
		g_CircleState = CircleState::up;
		break;
	case SDLK_DOWN:
		//std::cout << "Donw arrow key released\n";
		g_CircleState = CircleState::down;
		break;
	default:
		g_CircleState = CircleState::nothing;
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