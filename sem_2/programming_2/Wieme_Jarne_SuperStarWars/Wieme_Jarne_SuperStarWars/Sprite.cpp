#include "pch.h"
#include "Sprite.h"
#include "Texture.h"
#include <iostream>

Sprite::Sprite( const std::string& path, int cols, int rows, float frameSec, bool loop )
	: m_TexturePath{ path }
	, m_Cols{ cols }
	, m_Rows{ rows }
	, m_FrameSec{ frameSec }
	, m_AccuSec{}
	, m_ActFrame{}
	, m_Loop{ loop }
{
	m_pTexture = new Texture( m_TexturePath );
}

Sprite::~Sprite( )
{
	delete m_pTexture;
}

void Sprite::Update( float elapsedSec )
{
	m_AccuSec += elapsedSec;

	if (m_Loop)
	{
		if (m_AccuSec > 1.f / m_FrameSec)
		{
			++m_ActFrame;

			if (m_ActFrame >= m_Cols * m_Rows)
			{
				m_ActFrame = 0;
			}

			m_AccuSec -= 1.f / m_FrameSec;
		}
	}
	
}

void Sprite::Draw( const Point2f& pos, float scale ) const
{
	// frame dimensions
	const float frameWidth{  m_pTexture->GetWidth() / m_Cols };
	const float frameHeight{  m_pTexture->GetHeight() / m_Rows };
	int row = m_ActFrame / m_Cols;
	int col = m_ActFrame % m_Cols;

	Rectf srcRect;
	srcRect.height = frameHeight;
	srcRect.width = frameWidth;
	srcRect.left = m_ActFrame % m_Cols * srcRect.width;
	srcRect.bottom = m_ActFrame / m_Cols * srcRect.height + srcRect.height;

	m_pTexture->Draw( Rectf{}, srcRect );
}

float Sprite::GetFrameWidth( ) const
{
	return m_pTexture->GetWidth( ) / m_Cols;
}

float Sprite::GetFrameHeight( ) const
{
	return m_pTexture->GetHeight( ) / m_Rows;
}