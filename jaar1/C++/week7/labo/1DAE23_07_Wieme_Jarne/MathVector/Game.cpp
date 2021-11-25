#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	g_Red.r = 1.f;

	//test ToString function
	Vector2f vector1{ 34,53 };
	std::cout << ToString(vector1) << '\n';

	//test dot product
	vector1 = Vector2f{ 80, 0 };
	Vector2f vector2{ 0, 50 };

	std::cout << "\nDot product:\nvector1 = " << ToString(vector1) << "\tvector2 = " << ToString(vector2) << "\tDot product: " << DotProduct(vector1, vector2) << '\n';

	Vector2f parallel{ 0, 25 };

	std::cout << "vector2 = " << ToString(vector2) << "\tparallel = " << ToString(parallel) << "\tDot product: " << DotProduct(vector2, parallel) << '\n';

	//test cross product
	std::cout << "\nCross product:\nvector1 = " << ToString(vector1) << "\tvector2 = " << ToString(vector2) << "\tCross product: " << CrossProduct(vector1, vector2) << '\n';
	std::cout << "\nCross product:\nvector2 = " << ToString(vector2) << "\tvector1 = " << ToString(vector1) << "\tCross product: " << CrossProduct(vector2, vector1) << '\n';

	//test Length function
	vector1 = Vector2f{ 100, 30 };

	std::cout << "\nLength: of " << ToString(vector1) << " is " << Length(vector1) << '\n';

	//test Scale function
	std::cout << "\nScaled " << ToString(vector1) << " is " << ToString( Scale(vector1, 0.1f) ) << '\n';

	//test Normalize function
	std::cout << "\nNormalized " << ToString(vector1) << " is " << ToString( Normalize(vector1) ) << " its length is: " << Length( Normalize(vector1) ) << "\n";

	//test AngleBetween Function
	vector1 = Vector2f{ 10, 0 };
	vector2 = Vector2f{ 10,10 };

	std::cout << "\nAngle between " << ToString(vector1) << " and " << ToString(vector2) << " is: " << AngleBetween(vector1, vector2) << " radians, or " << AngleBetween(vector1, vector2) * (180 / g_Pi) << " degrees.\n";

}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here

	//testing draw vector
	Vector2f vector1{ 34,53 };
	Point2f vector1StartPoint{ 54, 21 };

	//DrawVector(vector1);

	Vector2f vector2{ 34,53 };
	Point2f vector2StartPoint{ 75, 28 };

	//DrawVector(vector2);

	//test adding vectors
	vector1 = Vector2f{ 43, 56 };
	vector1StartPoint = Point2f{ 34, 45 };

	DrawVector(vector1, vector1StartPoint);

	vector2 = Vector2f{ 46, 14 };
	vector2StartPoint = Point2f{ vector1StartPoint.x + vector1.x, vector1StartPoint.y + vector1.y };

	DrawVector(vector2, vector2StartPoint);

	DrawVector(Add(vector1, vector2), vector1StartPoint);

	//test subtracting vectors
	vector1 = Vector2f{ 34, 46 };
	vector1StartPoint = Point2f{ 165, 153 };

	DrawVector(vector1, vector1StartPoint);

	vector2 = Vector2f{ 54, 21 };
	vector2StartPoint = vector1StartPoint;

	DrawVector(vector2, vector2StartPoint);

	DrawVector(Substract(vector1, vector2), Point2f{ vector2StartPoint.x + vector2.x, vector2StartPoint.y + vector2.y } );

	//animating projection
	vector1StartPoint = Point2f{ g_WindowWidth / 2, g_WindowHeight / 2 };
	vector2StartPoint = vector1StartPoint;

	const int vectorLength{ int(Length(vector1)) };
	vector1.x = vectorLength * cosf(g_Angle);
	vector1.y = vectorLength * sinf(g_Angle);

	DrawVector(vector1, vector1StartPoint);

	Vector2f normalizedVector{ Normalize( Vector2f{ 37, 29} ) };

	vector2 = Scale( normalizedVector, DotProduct(vector1, normalizedVector) );


	DrawVector(vector2, vector2StartPoint, g_Red);
}

void Update(float elapsedSec)
{
	// process input, do physics 
	g_Angle -= ( 25 * (g_Pi / 180) ) * elapsedSec;
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