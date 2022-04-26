#include "pch.h"
#include "DaeShape.h"
#include <iostream>
#include <iomanip>

DaeShape::DaeShape(const Point2f& center, float width, float height, const Color4f& color)
	:m_Center{center}
	,m_Width{width}
	,m_Height{height}
	,m_Color{color}
{
	//no code
}

DaeShape::~DaeShape( )
{

}

void DaeShape::Draw( ) const
{

}

void DaeShape::Translate(const Vector2f& tr)
{
	m_Center += tr;
}

std::string DaeShape::ToString() const
{
	return std::string{};
}

std::string DaeShape::PropertiesToString( ) const
{
	return std::string{ R"(  Center=")" + std::to_string(m_Center.x) + "," + std::to_string(m_Center.y) + R"(")" + '\n' +
						R"(  Width=")" + std::to_string(m_Width) + R"(")" + '\n' +
						R"(  Height=")" + std::to_string(m_Height) + R"(")" + '\n' +
						R"(  Color=")" + std::to_string(m_Color.r) + ',' + std::to_string(m_Color.g) + ',' + std::to_string(m_Color.b) + ',' + std::to_string(m_Color.a) + R"(")" + '\n'};
}