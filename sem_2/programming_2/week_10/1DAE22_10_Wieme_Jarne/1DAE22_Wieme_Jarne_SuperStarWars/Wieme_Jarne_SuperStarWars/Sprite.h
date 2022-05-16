#pragma once
#include <string>

class Texture;

class Sprite final
{
public:
	enum class AnimType
	{
		loop,
		repeatBackwards,
		dontRepeat
	};

	explicit Sprite( const Texture* pTexture, AnimType animType, int nrCols = 1, int nrRows = 1, float frameSec = 0 );

	void Update( float elapsedSec );
	void Draw( ) const;

	float GetFrameWidth( ) const;
	float GetFrameHeight( ) const;
	int GetAmountOfFrames( ) const;
	int GetFrameNr( );
	void SetFrameNr(const int frameSec);
	void SetAccuSec(const float accuSec);

private:
	const Texture* m_pTexture;
	const AnimType m_AnimType;
	const int m_Columns;
	const int m_Rows;
	const float m_FramesPerSec;
	float m_AccuSec;
	int m_FrameNr;
	int m_FrameDirection;
};