#include "pch.h"
#include "Diamond.h"
#include "Texture.h"
#include "Matrix2x3.h"
#include "utils.h"

Diamond::Diamond(const Point2f& position)
	:m_StartPos{position}
	,m_Position{position}
	,m_Scale{1.f}
	,m_Angle{0.f}
	,m_IsSelected{}
	,m_Vertices{}
	,m_DiamondTexture{ new Texture{"Resources/Diamond.png"} }
{
	m_Vertices.push_back(Point2f{ m_DiamondTexture->GetWidth(), m_DiamondTexture->GetHeight() / 2.f });
	m_Vertices.push_back(Point2f{ m_DiamondTexture->GetWidth() / 2.f, m_DiamondTexture->GetHeight() });
	m_Vertices.push_back(Point2f{ 0, m_DiamondTexture->GetHeight() / 2.f });
	m_Vertices.push_back(Point2f{ m_DiamondTexture->GetWidth() / 2.f, 0 });
}

Diamond::~Diamond()
{
	delete m_DiamondTexture;
}

void Diamond::Draw() const
{
	//translate and draw texture
	glPushMatrix();
		glTranslatef(m_Position.x, m_Position.y, 0);
		glRotatef(m_Angle, 0.f, 0.f, 1.f);
		glScalef(m_Scale, m_Scale, 1.f);
		glTranslatef(-m_DiamondTexture->GetWidth() / 2.f, -m_DiamondTexture->GetHeight() / 2.f, 0.f);
		m_DiamondTexture->Draw();
	glPopMatrix();

	if (m_IsSelected)
	{
		utils::SetColor(Color4f{ 1.f,0.f,0.f,1.f });
	}
	else
	{
		utils::SetColor(Color4f{ 0.f,0.f,1.f,1.f });
	}

	utils::DrawPolygon(CalculateTransformedDiamond());
}

bool Diamond::GetIsSelected() const
{
	return m_IsSelected;
}

void Diamond::SetIsSelected(const bool selected)
{
	m_IsSelected = selected;
}

void Diamond::SetPosition(const Vector2f& position)
{
	if (m_IsSelected)
	{
		m_Position = position;
	}
}

void Diamond::SetAngle(const float angle)
{
	if (m_IsSelected)
	{
		m_Angle = angle;
	}
}

void Diamond::SetScale(const float scale)
{
	if (m_IsSelected)
	{
		m_Scale = scale;
	}
}

void Diamond::Reset()
{
	const size_t verticesVertorSize(m_Vertices.size());
	for (int index{}; index < verticesVertorSize; ++index)
	{
		m_Vertices.pop_back();
	}
	m_Vertices.clear();

	m_Vertices.push_back(Point2f{ m_DiamondTexture->GetWidth(), m_DiamondTexture->GetHeight() / 2.f });
	m_Vertices.push_back(Point2f{ m_DiamondTexture->GetWidth() / 2.f, m_DiamondTexture->GetHeight() });
	m_Vertices.push_back(Point2f{ 0, m_DiamondTexture->GetHeight() / 2.f });
	m_Vertices.push_back(Point2f{ m_DiamondTexture->GetWidth() / 2.f, 0 });

	m_Position.x = m_StartPos.x;
	m_Position.y = m_StartPos.y;
	m_Angle = 0.f;
	m_Scale = 1.f;
	m_IsSelected = false;
}

Point2f Diamond::GetPosition() const
{
	Point2f position{};
	position.x = m_Position.x;
	position.y = m_Position.y;
	return position;
}

float Diamond::GetAngle() const
{
	return m_Angle;
}

float Diamond::GetScale() const
{
	return m_Scale;
}

bool Diamond::IsPointInDiamond(const Point2f& point)
{
	return utils::IsPointInPolygon(point, CalculateTransformedDiamond());
}

std::vector<Point2f> Diamond::CalculateTransformedDiamond() const
{
	Matrix2x3 maTranslate{}, matRotate{}, matScale{}, matCenter{};
	maTranslate.SetAsTranslate(m_Position);
	matRotate.SetAsRotate(m_Angle);
	matScale.SetAsScale(m_Scale, m_Scale);
	matCenter.SetAsTranslate(-m_DiamondTexture->GetWidth() / 2.f, -m_DiamondTexture->GetHeight() / 2.f);

	Matrix2x3 matWorld = maTranslate * matRotate * matScale * matCenter;
	std::vector<Point2f> transformedVertices;
	transformedVertices = matWorld.Transform(m_Vertices);

	return transformedVertices;
}