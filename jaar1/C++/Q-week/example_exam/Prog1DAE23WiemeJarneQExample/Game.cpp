#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	Generate();
	PrintRandomNumbers();
	g_Red.r = 1.f;
	g_Green.g = 1.f;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawElevator();
}

void Update(float elapsedSec)
{
	// process input, do physics
	g_Time += elapsedSec;

	if (g_Time >= 1)
	{
		Generate();
		PrintRandomNumbers();

		g_Time = 0;
	}

	if (g_ElevatorIsMoving == true)
	{
		g_TimeForElevator += 0.01f;
		g_SpaceBelowElevator = 90 * sinf( g_Pi * g_TimeForElevator + 3 * (g_Pi/2) ) + 120;
		DrawElevator();
	}

	if (cosf(g_Pi * g_TimeForElevator + 3 * (g_Pi / 2)) <= 1 && cosf(g_Pi * g_TimeForElevator + 3 * (g_Pi / 2)) >= 0)
	{
		g_ElevatorIsGoingUp = true;
	}
	else
	{
		g_ElevatorIsGoingUp = false;
	}

	if (g_ElevatorIsGoingUp == true)
	{
		g_ElevatorInteriorColor = g_Red;
	}

	if (g_ElevatorIsGoingUp == false && g_ElevatorIsMoving)
	{
		g_ElevatorInteriorColor = g_Green;
	}

	if (g_ElevatorIsMoving == false)
	{
		g_ElevatorInteriorColor = g_Black;
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
	switch (key)
	{
	case SDLK_n:
		Generate();
		PrintRandomNumbers();
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
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		g_MousePos = Point2f( float( e.x ), float( g_WindowHeight - e.y ) );
		g_LeftMouseButtonClicked = true;
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void Generate()
{
	g_Even = rand() % 10;

	if (g_Even % 2 == 1)
	{
		g_Even -= 1;
	}

	g_Odd = rand() % 10;

	if (g_Odd % 2 == 0)
	{
		g_Odd += 1;
	}

	g_Any = rand() % 10;
}

void PrintRandomNumbers()
{
	std::cout << "Even: " << g_Even << ", odd: " << g_Odd << ", any: " << g_Any << "\n";
}

void DrawElevator()
{
	const float exteriorElevatorWidth{40};
	const float exteriorElevatorHeight{ 60 };

	const float wallThickness{ 10 };

	const float interiorElevatorWidth{ exteriorElevatorWidth - ( 2 * wallThickness ) };
	const float interiorElevatorHeight{ exteriorElevatorHeight - ( 2 * wallThickness ) };

	const float spaceLeftFromElevator{g_WindowWidth - 30 - exteriorElevatorWidth };

	const float spaceLeftFromInterior{ spaceLeftFromElevator + wallThickness };
	const float spaceBelowInterior{ g_SpaceBelowElevator + wallThickness };
	
	if ( (    g_MousePos.x >= spaceLeftFromElevator 
		   && g_MousePos.x <= (spaceLeftFromElevator + exteriorElevatorWidth)
		   && g_MousePos.y >= g_SpaceBelowElevator
		   && g_MousePos.y <= (g_SpaceBelowElevator + exteriorElevatorHeight) 
		   && !( (g_MousePos.x >= spaceLeftFromInterior)
			     && (g_MousePos.x <= spaceLeftFromInterior + interiorElevatorWidth)
		         && (g_MousePos.y >= spaceBelowInterior)
				 && (g_MousePos.y <= spaceBelowInterior + interiorElevatorHeight)   ) ) && !g_ElevatorIsMoving && g_LeftMouseButtonClicked )
	{
		g_ElevatorIsMoving = true;
		g_LeftMouseButtonClicked = false;
	}
	else if(g_LeftMouseButtonClicked)
	{
		g_ElevatorIsMoving = false;
		g_LeftMouseButtonClicked = false;
	}

	SetColor(0.f, 0.f, 1.f);
	FillRect(spaceLeftFromElevator, g_SpaceBelowElevator, exteriorElevatorWidth, exteriorElevatorHeight);

	SetColor(g_ElevatorInteriorColor);
	FillRect(spaceLeftFromInterior, spaceBelowInterior, interiorElevatorWidth, interiorElevatorHeight);
}

#pragma endregion ownDefinitions