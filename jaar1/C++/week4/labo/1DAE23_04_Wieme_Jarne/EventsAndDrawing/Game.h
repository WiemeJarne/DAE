#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "EventsAndDrawing - Wieme, Jarne - 1DAE23" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
float g_SpaceLeftFromRect{};
float g_SpaceBelowRect{};
float g_RectWidth{};
float g_RectHeight{};
float g_NewSpaceLeftFromRect{};
float g_NewRectWidth{};
float g_SpaceLeftPlusRectWidth{};

Color4f g_Grey{};
Color4f g_Green{};

bool g_RectangleIsGrey{ true };
bool g_RectangleMovingState{ false };
bool g_BoucinglineState{ false };

Point2f g_BouncingLinePoint1{};
Point2f g_BouncingLinePoint2{};

enum class RectangleMovingState
{
	rectangleIsMoving,
	rectangleIsNotmoving
};

enum class LinePoint1xMovingState
{
	xIncreasing,
	xDecreasing
};
LinePoint1xMovingState g_LinePoint1xMovingState{ LinePoint1xMovingState::xIncreasing };

enum class LinePoint1yMovingState
{
	yIncreasing,
	yDecreasing
};
LinePoint1yMovingState g_LinePoint1yMovingState{ LinePoint1yMovingState::yIncreasing };

enum class LinePoint2xMovingState
{
	xIncreasing,
	xDecreasing
};
LinePoint2xMovingState g_LinePoint2xMovingState{ LinePoint2xMovingState::xDecreasing };

enum class LinePoint2yMovingState
{
	yIncreasing,
	yDecreasing
};
LinePoint2yMovingState g_LinePoint2yMovingState{ LinePoint2yMovingState::yIncreasing };

// Declare your own functions here
void GenerateRandomNumbersForRectangle();
void GenerateRandomNumbersForLine();
void RectangleIsOfScreen();
void BouncingLineMovingState();
void RectangleMovingState();
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
