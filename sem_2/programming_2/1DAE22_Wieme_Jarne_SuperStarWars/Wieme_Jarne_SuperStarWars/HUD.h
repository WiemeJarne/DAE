#pragma once
class TextureManager;
class Texture;

class HUD final
{
public:
	explicit HUD(const Point2f& topLeft, int totalAvatarHearts, int totalAvatarHealth, TextureManager& textureManager);
	
	HUD(const HUD& HUD) = delete;
	HUD& operator=(const HUD& rhs) = delete;
	HUD(HUD&& HUD) = delete;
	HUD& operator=(HUD&& rhs) = delete;

	void Update(int avatarHealth, int amountOfHearts, bool gameOver, bool gameHasStarted);
	void Draw( ) const;
	void LostHeart( );
	void LostHealth( );

private:
	const int m_TotalAvatarHearts;
	int m_AmountOfHearts;
	const float m_TotalAvatarHealth;
	int m_AvatarHealth;
	const Texture* m_pHealthBar;
	const Texture* m_pNumberZero;
	const Texture* m_pNumberOne;
	const Texture* m_pNumberTwo;
	const Texture* m_pNumberThree;
	const Texture* m_pStartScreen;
	const Texture* m_pGameOverScreen;
	const Point2f m_BottomLeft;
	bool m_GameOver;
	bool m_GameHasStarted;
	TextureManager& m_TextureManager;

	void DrawAmountOfLives( ) const;
	void DrawAmountOfHealth( ) const;
};

