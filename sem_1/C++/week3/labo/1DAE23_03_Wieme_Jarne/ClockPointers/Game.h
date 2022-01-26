#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ClockPointers - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_hoekKleineWijzer{};
float g_kleineHoek1KleineWijzer{ float( 2 * M_PI / 48 ) };
float g_kleineHoek2KleineWijzer{ float(- ( 2 * M_PI / 48 )) };
float g_hoekGroteWijzer{};
float g_kleineHoek1GroteWijzer{ float( 2 * M_PI / 48 ) };
float g_kleineHoek2GroteWijzer{ float(- ( 2 * M_PI / 48 )) };
// Declare your own functions here
void DrawClockPointers();
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
