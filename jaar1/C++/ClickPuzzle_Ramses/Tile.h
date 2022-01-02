#pragma once

class Tile 
{
public:

	Tile(const Rectf& dstRect, const std::string& textPath, int nrAnimals );
	~Tile();

	void Draw();
	void CheckActivation(const Point2f& pos);
	bool CheckHit(const Point2f& pos);
	

private: 

	int GetCurrentAnimal();
	void Deactivate();
	void Randomize();

	Rectf m_DstCurrentAnimal{};
	const int m_NrOfColumns{};
	Rectf* m_pSrcAnimals;
	Rectf m_SrcCurrentAnimal{};

	int m_IndexCurrentAnimal{};

	utils::Texture m_TileTexture{};

	const float m_TileSize{};

	float m_HitRegionWidth{};
	float m_HitRegionHeight{};
	Rectf m_LeftHitRegion{}, m_RightHitRegion{};

	bool m_IsActivated{};
	

};
