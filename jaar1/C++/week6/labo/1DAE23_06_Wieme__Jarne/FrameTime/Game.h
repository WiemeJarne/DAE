#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "FrameTime - Jarne, Wieme - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
int g_NrFrames{};
float g_AccumulatedTime{};

const float g_SquareSpeedxPerSeconds{};

float g_CircleSpeedXPerSeconds{};
float g_CircleSpeedYPerSeconds{};

float g_CircleXStartValue{};
float g_CircleYStartValue{};

const float g_CircleRadius{ 15.f };

float g_CircleX{};
float g_CircleY{};

bool g_CirclePositiveDirectionX{ true };
bool g_CirclePositiveDirectionY{ true };
// Declare your own functions here
void DrawBall();
void UpdateBall(float elapsedSec);
void CheckIfBallHitBorder();
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
