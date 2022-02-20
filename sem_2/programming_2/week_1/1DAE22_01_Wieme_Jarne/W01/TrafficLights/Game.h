#pragma once
#include <vector>
class TrafficLight;

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
	std::vector<TrafficLight*> m_TrafficLights;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;
	void InitTraficlights(const int aamountOfRows, const int amountOfcolumns);
	void DeleteTrafficLights();
	void DrawTrafficLights() const;
	void UpdateTrafficLights(const float elapsedSec);
	void DoHitTestTrafficLights(const Point2f& mousePos);
};