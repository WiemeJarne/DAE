#pragma once
using namespace utils;
#include "Sprite.h"

#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfSprites{ 5 };
const int g_SpritesHeight{ 200 };

Sprite* g_MySpritesArr[g_AmountOfSprites]{};
Point2f g_MySpritesLocationArr[g_AmountOfSprites]{ {50,g_SpritesHeight}
												  ,{150,g_SpritesHeight}
												  ,{200,g_SpritesHeight}
												  ,{200,g_SpritesHeight}
												  ,{2500,g_SpritesHeight} };
// Declare your own functions here

#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
