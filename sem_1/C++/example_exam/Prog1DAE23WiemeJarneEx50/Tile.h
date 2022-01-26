#pragma once
using utils::Texture;

class Tile 
{
public:
	Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals );
	~Tile();

	void Draw();
	void CheckActivation(const Point2f& pos);
	bool CheckHit(const Point2f& pos);
	int GetCurrentAnimal();
	void Deactivate();
	void Randomize();

	
	Rectf m_SourceRect;
	int m_AmountOfAnimals;

private:
	Texture m_Texture;
	Rectf m_DestinationRect;
	
	int m_CurrentAnimal;

	bool m_TileState;
	bool m_TileIsActive;

	float m_SmallRectX;
	float m_SmallRectY;
	float m_SmallRectWidth;
	float m_SmallRectHeight;
};