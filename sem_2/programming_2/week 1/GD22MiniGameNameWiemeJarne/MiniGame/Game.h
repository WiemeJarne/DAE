#pragma once
#include "Level.h"
#include "PowerUpManager.h"
#include "Vector2f.h"

class Game final
{
public:
	explicit Game(const Window& window);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	Game(Game&& other) = delete;
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
	const Vector2f m_GravityAccelaration;

	Rectf m_ActorShape;
	const Color4f m_InAirColor;
	const Color4f m_OnGroundColor;
	bool m_IsOnGround;
	Vector2f m_ActorVelocity;

	Level m_Level;
	PowerUpManager m_PowerUpManager;

	// FUNCTIONS
	void Initialize( );
	void Cleanup();
	void ClearBackground( ) const;
	void ShowTestMessage( ) const;
	void AddPowerUps( );
	void UpdateActor( float elapsedSec );
	void DrawActor( ) const;
	void PositionActor( float newCenterX );
};