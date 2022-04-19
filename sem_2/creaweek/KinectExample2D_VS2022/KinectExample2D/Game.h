#pragma once
#include <vector>
#include "Kinect.h"
#include "Texture.h"

class Ball;

class Game
{
public:
	explicit Game( const Window& window );
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game( Game&& other) = delete;
	Game& operator=(Game&& other) = delete;
	~Game();

	void Update( float elapsedSec );
	void Draw( );

	// Event handling
	void ProcessKeyDownEvent( const SDL_KeyboardEvent& e );
	void ProcessKeyUpEvent( const SDL_KeyboardEvent& e );
	void ProcessMouseMotionEvent( const SDL_MouseMotionEvent& e );
	void ProcessMouseDownEvent( const SDL_MouseButtonEvent& e );
	void ProcessMouseUpEvent( const SDL_MouseButtonEvent& e );

private:
	// DATA MEMBERS
	const Window m_Window;
	Kinect m_Kinect;
	std::vector<Ball> m_Balls;
	float m_AccuSec;
	int m_Score;
	int m_Health;
	const Texture m_HeartTexture;
	Texture m_ScoreTexture;
	Texture m_GameOverTexture;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;
	void AddBall(float elapsedSec);
	void HandleCollision(int index);
};