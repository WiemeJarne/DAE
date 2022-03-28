#include "pch.h"
#include "Card.h"
#include "Texture.h"

const int Card::m_MinRank{ 1 };
const int Card::m_MaxRank{ 13 };

Card::Card(Suit suit, int rank, float angle, const Circlef& circle)
	:m_Suit{suit}
	,m_Rank{rank}
	,m_Angle{angle}
	,m_Circle{circle}
	,m_pTexture{ new Texture{ GetImagePath(suit, rank) } }
	,m_RotationalSpeed{10.f}
{
	m_Width = GetWidth();
	m_Height = GetHeight();
}

Card::~Card()
{
	delete m_pTexture;
}

void Card::Update(float elpasedSec)
{
	m_Angle += m_RotationalSpeed * elpasedSec;
}

void Card::Draw() const
{
	glPushMatrix();
		glTranslatef(m_Circle.center.x, m_Circle.center.y, 0);
		glRotatef(m_Angle, 0, 0, 1);
		m_pTexture->Draw(Point2f{m_Circle.radius, -m_Circle.center.y / 2.f});
	glPopMatrix();
}

float Card::GetWidth() const
{
	return m_pTexture->GetWidth();
}

float Card::GetHeight() const
{
	return m_pTexture->GetHeight();
}

std::string Card::GetImagePath(Suit suit, int rank) const
{
	return "Resources/Cards/" + std::to_string(int(suit) * 100 + rank) + ".png";
}
