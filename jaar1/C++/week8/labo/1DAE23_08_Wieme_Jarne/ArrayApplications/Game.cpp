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
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	if (g_amountOfPointsInPointsClicked >= 1)
	{
		DrawClickedPoints();
	}

	if (g_amountOfPointsInPointsClicked >= 2)
	{
		ConnectClickedPoints();
	}
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		Point2f mousePos = Point2f(float(e.x), float(g_WindowHeight - e.y));
		AddClickedPoint(mousePos);
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void AddClickedPoint(Point2f mousePos)
{
	if (g_amountOfPointsInPointsClicked == 5)
	{
		for (int index{}; index < g_MaxNumberOfClickedPoints - 1; ++index)
		{
			g_PointsClicked[index] = g_PointsClicked[index + 1];
		}
		g_PointsClicked[g_IndexNextPoint] = mousePos;
	}
	else
	{
		g_PointsClicked[g_IndexNextPoint] = mousePos;
		++g_amountOfPointsInPointsClicked;
		if (g_IndexNextPoint != 4)
		{
			++g_IndexNextPoint;
		}
	}
}

void DrawClickedPoints()
{
	float dotRadius{ 5.f };
	
	for (int index{}; index < g_amountOfPointsInPointsClicked; ++index)
	{
		SetColor(1.f, 0.f, 0.f);
		FillEllipse(g_PointsClicked[index].x, g_PointsClicked[index].y, dotRadius, dotRadius);
	}
}

void ConnectClickedPoints()
{
	for (int index{}; index < g_amountOfPointsInPointsClicked - 1; ++index)
	{
		if (g_amountOfPointsInPointsClicked > 1)
		{
			SetColor(1.f, 1.f, 1.f);
			DrawLine(g_PointsClicked[index].x, g_PointsClicked[index].y, g_PointsClicked[index + 1].x, g_PointsClicked[index + 1].y);
		}
	}

}
#pragma endregion ownDefinitions