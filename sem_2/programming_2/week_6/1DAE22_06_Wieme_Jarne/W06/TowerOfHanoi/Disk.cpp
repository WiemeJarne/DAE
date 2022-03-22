#include "pch.h"
#include "Disk.h"
#include "utils.h"

Disk::Disk(const Rectf& shape, const Color4f& color)
	:m_Shape{shape}
	,m_Color{color}
{
	//no code
}

void Disk::Draw(const Point2f& bottomleftPos) const
{
	Rectf dstDiskRect{};
	dstDiskRect.left = bottomleftPos.x;
	dstDiskRect.bottom = bottomleftPos.y;
	dstDiskRect.width = m_Shape.width;
	dstDiskRect.height = m_Shape.height;

	utils::SetColor(m_Color);

	utils::FillRect(dstDiskRect);
}

void Disk::Move(const Point2f& mousePos)
{
	m_Shape.left = mousePos.x - m_Shape.width / 2.f;
	m_Shape.bottom = mousePos.y - m_Shape.height / 2.f;
}

Rectf Disk::GetShape() const
{
	return m_Shape;
}