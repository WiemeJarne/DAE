#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	g_Red.r = 241.f / 255.f;
	g_Red.g = 145.f / 255.f;
	g_Red.b = 145.f / 255.f;

	g_Blue.r = 141.f / 255.f;
	g_Blue.g = 188.f / 255.f;
	g_Blue.b = 235.f / 255.f;

	g_Yellow.r = 199.f / 255.f;
	g_Yellow.g = 199.f / 255.f;
	g_Yellow.b = 120.f / 255.f;

	g_Green.r = 127.f / 255.f;
	g_Green.g = 213.f / 255.f;
	g_Green.b = 170.f / 255.f;
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawConcentricSquares();
	DrawStairs();
	DrawSpiral();
	DrawSpinningLines();
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
void DrawConcentricSquares()
{
	float spaceLeftFromBiggestRect{ 20 };
	float spaceLeftFromRect{ spaceLeftFromBiggestRect };
	float spaceBelowRect{ spaceLeftFromRect };
	float rectWidth{ 220 };
	float rectHeight{ rectWidth };

	int amountOfRectangles{ 4 };

	SetColor(g_Green);

	for (int rectangleNumber{}; rectangleNumber <= amountOfRectangles; ++rectangleNumber)
	{
		DrawRect(spaceLeftFromRect, spaceBelowRect, rectWidth, rectHeight, 2.f);

		spaceLeftFromRect += spaceLeftFromBiggestRect;
		spaceBelowRect = spaceLeftFromRect;
		rectWidth -= spaceLeftFromBiggestRect * 2;
		rectHeight = rectWidth;
	}
}

void DrawStairs()
{
	int stairWidth{ 44 };
	int stairHeight{ 44 };

	Point2f point(20, 265);
	Point2f point2(point.x + stairWidth, point.y);

	int amountOfStairs{ 4 };

	for (int stairNumber{}; stairNumber <= amountOfStairs; ++stairNumber)
	{
		if (stairNumber % 2 == 1)
		{
			SetColor(g_Red);
			DrawLine(point, point2, 2.f);

			point = point2;

			point2.y += stairHeight;

			DrawLine(point, point2, 2.f);
		}
		else
		{
			SetColor(g_Blue);
			DrawLine(point, point2, 2.f);

			point = point2;

			point2.y += stairHeight;

			DrawLine(point, point2, 2.f);
		}

		point.x = point2.x;
		point.y = point2.y;

		point2.x += stairWidth;
	}
}

void DrawSpiral()
{
	float firstLoopLineLenght{ 220 };
	float yStartPosition{ 20 };
	float xStartPosition{ 260 };
	float spaceBetweenLines{};
	float spaceBetweenLinesFactor{ 2 };

	Point2f point{ xStartPosition, yStartPosition };
	Point2f point2{ xStartPosition + firstLoopLineLenght, yStartPosition };

	int amountOfLoops{ 4 };

	SetColor(g_Blue);

	for (int loopNumber{0}; loopNumber <= amountOfLoops; ++loopNumber)
	{
		DrawLine(point, point2, 2.f);

		point = point2;
		point2.y = firstLoopLineLenght + yStartPosition - loopNumber * spaceBetweenLines;
		spaceBetweenLines = yStartPosition;

		DrawLine(point, point2, 2.f);

		point = point2;
		point2.x = xStartPosition + (loopNumber + 1) * spaceBetweenLines;

		DrawLine(point, point2, 2.f);

		point = point2;
		point2.y = spaceBetweenLinesFactor * spaceBetweenLines;
		++spaceBetweenLinesFactor;

		DrawLine(point, point2, 2.f);

		point = point2;
		point2.x = xStartPosition - (loopNumber + 1) * spaceBetweenLines + firstLoopLineLenght;
	}

}

void DrawSpinningLines()
{
	const float lineLenght{ 220 };
	const float yStartPosition{ 260 };
	const float xStartPosition{ 260 };
	const float lineWidth{ 2 };
	float rotation{ 0 };

	Point2f point{ xStartPosition, yStartPosition };
	Point2f point2{ xStartPosition + lineLenght, yStartPosition };

	int amountOfSpinningLinesSets{ 4 };

	for (int setNumber{}; setNumber <= amountOfSpinningLinesSets; ++setNumber)
	{
		point.x = xStartPosition + rotation;
		point.y = yStartPosition;
		point2.x = xStartPosition + lineLenght;
		point2.y = yStartPosition + rotation;

		SetColor(g_Red);
		DrawLine(point, point2, lineWidth);

		point = point2;
		point2.x = xStartPosition + lineLenght - rotation;
		point2.y = yStartPosition + lineLenght;

		SetColor(g_Green);
		DrawLine(point, point2, lineWidth);

		point = point2;
		point2.x = xStartPosition;
		point2.y = yStartPosition + lineLenght - rotation;

		SetColor(g_Blue);
		DrawLine(point, point2, lineWidth);

		point = point2;
		point2.x = xStartPosition + rotation;
		point2.y = yStartPosition;

		SetColor(g_Yellow);
		DrawLine(point, point2, lineWidth);

		rotation += (lineLenght / 5);
	}
}
#pragma endregion ownDefinitions