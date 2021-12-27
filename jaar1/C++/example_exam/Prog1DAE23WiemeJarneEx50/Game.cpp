#include "pch.h"
#include "Game.h"
#include "Tile.h"

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	CreateTiles();
	CreateTextures();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		g_DynnArrTiles[index]->Draw();
	}

	if (CheckIfPuzzleIsSolved()) PuzzleIsSolved();
	else
	{
		SetColor(1.f, 0.f, 0.f);
		DrawRect(1, 0, g_DynnArrTiles[0]->m_SourceRect.width * g_AmountOfColumns - 1, g_DynnArrTiles[0]->m_SourceRect.height * g_AmountOfRows);
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
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };

	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		g_DynnArrTiles[index]->CheckActivation(mousePos);
	}
}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };

	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
		for (int index{}; index < g_AmountOfTiles; ++index)
		{
			g_DynnArrTiles[index]->CheckHit(mousePos);
		}
	}
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
void CreateTiles()
{
	Rectf destinationRect{};
	destinationRect.height = 128;
	destinationRect.width = destinationRect.height;
	destinationRect.bottom = 0;
	destinationRect.left = 0;

	g_DynnArrTiles[0] = new Tile(destinationRect, "Resources/Tiles10.png", g_AmountOfAnimals);

	destinationRect.left = destinationRect.width;
	g_DynnArrTiles[1] = new Tile(destinationRect, "Resources/Tiles11.png", g_AmountOfAnimals);

	destinationRect.bottom = destinationRect.height;
	g_DynnArrTiles[2] = new Tile(destinationRect, "Resources/Tiles01.png", g_AmountOfAnimals);

	destinationRect.left = 0;
	g_DynnArrTiles[3] = new Tile(destinationRect, "Resources/Tiles00.png", g_AmountOfAnimals);
}

void CreateTextures()
{
	TextureFromFile("Resources/Names.png", g_AnimalNames);
}

void DeleteTexturesAndObject()
{
	DeleteTexture(g_AnimalNames);

	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		delete g_DynnArrTiles[index];
	}
}

bool CheckIfPuzzleIsSolved()
{
	for (int index{}; index < g_DynnArrTiles[0]->m_AmountOfAnimals; ++index)
	{
		if (	g_DynnArrTiles[0]->m_SourceRect.left == g_DynnArrTiles[0]->m_SourceRect.width * index
			 && g_DynnArrTiles[1]->m_SourceRect.left == g_DynnArrTiles[0]->m_SourceRect.width * index
			 && g_DynnArrTiles[2]->m_SourceRect.left == g_DynnArrTiles[0]->m_SourceRect.width * index
			 && g_DynnArrTiles[3]->m_SourceRect.left == g_DynnArrTiles[0]->m_SourceRect.width * index)
		{
			return true;
		}
	}
	return false;
}

void PuzzleIsSolved()
{
	SetColor(0.f, 1.f, 0.f);
	DrawRect(1, 0, g_DynnArrTiles[0]->m_SourceRect.width * g_AmountOfColumns - 1, g_DynnArrTiles[0]->m_SourceRect.height * g_AmountOfRows);
	for (int index{}; index < g_AmountOfTiles; ++index)
	{
		g_DynnArrTiles[index]->Deactivate();
	}


	Rectf destinationRect{};
	destinationRect.left = 0;
	destinationRect.bottom = g_DynnArrTiles[0]->m_SourceRect.width * g_AmountOfRows + 10;
	destinationRect.width = g_AnimalNames.width;
	destinationRect.height = g_AnimalNames.height / float(g_AmountOfAnimals);

	Rectf sourceRect{};
	sourceRect.left = 0;
	sourceRect.bottom = g_AnimalNames.height - g_DynnArrTiles[0]->GetCurrentAnimal() * g_AnimalNames.height / float(g_AmountOfAnimals);
	sourceRect.width = g_AnimalNames.width;
	sourceRect.height = g_AnimalNames.height / float(g_AmountOfAnimals);

	DrawTexture(g_AnimalNames, destinationRect, sourceRect);
}
#pragma endregion ownDefinitions