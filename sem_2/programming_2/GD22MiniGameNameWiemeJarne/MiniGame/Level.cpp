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
				 Point2f{660, 124},
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
	m_pFenceTexture->Draw();
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity)
{
	for (Point2f index : m_Vertices)
	{
		if (actorShape.bottom <= index.y) actorShape.bottom = index.y;
		actorVelocity.y = 0;
	}
}

bool Level::IsOnGround(const Rectf& actorShape)
{
	for (Point2f index : m_Vertices)
	{
		if (actorShape.bottom - 1 == index.y) return true;
	}
	return false;
}