#pragma once
#include <string>

class Texture;

class Sprite final
{
public:
	enum class animType
	{
		loop,
		repeatBackwards,
		dontRepeat
	};

	Sprite( const std::string& filename, animType animType, int nrCols = 1, int nrRows = 1, float frameSec = 0 );
	Sprite( Sprite&& other ) = delete;
	~Sprite( );

	Sprite& operator=( const Sprite& rhs ) = delete;
	Sprite& operator=( Sprite&& rhs ) = delete;

	void Update( float elapsedSec );
	void Draw( const Point2f& pos, float scale = 1.0f ) const;

	float GetFrameWidth( ) const;
	float GetFrameHeight( ) const;
	int GetAmountOfFrames( ) const;
	int Get();
	void SetFrameNr(const int frameSec);
	void SetAccuSec(const float accuSec);
	int m_FrameDirection;
private:
	std::string m_TexturePath;
	Texture *m_pTexture;
	const animType m_AnimType;
	const int m_Columns;
	const int m_Rows;
	const float m_FramesPerSec;
	float m_AccuSec;
	int m_FrameNr;
	
};