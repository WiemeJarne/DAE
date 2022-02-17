#include "pch.h"
#include "Level.h"
#include "Texture.h"

Level::Level()
	:m_pBackgroundTexture{ new Texture{"Resources/Images/background.png"} }
	,m_pFenceTexture{new Texture{"Resources/Images/fence.png"}}
	,m_FenceBottomLeft{200, 190}
	,m_Vertices{ Point2f{0, 0}, 
				 Point2f{0, 190},
				 Point2f{340, 190},
				 Point2f{408, 124},
				 Point2f{560, 124},
				 Point2f{660, 224},
				 Point2f{846, 224},
				 Point2f{846, 0},
				 Point2f{0, 0}	   }
{

}

void Level::DrawBackground() const
{
	m_pBackgroundTexture->Draw();
}

void Level::DrawForeground() const
{
	m_pFenceTexture->Draw(m_FenceBottomLeft);
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity)
{
	Point2f actorBottomMiddlePoint{ actorShape.left + actorShape.width / 2.f, actorShape.bottom };
	size_t vectorSize{ m_Vertices.size() };

	for (int index{}; index < vectorSize - 1; ++index)
	{
		const float rico{ (m_Vertices[index + 1].y - m_Vertices[index].y) / (m_Vertices[index + 1].x - m_Vertices[index].x) };
		const float intercept{ m_Vertices[index].y - rico * m_Vertices[index].x };

		if (	actorShape.left >= m_Vertices[index].x
			 && actorShape.left <= m_Vertices[index + 1].x
			 && ( 	actorShape.bottom < m_Vertices[index].y
				  || actorShape.bottom < m_Vertices[index + 1].y ) )
		{
			actorVelocity.y = 0.f;
			actorShape.bottom = rico * actorBottomMiddlePoint.x + intercept;
		}
	}
}

bool Level::IsOnGround(const Rectf& actorShape)
{
	Point2f actorBottomMiddlePoint{ actorShape.left + actorShape.width / 2.f, actorShape.bottom };
	size_t vectorSize{ m_Vertices.size() };

	for (int index{}; index < vectorSize - 1; ++index)
	{
		const float rico{ (m_Vertices[index + 1].y - m_Vertices[index].y) / (m_Vertices[index + 1].x - m_Vertices[index].x) };
		const float intercept{ m_Vertices[index].y - rico * m_Vertices[index].x };

		if (	actorShape.left >= m_Vertices[index].x
			 && actorShape.left <= m_Vertices[index + 1].x
			 && actorShape.bottom == rico * actorBottomMiddlePoint.x + intercept )
		{
			return true;
		}
	}
	return false;
}