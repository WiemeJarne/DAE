#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MatchesGame - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 600 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Color4f g_Red{};
Color4f g_Yellow{};

std::string g_PCMoves{ "PC moves: " };
std::string g_PlayerMoves{ "Your moves: " };

int g_MainPile{ 21 };
int g_PlayerPile{};
int g_PCPile{};
int g_NumberOfMatchesTakenByPlayer{};
int g_NumberOfMatchesTakenByPC{};

bool g_PCTurn{};
bool g_PlayerWon{};
bool g_PlayerLost{};
// Declare your own functions here
void DrawMainPile();
void DrawPlayerPile();
void DrawPCPile();
void GenerateRandomNumberOfMatches();
void CheckIfSomeoneWon();
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
