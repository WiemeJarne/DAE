
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
	ClearBackground();

	// Put your own draw statements here
	DrawColumnChart();
	DrawHouse();
	DrawFlag();
	DrawCheckerPattern();
	DrawColorBand();
	DrawPentagram();
	
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

void DrawHouse()
{
	const float trianglePoint1x{ 250 };
	const float trianglePoint1y{ 690 };
	const float trianglePoint2x{ 10 };
	const float trianglePoint2y{ 620 };
	const float trianglePoint3x{ 510 };
	const float trianglePoint3y{ 620 };

	SetColor(1.f, 0.f, 0.f, 1.f);
	FillTriangle(Point2f(trianglePoint1x, trianglePoint1y), Point2f(trianglePoint2x, trianglePoint2y), Point2f(trianglePoint3x, trianglePoint3y));

	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawTriangle(Point2f(trianglePoint1x, trianglePoint1y), Point2f(trianglePoint2x, trianglePoint2y), Point2f(trianglePoint3x, trianglePoint3y));

	const float spaceLeftFromRectangle{ 10 };
	const float spaceBelowRectangle{ 540 };
	const float rectangleWith{ 500 };
	const float rectangleHeight{ 80 };

	SetColor(1.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);
}

void DrawFlag()
{
	float spaceLeftFromRectangle{ 10 };
	const float spaceBelowRectangle{ 320 };
	float rectangleWith{ 500 / 3 };
	const float rectangleHeight{ 200 };

	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 10 + 500 / 3;

	SetColor(1.f, 1.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 10 + ( 500 / 3 ) * 2;

	SetColor(1.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 10;
	rectangleWith = 500;

	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);
}

void DrawCheckerPattern()
{
	float spaceLeftFromRectangle{ 10 };
	float spaceBelowRectangle{ 210 };
	float rectangleWith{ 100 };
	float rectangleHeight{ rectangleWith };

	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 110;
	spaceBelowRectangle = 210;

	SetColor(1.f, 1.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 210;
	spaceBelowRectangle = 210;

	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 10;
	spaceBelowRectangle = 110;

	SetColor(1.f, 1.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 110;
	spaceBelowRectangle = 110;

	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 210;
	spaceBelowRectangle = 110;

	SetColor(1.f, 1.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 10;
	spaceBelowRectangle = 10;

	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 110;
	spaceBelowRectangle = 10;

	SetColor(1.f, 1.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 210;
	spaceBelowRectangle = 10;

	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 10;
	spaceBelowRectangle = 10;
	rectangleWith = 300;
	rectangleHeight = rectangleWith;

	SetColor(1.f, 1.f, 1.f, 1.f);
	DrawRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);
}

void DrawColorBand()
{
	float spaceLeftFromRectangle{ 520 };
	float spaceBelowRectangle{ 490 };
	float rectangleWith{ 50 };
	float rectangleHeight{ 200 };

	SetColor(0.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 570;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(1.f, 0.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 620;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(0.f, 1.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 670;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(0.f, 0.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 720;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(1.f, 0.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 770;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(1.f, 1.f, 0.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 820;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(0.f, 1.f, 0.25f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 870;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(0.f, 1.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 920;
	spaceBelowRectangle = 490;
	rectangleWith = 50;
	rectangleHeight = 200;

	SetColor(1.f, 1.f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 520;
	spaceBelowRectangle = 490;
	rectangleWith = 450;
	rectangleHeight = 100;

	SetColor(0.f, 0.f, 0.f, 0.5f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight);

	spaceLeftFromRectangle = 520;
	spaceBelowRectangle = 490;
	rectangleWith = 450;
	rectangleHeight = 200;
	const float lineWith{ 5 };

	SetColor(1.f, 1.f, 0.f, 1.f);
	DrawRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, rectangleHeight, lineWith);
}

void DrawPentagram()
{
	const int middlePointx{ 850 };
	const int middlePointy{ 350 };
	const float radius{ 125.f };
	const float angle = { 1.25663706f };

	SetColor(200.f / 255.f, 60.f / 255.f, 185.f / 255.f, 1.f);
	DrawLine(float(middlePointx + radius * cos(angle)), float(middlePointy + radius * sin(angle)), float(middlePointx + radius * cos(angle * 4)), float(middlePointy + radius * sin(angle * 4)), 5.f);
	DrawLine(float(middlePointx + radius * cos(angle * 4)), float(middlePointy + radius * sin(angle * 4)), float(middlePointx + radius * cos(angle * 2)), float(middlePointy + radius * sin(angle * 2)), 5.f);
	DrawLine(float(middlePointx + radius * cos(angle * 2)), float(middlePointy + radius * sin(angle * 2)), float(middlePointx + radius), float(middlePointy), 5.f);
	DrawLine(float(middlePointx + radius), float(middlePointy), float(middlePointx + radius * cos(angle * 3)), float(middlePointy + radius * sin(angle * 3)), 5.f);
	DrawLine(float(middlePointx + radius * cos(angle * 3)), float(middlePointy + radius * sin(angle * 3)), float(middlePointx + radius * cos(angle)), float(middlePointy + radius * sin(angle)), 5.f);
}

void DrawColumnChart()
{
	std::cout << "% of people playing games: " << std::endl;

	float inRange0To20{ 95 };
	float inRange21To40{ 80 };
	float inRange41To60{ 50 };
	float olderThen60{ 20 };

	std::cout << "In the range [0, 20]? ";
	std::cin >> inRange0To20;

	std::cout << std::endl << "In the range [21, 40]? ";
	std::cin >> inRange21To40;

	std::cout << std::endl << "In the range [41, 60]? ";
	std::cin >> inRange41To60;

	std::cout << std::endl << "Older then 60? ";
	std::cin >> olderThen60;

	float spaceLeftFromRectangle{ 500 };
	const float spaceBelowRectangle{ 20 };
	const float rectangleWith{ 75 };
	
	SetColor(0.f, 0.75f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, inRange0To20 * 3);

	spaceLeftFromRectangle = 575;

	SetColor(0.f, 0.60f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, inRange21To40 * 3);

	spaceLeftFromRectangle = 650;

	SetColor(0.f, 0.55f, 0.8f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, inRange41To60 * 3);

	spaceLeftFromRectangle = 725;

	SetColor(0.f, 0.65f, 1.f, 1.f);
	FillRect(spaceLeftFromRectangle, spaceBelowRectangle, rectangleWith, olderThen60 * 3);
}