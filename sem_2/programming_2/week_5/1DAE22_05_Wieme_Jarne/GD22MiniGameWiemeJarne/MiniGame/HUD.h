#pragma once

class Texture;

class HUD final
{
public:
	HUD(const Point2f& topLeft, int totalPowerUps);
	~HUD();

	void Draw() const;
	void PowerUpHit();

private:
	Point2f m_BottomLeft;
	int m_TotalPowerUps;
	int m_HitPowerUps;
	const Texture* m_pLeftTexture;
	const Texture* m_pRightTexture;
	const Texture* m_pPowerUpTexture;
};