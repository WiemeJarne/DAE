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
	SimulateRollingDice();
	DrawAmountsOfEachNumberTrownRectangle();
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
void SimulateRollingDice()
{
	const float dice1Roll{ float(rand() % 6 + 1) };
	const float dice2Roll{ float(rand() % 6 + 1) };

	const float twoDiceRollTotal{ dice1Roll + dice2Roll };

	if (dice1Roll == 1)
	{
		++g_AmountNumber1Trown;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (dice1Roll == 2)
	{
		++g_AmountNumber2TrownWithOneDie;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (dice1Roll == 3)
	{
		++g_AmountNumber3TrownWithOneDie;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (dice1Roll == 4)
	{
		++g_AmountNumber4TrownWithOneDie;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (dice1Roll == 5)
	{
		++g_AmountNumber5TrownWithOneDie;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (dice1Roll == 6)
	{
		++g_AmountNumber6TrownWithOneDie;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 2)
	{
		++g_AmountNumber2TrownWithOneDie;

		DrawAmountsOfEachNumberTrownRectangle();
	}
	
	if (twoDiceRollTotal == 3)
	{
		++g_AmountNumber3TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 4)
	{
		++g_AmountNumber4TrownWithTwoDice;
;
		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 5)
	{
		++g_AmountNumber5TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 6)
	{
		++g_AmountNumber6TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 7)
	{
		++g_AmountNumber7TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 8)
	{
		++g_AmountNumber8TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 9)
	{
		++g_AmountNumber9TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 10)
	{
		++g_AmountNumber10TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 11)
	{
		++g_AmountNumber11TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}

	if (twoDiceRollTotal == 12)
	{
		++g_AmountNumber12TrownWithTwoDice;

		DrawAmountsOfEachNumberTrownRectangle();
	}
}

void DrawAmountsOfEachNumberTrownRectangle()
{
	const float spaceLeftFromRectangle{ 15.f };
	const float rectHeight{ 25 };

	float spaceBetweenRectangles{ 5 };
	float spaceBelowBottomRectangle{ ( g_WindowHeight - (16 * rectHeight + 14 * spaceBetweenRectangles) ) / 3 };
	
	Color4f red{};
	Color4f purple{};

	red.r = 1.f;

	purple.r = 0.5f;
	purple.b = 1.f;

	SetColor(purple);

	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 16 * rectHeight + 15 * spaceBetweenRectangles, g_AmountNumber2TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 15 * rectHeight + 14 * spaceBetweenRectangles, g_AmountNumber3TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 14 * rectHeight + 13 * spaceBetweenRectangles, g_AmountNumber4TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 13 * rectHeight + 12 * spaceBetweenRectangles, g_AmountNumber5TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 12 * rectHeight + 11 * spaceBetweenRectangles, g_AmountNumber6TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 11 * rectHeight + 10 * spaceBetweenRectangles, g_AmountNumber7TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 10 * rectHeight + 9 * spaceBetweenRectangles, g_AmountNumber8TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 9 * rectHeight + 8 * spaceBetweenRectangles, g_AmountNumber9TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 8 * rectHeight + 7 * spaceBetweenRectangles, g_AmountNumber10TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 7 * rectHeight + 6 * spaceBetweenRectangles, g_AmountNumber11TrownWithTwoDice, rectHeight);
	FillRect(spaceLeftFromRectangle, 2 * spaceBelowBottomRectangle + 6 * rectHeight + 5 * spaceBetweenRectangles, g_AmountNumber12TrownWithTwoDice, rectHeight);

	SetColor(red);

	FillRect(spaceLeftFromRectangle, spaceBelowBottomRectangle + 5 * rectHeight + 5 * spaceBetweenRectangles, g_AmountNumber1Trown, rectHeight);
	FillRect(spaceLeftFromRectangle, spaceBelowBottomRectangle + 4 * rectHeight + 4 * spaceBetweenRectangles, g_AmountNumber2TrownWithOneDie, rectHeight);
	FillRect(spaceLeftFromRectangle, spaceBelowBottomRectangle + 3 * rectHeight + 3 * spaceBetweenRectangles, g_AmountNumber3TrownWithOneDie, rectHeight);
	FillRect(spaceLeftFromRectangle, spaceBelowBottomRectangle + 2 * rectHeight + 2 * spaceBetweenRectangles, g_AmountNumber4TrownWithOneDie, rectHeight);
	FillRect(spaceLeftFromRectangle, spaceBelowBottomRectangle + rectHeight + spaceBetweenRectangles, g_AmountNumber5TrownWithOneDie, rectHeight);
	FillRect(spaceLeftFromRectangle, spaceBelowBottomRectangle, g_AmountNumber6TrownWithOneDie, rectHeight);
}
#pragma endregion ownDefinitions