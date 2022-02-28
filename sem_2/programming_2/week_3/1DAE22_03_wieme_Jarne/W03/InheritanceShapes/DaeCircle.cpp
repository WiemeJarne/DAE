#include "pch.h"		
#include "DaeCircle.h"
#include "utils.h"

DaeCircle::DaeCircle( const Point2f &center, float diameter, const Color4f &color, bool isFilled )
:DaeEllipse(center, diameter, diameter, color, isFilled)
,m_Diameter{diameter}
{
	//no code
}

void DaeCircle::Draw() const
{
	utils::SetColor( m_Color );
	if ( m_IsFilled )
	{
		utils::FillEllipse( m_Center, m_Diameter / 2, m_Diameter / 2 );
	}
	else
	{
		utils::DrawEllipse( m_Center, m_Diameter / 2, m_Diameter / 2 );
	}
}