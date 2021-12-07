#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateOxoTextures();
	ChooseRandomStartPlayer();
	std::cout << "Press i for more info.\n";
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawGrid();
	DrawPlayerBoxes(Point2f{ 10, 10 }, Point2f{ g_WindowWidth - (10 + g_LeftPlayerBoxTexture.width * g_ScaleFactor), 10 });
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
	DeleteOxoTextures();
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
	case SDLK_a:
		if (g_LeftPlayerTurn)
		{
			SwitchLeftPlayerChoice();
		}		
		break;
	case SDLK_l:
		if (g_LeftPlayerTurn == false)
		{
			SwitchRightPlayerChoice();
		}
		break;
	case SDLK_r:
		Reset();
		break;
	case SDLK_i:
		PrintGameInfo();
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
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		CheckMousePos(mousePos);
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void CreateOxoTextures()
{
	TextureFromFile("Recources/FreeCell.png", g_FreeCell);
	TextureFromFile("Recources/GreenO.png", g_GreenO);
	TextureFromFile("Recources/GreenX.png", g_GreenX);
	TextureFromFile("Recources/WhiteO.png", g_WhiteO);
	TextureFromFile("Recources/WhiteX.png", g_WhiteX);
	TextureFromFile("Recources/Win.png", g_Win);
	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			g_OxoGrid[(columnNumber) + g_AmountOfRows * (rowNumber)] = g_FreeCell;
		}
	}
}

void DeleteOxoTextures()
{
	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			DeleteTexture(g_OxoGrid[(columnNumber) + g_AmountOfRows * (rowNumber)]);
		}
	}
	DeleteTexture(g_FreeCell);
	DeleteTexture(g_GreenO);
	DeleteTexture(g_GreenX);
	DeleteTexture(g_WhiteO);
	DeleteTexture(g_WhiteX);
	DeleteTexture(g_Win);
	DeleteTexture(g_LeftPlayerBoxTexture);
	DeleteTexture(g_RightPlayerBoxTexture);
}

void DrawGrid()
{
	Rectf cellRect{  g_BottomLeftCornerOfGrid.x, g_BottomLeftCornerOfGrid.y, g_OxoGrid[0].width * g_ScaleFactor, g_OxoGrid[0].height * g_ScaleFactor };

	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			DrawTexture(g_OxoGrid[(columnNumber) + g_AmountOfRows * (rowNumber)], cellRect);
			cellRect.left += g_OxoGrid[0].width * g_ScaleFactor + g_SpaceBetweenCells;
		}
		cellRect.left = g_BottomLeftCornerOfGrid.x;
		cellRect.bottom += g_OxoGrid[0].height * g_ScaleFactor + g_SpaceBetweenCells;
	}
}

void DrawPlayerBoxes(Point2f bottomLeftCornerOfLeftPlayer, Point2f bottomLeftCornerOfRightPlayer)
{
	g_LeftPlayerBoxTexture.width = g_LeftPlayerBoxTexture.width * g_ScaleFactor;
	g_LeftPlayerBoxTexture.height = g_LeftPlayerBoxTexture.height * g_ScaleFactor;
	g_RightPlayerBoxTexture.width = g_RightPlayerBoxTexture.width * g_ScaleFactor;
	g_RightPlayerBoxTexture.height = g_RightPlayerBoxTexture.height * g_ScaleFactor;

	DrawTexture(g_LeftPlayerBoxTexture, bottomLeftCornerOfLeftPlayer);
	DrawTexture(g_RightPlayerBoxTexture, bottomLeftCornerOfRightPlayer);
}

void SwitchLeftPlayerChoice()
{
	if (g_LeftPlayerBoxTexture.id == g_GreenO.id)
	{
		g_LeftPlayerBoxTexture.id = g_GreenX.id;
		g_SelectedTexture.id = g_WhiteX.id;
	}
	else if (g_LeftPlayerBoxTexture.id == g_GreenX.id)
	{
		g_LeftPlayerBoxTexture.id = g_GreenO.id;
		g_SelectedTexture.id = g_WhiteO.id;
	}
}

void SwitchRightPlayerChoice()
{
	if (g_RightPlayerBoxTexture.id == g_GreenO.id)
	{
		g_RightPlayerBoxTexture.id = g_GreenX.id;
		g_SelectedTexture.id = g_WhiteX.id;
	}
	else if (g_RightPlayerBoxTexture.id == g_GreenX.id)
	{
		g_RightPlayerBoxTexture.id = g_GreenO.id;
		g_SelectedTexture.id = g_WhiteO.id;
	}
}

void PrintGameInfo()
{
	std::cout << "The Player who's turn it is, is indicated in the bottom corners.\n";
	std::cout << "If your square is green with a letter inside it then it is your turn.\n";
	std::cout << "The letter in your square is the selected letter.\n";
	std::cout << "If it is the left player's turn press a to change the selected letter.\n";
	std::cout << "If it is the right player's turn press l to change the selected letter.\n";
}

