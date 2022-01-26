#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Recursion - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 1920 };
float g_WindowHeight{ 1080 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Color4f g_Red{};
Color4f g_Blue{};
Color4f g_Green{};

int g_NumberOfLoops{};
// Declare your own functions here
void DrawSierpinskiTriangle(const Point2f& left, const Point2f& top, const Point2f& right);
Point2f Middle(const Point2f& point1, const Point2f& point2);
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
