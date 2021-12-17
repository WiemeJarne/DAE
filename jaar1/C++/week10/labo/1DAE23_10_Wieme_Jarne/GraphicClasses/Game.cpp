#include "pch.h"
#include "Game.h"
#include "Fraction.h"
#include "Light.h"
#include "DaeEllipse.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions										
void Start()
{
	// initialize game resources here
	g_DynArrFractions = new Fraction* [g_AmountOfFractions];
	CreateFractions();
	PrintFractionsSum();

	g_DynArrLights = new Light* [g_AmountOfLights];
	CreateLights();

	g_DynArrDaeEllipses = new DaeEllipse* [g_AmountOfDaeEllipses];
	CreateDaeEllipses();
}

void Draw()
{
	ClearBackground(0.f, 0.f, 0.f);

	// Put your own draw statements here
	DrawFractions();
	DrawLights();
	DrawDaeEllipses();
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
	DeleteFractions();
	DeleteLights();
	DeleteDaeEllipses();
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

	ActivateDaeEllipsesTest(mousePos);
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
		Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
		HitLights(mousePos);
		
		PrintAmountOfLightsOn();
		break;
	}
	}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here

void CreateFractions()
{
	int numerator{ 3 };
	int denominator{ 5 };

	for (int index{}; index < g_AmountOfFractions; ++index)
	{
		g_DynArrFractions[index] = new Fraction(numerator, denominator);

		if (index == 0) numerator = 2;
		if (index == 1 || index == 4) denominator = 3;
		if (index == 2) denominator = 4;
		if (index == 3) numerator = 1;
	}
}

void DeleteFractions()
{
	for (int index{}; index < g_AmountOfFractions; ++index)
	{
		delete g_DynArrFractions[index];
		g_DynArrFractions[index] = nullptr;
	}
	delete[] g_DynArrFractions;
	g_DynArrFractions = nullptr;
}

void PrintFractionsSum()
{
	float fractionsSum{};

	for (int index{}; index < g_AmountOfFractions; ++index)
	{
		fractionsSum += g_DynArrFractions[index]->GetValue();
	}

	std::cout << "Total value of created Fraction objects: " << fractionsSum << '\n';
}

void DrawFractions()
{
	Point2f pos{10, 10};
	const float size{ 20 };
	const float spaceBetweenFractions{ 10 };

	for (int index{ g_AmountOfFractions - 1 }; index > -1; --index)
	{
		g_DynArrFractions[index]->Draw(pos, size);
		pos.y += size + spaceBetweenFractions;
	}
}

void CreateLights()
{
	Color4f randColor{};
	Rectf lightRect{};
	const float spaceBetweenLights{ 10 };
	const float startPosX{125};

	lightRect.left = startPosX;
	lightRect.bottom = 10;
	lightRect.height = 25;
	
	for (int rowNumber{}; rowNumber < g_AmountOfRows; ++rowNumber)
	{
		for (int columnNumber{}; columnNumber < g_AmountOfColumns; ++columnNumber)
		{
			const int currentIndex{ rowNumber + g_AmountOfRows * columnNumber };

			randColor.r = (rand() % 256) / 255.f;
			randColor.g = (rand() % 256) / 255.f;
			randColor.b = (rand() % 256) / 255.f;

			lightRect.width = float(rand() % 31 + 15);

			g_DynArrLights[currentIndex] = new Light{ lightRect, randColor };

			lightRect.left += lightRect.width + spaceBetweenLights;
		}
		lightRect.left = startPosX;
		lightRect.bottom += lightRect.height + spaceBetweenLights;
	}
}

void DeleteLights()
{
	for (int index{}; index < g_AmountOfLights; ++index)
	{
		delete g_DynArrLights[index];
		g_DynArrLights[index] = nullptr;
	}
	delete[] g_DynArrLights;
	g_DynArrLights = nullptr;
}

void DrawLights()
{
	for (int index{}; index < g_AmountOfLights; ++index)
	{
		g_DynArrLights[index]->Draw();
	}
}

void HitLights(const Point2f& pos)
{
	for (int index{}; index < g_AmountOfLights; ++index)
	{
		g_DynArrLights[index]->IsHit(pos);
	}
}

void PrintAmountOfLightsOn()
{
	if (CalculateAmountOfLightOn() < g_AmountOfLightsOn)
	{
		--g_AmountOfLightsOn;
		std::cout << CalculateAmountOfLightOn() << " lights are on\n";
	}
	else if (CalculateAmountOfLightOn() > g_AmountOfLightsOn)
	{
		++g_AmountOfLightsOn;
		std::cout << CalculateAmountOfLightOn() << " lights are on\n";
	}
}

int CalculateAmountOfLightOn()
{
	int AmountIfLightsOn{};
	for (int index{}; index < g_AmountOfLights; ++index)
	{
		if (g_DynArrLights[index]->IsOn()) ++AmountIfLightsOn;
	}
	return AmountIfLightsOn;
}

void CreateDaeEllipses()
{
	Point2f center{350, g_WindowHeight / 2 };
	float radX{ 140 };
	float radY{ radX };
	Color4f fillColor{ 1.f, 1.f, 0.f, 1.f };

	for (int index{}; index < g_AmountOfDaeEllipses; ++index)
	{
		g_DynArrDaeEllipses[index] = new DaeEllipse{ center, radX, radY, fillColor };

		if (index == 0) center = Point2f{ 200, 240 }, radX = 50, radY = 100, fillColor = Color4f{ 0.f, 1.f, 0.f, 1.f };
		if (index == 1) center = Point2f{ 100, 240 }, radX = 50, radY = radX, fillColor = Color4f{ 1.f, 0.f, 0.f, 1.f };
	}
}

void DeleteDaeEllipses()
{
	for (int index{}; index < g_AmountOfDaeEllipses; ++index)
	{
		delete g_DynArrDaeEllipses[index];
		g_DynArrDaeEllipses[index] = nullptr;
	}
	delete[] g_DynArrDaeEllipses;
	g_DynArrDaeEllipses = nullptr;
}

void DrawDaeEllipses()
{
	for (int index{}; index < g_AmountOfDaeEllipses; ++index)
	{
		g_DynArrDaeEllipses[index]->Draw();
	}
}

void ActivateDaeEllipsesTest(const Point2f& mousePos)
{
	for (int index{}; index < g_AmountOfDaeEllipses; ++index)
	{
		g_DynArrDaeEllipses[index]->ActivateTests(mousePos);
	}
}
#pragma endregion ownDefinitions