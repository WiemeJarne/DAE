#include "pch.h"
#include "Camera.h"

Camera::Camera(float width, float height)
	: m_Width{ width }
	, m_Height{ height }
	, m_LevelBoundaries{ }
{
}

void Camera::SetLevelBoundaries(const Rectf& levelBoundaries)
{
	m_LevelBoundaries = levelBoundaries;
}

void Camera::Transform(const Rectf& target, const float scale, Point2f& translation) const
{
	Point2f m_BottomLeftPoint{ Track(target, scale) };

	Clamp(m_BottomLeftPoint, scale);
	
	glScalef(scale, scale, 1.f);
	glTranslatef(-m_BottomLeftPoint.x, -m_BottomLeftPoint.y, 0);
	translation = m_BottomLeftPoint;
}

Point2f Camera::Track(const Rectf& target, const float scaleFactor) const
{
	return Point2f{ target.left + (target.width / 2.f - m_Width / 2.f) / scaleFactor, target.bottom + (target.height / 2.f - m_Height / 2.f) / scaleFactor };
}

void Camera::Clamp(Point2f& bottomLeftPos, const float scaleFactor) const
{
	if (bottomLeftPos.x < m_LevelBoundaries.left)
	{
		bottomLeftPos.x = m_LevelBoundaries.left;
	}
	else if (bottomLeftPos.x + m_Width / scaleFactor > m_LevelBoundaries.left + m_LevelBoundaries.width)
	{
		bottomLeftPos.x = m_LevelBoundaries.left + m_LevelBoundaries.width - m_Width / scaleFactor;
	}

	if (bottomLeftPos.y < m_LevelBoundaries.bottom)
	{
		bottomLeftPos.y = m_LevelBoundaries.bottom;
	}
	else if (bottomLeftPos.y + m_Height > m_LevelBoundaries.bottom + m_LevelBoundaries.height)
	{
		bottomLeftPos.y = m_LevelBoundaries.bottom + m_LevelBoundaries.height - m_Height;
	}
}