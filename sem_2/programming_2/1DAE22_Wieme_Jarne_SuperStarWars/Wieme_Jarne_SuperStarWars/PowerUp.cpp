#include "pch.h"
#include "PowerUp.h"
#include "Texture.h"
#include "Level.h"
#include "utils.h"

PowerUp::PowerUp(const Point2f& bottomLeftPos, Type powerUpType)
	: m_Shape{ bottomLeftPos.x, bottomLeftPos.y, 0.f, 0.f }
	, m_pTexture{ }
	, m_Type{ powerUpType }
	, m_Velocity{ }
	, m_Acceleration{ }
{
	if (m_Type == Type::heart)
	{
		m_Acceleration.y = -981.f;
		m_Velocity.y = 400.f;
		m_pTexture = new Texture{ "Resources/SmallHeart.png" };
	}
	else
	{
		m_pTexture = new Texture{ "Resources/BlasterPowerup.png" };
	}

	m_Shape.width = m_pTexture->GetWidth( ); 
	m_Shape.height = m_pTexture->GetHeight( );
}

PowerUp::~PowerUp( )
{
	delete m_pTexture;
}

void PowerUp::Update(float elapsedSec, const Level& level)
{
	m_Shape.bottom += elapsedSec * m_Velocity.y;
	m_Velocity.y += elapsedSec * m_Acceleration.y;

	level.HandleCollision(m_Shape, m_Velocity);
}

void PowerUp::Draw( ) const
{
	glPushMatrix();
		glTranslatef(m_Shape.left, m_Shape.bottom, 0);
		m_pTexture->Draw( );
	glPopMatrix();
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	return utils::IsOverlapping(rect, m_Shape);
}

PowerUp::Type PowerUp::GetPowerUpType() const
{
	return m_Type;
}