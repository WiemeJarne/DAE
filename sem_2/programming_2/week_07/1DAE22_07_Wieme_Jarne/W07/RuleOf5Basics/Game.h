#pragma once
#include <vector>

class Container;
class Sprite;

class Game final
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( ) const;

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	const Window m_Window;

	const int m_AmountOfRows;
	const int m_AmountOfColumns;
	std::vector<Sprite*> m_Sprites;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;

	Container CreateContainer(int amountOfElements, int min, int max);
	void TestContainer();

	void TestSpriteClass();
	Sprite CreateSprite(const std::string& path, int cols, int rows, float frameSec);
	void CreateSprites( );
	void DrawSprites( ) const;
};