#include "pch.h"
#include "HUD.h"
#include "TextureManager.h"
#include "Texture.h"
#include "utils.h"

HUD::HUD(const Point2f& windowTopRight, int totalAvatarHearts, int totalAvatarHealth, int totalPitMonsterHealth, TextureManager& textureManager)
	: m_TotalAvatarHearts{ totalAvatarHearts }
	, m_AmountOfAvatarHearts{ totalAvatarHearts }
	, m_TotalAvatarHealth{ float(totalAvatarHealth) }
	, m_AvatarHealth{ totalAvatarHealth }
	, m_TotalPitMonsterHealth{ float(totalPitMonsterHealth) }
	, m_PitMonsterHealth{ totalPitMonsterHealth }
	, m_TopRight{ windowTopRight.x, windowTopRight.y }
	, m_pHealthBarAvatar{ textureManager.GetTexture("Resources/HUD/HealthBar.png") }
	, m_pNumberZero{ textureManager.GetTexture("Resources/HUD/Numbers/0.png") }
	, m_pNumberOne{ textureManager.GetTexture("Resources/HUD/Numbers/1.png") }
	, m_pNumberTwo{ textureManager.GetTexture("Resources/HUD/Numbers/2.png") }
	, m_pNumberThree{ textureManager.GetTexture("Resources/HUD/Numbers/3.png") }
	, m_pStartScreen{ textureManager.GetTexture("Resources/HUD/StartScreen.png") }
	, m_pHealthBarPitMonster{ }
	, m_pPitMonsterNameGrey{ }
	, m_pGameOverScreen{ }
	, m_GameOver{ }
	, m_GameHasStarted{ }
	, m_AvatarIsInPitMonsterRange{ }
	, m_TextureManager{ textureManager }
	, m_AccuSec{ }
{
}

void HUD::Update(float elapsedSec, int avatarHealth, int amountOfAvatarHearts, int pitMonsterHealth, bool gameOver, bool gameHasStarted, bool avatarIsInPitMonsterRange)
{
	m_AvatarHealth = avatarHealth;
	m_AmountOfAvatarHearts = amountOfAvatarHearts;
	m_PitMonsterHealth = pitMonsterHealth;

	m_GameOver = gameOver;
	m_GameHasStarted = gameHasStarted;
	m_AvatarIsInPitMonsterRange = avatarIsInPitMonsterRange;


	if (!m_GameOver && m_GameHasStarted && m_pStartScreen != nullptr)
	{
		m_TextureManager.DeleteTexture("Resources/HUD/StartScreen.png");
		m_pStartScreen = nullptr;
	}

	if (m_GameOver && m_pGameOverScreen == nullptr)
	{
		m_pGameOverScreen = m_TextureManager.GetTexture("Resources/HUD/GameOverScreen.png");
	}

	if (!m_GameOver && m_pGameOverScreen != nullptr)
	{
		m_TextureManager.DeleteTexture("Resources/HUD/GameOverScreen.png");
		m_pGameOverScreen = nullptr;
	}

	if (m_AvatarIsInPitMonsterRange)
	{
		m_AccuSec += elapsedSec;

		if (m_AccuSec >= 0.5f)
		{
			m_AccuSec = 0.f;
		}

		if (m_pHealthBarPitMonster == nullptr)
		{
			m_pHealthBarPitMonster = m_TextureManager.GetTexture("Resources/HUD/PitMonsterHealthBar.png");
			m_pPitMonsterNameGrey = m_TextureManager.GetTexture("Resources/HUD/PitMonsterNameGrey.png");
		}
	}
}

void HUD::Draw( ) const
{
	glPushMatrix( );
	if (m_GameHasStarted && !m_GameOver)
	{
		glTranslatef(0.f, m_TopRight.y - m_pHealthBarAvatar->GetHeight( ), 0.f);

		m_pHealthBarAvatar->Draw( );
		DrawAmountOfLives( );
		DrawAmountOfHealth( );

		glTranslatef(0.f, -m_TopRight.y + m_pHealthBarAvatar->GetHeight( ), 0.f);

		if (m_AvatarIsInPitMonsterRange)
		{
			glScalef(2.f, 2.f, 0.f);
			DrawAmountOfHealthPitMonster( );
			m_pHealthBarPitMonster->Draw( );

			if (m_AccuSec >= 0.25f)
			{
				glTranslatef(0.f, 7.f, 0.f);
				m_pPitMonsterNameGrey->Draw( );
			}
		}
	}
	else if (!m_GameHasStarted && !m_GameOver)
	{
		glScalef(0.35f, 0.47f, 1.f);
		m_pStartScreen->Draw( );
	}
	else if (m_GameOver)
	{
		glScalef(0.35f, 0.6f, 1.f);
		m_pGameOverScreen->Draw( );
	}
	glPopMatrix( );
}

void HUD::LostHeart( )
{
	--m_AmountOfAvatarHearts;
}

void HUD::LostHealth( )
{
	--m_AvatarHealth;
}

void HUD::DrawAmountOfLives( ) const
{
	glTranslatef(70.f, 18.f, 0.f);
	switch (m_AmountOfAvatarHearts)
	{
	case 0:
		m_pNumberZero->Draw();
		break;

	case 1:
		m_pNumberOne->Draw();
		break;

	case 2:
		m_pNumberTwo->Draw();
		break;

	case 3:
		m_pNumberThree->Draw();
		break;
	}
	glTranslatef(-70.f, -18.f, 0.f);
}

void HUD::DrawAmountOfHealth( ) const
{
	Rectf healthRect{};
	healthRect.width = m_AvatarHealth / m_TotalAvatarHealth * 124.f;
	healthRect.height = 2.f;

	utils::SetColor(Color4f{ 80 / 255.f, 148 / 255.f, 149 / 255.f, 1.f });

	glTranslatef(33.f, 4.f, 0.f);
	utils::FillRect(healthRect);

	glTranslatef(0.f, 6.f, 0.f);
	utils::FillRect(healthRect);

	healthRect.width = m_AvatarHealth / m_TotalAvatarHealth * 126.f;
	healthRect.height = 4.f;

	utils::SetColor(Color4f{ 173 / 255.f, 222 / 255.f, 1.f, 1.f });

	glTranslatef(0.f, -4.f, 0.f);
	utils::FillRect(healthRect);

	glTranslatef(-33.f, -6.f, 0.f);
}

void HUD::DrawAmountOfHealthPitMonster() const
{
	Rectf healthRect{};
	healthRect.width = m_PitMonsterHealth / m_TotalPitMonsterHealth * 142.f;
	healthRect.height = 1.f;

	utils::SetColor(Color4f{ 248 / 255.f, 152 / 255.f, 40 / 255.f, 1.f });

	glTranslatef(0.f, 1.f, 0.f);
	utils::FillRect(healthRect);

	glTranslatef(0.f, 3.f, 0.f);
	utils::FillRect(healthRect);

	healthRect.width = m_PitMonsterHealth / m_TotalPitMonsterHealth * 143.f;
	healthRect.height = 2.f;

	utils::SetColor(Color4f{ 248 / 255.f, 224 / 255.f, 160 / 255.f, 1.f });

	glTranslatef(0.f, -2.f, 0.f);
	utils::FillRect(healthRect);

	glTranslatef(0.f, -2.f, 0.f);
}