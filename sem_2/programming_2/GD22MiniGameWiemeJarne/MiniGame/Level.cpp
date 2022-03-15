#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "SVGParser.h"
#include "Platform.h"
#include <iostream>

Level::Level()
	:m_pBackgroundTexture{ new Texture{"Resources/Images/background.png" } }
	,m_pFenceTexture{ new Texture{ "Resources/Images/Fence.png" } }
	,m_FenceBottomLeft{200.f, 190.f}
	,m_Vertices{}
	,m_Boundaries{}
	, m_pPlatform{ new Platform{Point2f{300, 300}} }
{
	SVGParser::GetVerticesFromSvgFile("Resources/Images/level.svg", m_Vertices);
	
	m_Boundaries.width = m_pBackgroundTexture->GetWidth();
	m_Boundaries.height = m_pBackgroundTexture->GetHeight();
}

Level::~Level()
{
	delete m_pBackgroundTexture;
	delete m_pFenceTexture;
	delete m_pPlatform;
}

void Level::DrawBackground() const
{
	m_pBackgroundTexture->Draw();
	m_pPlatform->Draw();
}

void Level::DrawForeground() const
{
	m_pFenceTexture->Draw(m_FenceBottomLeft);
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const
{
	m_pPlatform->HandleCollision(actorShape, actorVelocity);

	Point2f rayStartPoint{ actorShape.left + actorShape.width / 2.f,
						   actorShape.bottom + actorShape.height	};
	Point2f rayEndPoint{ actorShape.left + actorShape.width / 2.f,
						 actorShape.bottom							};

	utils::HitInfo hitInfo{};

	if (utils::Raycast(m_Vertices.back(), rayStartPoint, rayEndPoint, hitInfo))
	{
		actorShape.bottom = hitInfo.intersectPoint.y;
		actorVelocity.y = 0.f;
	}
}

bool Level::IsOnGround(const Rectf& actorShape, const Vector2f& actorVelocity) const
{
	if (m_pPlatform->IsOnGround(actorShape, actorVelocity))
	{
		return true;
	}

	Point2f rayStartPoint{ actorShape.left + actorShape.width / 2.f,
						   actorShape.bottom + actorShape.height	 };
	Point2f rayEndPoint{ actorShape.left + actorShape.width / 2.f,
						 actorShape.bottom - 1.f				   };

	utils::HitInfo hitInfo{};

	if (utils::Raycast(m_Vertices.back(), rayStartPoint, rayEndPoint, hitInfo))
	{
		return true;
	}

	return false;
}

Rectf Level::GetBoundaries() const
{
	return m_Boundaries;
}