#include "pch.h"
#include "Light.h"

Light::Light(const Rectf& rect, const Color4f color)
	:m_Rect{ rect }
	,m_IsOn{true}
	,m_Color{color}
{
	//no code
}

void Light::Draw()
{
	IsOn() == true ? utils::SetColor(m_Color)
			       : utils::SetColor(115.f / 255, 115.f / 255, 115.f / 255);

	utils::FillRect(m_Rect);

	utils::SetColor(1.f, 1.f, 1.f);
	utils::DrawRect(m_Rect);
}

bool Light::IsHit(const Point2f& pos)
{
	if (	pos.x >= m_Rect.left
		 && pos.x <= m_Rect.left + m_Rect.width
		 && pos.y >= m_Rect.bottom
		 && pos.y <= m_Rect.bottom + m_Rect.height )
	{
		m_IsOn = !m_IsOn;
	}
	return m_IsOn;
}

bool Light::IsOn()
{
	if (m_IsOn) return true;
	else return false;
}