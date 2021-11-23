#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_RandomRadius = float( rand() % 16 + 25 );
	g_RandomMiddlePoint.x = float( rand() % int(g_WindowWidth - 2 * g_RandomRadius) + g_RandomRadius );
	g_RandomMiddlePoint.y = float( rand() % int(g_WindowHeight - 2 * g_RandomRadius) + g_RandomRadius );

	g_Circle.radius = g_RandomRadius;
	g_Circle.center.x = g_RandomMiddlePoint.x;
	g_Circle.center.y = g_RandomMiddlePoint.y;

	g_RandomRectangleHeight = float(rand() % 11 + 10);
	g_RandomRectangleWitdh = float(rand() % 6 + 30);
	g_RandomLeftBottomRectanglePoint.x = float(rand() % int(g_WindowWidth - 2 * g_RandomRectangleWitdh) + g_RandomRectangleWitdh);
	g_RandomLeftBottomRectanglePoint.y = float(rand() % int(g_WindowHeight - 2 * g_RandomRectangleHeight) + g_RandomRectangleHeight);

	g_Rectangle.left = g_RandomLeftBottomRectanglePoint.x;
	g_Rectangle.bottom = g_RandomLeftBottomRectanglePoint.y;
	g_Rectangle.width = g_RandomRectangleWitdh;
	g_Rectangle.height = g_RandomRectangleHeight;
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	
	SetColor(1.f, 1.f, 1.f);
	FillEllipse(g_Circle.center.x, g_Circle.center.y, g_Circle.radius, g_Circle.radius);

	FillRect(g_RandomLeftBottomRectanglePoint, g_RandomRectangleWitdh, g_RandomRectangleHeight);

	if (IsPointInCircle(g_MousePos, g_Circle))
	{
		SetColor(1.f, 0.f, 0.f);
		DrawEllipse(g_Circle.center.x, g_Circle.center.y, g_Circle.radius, g_Circle.radius, 3.f);
	}

	if (IsPointInRect(g_MousePos, g_Rectangle))
	{
		SetColor(1.f, 0.f, 0.f);
		DrawRect(g_RandomLeftBottomRectanglePoint, g_RandomRectangleWitdh, g_RandomRectangleHeight);
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
	g_MousePos = Point2f( float( e.x ), float( g_WindowHeight - e.y ) );
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