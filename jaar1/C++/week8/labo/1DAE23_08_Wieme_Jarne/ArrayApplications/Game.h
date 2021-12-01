#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ArrayApplications- Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_MaxNumberOfClickedPoints{ 5 };
Point2f g_PointsClicked[g_MaxNumberOfClickedPoints]{};
int g_IndexNextPoint{};
int g_amountOfPointsInPointsClicked{};
// Declare your own functions here
void AddClickedPoint(Point2f mousePos);
void DrawClickedPoints();
void ConnectClickedPoints();
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
