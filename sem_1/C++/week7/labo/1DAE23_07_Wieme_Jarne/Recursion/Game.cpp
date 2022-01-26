#include "pch.h"
#include "Game.h"

#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_Red.r = 1.f;

	g_Blue.b = 1.f;

	g_Green.g = 1.f;
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	Point2f leftPoint{ 0.f,0.f };
	Point2f topPoint{ g_WindowWidth / 2, g_WindowHeight };
	Point2f rightPoint{ g_WindowWidth, 0 };
	DrawSierpinskiTriangle(leftPoint, topPoint, rightPoint);
}

void Update(float elapsedSec)
{
	// process input, do physics 
	// 
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
Point2f Middle(const Point2f& point1, const Point2f& point2)
{
	return Point2f((point1.x + point2.x) / 2, (point1.y + point2.y) / 2);
}


void DrawSierpinskiTriangle(const Point2f& left,const Point2f& top,const Point2f& right)
{
	DrawTriangle(left, top, right);

	if (right.x - left.x > 20)
	{
		SetColor(g_Red);
		DrawSierpinskiTriangle(left, Middle(left, top), Middle(left, right));
		SetColor(g_Green);
		DrawSierpinskiTriangle(Middle(left, top), top, Middle(top, right));
		SetColor(g_Blue);
		DrawSierpinskiTriangle(Middle(left, right), Middle(right, top), right);
	}
}

#pragma endregion ownDefinitions