#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "SVGParser.h"

Level::Level()
	:m_LevelTexture{ new Texture{"Resources/Level/Level.png" } }
	,m_PitTexture{ new Texture{"Resources/Level/Pit.png"} }
	,m_BossPitTexture{ new Texture{"Resources/Level/PitMonsterPit.png"} }
	,m_Vertices{}
	,m_Boundaries{}
{
	SVGParser::GetVerticesFromSvgFile("Resources/Level/Level.svg", m_Vertices);
	
	m_Boundaries.width = m_LevelTexture->GetWidth();
	m_Boundaries.height = 500.f;
}

Level::~Level()
{
	delete m_LevelTexture;
	delete m_PitTexture;
	delete m_BossPitTexture;
}

void Level::DrawBackground() const
{
	m_LevelTexture->Draw();
}

void Level::DrawPitTexture(Point2f bottomLeftPoint) const
{
	glPushMatrix();
		glTranslatef(bottomLeftPoint.x, bottomLeftPoint.y, 0);
		m_PitTexture->Draw();
	glPopMatrix();
}

void Level::DrawPitMonsterPitTexture(Point2f bottomLeftPoint) const
{
	glPushMatrix();
	glTranslatef(bottomLeftPoint.x, bottomLeftPoint.y, 0);
	m_BossPitTexture->Draw();
	glPopMatrix();
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const
{
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

bool Level::IsOnGround(const Rectf& actorShape) const
{
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