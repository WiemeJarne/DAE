#include "pch.h"
#include "PowerUp.h"
#include "Texture.h"
#include "utils.h"

PowerUp::PowerUp(const Point2f& bottomLeftPos)
	: m_Shape{ bottomLeftPos.x, bottomLeftPos.y, 0.f, 0.f }
	, m_pTexture{ new Texture{ "Resources/BlasterPowerup.png" } }
{
	m_Shape.width = m_pTexture->GetWidth( ); 
	m_Shape.height = m_pTexture->GetHeight( );
}

PowerUp::~PowerUp( )
{
	delete m_pTexture;
}

void PowerUp::Draw( ) const
{
	glPushMatrix();
		glTranslatef(m_Shape.left, m_Shape.bottom, 0);
		if (m_pTexture)
		{
			m_pTexture->Draw( );
		}
	glPopMatrix();
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	return utils::IsOverlapping(rect, m_Shape);
}