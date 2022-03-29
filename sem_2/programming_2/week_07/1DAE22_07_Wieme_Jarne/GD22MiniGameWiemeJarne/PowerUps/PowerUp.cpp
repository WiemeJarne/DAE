#include "pch.h"
#include "PowerUp.h"
#include "Texture.h"
#include "utils.h"

PowerUp::PowerUp(const Point2f& center, PowerUp::Type type)
	:m_Type{ type }
	,m_pTexture{ new Texture{"Resources/Images/PowerUp.png"} }
	,m_RotSpeed{ 360.f }
	,m_Angle{}
{
	m_TextClip.left = 0.f;
	m_TextClip.bottom = m_pTexture->GetHeight();
	m_TextClip.width = m_pTexture->GetWidth();
	m_TextClip.height = m_pTexture->GetHeight() / 2;

	if (type == Type::green) 
		m_TextClip.bottom += m_pTexture->GetHeight() / 2;

	m_Shape.center = center;
	m_Shape.radius = m_pTexture->GetWidth() / 2;
}

PowerUp::~PowerUp()
{
	delete m_pTexture;
}

void PowerUp::Update(float elapsedSec)
{
	m_Angle += elapsedSec * m_RotSpeed;
}

void PowerUp::Draw() const
{
	glPushMatrix();
		glTranslatef(m_Shape.center.x, m_Shape.center.y, 0);
		glRotatef(m_Angle, 0, 0, 1);
		m_pTexture->Draw(Point2f{ -m_Shape.radius, -m_Shape.radius }, m_TextClip);
	glPopMatrix();
}

bool PowerUp::IsOverlapping(const Rectf& rect) const
{
	return utils::IsOverlapping(rect, m_Shape);
}