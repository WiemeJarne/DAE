#include "pch.h"
#include "Level.h"
#include "Texture.h"

Level::Level()
	:m_pBackgroundTexture{ new Texture{"Resources/Images/background.png" } }
	,m_pFenceTexture{ new Texture{ "Resources/Images/Fence.png" } }
	,m_FenceBottomLeft{200.f, 190.f}
	,m_Vertices{Point2f{0.f, 0.f}, Point2f{0.f, 190.f}, Point2f{340.f, 190.f},
				Point2f{408.f, 124.f}, Point2f{560.f, 124.f}, Point2f{660.f, 224.f},
				Point2f{846.f, 224.f}, Point2f{864.f, 0}, Point2f{0, 0}				}
{
	//no code
}

Level::~Level()
{
	delete m_pBackgroundTexture;
	delete m_pFenceTexture;
}

void Level::DrawBackground() const
{
	m_pBackgroundTexture->Draw();
}

void Level::DrawForeground() const
{
	m_pFenceTexture->Draw(m_FenceBottomLeft);
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const
{
	Point2f rayStartPoint{ actorShape.left + actorShape.width / 2.f,
						   actorShape.bottom + actorShape.height	};
	Point2f rayEndPoint{ actorShape.left + actorShape.width / 2.f,
						 actorShape.bottom							};

	utils::HitInfo hitInfo{};

	if (utils::Raycast(m_Vertices, rayStartPoint, rayEndPoint, hitInfo))
	{
		actorShape.bottom = hitInfo.intersectPoint.y;
		actorVelocity.y = 0.f;
	}
}

bool Level::IsOnGround(const Rectf& actorShape) const
{
	Point2f rayStartPoint{ actorShape.left + actorShape.width / 2.f,
						   actorShape.bottom + actorShape.height	 };
	Point2f rayEndPoint{ actorShape.left + actorShape.width / 2.f,
						 actorShape.bottom - 1.f				   };

	utils::HitInfo hitInfo{};

	if (utils::Raycast(m_Vertices, rayStartPoint, rayEndPoint, hitInfo))
	{
		return true;
	}

	return false;
}