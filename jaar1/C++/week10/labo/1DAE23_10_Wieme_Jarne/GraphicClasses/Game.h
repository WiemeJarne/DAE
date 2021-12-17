#pragma once
using namespace utils;
class Fraction;
class Light;
class DaeEllipse;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "GraphicsClasses - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 300 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfFractions{ 6 };
Fraction** g_DynArrFractions;

const int g_AmountOfRows{ 4 };
const int g_AmountOfColumns{ 2 };
const int g_AmountOfLights{ g_AmountOfRows * g_AmountOfColumns };
Light** g_DynArrLights;
int g_AmountOfLightsOn{ g_AmountOfRows * g_AmountOfColumns };

const int g_AmountOfDaeEllipses{ 3 };
DaeEllipse** g_DynArrDaeEllipses;
// Declare your own functions here
void CreateFractions();
void DeleteFractions();
void PrintFractionsSum();
void DrawFractions();

void CreateLights();
void DeleteLights();
void DrawLights();
void HitLights(const Point2f& pos);
void PrintAmountOfLightsOn();
int CalculateAmountOfLightOn();

void CreateDaeEllipses();
void DeleteDaeEllipses();
void DrawDaeEllipses();
void ActivateDaeEllipsesTest(const Point2f& mousePos);
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
