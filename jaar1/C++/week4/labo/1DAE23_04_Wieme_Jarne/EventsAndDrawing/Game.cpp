#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	GenerateRandomNumbersForRectangle();

	GenerateRandomNumbersForLine();

	g_SpaceLeftPlusRectWidth = g_SpaceLeftFromRect + g_RectWidth;

	g_Grey.r = 128.f / 255.f;
	g_Grey.g = 128.f / 255.f;
	g_Grey.b = 128.f / 255.f;

	SetColor(g_Grey);

	g_Green.g = 0.75f;

	std::cout << "Press 'r' to toggle the rectangle moving to the right.\n Press 'l'to toggle bouncing line.\n";
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	
	if (g_RectangleIsGrey == true)
	{
		SetColor(g_Grey);
	}

	FillRect(g_SpaceLeftFromRect, g_SpaceBelowRect, g_RectWidth, g_RectHeight);

	if (g_RectangleMovingState == true)
	{
		RectangleIsOfScreen();
	}

	if (g_BoucinglineState == true)
	{
		SetColor(g_Green);
		DrawLine(g_BouncingLinePoint1, g_BouncingLinePoint2);
	}
}

void Update(float elapsedSec)
{
	// process input, do physics
	RectangleMovingState();

	BouncingLineMovingState();

	g_SpaceLeftPlusRectWidth = g_SpaceLeftFromRect + g_RectWidth;
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
	case SDLK_r:
	{
		if (g_RectangleMovingState == false)
		{
			g_RectangleMovingState = true;
		}
		else
		{
			g_RectangleMovingState = false;
		}
		break;
	}
	case SDLK_l:
		if (g_BoucinglineState == false)
		{
			g_BoucinglineState = true;
		}
		else
		{
			g_BoucinglineState = false;
		}
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		if (g_RectangleIsGrey == true)
		{
			//changes the color of the grey rectangle if the left mouse button is clicked inside the rectangle
			if (    (mousePos.x > g_SpaceLeftFromRect)
				 && (mousePos.x < g_RectWidth + g_SpaceLeftFromRect)
				 && (mousePos.y > g_SpaceBelowRect)
				 && (mousePos.y < g_RectHeight + g_SpaceBelowRect) )
			{
				SetColor(g_Green);
				FillRect(g_SpaceLeftFromRect, g_SpaceBelowRect, g_RectWidth, g_RectHeight);
				g_RectangleIsGrey = false;
			}
		}
		else if (g_RectangleIsGrey == false)
		{
			if (    (mousePos.x > g_SpaceLeftFromRect)
				 && (mousePos.x < g_RectWidth + g_SpaceLeftFromRect)
				 && (mousePos.y > g_SpaceBelowRect)
				 && (mousePos.y < g_RectHeight + g_SpaceBelowRect) )
			{
				SetColor(g_Grey);
				GenerateRandomNumbersForRectangle();
				FillRect(g_SpaceLeftFromRect, g_SpaceBelowRect, g_RectWidth, g_RectHeight);
				g_RectangleIsGrey = true;
			}
		}
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

#pragma endregion ownDefinitions

void GenerateRandomNumbersForRectangle()
{
	g_SpaceLeftFromRect = float(rand() % 271 + 60);
	g_SpaceBelowRect = float(rand() % 311 + 40);
	g_RectWidth = float(rand() % 61 + 60);
	g_RectHeight = float(rand() % 41 + 40);

	
}

void GenerateRandomNumbersForLine()
{
	g_BouncingLinePoint1.x = float(rand() % int(g_WindowWidth));
	g_BouncingLinePoint1.y = float(rand() % int(g_WindowHeight));

	g_BouncingLinePoint2.x = float(rand() % int(g_WindowWidth));
	g_BouncingLinePoint2.y = float(rand() % int(g_WindowHeight));
}

void RectangleIsOfScreen()
{
	if (g_SpaceLeftPlusRectWidth > g_WindowWidth)
	{
		FillRect(g_NewSpaceLeftFromRect, g_SpaceBelowRect, g_NewRectWidth, g_RectHeight);

		--g_SpaceLeftPlusRectWidth;

		if (g_RectWidth > g_NewRectWidth)
		{
			++g_NewRectWidth;
		}
	}
}

void RectangleMovingState()
{
	if (g_RectangleMovingState == true)
	{
		if (g_NewRectWidth == g_RectWidth)
		{
			g_SpaceLeftFromRect = 0;
			g_NewRectWidth = 0;
		}
		++g_SpaceLeftFromRect;
	}
}

void BouncingLineMovingState()
{
	if (g_BoucinglineState == true)
	{
		//point x1 moving state
		if (g_BouncingLinePoint1.x == g_WindowWidth)
		{
			g_LinePoint1xMovingState = LinePoint1xMovingState::xDecreasing;
		}

		if (g_BouncingLinePoint1.x == 0)
		{
			g_LinePoint1xMovingState = LinePoint1xMovingState::xIncreasing;
		}

		//point y1 moving state
		if (g_BouncingLinePoint1.y == g_WindowHeight)
		{
			g_LinePoint1yMovingState = LinePoint1yMovingState::yDecreasing;
		}

		if (g_BouncingLinePoint1.y == 0)
		{
			g_LinePoint1yMovingState = LinePoint1yMovingState::yIncreasing;
		}

		//point x2 moving state
		if (g_BouncingLinePoint2.x == g_WindowWidth)
		{
			g_LinePoint2xMovingState = LinePoint2xMovingState::xDecreasing;
		}

		if (g_BouncingLinePoint2.x == 0)
		{
			g_LinePoint2xMovingState = LinePoint2xMovingState::xIncreasing;
		}

		//point y2 moving state
		if (g_BouncingLinePoint2.y == g_WindowHeight)
		{
			g_LinePoint2yMovingState = LinePoint2yMovingState::yDecreasing;
		}

		if (g_BouncingLinePoint2.y == 0)
		{
			g_LinePoint2yMovingState = LinePoint2yMovingState::yIncreasing;
		}
		
		//point x1 moving
		if (g_LinePoint1xMovingState == LinePoint1xMovingState::xDecreasing)
		{
			--g_BouncingLinePoint1.x;
		}
		else
		{
			++g_BouncingLinePoint1.x;
		}

		//point y1 moving
		if (g_LinePoint1yMovingState == LinePoint1yMovingState::yDecreasing) 
		{
			--g_BouncingLinePoint1.y;
		}
		else 
		{
			++g_BouncingLinePoint1.y;
		}

		//point x2 moving
		if (g_LinePoint2xMovingState == LinePoint2xMovingState::xDecreasing)
		{
			--g_BouncingLinePoint2.x;
		}
		else
		{
			++g_BouncingLinePoint2.x;
		}

		//point y1 moving
		if (g_LinePoint2yMovingState == LinePoint2yMovingState::yDecreasing)
		{
			--g_BouncingLinePoint2.y;
		}
		else
		{
			++g_BouncingLinePoint2.y;
		}
	}
}
