#include "pch.h"
#include "PowerUp.h"
#include "Texture.h"
#include <iostream>

PowerUp::PowerUp(const Point2f& center, PowerUp::Type type)
	:m_Type{type}
	,m_RotSpeed{360.f}
	,m_Angle{}
	,m_pTexture{ new Texture{"Resources/Images/PowerUp.png"} }
{
	m_Shape.center = center;
	m_Shape.radius = m_pTexture->GetWidth() / 2.f;

	m_TextClip.left = 0.f;
	m_TextClip.width = m_pTexture->GetWidth();
	m_TextClip.height = m_pTexture->GetHeight() / 2.f;

	if (m_Type == Type::brown)
	{
		m_TextClip.bottom = m_pTexture->GetHeight();
	}
	else
	{
		m_TextClip.bottom = m_pTexture->GetHeight() + m_pTexture->GetHeight() / 2.f;
	}
}

PowerUp::~PowerUp()
{
	delete m_pTexture;
}

void PowerUp::Update(float elapsedSec)
{

}

void PowerUp::Draw() const
{
	Rectf destRect{};
	destRect.left = m_Shape.center.x - m_Shape.radius;
	destRect.bottom = m_Shape.center.y - m_Shape.radius;
	destRect.width = m_Shape.radius * 2;
	destRect.height = m_Shape.radius * 2;

	m_pTexture->Draw(destRect, m_TextClip);
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	if (sqrtf( powf(m_Shape.center.x - rect.left,2) + powf(m_Shape.center.y - rect.bottom,2) ) <= m_Shape.radius
		|| sqrtf( powf(m_Shape.center.x - (rect.left + rect.width), 2) + powf(m_Shape.center.y - rect.bottom, 2) ) <= m_Shape.radius
		|| sqrtf( powf(m_Shape.center.x - rect.left, 2) + powf(m_Shape.center.y - (rect.bottom + rect.height), 2) ) <= m_Shape.radius
		|| sqrtf( powf(m_Shape.center.x - (rect.left + rect.width), 2) + powf(m_Shape.center.y - (rect.bottom + rect.height), 2) ) <= m_Shape.radius )
	{
		return true;
	}
	return false;
}