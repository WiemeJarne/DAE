#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DrawFuntions - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 650 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

// Declare your own functions here
void DrawSquares(const int numberOfSquares, float pointX, float pointY, int sideLenght);
void DrawSquares(int numberOfSquares, Point2f point2, int sideLenght);

void DrawEquilateralTriangle(const float bottomLeftPointX, const float bottomLeftPointY, const float sideLenght, const bool filled, const Color4f color);
void DrawEquilateralTriangle(const Point2f bottomLeftPoint, const float sideLenght, const bool filled, const Color4f color);

void DrawPentagram(const float middlePointX, const float middlePointY, const float radius, const float lineWidth, const Color4f color);
void DrawPentagram(const Point2f middlePoint, const float radius, const float lineWidth, const Color4f color);

void DrawLinearGradient(const Rectf rectangle, Color4f startColor, Color4f endColor);
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
