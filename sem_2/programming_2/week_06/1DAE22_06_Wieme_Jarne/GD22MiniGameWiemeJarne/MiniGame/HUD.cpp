#include "pch.h"
#include "HUD.h"
#include "Texture.h"

HUD::HUD(const Point2f& topLeft, int totalPowerUps)
:m_TotalPowerUps{totalPowerUps}
,m_HitPowerUps{}
,m_pLeftTexture{ new Texture{ "Resources/Images/HudLeft.png" } }
,m_pRightTexture{ new Texture{ "Resources/Images/HudRight.png" } }
,m_pPowerUpTexture{ new Texture{ "Resources/Images/HudPowerUp.png" } }
{
	m_BottomLeft.x = topLeft.x;
	m_BottomLeft.y = topLeft.y - m_pPowerUpTexture->GetHeight();
}

HUD::~HUD()
{
	delete m_pLeftTexture;
	delete m_pRightTexture;
	delete m_pPowerUpTexture;
}

void HUD::Draw() const
{
	Rectf srcRectPowerUp{};
	srcRectPowerUp.width = m_pPowerUpTexture->GetWidth() / 2.f;
	srcRectPowerUp.height = m_pPowerUpTexture->GetHeight();

	Point2f bottomLeft{ m_BottomLeft };

	m_pLeftTexture->Draw(bottomLeft);

	bottomLeft.x += m_pLeftTexture->GetWidth();

	for (int index{}; index < m_HitPowerUps; ++index)
	{
		srcRectPowerUp.left = 0.f;
		
		m_pPowerUpTexture->Draw(bottomLeft, srcRectPowerUp);

		bottomLeft.x += m_pPowerUpTexture->GetWidth() / 2.f;
	}

	for (int index{}; index < m_TotalPowerUps - m_HitPowerUps; ++index)
	{
		srcRectPowerUp.left = m_pPowerUpTexture->GetWidth() / 2.f;

		m_pPowerUpTexture->Draw(bottomLeft, srcRectPowerUp);

		bottomLeft.x += m_pPowerUpTexture->GetWidth() / 2.f;
	}

	m_pRightTexture->Draw(bottomLeft);
}

void HUD::PowerUpHit()
{
	++m_HitPowerUps;
}