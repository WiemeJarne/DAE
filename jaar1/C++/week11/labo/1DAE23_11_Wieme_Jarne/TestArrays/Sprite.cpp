#include "pch.h"
#include "Sprite.h"
#include <iostream>
using namespace utils;

Sprite::Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale)
	: m_Columns{ nrCols }
	, m_Rows{ nrRows }
	, m_SecondsPerFrame{ frameSec }
	, m_Scale{ scale }
	,m_AmountOfFrames{nrCols * nrRows}
{
	TextureFromFile(filename, m_Texture);

	m_TextureFrameWidth  = m_Texture.width	/ m_Columns;
	m_TextureFrameHeight = m_Texture.height / m_Rows;

	m_SpriteFrameWidth  = m_TextureFrameWidth  * m_Scale;
	m_SpriteFrameHeight = m_TextureFrameHeight * m_Scale;
}

Sprite::~Sprite()
{
	DeleteTexture(m_Texture);
}

void Sprite::Update(float elapsedSec)
{
	m_AccumulateSeconds += elapsedSec;

	float elapsedFrames{m_AccumulateSeconds / m_SecondsPerFrame};
	
	m_CurrentFrame = int(elapsedFrames) % m_AmountOfFrames;
}

void Sprite::Draw(const Point2f& pos)
{
	Rectf destinationRect{};
	destinationRect.left   = pos.x;
	destinationRect.bottom = pos.y;
	destinationRect.width  = m_SpriteFrameWidth;
	destinationRect.height = m_SpriteFrameHeight;

	Rectf sourceRect{};
	sourceRect.left   = (m_CurrentFrame % m_Columns) * m_TextureFrameWidth;
	sourceRect.bottom = (m_CurrentFrame / m_Columns + 1) * m_TextureFrameHeight;
	sourceRect.width  = m_TextureFrameWidth;
	sourceRect.height = m_TextureFrameHeight;

	DrawTexture(m_Texture, destinationRect, sourceRect);
}

float Sprite::GetFrameWitdh()
{
	return m_SpriteFrameWidth;
}

float Sprite::GetFrameHeight()
{
	return m_SpriteFrameHeight;
}