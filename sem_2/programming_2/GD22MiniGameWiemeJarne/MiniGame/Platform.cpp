#include "pch.h"
#include "Platform.h"
#include "Texture.h"
#include "utils.h"
#include <iostream>

Platform::Platform(const Point2f& bottomLeftPoint)
	:m_Shape{bottomLeftPoint.x, bottomLeftPoint.y, 0, 0}
	,m_pTexture{ new Texture{"Resources/Images/platform.png"} }
{
	m_Shape.width = m_pTexture->GetWidth();
	m_Shape.height = m_pTexture->GetHeight();
}

Platform::~Platform()
{
	delete m_pTexture;
}

void Platform::Draw() const
{
	glPushMatrix();
		glTranslatef(m_Shape.left, m_Shape.bottom, 0);
		m_pTexture->Draw();
	glPopMatrix();
}

void Platform::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const
{
	if (actorVelocity.y <= 0)
	{
		std::cout << IsOnGround(actorShape, actorVelocity) << '\n';
		if (IsOnGround(actorShape, actorVelocity))
		{
			actorVelocity.y = 0.f;
			actorShape.bottom = m_Shape.bottom + m_Shape.height;
		}
	}
}

bool Platform::IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity) const
{
	if ( actorVelocity.y <= 0
		 && actorShape.left >= m_Shape.left
		 && actorShape.left + actorShape.width <= m_Shape.left + m_Shape.width
		 && actorShape.bottom < m_Shape.bottom + m_Shape.height
		 && actorShape.bottom > m_Shape.bottom + m_Shape.height - 0.05f        )
	{
		return true;
	}
	return false;
}