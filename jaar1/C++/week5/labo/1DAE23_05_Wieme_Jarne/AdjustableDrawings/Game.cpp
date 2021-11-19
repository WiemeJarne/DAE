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

	std::cout << "press the up or down arrow key for more or les loops.\n";
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
	switch (key)
	{
	case SDLK_UP:
		if (g_AmountOfLoops < 20)
		{
			++g_AmountOfLoops;
			std::cout << g_AmountOfLoops << "\n";
		}
		break;
	case SDLK_DOWN:
		if (g_AmountOfLoops > 5)
		{
			--g_AmountOfLoops;
			std::cout << g_AmountOfLoops << "\n";
		}
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
	float spaceBelowAndLeftFromLine{ 15.f };
	float lineLenght{ 220.f };
	float spaceBetweenLines{ 22.f };

	Point2f point{ spaceBelowAndLeftFromLine, spaceBelowAndLeftFromLine };
	Point2f point2{ spaceBelowAndLeftFromLine + lineLenght, spaceBelowAndLeftFromLine };

	spaceBetweenLines -= (g_AmountOfLoops - 5);

	SetColor(g_Green);

	for (int loopNumber{ 1 }; loopNumber <= g_AmountOfLoops; ++loopNumber)
	{
		DrawLine(point, point2);

		point = point2;
		point2.y = spaceBelowAndLeftFromLine + lineLenght;

		DrawLine(point, point2);

		point = point2;
		point2.x = spaceBelowAndLeftFromLine;

		DrawLine(point, point2);

		point = point2;
		point2.y = spaceBelowAndLeftFromLine;

		DrawLine(point, point2);

		spaceBelowAndLeftFromLine += spaceBetweenLines;
		lineLenght -= 2 * spaceBetweenLines;

		point.x = spaceBelowAndLeftFromLine;
		point.y = spaceBelowAndLeftFromLine;

		point2.x = spaceBelowAndLeftFromLine + lineLenght;
		point2.y = spaceBelowAndLeftFromLine;
	}
}

void DrawStairs()
{
	int stairWidth{ 220 / g_AmountOfLoops };
	int stairHeight{ 220 / g_AmountOfLoops };

	Point2f point(20, 250);
	Point2f point2(point.x + stairWidth, point.y);

	for (int stairNumber{1}; stairNumber <= g_AmountOfLoops; ++stairNumber)
	{
		if (stairNumber % 2 == 1)
		{
			SetColor(g_Blue);
			DrawLine(point, point2, g_LineWidth);

			point = point2;

			point2.y += stairHeight;

			DrawLine(point, point2, g_LineWidth);
		}
		else
		{
			SetColor(g_Red);
			DrawLine(point, point2, g_LineWidth);

			point = point2;

			point2.y += stairHeight;

			DrawLine(point, point2, g_LineWidth);
		}

		point = point2;
		point2.x += stairWidth;
	}
}

void DrawSpiral()
{
	float spaceBetweenLines{ 22.f };
	spaceBetweenLines -= (g_AmountOfLoops - 5);
	float spaceLeftFromLine{ 255.f + g_AmountOfLoops * spaceBetweenLines };
	float spaceBelowLine{ 15.f + g_AmountOfLoops * spaceBetweenLines };
	float lineLenght{ 220.f - ( ((g_AmountOfLoops * 2) - 1) * spaceBetweenLines )  };

	Point2f point{ spaceLeftFromLine, spaceBelowLine };
	Point2f point2{ spaceLeftFromLine, spaceBelowLine + lineLenght };

	SetColor(g_Blue);

	for (int loopNumber{ 1 }; loopNumber <= g_AmountOfLoops; ++loopNumber)
	{
		DrawLine(point, point2);

		point = point2;
		point2.x = lineLenght + spaceLeftFromLine;

		DrawLine(point, point2);

		point = point2;
		point2.y -= 2 * lineLenght;

		DrawLine(point, point2);

		point = point2;
		point2.x -= 2* lineLenght;;

		DrawLine(point, point2);

		point = point2;
		lineLenght += spaceBetweenLines;
		point2.y = spaceBelowLine + lineLenght;
	}

	/*float spaceLeftFromLine{ 255.f };
	float spaceBelowLine{ 15 };
	float lineLenght{ 220.f };
	float spaceBetweenLines{ 17.f };

	Point2f point{ spaceLeftFromLine, spaceBelowLine };
	Point2f point2{ spaceLeftFromLine + lineLenght, spaceBelowLine };

	spaceBetweenLines -= (g_AmountOfLoops - 5);

	SetColor(g_Blue);

	for (int loopNumber{ 1 }; loopNumber <= g_AmountOfLoops; ++loopNumber)
	{
		DrawLine(point, point2);

		point = point2;
		point2.y = lineLenght - (loopNumber - 1) * spaceBetweenLines + spaceBelowLine;

		DrawLine(point, point2);

		point = point2;
		point2.x = spaceLeftFromLine + loopNumber * spaceBetweenLines;

		DrawLine(point, point2);

		point = point2;
		point2.y = spaceBelowLine + loopNumber * spaceBetweenLines;

		DrawLine(point, point2);

		point = point2;
		point2.x = spaceLeftFromLine + lineLenght - loopNumber * spaceBetweenLines;
	}*/
}

void DrawSpinningLines()
{
	const float lineLenght{ 220.f };
	const float yStartPosition{ 250.f };
	const float xStartPosition{ 255.f };
	float rotation{ 0 };

	Point2f point{ xStartPosition, yStartPosition };
	Point2f point2{ xStartPosition + lineLenght, yStartPosition };

	for (int setNumber{1}; setNumber <= g_AmountOfLoops; ++setNumber)
	{
		point.x = xStartPosition + rotation;
		point.y = yStartPosition;
		point2.x = xStartPosition + lineLenght;
		point2.y = yStartPosition + rotation;

		SetColor(g_Red);
		DrawLine(point, point2, g_LineWidth);

		point = point2;
		point2.x = xStartPosition + lineLenght - rotation;
		point2.y = yStartPosition + lineLenght;

		SetColor(g_Green);
		DrawLine(point, point2, g_LineWidth);

		point = point2;
		point2.x = xStartPosition;
		point2.y = yStartPosition + lineLenght - rotation;

		SetColor(g_Blue);
		DrawLine(point, point2, g_LineWidth);

		point = point2;
		point2.x = xStartPosition + rotation;
		point2.y = yStartPosition;

		SetColor(g_Yellow);
		DrawLine(point, point2, g_LineWidth);

		rotation += (lineLenght / g_AmountOfLoops);
	}
}
#pragma endregion ownDefinitions