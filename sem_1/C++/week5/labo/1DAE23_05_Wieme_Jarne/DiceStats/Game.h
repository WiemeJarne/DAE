#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "DiceStats - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 515 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_AmountNumber1Trown{};
float g_AmountNumber2TrownWithOneDie{};
float g_AmountNumber3TrownWithOneDie{};
float g_AmountNumber4TrownWithOneDie{};
float g_AmountNumber5TrownWithOneDie{};
float g_AmountNumber6TrownWithOneDie{};

float g_AmountNumber2TrownWithTwoDice{};
float g_AmountNumber3TrownWithTwoDice{};
float g_AmountNumber4TrownWithTwoDice{};
float g_AmountNumber5TrownWithTwoDice{};
float g_AmountNumber6TrownWithTwoDice{};
float g_AmountNumber7TrownWithTwoDice{};
float g_AmountNumber8TrownWithTwoDice{};
float g_AmountNumber9TrownWithTwoDice{};
float g_AmountNumber10TrownWithTwoDice{};
float g_AmountNumber11TrownWithTwoDice{};
float g_AmountNumber12TrownWithTwoDice{};

// Declare your own functions here
void SimulateRollingDice();
void DrawAmountsOfEachNumberTrownRectangle();
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
