#include "pch.h"
#include "Game.h"
#include "Vehicle.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	PrintGameInfo();

	CreateTextures();
}

void Draw()
{
	ClearBackground();

	// Put your own draw statements here
	const Point2f bottomLeftPointStreet{ 0,0 };
	DrawStreet(bottomLeftPointStreet);
	
	DrawChicken();

	DrawCars();

	if (g_ChickenSurvived == true)
	{
		ChickenSurvived();
	}

	if (g_ChickenIsDead == true)
	{
		ChickenIsDead();
	}
}

void Update(float elapsedSec)
{
	// process input, do physics 
	if (CheckCollisions() == true)
	{
		g_ChickenIsDead = true;
	}

	for (int index{}; index < g_AmountOfVehicles; ++index)
	{
		g_PtrVehicles[index]->Update(elapsedSec, g_WindowWidth);
	}
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
	DeleteTextures();
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{
	const int amountOfPixelsToMove{ 1 };

	switch (key)
	{
	case SDLK_LEFT:
		if ((CheckIfChickenIsOnBottomPavement() == false || g_ChickenIsDead == false) && g_Pause == false)
		{
			g_ChickenPos.x -= amountOfPixelsToMove;
			if (key == SDLK_DOWN)
			{
				g_ChickenPos.y -= amountOfPixelsToMove;
			}
		}
		break;
	case SDLK_RIGHT:
		if ((CheckIfChickenIsOnBottomPavement() == false || g_ChickenIsDead == false) && g_Pause == false)
		{
			g_ChickenPos.x += amountOfPixelsToMove;
			if (key == SDLK_DOWN)
			{
				g_ChickenPos.y -= amountOfPixelsToMove;
			}
		}
		break;
	case SDLK_DOWN:
		if ((CheckIfChickenIsOnBottomPavement() == false || g_ChickenIsDead == false) && g_Pause == false)
		{
			g_ChickenPos.y -= amountOfPixelsToMove;
		}
		break;
	case SDLK_r:
		Reset();
		break;
	case SDLK_p:
		g_Pause = !g_Pause;
		break;
	}
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
void PrintGameInfo()
{
	std::cout << "Het doel van het spel is om de kip aan de andere kant van de straat te krijgen.\n";
	std::cout << "Klik op het linker pijltje om de kip naar links te doen bewegen.\n";
	std::cout << "Klik op het rechter pijltje om de kip naar rechts te doen bewegen.\n";
	std::cout << "Klik op het pijltje naar onder om de kip naar onder the doen bewegen.\n";
	std::cout << "Als je tergelijk op het linker pijltje en het pijltje naar onder klikt dan beweegt de kip diagonaal naar links onder.\n";
	std::cout << "Als je tergelijk op het rechter pijltje en het pijltje naar onder klikt dan beweegt de kip diagonaal naar rechts onder.\n";
	std::cout << "Als de kip door een auto geraakt word dan is het GAME OVER!\n";
	std::cout << "Klik op r om te herstarten.\n";
	std::cout << "Klik op p om de game te pauzeren en druk nog eens op p om de game te hervatten.\n";
}

void CreateTextures()
{
	TextureFromFile("Resources/street.PNG", g_StreetTexture);
	TextureFromFile("Resources/Chicken.bmp", g_ChickenTexture);

	const float laneHeight{ 45 };

	for (int index{ 1 }; index <= g_AmountOfVehicles; ++index)
	{
		g_PtrVehicles[index -1] = { new Vehicle{index} };

		g_PtrVehicles[index - 1]->SetYPos(g_PavementHeight + (index - 1) * laneHeight);
	}
}

void DeleteTextures()
{
	DeleteTexture(g_StreetTexture);
	DeleteTexture(g_ChickenTexture);

	for (int index{}; index < g_AmountOfVehicles; ++index)
	{
		delete g_PtrVehicles[index];
		g_PtrVehicles[index] = nullptr;
	}
}

void DrawStreet(const Point2f& bottomLeftPointStreet)
{
	Rectf destinationRectStreet{};
	destinationRectStreet.left = bottomLeftPointStreet.x;
	destinationRectStreet.bottom = bottomLeftPointStreet.y;
	destinationRectStreet.width = g_StreetTexture.width;
	destinationRectStreet.height = g_StreetTexture.height;

	DrawTexture(g_StreetTexture, destinationRectStreet);
}

void DrawChicken()
{
	const int amountOfFrames{ 3 };

	Rectf destinationRectChicken{};
	destinationRectChicken.left = g_ChickenPos.x;
	destinationRectChicken.bottom = g_ChickenPos.y;
	destinationRectChicken.width = g_ChickenTexture.width / amountOfFrames;
	destinationRectChicken.height = g_ChickenTexture.height;

	Rectf sourceRectChicken{};
	sourceRectChicken.left = 0;
	sourceRectChicken.bottom = g_ChickenTexture.height;
	sourceRectChicken.width = g_ChickenTexture.width / amountOfFrames;
	sourceRectChicken.height = g_ChickenTexture.height;

	DrawTexture(g_ChickenTexture, destinationRectChicken, sourceRectChicken);
}

bool CheckIfChickenIsOnBottomPavement()
{
	if (g_ChickenPos.y + g_ChickenTexture.height <= g_PavementHeight)
	{
		g_ChickenSurvived = true;
		return true;
	}

	return false;
}

void ChickenSurvived()
{
	Texture imgText{};
	const std::string textForImage{ "The chicken survived!" };
	const Color4f textColor{ 1.f, 1.f, 1.f, 1.f };

	TextureFromString(textForImage, g_FontPath, g_TextSize, textColor, imgText);

	Rectf destinationRect{};
	destinationRect.left = g_WindowWidth / 2 - imgText.width / 2;
	destinationRect.bottom = g_WindowHeight / 2 - imgText.height / 2;
	destinationRect.width = imgText.width;
	destinationRect.height = imgText.height;

	SetColor(0.f, 0.f, 0.f, 0.30f);
	FillRect(destinationRect);

	DrawTexture(imgText, destinationRect);

	DeleteTexture(imgText);
}

void Reset()
{
	g_ChickenSurvived = false;
	g_ChickenPos = g_ChickenStartPos;

	for (int index{}; index < g_AmountOfVehicles; ++index)
	{
		g_PtrVehicles[index]->Reset();
	}
}

void DrawCars()
{
	for (int index{}; index < g_AmountOfVehicles; ++index)
	{
		g_PtrVehicles[index]->Draw();
	}
}

bool CheckCollisions()
{
	Point2f middlePosChicken{ g_ChickenPos.x + g_ChickenTexture.width / 2, g_ChickenPos.y + g_ChickenTexture.height / 2 };

	for (int index{}; index < g_AmountOfVehicles; ++index)
	{
		if (g_PtrVehicles[index]->IsIntersecting(middlePosChicken))
		{
			g_PtrVehicles[index]->SetActive(false);
			return true;
		}
	}

	return false;
}

void ChickenIsDead()
{
	Texture imgText{};
	const std::string textForImage{ "The chicken died!" };
	const Color4f textColor{ 1.f, 1.f, 1.f, 1.f };

	TextureFromString(textForImage, g_FontPath, g_TextSize, textColor, imgText);

	Rectf destinationRect{};
	destinationRect.left = g_WindowWidth / 2 - imgText.width / 2;
	destinationRect.bottom = g_WindowHeight / 2 - imgText.height / 2;
	destinationRect.width = imgText.width;
	destinationRect.height = imgText.height;

	SetColor(0.f, 0.f, 0.f, 0.30f);
	FillRect(destinationRect);

	DrawTexture(imgText, destinationRect);

	DeleteTexture(imgText);
}
#pragma endregion ownDefinitions