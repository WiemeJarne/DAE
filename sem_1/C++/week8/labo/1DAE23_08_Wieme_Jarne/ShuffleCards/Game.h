#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "ShuffleCards - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 910 };
float g_WindowHeight{ 380 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
const int g_AmountOfCards{ 52 };
Texture g_Cards[g_AmountOfCards]{};
// Declare your own functions here
void CreateCardTextures();
void DeleteCardTextures();
void DrawCardTextures(int amountOfColumns, int amountOfRows, Point2f bottomLeftCorner);
void ShuffleCardTextures(Texture array[], const int arraySize, int numberOfSwaps);
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
