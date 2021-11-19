#include "pch.h"
#include "Game.h"
#include <cmath>
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
	Color4f red{};
	red.r = 1.f;

	Color4f green{};
	green.g = 1.f;

	Color4f blue{};
	blue.b = 1.f;

	Color4f magenta{};
	magenta.r = 1.f;
	magenta.b = 1.f;

	Color4f yellow{};
	yellow.r = 1.f;
	yellow.g = 1.f;

	Color4f cyan{};
	cyan.g = 1.f;
	cyan.b = 1.f;

	Color4f black{};

	Color4f white{};
	white.r = 1.f;
	white.g = 1.f;
	white.b = 1.f;

	DrawSquares(10, 10, g_WindowHeight - 10 - 100, 100);
	DrawSquares(5, 10 + 100 + 10, g_WindowHeight - 10 - 100, 75);
	DrawSquares(3, 10 + 100 + 10 + 75 + 10, g_WindowHeight - 10 - 100, 50);

	DrawEquilateralTriangle(400, 420, 75, true, red);
	DrawEquilateralTriangle(405, 423, 65, true, green);
	DrawEquilateralTriangle(410, 426, 55, true, blue);

	DrawEquilateralTriangle(490, 420, 75 / 2.f, true, cyan);
	DrawEquilateralTriangle(490, 420, 75 / 2.f, false, black);

	DrawEquilateralTriangle(490 + 75 / 2.f, 420, 75 / 2.f, true, yellow);
	DrawEquilateralTriangle(490 + 75 / 2.f, 420, 75 / 2.f, false, black);

	DrawEquilateralTriangle(490 + (75 / 2.f) / 2.f, 420 + sqrtf(powf(75 / 2.f, 2) - powf((75 / 2.f) / 2.f, 2)), 75 / 2, true, magenta);
	DrawEquilateralTriangle(490 + (75 / 2.f) / 2.f, 420 + sqrtf(powf(75 / 2.f, 2) - powf((75 / 2.f) / 2.f, 2)), 75 / 2, false, black);

	DrawPentagram(425.f, 350.f, 50.f, 2.f, red);
	DrawPentagram(525.f, 350.f, 25.f, 2.f, blue);

	Rectf rectangle{ 10, 250, 200, 30 };
	DrawLinearGradient(rectangle, black, white);

	rectangle.bottom = 200;
	rectangle.width = 300;
	rectangle.height = 40;
	DrawLinearGradient(rectangle, red, magenta);

	rectangle.bottom = 140;
	rectangle.width = 425;
	rectangle.height = 50;
	DrawLinearGradient(rectangle, green, yellow);

	rectangle.bottom = 65;
	rectangle.width = 550;
	rectangle.height = 65;
	DrawLinearGradient(rectangle, blue, yellow);
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
void DrawSquares(const int numberOfSquares, float pointX, float pointY, int sideLenght)
{
	SetColor( 0.f,0.f,0.f );

	const int spaceBetweenLines{ sideLenght / ( numberOfSquares * 2 ) };

	Point2f point{ pointX, pointY };
	Point2f point2{ pointX + sideLenght, pointY };

	for (int loopNumber{ 1 }; loopNumber <= numberOfSquares; ++loopNumber)
	{
		DrawLine(point, point2);

		point = point2;
		point2.y = pointY + sideLenght;

		DrawLine(point, point2);

		point = point2;
		point2.x = pointX;

		DrawLine(point, point2);

		point = point2;
		point2.y = pointY;

		DrawLine(point, point2);

		pointX += spaceBetweenLines;
		pointY += spaceBetweenLines;
		sideLenght -= 2 * spaceBetweenLines;

		point.x = pointX;
		point.y = pointY;

		point2.x = pointX + sideLenght;
		point2.y = pointY;
	}
}

void DrawSquares(int numberOfSquares, Point2f point1, int sideLenght)
{
	SetColor(0.f, 0.f, 0.f);

	const int spaceBetweenLines{ sideLenght / (numberOfSquares * 2) };

	Point2f point2{ point1.x + sideLenght, point1.y };

	for (int loopNumber{ 1 }; loopNumber <= numberOfSquares; ++loopNumber)
	{
		DrawLine(point1, point2);

		point1 = point2;
		point2.y = point1.y + sideLenght;

		DrawLine(point1, point2);

		point1 = point2;
		point2.x = point1.x;

		DrawLine(point1, point2);

		point1 = point2;
		point2.y = point1.y;

		DrawLine(point1, point2);

		point1.x += spaceBetweenLines;
		point1.y += spaceBetweenLines;
		sideLenght -= 2 * spaceBetweenLines;

		point1.x = point1.x;
		point1.y = point1.y;

		point2.x = point1.x + sideLenght;
		point2.y = point1.y;
	}
}

void DrawEquilateralTriangle(const float bottomLeftPointX, const float bottomLeftPointY, const float sideLenght, const bool filled, const Color4f color)
{
	const Point2f bottomLeftPoint{ bottomLeftPointX, bottomLeftPointY };
	const Point2f bottomRightPoint{ bottomLeftPointX + sideLenght, bottomLeftPointY };
	const Point2f topPoint{ bottomLeftPointX + sideLenght / 2, bottomLeftPointY + sqrtf(powf(sideLenght, 2) - powf(sideLenght / 2, 2)) };

	SetColor(color);

	if (filled)
	{
		FillTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}
	else
	{
		DrawTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}

}

