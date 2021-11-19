#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Point2f g_MousePos{};

Color4f g_CircleColor{};
Color4f g_Red{};

int g_RandomMaxRadius{};

float g_Radius{};
float g_Speed{2.f};

bool g_CircleIsDrawing{};

enum class g_CircleState
{
	circleIsGrowing,
	circleIsShrinking,
	noCircle
};
g_CircleState g_CircleDrawingState{g_CircleState::noCircle};
// Declare your own functions here

// Functies voor console oefening
void PrintLetters();

// Functies voor grafische oefening
void DrawCircle();
void Check_g_CircleDrawingState();
void CheckIfCircleTouchesWindowEdge();
void GenerateRandomColorAndRadius();
void Check_g_Radius();
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
