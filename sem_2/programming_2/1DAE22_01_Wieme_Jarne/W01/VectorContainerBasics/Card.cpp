#include "pch.h"
#include "Card.h"
#include "Texture.h"

Card::Card(Suit suit, int rank)
	:m_Suit{ suit }
	,m_Rank{ rank }
	,m_Scale{ 0.5f }
	,m_MinRank{ 1 }
	,m_MaxRank{ 13 }
{
	m_pTexture = new Texture{ GetImagePath(m_Suit, m_Rank) };
	m_Width = m_pTexture->GetWidth();
	m_Height = m_pTexture->GetHeight();
}

Card::~Card()
{
	delete m_pTexture;
}

void Card::Draw( const Rectf& destRect ) const
{
	m_pTexture->Draw(destRect);
}

float Card::GetWidth() const
{
	return m_Width;
}

float Card::GetHeight() const
{
	return m_Height;
}

std::string Card::GetImagePath(Suit suit, int rank) const
{
	return "Resources/" + std::to_string( int(suit) * 100 + rank ) + ".png";
}