#pragma once
#include <vector>
#include <iostream>
#include "Materials/DiffuseMaterial.h"
#include "Cell.h"

class Grid final
{
public:
	Grid(int amountOfRows, int amountOfColumns, GameScene* pGameScene, PxMaterial* pPhysxMaterial);
	~Grid();

	void Update();
	void PlaceBomb(XMFLOAT3 posInCell, CharacterDesc* pCharacterDesc);
	Cell* GetCell(int rowNr, int colNr) const;
	Cell* GetCell(XMFLOAT3 posInCell) const;
	int GetAmountOfRow() const { return m_AmountOfRows; }
	int GetAmountOfColumns() const { return m_AmountOfColumns;  }

private:
	const int m_AmountOfRows{};
	const int m_AmountOfColumns{};
	std::vector<Cell*> m_PlayingFieldCells{};
	std::vector<GameObject*> m_BottomLayerGameObject{};
	
};