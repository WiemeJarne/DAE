#include "pch.h"
#include "Grid.h"

Grid::Grid(Texture texture, int amountOfRows, int amountOfColumns)
	:m_AmountOfRows{0}
	,m_AmountOfColumns{0}
	,m_Texture{texture}
	,m_DynArrGrid{ new Texture[amountOfRows * amountOfColumns] }
{
	InitDynArrGrid(amountOfRows, amountOfColumns);


}

Grid::~Grid()
{

}

void InitDynArrGrid(int amountOfRows, int amountOfColumns)
{
	const int size{ amountOfRows * amountOfColumns };

	for (int index{}; index < size; ++index)
	{
		m_DynArrGrid[index] = m_Texture;
	}
}