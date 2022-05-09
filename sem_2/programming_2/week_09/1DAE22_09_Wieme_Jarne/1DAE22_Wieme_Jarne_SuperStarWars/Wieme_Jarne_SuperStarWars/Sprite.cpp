#include "pch.h"
#include "Sprite.h"
#include "Texture.h"

Sprite::Sprite( const std::string& path, AnimType animType, int cols, int rows, float frameSec )
	: m_TexturePath{ path }
	, m_AnimType{ animType }
	, m_Columns{ cols }
	, m_Rows{ rows }
	, m_FramesPerSec{ frameSec }
	, m_AccuSec{ }
	, m_FrameNr{ }
	, m_FrameDirection{ -1 }
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

	switch (m_AnimType)
	{
	case AnimType::loop:

		if (m_AccuSec >= 1.f / m_FramesPerSec)
		{
			m_AccuSec -= 1.f / m_FramesPerSec;

			m_FrameNr = (m_FrameNr + 1) % (m_Rows * m_Columns);
		}

		break;

	case AnimType::repeatBackwards:

		if (m_AccuSec >= 1.f / m_FramesPerSec)
		{
			m_AccuSec -= 1.f / m_FramesPerSec;

			if (m_FrameNr == (m_Rows * m_Columns) - 1 || m_FrameNr == 0)
			{
				m_FrameDirection *= -1;
			}

			m_FrameNr += m_FrameDirection;
			
		}

		break;

	case AnimType::dontRepeat:

		if (m_FrameNr < m_Rows * m_Columns - 1 && m_AccuSec >= 1.f / m_FramesPerSec)
		{
			m_AccuSec -= 1.f / m_FramesPerSec;
			++m_FrameNr;
		}

		break;
	}
}

void Sprite::Draw( ) const
{
	int rowNr = m_FrameNr / m_Columns;
	int columnNr = m_FrameNr % m_Columns;
	
	Rectf srcRect;
	srcRect.width = GetFrameWidth( );
	srcRect.height = GetFrameHeight( );
	srcRect.left = columnNr * srcRect.width;
	srcRect.bottom = rowNr * srcRect.height;

	m_pTexture->Draw( Rectf{}, srcRect );
}

float Sprite::GetFrameWidth( ) const
{
	return m_pTexture->GetWidth( ) / m_Columns;
}

float Sprite::GetFrameHeight( ) const
{
	return m_pTexture->GetHeight( ) / m_Rows;
}

int Sprite::GetAmountOfFrames( ) const
{
	return m_Rows * m_Columns;
}

void Sprite::SetFrameNr(const int frameNr)
{
	m_FrameNr = frameNr;
}

void Sprite::SetAccuSec(const float accuSec)
{
	m_AccuSec = accuSec;
}

int Sprite::GetFrameNr( )
{
	return m_FrameNr;
}