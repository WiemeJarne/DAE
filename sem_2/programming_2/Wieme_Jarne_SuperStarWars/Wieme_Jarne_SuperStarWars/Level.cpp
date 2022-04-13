#include "pch.h"
#include "Level.h"
#include "Texture.h"
#include "Platform.h"
#include "SVGParser.h"
#include "utils.h"

Level::Level( )
	:m_LevelTexture{ new Texture{"Resources/Level/Level.png" } }
	,m_PitTexture{ new Texture{"Resources/Level/Pit.png"} }
	,m_BossPitTexture{ new Texture{"Resources/Level/PitMonsterPit.png"} }
	,m_BackgroundTexture{ new Texture{"Resources/Level/Background.png"} }
	,m_Vertices{ }
	,m_Boundaries{ }
{
	SVGParser::GetVerticesFromSvgFile("Resources/Level/Level.svg", m_Vertices);
	
	m_Boundaries.width = m_LevelTexture->GetWidth();
	m_Boundaries.height = 500.f;

	InitializePlatforms( );
}

Level::~Level( )
{
	delete m_LevelTexture;
	delete m_PitTexture;
	delete m_BossPitTexture;
	delete m_BackgroundTexture;

	for (Platform* platform : m_Platforms)
	{
		delete platform;
	}
}

void Level::DrawLevel( ) const
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

void Level::DrawBackground(const Point2f& translation) const
{
	glPushMatrix();
	glTranslatef(translation.x, translation.y, 0);
	m_BackgroundTexture->Draw();
	glPopMatrix();
}

void Level::HandleCollision(Rectf& actorShape, Vector2f& actorVelocity) const
{
	for (Platform* platform : m_Platforms)
	{
		platform->HandleCollision(actorShape, actorVelocity);
	}

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
	for (Platform* platform : m_Platforms)
	{
		if (platform->IsOnGround(actorShape, actorVelocity))
		{
			return true;
		}
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

Rectf Level::GetBoundaries( ) const
{
	return m_Boundaries;
}

void Level::InitializePlatforms( )
{
	const float bigRockWidth{ 70.f };
	const float normalRockWidth{ 41.f };
	const float smallRockWidth{ 14.f };

	m_Platforms.push_back(new Platform{ Point2f{83.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{210.f, 90.f}, normalRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{283.f, 84.f}, smallRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{1105.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{1295.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{1438.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{2383.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{2584.f, 84.f}, smallRockWidth + bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{2895.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{3020.f, 84.f}, normalRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{3095.f, 84.f}, smallRockWidth + bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{3606.f, 84.f}, smallRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{3692.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{4888.f, 84.f}, smallRockWidth + bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{5200.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{5327.f, 84.f}, normalRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{5390.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{5534.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{6474.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{6602.f, 84.f}, normalRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{6676.f, 84.f}, smallRockWidth + bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{7498.f, 84.f}, bigRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{7626.f, 84.f}, normalRockWidth });
	m_Platforms.push_back(new Platform{ Point2f{7699.f, 84.f}, smallRockWidth });
}