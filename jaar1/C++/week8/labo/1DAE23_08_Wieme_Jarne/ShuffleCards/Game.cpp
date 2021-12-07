#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here

	CreateCardTextures();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	DrawCardTextures(13, 4, Point2f{ 0.f, 0.f });
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
	DeleteCardTextures();
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
	case SDLK_s:
		ShuffleCardTextures(g_Cards, g_AmountOfCards, 100);
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
void CreateCardTextures()
{
	const int numberOfRanks{ 13 };
	const int numberOfSuits{ 4 };

	for (int suitNumber{ 1 }; suitNumber <= numberOfSuits; ++suitNumber)
	{
		for (int rankNumber{ 1 }; rankNumber <= numberOfRanks; ++rankNumber)
		{
			if (rankNumber < 10)
			{
				TextureFromFile("Recources/" + std::to_string(suitNumber) + '0' + std::to_string(rankNumber) + ".png", g_Cards[(rankNumber - 1) + numberOfRanks * (suitNumber - 1)]);
			}
			else
			{
				TextureFromFile("Recources/" + std::to_string(suitNumber) + std::to_string(rankNumber) + ".png", g_Cards[(rankNumber  - 1) + numberOfRanks * (suitNumber - 1)]);
			}
		}
	}
}

void DeleteCardTextures()
{
	for (int suitNumber{ 1 }; suitNumber <= 4; ++suitNumber)
	{
		for (int rankNumber{ 1 }; rankNumber <= 13; ++rankNumber)
		{
				DeleteTexture(g_Cards[rankNumber - 1]);
		}
	}
}

void DrawCardTextures(int amountOfColumns, int amountOfRows, Point2f bottomLeftCorner)
{
	const float scaleFactor{ 0.5f };
	int index{};
	int rowNumber{ 1 };
	Rectf cardRect{ bottomLeftCorner.x, bottomLeftCorner.y, g_Cards[0].width * scaleFactor, g_Cards[0].height * scaleFactor };

	while (index < amountOfColumns * amountOfRows)
	{
		while (index < amountOfColumns * rowNumber)
		{
			DrawTexture(g_Cards[index], cardRect);

			cardRect.left += g_Cards[index].width * scaleFactor;
			++index;
		}
		cardRect.left = bottomLeftCorner.x;
		cardRect.bottom += g_Cards[index].height * scaleFactor;
		++rowNumber;
	}
}

void ShuffleCardTextures(Texture array[], const int arraySize, int numberOfSwaps)
{
	for (int swapNumber{}; swapNumber < numberOfSwaps; ++swapNumber)
	{
		int randomIndex1{ rand() % (arraySize / 2) };
		int randomIndex2{ rand() % (arraySize / 2) + (arraySize / 2) };

		Texture randomIndex1Copy = array[randomIndex1];

		array[randomIndex1] = array[randomIndex2];
		array[randomIndex2] = randomIndex1Copy;
	}
}
#pragma endregion ownDefinitions