#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	PrintLetters();
	std::cout << '\n';

	g_Red.r = 1.f;
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	if (g_CircleIsDrawing == true)
	{
		DrawCircle();
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (g_CircleIsDrawing)
	{
		Check_g_CircleDrawingState();

		CheckIfCircleTouchesWindowEdge();

		Check_g_Radius();
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
	case SDLK_UP:

		if (g_Speed < 5.f)
		{
			g_Speed += 0.4f;
		}

		if (g_Speed >= 5.2f)
		{
			g_Speed = 5.f;
		}

		std::cout << "\ng_Speed = " << g_Speed;
		break;

	case SDLK_DOWN:

		if (g_Speed > 0.2f)
		{
			g_Speed -= 0.4f;
		}

		if (g_Speed < 0.1f )
		{
			g_Speed = 0.2f;
		}

		std::cout << "\ng_Speed = " << g_Speed;
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
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		if (g_CircleIsDrawing == false)
		{
			g_CircleDrawingState = g_CircleState::circleIsGrowing;

			GenerateRandomColorAndRadius();

			SetColor(g_CircleColor);

			g_MousePos = Point2f(float(e.x), float(g_WindowHeight - e.y));
			
			std::cout << "\nThe maximum radius is " << g_RandomMaxRadius << '\n';
			std::cout << "Growing state.\n";

			g_CircleIsDrawing = true;
		}
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void PrintLetters()
{
	char letter{ 'a' };

	int numberOfCharactersPerLine{};

	std::cout << "How many characters per line ?";

	std::cin >> numberOfCharactersPerLine;

	std::cout << '\n';

	for (int loopNumber{ 1 }; loopNumber <= numberOfCharactersPerLine; ++loopNumber)
	{
		std::cout << letter;
		++letter;

		if (loopNumber == numberOfCharactersPerLine)
		{
			std::cout << '\n';
			loopNumber = 0;
		}

		if (letter == 'z' + 1)
		{
			loopNumber = numberOfCharactersPerLine + 1;
		}
	}

}

void DrawCircle()
{

	FillEllipse(g_MousePos, g_Radius, g_Radius);
	
	
}

void Check_g_CircleDrawingState()
{
	if (g_CircleDrawingState == g_CircleState::circleIsGrowing)
	{
		g_Radius += g_Speed;
	}

	if (g_CircleDrawingState == g_CircleState::circleIsShrinking)
	{
		g_Radius -= g_Speed;
	}
}

void CheckIfCircleTouchesWindowEdge()
{
	if (    g_MousePos.x + g_Radius >= g_WindowWidth
		 || g_MousePos.x - g_Radius <= 0
		 || g_MousePos.y + g_Radius >= g_WindowHeight
		 || g_MousePos.y - g_Radius <= 0              )
	{
		SetColor(g_Red);

		std::cout << "Ouch!\nShrinking state.\n";

		g_CircleDrawingState = g_CircleState::circleIsShrinking;
	}
}

void GenerateRandomColorAndRadius()
{
	g_CircleColor.r = float( (rand() % 255) / 255.f );
	g_CircleColor.g = float( (rand() % 255) / 255.f );
	g_CircleColor.b = float( (rand() % 255) / 255.f );

	g_RandomMaxRadius = rand() % 101 + 50;
}

void Check_g_Radius()
{
	if (g_Radius >= g_RandomMaxRadius)
	{
		g_CircleDrawingState = g_CircleState::circleIsShrinking;
		std::cout << "Shrinking state.\n";
	}

	if (g_Radius <= 0)
	{
		g_CircleDrawingState = g_CircleState::noCircle;
		g_CircleIsDrawing = false;

		std::cout << "Waiting state.\n";
	}
}
#pragma endregion ownDefinitions