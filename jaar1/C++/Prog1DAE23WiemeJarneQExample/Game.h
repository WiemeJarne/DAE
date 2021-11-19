#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Prog1DAE23WiemeJarneQExample - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_Even{};
int g_Odd{};
int g_Any{};
float g_Time{};

bool g_ElevatorIsMoving{};
bool g_LeftMouseButtonClicked{};
bool g_ElevatorIsGoingUp{};
Point2f g_MousePos{};
float g_SpaceBelowElevator{ 30 };
float g_TimeForElevator{};
Color4f g_Red{};
Color4f g_Green{};
Color4f g_Black{};
Color4f g_ElevatorInteriorColor{};

// Declare your own functions here
void Generate();
void PrintRandomNumbers();

void DrawElevator();
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