void CheckMousePos(Point2f mousePos)
{
	Point2f bottomLeftCornerOfCurrentCell{ g_BottomLeftCornerOfGrid };

	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			if (	mousePos.x >= bottomLeftCornerOfCurrentCell.x
				 && mousePos.x <= bottomLeftCornerOfCurrentCell.x + g_OxoGrid[0].width * g_ScaleFactor
				 && mousePos.y >= bottomLeftCornerOfCurrentCell.y
				 && mousePos.y <= bottomLeftCornerOfCurrentCell.y + g_OxoGrid[0].height * g_ScaleFactor )
			{
				ChangeClickedCellTexture(rowNumber, columnNumber);
				CheckIfPlayerWon();

				if (    g_LeftPlayerBoxTexture.id != g_Win.id
					 && g_RightPlayerBoxTexture.id != g_Win.id )
				{
					ChangePlayerTurn();
				}
			}
			bottomLeftCornerOfCurrentCell.x += g_OxoGrid[0].width * g_ScaleFactor + g_SpaceBetweenCells;
		}
		bottomLeftCornerOfCurrentCell.x = g_BottomLeftCornerOfGrid.x;
		bottomLeftCornerOfCurrentCell.y += g_OxoGrid[0].height * g_ScaleFactor + g_SpaceBetweenCells;
	}
}

void ChangeClickedCellTexture(const int rowNumber, const int columnNumber)
{
	if (g_SelectedTexture.id == g_WhiteO.id)
	{
		g_OxoGrid[(columnNumber) + g_AmountOfRows * (rowNumber)].id = g_WhiteO.id;
	}
	else if (g_SelectedTexture.id == g_WhiteX.id)
	{
		g_OxoGrid[(columnNumber) + g_AmountOfRows * (rowNumber)].id = g_WhiteX.id;
	}
}

void ChangePlayerTurn()
{
	if (g_LeftPlayerTurn)
	{
		g_LeftPlayerTurn = false;
		g_RightPlayerBoxTexture = g_LeftPlayerBoxTexture;
		g_LeftPlayerBoxTexture = g_FreeCell;
	}
	else
	{
		g_LeftPlayerTurn = true;
		g_LeftPlayerBoxTexture = g_RightPlayerBoxTexture;
		g_RightPlayerBoxTexture = g_FreeCell;
	}
}

void CheckIfPlayerWon()
{
	const int amountOfOffSets{ 3 };
	int offSet[amountOfOffSets]{1, 3, 4};

	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			for (int index{}; index < amountOfOffSets; ++index)
			{
				if (	g_OxoGrid[(columnNumber) + g_AmountOfRows * (rowNumber)].id == g_WhiteO.id
					 && g_OxoGrid[((columnNumber) + g_AmountOfRows * (rowNumber)) + offSet[index]].id == g_WhiteX.id
					 && g_OxoGrid[((columnNumber) + g_AmountOfRows * (rowNumber)) + 2 * offSet[index]].id == g_WhiteO.id )
				{
					if (g_LeftPlayerTurn)
					{
						g_LeftPlayerBoxTexture.id = g_Win.id;
					}
					else
					{
						g_RightPlayerBoxTexture.id = g_Win.id;
					}
				}
			}

			if (    g_OxoGrid[((columnNumber)+g_AmountOfRows * (rowNumber)) + 2].id == g_WhiteO.id
				 && g_OxoGrid[((columnNumber)+g_AmountOfRows * (rowNumber)) + 4].id == g_WhiteX.id
				 && g_OxoGrid[((columnNumber)+g_AmountOfRows * (rowNumber)) + 6].id == g_WhiteO.id )
			{
				if (g_LeftPlayerTurn)
				{
					g_LeftPlayerBoxTexture.id = g_Win.id;
				}
				else
				{
					g_RightPlayerBoxTexture.id = g_Win.id;
				}
			}
		}
	}
}

void Reset()
{
	ChooseRandomStartPlayer();

	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			g_OxoGrid[(columnNumber) + g_AmountOfRows * (rowNumber)].id = g_FreeCell.id;
		}
	}
}

int GenerateRandomNumber()
{
	return rand() % 2 ;
}

void ChooseRandomStartPlayer()
{
	if (GenerateRandomNumber() == 0)
	{
		
		g_LeftPlayerBoxTexture = g_GreenO;
		g_RightPlayerBoxTexture = g_FreeCell;
		g_SelectedTexture = g_WhiteO;
		g_LeftPlayerTurn = true;
	}
	else
	{
		g_RightPlayerBoxTexture = g_GreenO;
		g_LeftPlayerBoxTexture = g_FreeCell;
		g_SelectedTexture = g_WhiteO;
		g_LeftPlayerTurn = false;
	}
}
#pragma endregion ownDefinitions