void DrawEquilateralTriangle(const Point2f bottomLeftPoint, const float sideLenght, const bool filled, const Color4f color)
{
	const Point2f bottomRightPoint{ bottomLeftPoint.x + sideLenght, bottomLeftPoint.y };
	const Point2f topPoint{ bottomLeftPoint.x + sideLenght / 2, bottomLeftPoint.y + sqrtf(powf(sideLenght, 2) - powf(sideLenght / 2, 2)) };

	SetColor(color);

	if (filled)
	{
		FillTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}
	else
	{
		DrawTriangle(bottomLeftPoint, bottomRightPoint, topPoint);
	}
}

void DrawPentagram(const float middlePointX, const float middlePointY, const float radius, const float lineWidth, const Color4f color)
{
	const float angle = { 1.25663706f };

	SetColor(color);

	DrawLine(middlePointX + radius * cos(angle), middlePointY + radius * sin(angle), middlePointX + radius * cos(angle * 4), middlePointY + radius * sin(angle * 4), lineWidth);
	DrawLine(middlePointX + radius * cos(angle * 4), middlePointY + radius * sin(angle * 4), middlePointX + radius * cos(angle * 2), middlePointY + radius * sin(angle * 2), lineWidth);
	DrawLine(middlePointX + radius * cos(angle * 2), middlePointY + radius * sin(angle * 2), middlePointX + radius, middlePointY, lineWidth);
	DrawLine(middlePointX + radius, middlePointY, middlePointX + radius * cos(angle * 3), middlePointY + radius * sin(angle * 3), lineWidth);
	DrawLine(middlePointX + radius * cos(angle * 3), middlePointY + radius * sin(angle * 3), middlePointX + radius * cos(angle), middlePointY + radius * sin(angle), lineWidth);
}

void DrawPentagram(const Point2f middlePoint, const float radius, const float lineWidth, const Color4f color)
{
	const float angle = { 1.25663706f };

	SetColor(color);

	DrawLine(middlePoint.x + radius * cos(angle), middlePoint.y + radius * sin(angle), middlePoint.x + radius * cos(angle * 4), middlePoint.y + radius * sin(angle * 4), 5.f);
	DrawLine(middlePoint.x + radius * cos(angle * 4), middlePoint.y + radius * sin(angle * 4), middlePoint.x + radius * cos(angle * 2), middlePoint.y + radius * sin(angle * 2), 5.f);
	DrawLine(middlePoint.x + radius * cos(angle * 2), middlePoint.y + radius * sin(angle * 2), middlePoint.x + radius, middlePoint.y, 5.f);
	DrawLine(middlePoint.x + radius, middlePoint.y, middlePoint.x + radius * cos(angle * 3), middlePoint.y + radius * sin(angle * 3), 5.f);
	DrawLine(middlePoint.x + radius * cos(angle * 3), middlePoint.y + radius * sin(angle * 3), middlePoint.x + radius * cos(angle), middlePoint.y + radius * sin(angle), 5.f);
}

void DrawLinearGradient(const Rectf rectangle, Color4f startColor, Color4f endColor)
{
	const float rectangleWidth{ 1 };

	Color4f color1{ startColor };
	Color4f color2{ endColor };
	Color4f rectangleColor{ startColor };

	for (float rectangleLeft{ rectangle.left }; rectangleLeft <= rectangle.width; rectangleLeft += rectangleWidth)
	{
		SetColor(rectangleColor);

		FillRect(rectangleLeft, rectangle.bottom, rectangleWidth, rectangle.height);

		if (startColor.r > 0)
		{ 
			color1.r = (((rectangleLeft - rectangle.left) / rectangle.width) - 1.f) * (-1);
			rectangleColor.r = color1.r;
		}
			
		if (startColor.g > 0)
		{
			color1.g = (((rectangleLeft - rectangle.left) / rectangle.width) - 1.f) * (-1);
			rectangleColor.g = color1.g;
		}

		if (startColor.b > 0)
		{
			color1.b = (((rectangleLeft - rectangle.left) / rectangle.width) - 1.f) * (-1);
			rectangleColor.b = color1.b;
		}
		
		if (endColor.r > 0)
		{
			color2.r = ((rectangleLeft - rectangle.left) / rectangle.width);
			rectangleColor.r = color2.r;
		}

		if (endColor.g > 0)
		{
				color2.g = ((rectangleLeft - rectangle.left) / rectangle.width);
				rectangleColor.g = color2.g;
		}

		if (endColor.b > 0)
		{
			color2.b = ((rectangleLeft - rectangle.left) / rectangle.width);
			rectangleColor.b = color2.b;
		}
			rectangleColor.r = color1.r + color2.r;
			rectangleColor.g = color1.g + color2.g;
			rectangleColor.b = color1.b + color2.b;	
	}
}
#pragma endregion ownDefinitions