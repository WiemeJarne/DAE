#include "pch.h"
#include "Disk.h"
#include "utils.h"

Disk::Disk(const float width, const float height, const Color4f& color)
	:m_Shape{0.f, 0.f, width, height}
	,m_Color{color}
	,m_IsSelected{}
{
	//no code
}

void Disk::Draw( ) const
{
	float lineWidth{ 1.f };

	if (m_IsSelected)
	{
		lineWidth = 2.f;
	}

	utils::SetColor(m_Color);
	utils::FillRect(m_Shape);

	utils::SetColor(Color4f{ 0.f, 0.f, 0.f, 1.f });
	utils::DrawRect(m_Shape, lineWidth);
}

void Disk::Move(const Point2f& mousePos)
{
	m_Shape.left = mousePos.x - m_Shape.width / 2.f;
	m_Shape.bottom = mousePos.y - m_Shape.height / 2.f;
}

void Disk::SetPosition(const Point2f& position)
{
	m_Shape.left = position.x;
	m_Shape.bottom = position.y;
}

Rectf Disk::GetShape() const
{
	return m_Shape;
}

bool Disk::IsMousePosInDisk(const Point2f& mousePos)
{
	if (utils::IsPointInRect(mousePos, m_Shape))
	{
		return true;
	}

	return false;
}

void Disk::SetIsSelected(bool isSelected)
{
	m_IsSelected = isSelected;
}

bool Disk::GetIsSelected() const
{
	return m_IsSelected;
}