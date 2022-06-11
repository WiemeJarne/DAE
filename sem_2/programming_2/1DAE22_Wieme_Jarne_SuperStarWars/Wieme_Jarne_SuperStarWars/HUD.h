#pragma once
class TextureManager;
class Texture;

class HUD final
{
public:
	explicit HUD(const Point2f& topLeft, int totalAvatarHearts, int totalAvatarHealth, TextureManager& textureManager);
	HUD(const HUD& HUD) = delete;
	HUD(HUD&& HUD) = delete;
	~HUD( );

	HUD& operator=(const HUD& rhs) = delete;
	HUD& operator=(HUD&& rhs) = delete;

	void Update(int avatarHealth, int amountOfHearts);
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
	const Point2f m_BottomLeft;
};

