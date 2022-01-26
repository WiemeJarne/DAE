#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "GameFunctions - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_RandomRadius{};
float g_RandomRectangleWitdh{};
float g_RandomRectangleHeight{};

Point2f g_RandomMiddlePoint{};
Point2f g_MousePos{};
Point2f g_RandomLeftBottomRectanglePoint{};

Circlef g_Circle{ g_RandomMiddlePoint, g_RandomRadius };

Rectf g_Rectangle{ g_RandomLeftBottomRectanglePoint.x, g_RandomLeftBottomRectanglePoint.y, g_RandomRectangleWitdh, g_RandomRectangleHeight };
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
