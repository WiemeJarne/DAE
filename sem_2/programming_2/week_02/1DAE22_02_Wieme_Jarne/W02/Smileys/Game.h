#pragma once
class Smiley;

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
	const float m_SafeZoneBorder;
	Rectf m_SafezoneBorderRect;
	static const int m_AmountOfSmileys{ 10 };
	Smiley* m_pSmileys[m_AmountOfSmileys];
	int m_PreviousHighestSmileyIndex;

	// FUNCTIONS
	void Initialize( );
	void Cleanup( );
	void ClearBackground( ) const;
	void CreateSmileys( );
	void DeleteSmileys( );
	void DrawSmileys( ) const;
	void UpdateSmileys( float elapsedSec );
	void DrawSafeZoneBorder( ) const;
	void HitTestSmileys( const Point2f& mousePos ) const;
	int DetermineHighestSmiley(const int highestSmileyIndex, const int index) const;
	void IncreaseSmileysSpeed( );
	void DecreaseSmileySpeed( );
	void DeleteSleepingSmileys( );
};