#pragma once
class TextureManager;
class Texture;

class HUD final
{
public:
	explicit HUD(const Point2f& windowTopRight, int totalAvatarHearts, int totalAvatarHealth, int totalPitMonsterHealth, TextureManager& textureManager);
	
	HUD(const HUD& HUD) = delete;
	HUD& operator=(const HUD& rhs) = delete;
	HUD(HUD&& HUD) = delete;
	HUD& operator=(HUD&& rhs) = delete;

	void Update(float elapsedSec, int avatarHealth, int amountOfAvatarHearts, int pitMonsterHealth, bool gameOver, bool gameHasStarted, bool pitMonsterHasBeenSummoned);
	void Draw( ) const;
	void LostHeart( );
	void LostHealth( );

private:
	const int m_TotalAvatarHearts;
	int m_AmountOfAvatarHearts;
	const float m_TotalAvatarHealth;
	int m_AvatarHealth;
	const float m_TotalPitMonsterHealth;
	int m_PitMonsterHealth;
	const Texture* m_pHealthBarAvatar;
	const Texture* m_pNumberZero;
	const Texture* m_pNumberOne;
	const Texture* m_pNumberTwo;
	const Texture* m_pNumberThree;
	const Texture* m_pStartScreen;
	const Texture* m_pGameOverScreen;
	const Texture* m_pHealthBarPitMonster;
	const Texture* m_pPitMonsterNameGrey;
	const Point2f m_TopRight;
	bool m_GameOver;
	bool m_GameHasStarted;
	bool m_AvatarIsInPitMonsterRange;
	TextureManager& m_TextureManager;
	float m_AccuSec;

	void DrawAmountOfLives( ) const;
	void DrawAmountOfHealth( ) const;
	void DrawAmountOfHealthPitMonster( ) const;
};

