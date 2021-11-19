#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	int sum{1}, count{};
	const int maxSum{ 150 };
	while (sum < maxSum)
	{
		sum += sum;
		++count;

		std::cout << sum << '\n';
	}
	std::cout << "Count = " << count << '\n';

	count = 0;
	int number{};
	int numberToGuess{};
	std::cin >> numberToGuess;
	do
	{
		int number{ rand() };
		number = rand();
		count++;
	} while (numberToGuess != number);
	std::cout << "Count = " << count << '\n';

	count = 0;
	number = rand();
	while (numberToGuess != number)
	{
		number = rand();
		count++;
	}
	std::cout << "Count = " << count << '\n';

	number = 0;
	for (int i{}; i < 20; ++i)
	{
		number += i;
	}
	std::cout << "number = " << number << '\n';

	for (float angle{}; angle < 2 * g_Pi; angle += 0.1f)
	{
		std::cout << sin(angle) << '\n';
	}
}

void Draw()
{
	ClearBackground();
	SetColor(0.f, 0.f, 0.f);
	// Put your own draw statements here

	float posX{};
	const float scale{ 100 };
	Point2f translation{ g_WindowWidth / 2, g_WindowHeight / 2 };
	
	for (float angle{}; angle < 2 * g_Pi; angle += 0.025f)
	{
		float height{ sin(angle) * scale };
		DrawLine(posX + translation.x, height + translation.y, posX+1 + translation.x, height + translation.y);

		posX += 1;
	}

	SetColor(1.f, 0.f, 0.f);
	float step(0.025f);
	for (float angle{}; angle < 2 * g_Pi; angle += step)
	{
		float y{ sin(angle * 4) * scale + translation.y};
		float x{ cos(angle * 2) * scale + translation.x};
		float y2{ sin((angle + step) * 4) * scale + translation.y };
		float x2{ cos((angle + step) * 2) * scale + translation.x };
		DrawLine(x, y, x2, y2);
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