#pragma once
class Texture;

class Card final
{
public:
	enum class Suit
	{
		clubs = 1,
		diamonds = 2,
		hearts = 3,
		spades = 4
	};

	explicit Card( Suit suit, int rank, float angle, const Circlef& circle );
	~Card();
	void Update(float elapsedSec);
	void Draw() const; // const member functions is new, will be explained in the theory

	static const int m_MinRank;
	static const int m_MaxRank;
	float GetWidth()const ;// const member functions is new, will be explained in the theory
	float GetHeight()const ;// const member functions is new, will be explained in the theory
private:
	float m_Width;
	float m_Height;
	const Texture *m_pTexture;
	const Suit m_Suit;
	const int m_Rank;
	float m_Angle;
	Circlef m_Circle;
	const float m_RotationalSpeed;
	std::string GetImagePath(Suit suit, int rank) const;// const member functions is new, will be explained in the theory
};