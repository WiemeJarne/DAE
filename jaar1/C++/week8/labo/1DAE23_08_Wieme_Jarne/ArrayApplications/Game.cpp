#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	float bottomBoundary{ 0.2f };
	float topBoundary{ 1.1f };
	for (int index{}; index < g_AmountOfPentagrams; ++index)
	{
		g_AngleSpeedArray[index].speed = float((rand() % int((topBoundary * 100 - 10)) + int(bottomBoundary * 100)) / 100.f);
	}

	int number{};

	for (int index{}; index < g_AmountOfImages; ++index)
	{
		g_NumbersForImage[index] = std::to_string(number);
		TextureFromString(g_NumbersForImage[index], g_FontName, g_TextSize, g_TextColor, g_ImagesNumbers[index]);
		++number;
	}
	
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	if (g_amountOfPointsInPointsClicked >= 1)
	{
		DrawClickedPoints();
	}

	if (g_amountOfPointsInPointsClicked >= 2)
	{
		ConnectClickedPoints();
	}

	DrawRotationPentagrams();

	DrawRandStats();

	DrawMousePoints();

	DrawGrid(g_BottomLeftCorner, g_CellSideLenght, g_SpaceBetweenCells);
}

void Update(float elapsedSec)
{
	// process input, do physics 
	UpdatePentagramsRotation(elapsedSec);
	UpdateRandStats();
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
	for (int index{}; index < g_AmountOfImages; ++index)
	{
		DeleteTexture(g_ImagesNumbers[index]);
	}
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
	case SDLK_RIGHT:
		
		break;
	}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	g_MousePos = Point2f( float(e.x), float(g_WindowHeight - e.y) );
	AddMousePos(g_MousePos);
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		g_MousePos = Point2f(float(e.x), float(g_WindowHeight - e.y));
		AddClickedPoint(g_MousePos);
		break;
	}
	case SDL_BUTTON_RIGHT:
	{
		g_MousePos = Point2f(float(e.x), float(g_WindowHeight - e.y));
		ToggleCell(g_BottomLeftCorner, g_CellSideLenght, g_SpaceBetweenCells);
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void AddClickedPoint(Point2f mousePos)
{
	if (g_amountOfPointsInPointsClicked == 5)
	{
		for (int index{}; index < g_MaxNumberOfClickedPoints - 1; ++index)
		{
			g_PointsClicked[index] = g_PointsClicked[index + 1];
		}
		g_PointsClicked[g_IndexNextPoint] = mousePos;
	}
	else
	{
		g_PointsClicked[g_IndexNextPoint] = mousePos;
		++g_amountOfPointsInPointsClicked;
		if (g_IndexNextPoint != 4)
		{
			++g_IndexNextPoint;
		}
	}
}

void DrawClickedPoints()
{
	float dotRadius{ 5.f };
	
	for (int index{}; index < g_amountOfPointsInPointsClicked; ++index)
	{
		SetColor(1.f, 0.f, 0.f);
		FillEllipse(g_PointsClicked[index].x, g_PointsClicked[index].y, dotRadius, dotRadius);
	}
}

void ConnectClickedPoints()
{
	for (int index{}; index < g_amountOfPointsInPointsClicked - 1; ++index)
	{
		if (g_amountOfPointsInPointsClicked > 1)
		{
			SetColor(1.f, 1.f, 1.f);
			DrawLine(g_PointsClicked[index].x, g_PointsClicked[index].y, g_PointsClicked[index + 1].x, g_PointsClicked[index + 1].y);
		}
	}

}

void DrawRotationPentagrams()
{
	const Color4f pentagramsColor{ 0.f ,1.f, 0.f, 1.f };
	const Point2f middelePointPentegrams{ 400, 90 };
	const float pentagramsRadius{ 75 };
	const float lineWidth{ 1 };

	for (int index{}; index < g_AmountOfPentagrams; ++index)
	{
		DrawPentagram(middelePointPentegrams, pentagramsRadius, g_AngleSpeedArray[index].newAngle, lineWidth, pentagramsColor);
	}
}

void UpdatePentagramsRotation(float elapsedSec)
{
	for (int index{}; index < g_AmountOfPentagrams; ++index)
	{
		g_AngleSpeedArray[index].newAngle = g_AngleSpeedArray[index].previousAngle + g_AngleSpeedArray[index].speed * elapsedSec;
		g_AngleSpeedArray[index].previousAngle = g_AngleSpeedArray[index].newAngle;
	}
}


void UpdateRandStats()
{
	int randomNumber = rand() % g_AmountOfRandomNumbers;
	++g_AmountOfRandomNumbersCount[randomNumber];
}

void DrawRandStats()
{
	Point2f bottomLeftPointOfImage{ 5, 265 };
	for (int index{}; index < g_AmountOfImages; ++index)
	{
		DrawTexture(g_ImagesNumbers[index], bottomLeftPointOfImage);
		bottomLeftPointOfImage.y -= 25;
	}

	const float spaceLeftFromRectangle{ 30 };
	const float rectangleHeight{ 15 };
	float spaceBelowRectangle{ 265 };

	SetColor(g_TextColor);

	for (int index{}; index < g_AmountOfImages; ++index)
	{
		FillRect(spaceLeftFromRectangle, spaceBelowRectangle, g_AmountOfRandomNumbersCount[index], rectangleHeight);
		spaceBelowRectangle -= 25;
	}
}

void AddMousePos(Point2f mousePos)
{
	if (g_AmountOfLastMousePosInArray < g_AmountOfLastMousePos)
	{
		g_LastMousePosArray[g_AmountOfLastMousePosInArray] = mousePos;
		++g_AmountOfLastMousePosInArray;
	}
	else
	{
		for (int index{}; index < g_AmountOfLastMousePos - 1; ++index)
		{
			g_LastMousePosArray[index] = g_LastMousePosArray[index + 1];
		}
		g_LastMousePosArray[g_AmountOfLastMousePosInArray - 1] = mousePos;
	}
}

void DrawMousePoints()
{
	float circleRadius{ 3 };
	float transparency(0.1f);
	Color4f circlesColor{ 0.f, 128 / 255.f,110 / 255.f, transparency };

	for (int index{}; index < g_AmountOfLastMousePosInArray; ++index)
	{
		SetColor(circlesColor);
		FillEllipse(g_LastMousePosArray[index], circleRadius, circleRadius);

		transparency += 0.09f;
		circlesColor.a = transparency;
		circleRadius += 1.f;
	}
}

void DrawGrid(const Point2f bottomleftCorner, const float cellSideLenght, const float spaceBetweenCells, const Color4f cellColor)
{
	Rectf gridBackground(bottomleftCorner.x, bottomleftCorner.y, cellSideLenght * g_AmountOfColumns + spaceBetweenCells * (g_AmountOfColumns + 1), cellSideLenght * g_AmountOfRows + spaceBetweenCells * (g_AmountOfRows + 1));

	Point2f bottomLeftCellBottomLeftPoint{ bottomleftCorner };

	SetColor(1.f, 1.f, 1.f);
	FillRect(gridBackground);

	bottomLeftCellBottomLeftPoint.x += spaceBetweenCells;
	bottomLeftCellBottomLeftPoint.y += spaceBetweenCells;

	int index{};
	int rowNumber{ 1 };

	while (index < g_AmountOfColumns * g_AmountOfRows)
	{
		for (; index < g_AmountOfColumns * rowNumber; ++index)
		{
			CheckCellState(index, cellColor);

			FillRect(bottomLeftCellBottomLeftPoint, cellSideLenght, cellSideLenght);
			bottomLeftCellBottomLeftPoint.x += cellSideLenght + spaceBetweenCells;
		}

		bottomLeftCellBottomLeftPoint.x = bottomleftCorner.x + spaceBetweenCells;
		bottomLeftCellBottomLeftPoint.y += cellSideLenght + spaceBetweenCells;

		++rowNumber;
	}
}

void CheckCellState(int index, Color4f cellColor)
{
	if (g_CellsSelected[index])
	{
		SetColor(g_SelectedCellColor);
	}
	else
	{
		SetColor(cellColor);
	}
}

void ToggleCell(const Point2f bottomleftCorner, const float cellSideLenght, const float spaceBetweenCells)
{
	Point2f bottomLeftCellBottomLeftPoint{ bottomleftCorner };

	bottomLeftCellBottomLeftPoint.x += spaceBetweenCells;
	bottomLeftCellBottomLeftPoint.y += spaceBetweenCells;

	int index{};
	int rowNumber{ 1 };

	while (index < g_AmountOfColumns * g_AmountOfRows)
	{
		for (; index < g_AmountOfColumns * rowNumber; ++index)
		{
			if (    g_MousePos.x >= bottomLeftCellBottomLeftPoint.x
				 && g_MousePos.x <= bottomLeftCellBottomLeftPoint.x + cellSideLenght
				 && g_MousePos.y >= bottomLeftCellBottomLeftPoint.y
				 && g_MousePos.y <= bottomLeftCellBottomLeftPoint.y + cellSideLenght  
				 && g_CellsSelected[index] == false									 )
			{
				g_CellsSelected[index] = true;
			}
			else if(	g_MousePos.x >= bottomLeftCellBottomLeftPoint.x
					 && g_MousePos.x <= bottomLeftCellBottomLeftPoint.x + cellSideLenght
					 && g_MousePos.y >= bottomLeftCellBottomLeftPoint.y
					 && g_MousePos.y <= bottomLeftCellBottomLeftPoint.y + cellSideLenght
				   	 && g_CellsSelected[index] == true									 )
			{
				g_CellsSelected[index] = false;
			}

			bottomLeftCellBottomLeftPoint.x += cellSideLenght + spaceBetweenCells;
		}

		bottomLeftCellBottomLeftPoint.x = bottomleftCorner.x + spaceBetweenCells;
		bottomLeftCellBottomLeftPoint.y += cellSideLenght + spaceBetweenCells;

		++rowNumber;
	}
}
#pragma endregion ownDefinitions