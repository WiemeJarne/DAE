#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_CircleXStartValue = float(rand() % int(g_WindowWidth));
	g_CircleYStartValue = float(rand() % int(g_WindowHeight));

	g_CircleSpeedXPerSeconds = float(rand() % 51 + 100);
	g_CircleSpeedYPerSeconds = float(rand() % 41 + 80);

	std::cout << "CircleXSpeedPerSeconds = " << g_CircleSpeedXPerSeconds << "\nCircleYSpeedPerSeconds = " << g_CircleSpeedYPerSeconds;

	g_CircleX = g_CircleXStartValue;
	g_CircleY = g_CircleYStartValue;
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawBall();
}

void Update(float elapsedSec)
{
	// process input, do physics 
	++g_NrFrames;
	g_AccumulatedTime += elapsedSec;

	//std::cout << g_ElapsedTime << '\n';

	UpdateBall(elapsedSec);
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
void UpdateBall(float elapsedSec)
{
	CheckIfBallHitBorder();

	g_CircleX += g_CircleSpeedXPerSeconds * elapsedSec * (g_CirclePositiveDirectionX ? 1 : -1);
	g_CircleY += g_CircleSpeedYPerSeconds * elapsedSec * (g_CirclePositiveDirectionY ? 1 : -1);
}

void DrawBall()
{
	FillEllipse(g_CircleX, g_CircleY, g_CircleRadius, g_CircleRadius);
}

void CheckIfBallHitBorder()
{
	if (g_CircleX + g_CircleRadius >= g_WindowWidth || g_CircleX - g_CircleRadius <= 0)
	{
		g_CirclePositiveDirectionX = !g_CirclePositiveDirectionX;
	}

	if (g_CircleY + g_CircleRadius >= g_WindowHeight || g_CircleY - g_CircleRadius <= 0)
	{
		g_CirclePositiveDirectionY = !g_CirclePositiveDirectionY;
	}
}
#pragma endregion ownDefinitions