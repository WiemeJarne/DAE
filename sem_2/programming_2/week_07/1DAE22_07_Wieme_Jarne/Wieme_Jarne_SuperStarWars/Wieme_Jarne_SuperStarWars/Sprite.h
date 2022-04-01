#pragma once
#include <string>

class Texture;

class Sprite final
{
public:
	Sprite( const std::string& filename, int nrCols = 1, int nrRows = 1, float frameSec = 0, bool loop = true);
	Sprite(const Sprite& other) = delete;
	Sprite(Sprite&& other) = delete;
	~Sprite( );

	Sprite& operator=(const Sprite& rhs) = delete;
	Sprite& operator=(Sprite&& rhs) = delete;

	void Update( float elapsedSec );
	void Draw( const Point2f& pos, float scale = 1.0f ) const;

	float GetFrameWidth( ) const;
	float GetFrameHeight( ) const;

private:
	std::string m_TexturePath;
	Texture *m_pTexture;
	int m_Cols;
	int m_Rows;
	float m_FrameSec;
	float m_AccuSec;
	int m_ActFrame;
	bool m_Loop;
};