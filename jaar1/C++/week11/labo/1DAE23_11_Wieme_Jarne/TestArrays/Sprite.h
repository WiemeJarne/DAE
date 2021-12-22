#pragma once
using utils::Texture;

class Sprite
{
public:
	// constructor(s) and destructor
	Sprite(const std::string& filename, int nrCols, int nrRows, float frameSec, float scale);
	~Sprite();
	
	// public member fucntions
	void Update(float elapsedSec);
	void Draw(const Point2f& pos);
	float GetFrameWitdh();
	float GetFrameHeight();

private:
	// private data members
	Texture m_Texture{};
	const int m_Columns{}, m_Rows{};
	int m_CurrentFrame{};
	const int m_AmountOfFrames{};
	const float m_g_SecondsPerFrame{};
	float m_AccumulateSeconds{};
	const float m_Scale{};
	float m_SpriteFrameWidth{}, m_SpriteFrameHeight{};
	float m_TextureFrameWidth{}, m_TextureFrameHeight{};
};