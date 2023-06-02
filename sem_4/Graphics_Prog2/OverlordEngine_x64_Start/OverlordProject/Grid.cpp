#include "stdafx.h"
#include "Grid.h"
#include "Materials/Shadow/DiffuseMaterial_Shadow.h"
#include "Materials/Shadow/DiffNormTex_Shadow.h"

Grid::Grid(int amountOfRows, int amountOfColumns, GameScene* pGameScene, PxMaterial* pPhysxMaterial)
	: m_AmountOfRows{ amountOfRows }
	, m_AmountOfColumns{ amountOfColumns }
{
	//brick material
	auto pBrickMaterial{ MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>() };
	pBrickMaterial->SetDiffuseTexture(L"Textures/brick.jpg");

	//crackedBrick material
	auto pCrackedBrickMaterial{ MaterialManager::Get()->CreateMaterial<DiffNormTex_Shadow>() };
	pCrackedBrickMaterial->SetDiffuseTexture(L"Textures/CrackedBrick/rock.jpg");
	pCrackedBrickMaterial->SetNormalMap(L"Textures/CrackedBrick/NormalMap.png");

	//grass material
	auto pGrassMaterial{ MaterialManager::Get()->CreateMaterial<DiffNormTex_Shadow>() };
	pGrassMaterial->SetDiffuseTexture(L"Textures/Grass/Diffuse_Seamless_Grass_Tile.png");
	pGrassMaterial->SetNormalMap(L"Textures/Grass/Normal_Seamless_Grass_Tile.png");

	//metalPlate material
	auto pMetalPlateMaterial{ MaterialManager::Get()->CreateMaterial<DiffuseMaterial_Shadow>() };
	pMetalPlateMaterial->SetDiffuseTexture(L"Textures/MetalPlate.png");

	for (int rowNr{}; rowNr < amountOfRows; ++rowNr)
	{
		for (int colNr{}; colNr < amountOfColumns; ++colNr)
		{
			if (rowNr == 0 || rowNr == (amountOfRows - 1) || colNr == 0 || colNr == (amountOfColumns - 1)) //at the edges of the grid add a wall of 2 blocks high
			{
				auto pBrick{ pGameScene->AddChild(new GameObject()) };
				pBrick->GetTransform()->Scale(0.045f);
				pBrick->GetTransform()->Translate(static_cast<float>(colNr), 0.5f, static_cast<float>(rowNr));
				auto pModel{ pBrick->AddComponent(new ModelComponent(L"Meshes/Brick.ovm")) };
				pModel->SetMaterial(pBrickMaterial);
				auto pRigidBody{ pBrick->AddComponent(new RigidBodyComponent(true)) };
				pRigidBody->AddCollider(PxBoxGeometry(0.75f / 2.f, 0.75f / 2.f, 0.75f / 2.f), *pPhysxMaterial);

				auto cellPos{ pBrick->GetTransform()->GetPosition() };
				cellPos.y += 1.f;
				
				m_BottomLayerGameObject.push_back(pBrick);

				pBrick = pGameScene->AddChild(new GameObject());
				pBrick->GetTransform()->Scale(0.045f);
				pBrick->GetTransform()->Translate(static_cast<float>(colNr), 1.5f, static_cast<float>(rowNr));
				pModel = pBrick->AddComponent(new ModelComponent(L"Meshes/Brick.ovm"));
				pModel->SetMaterial(pBrickMaterial);
				pRigidBody = pBrick->AddComponent(new RigidBodyComponent(true));
				pRigidBody->AddCollider(PxBoxGeometry(0.75f / 2.f, 0.75f / 2.f, 0.75f / 2.f), *pPhysxMaterial);
				m_PlayingFieldCells.push_back(new Cell(pGameScene, cellPos, rowNr, colNr, Cell::State::wall, pBrick));
			}
			else
			{
				auto pGrass{ pGameScene->AddChild(new GameObject()) };
				pGrass->GetTransform()->Scale(0.045f);
				pGrass->GetTransform()->Translate(static_cast<float>(colNr), 0.5f, static_cast<float>(rowNr));
				auto cellPos{ pGrass->GetTransform()->GetPosition() };
				cellPos.y += 1.f;

				m_BottomLayerGameObject.push_back(pGrass);

				//randomly rotate the grass block around the x-axis
				int randomNr{ rand() % 4 };
				switch (randomNr)
				{
				case 1:
					pGrass->GetTransform()->Rotate(90.f, 0.f, 0.f);
					break;
				case 2:
					pGrass->GetTransform()->Rotate(180.f, 0.f, 0.f);
					break;
				case 3:
					pGrass->GetTransform()->Rotate(270.f, 0.f, 0.f);
					break;
				}

				//randomly rotate the grass block around the y-axis
				randomNr = rand() % 4;
				switch (randomNr)
				{
				case 1:
					pGrass->GetTransform()->Rotate(0.f, 90.f, 0.f);
					break;
				case 2:
					pGrass->GetTransform()->Rotate(0.f, 180.f, 0.f);
					break;
				case 3:
					pGrass->GetTransform()->Rotate(0.f, 270.f, 0.f);
					break;
				}

				//randomly rotate the grass block around the z-axis
				randomNr = rand() % 4;
				switch (randomNr)
				{
				case 1:
					pGrass->GetTransform()->Rotate(0.f, 0.f, 90.f);
					break;
				case 2:
					pGrass->GetTransform()->Rotate(0.f, 0.f, 180.f);
					break;
				case 3:
					pGrass->GetTransform()->Rotate(0.f, 0.f, 270.f);
					break;
				}

				auto pModel{ pGrass->AddComponent(new ModelComponent(L"Meshes/Brick.ovm")) };
				pModel->SetMaterial(pGrassMaterial);
				auto pRigidBody{ pGrass->AddComponent(new RigidBodyComponent(true)) };
				pRigidBody->AddCollider(PxBoxGeometry(0.75f / 2.f, 0.75f / 2.f, 0.75f / 2.f), *pPhysxMaterial);

				//when not in 1 of the corners place a crackedBrick or a metal cube
				const int cellIndex{rowNr * amountOfColumns + colNr};
				if (cellIndex != (1 * amountOfColumns + 1) && cellIndex != (2 * amountOfColumns + 1) && cellIndex != (1 * amountOfColumns + 2) //no blocks in the bottom left corner
					&& cellIndex != (1 * amountOfColumns + (amountOfColumns - 2)) && cellIndex != (2 * amountOfColumns + (amountOfColumns - 2)) && cellIndex != (1 * amountOfColumns + (amountOfColumns - 3)) //no blocks in the bottom right corner
					&& cellIndex != ((amountOfRows - 2) * amountOfColumns + 1) && cellIndex != ((amountOfRows - 3) * amountOfColumns + 1) && cellIndex != ((amountOfRows - 2) * amountOfColumns + 2) //no blocks in the top left corner
					&& cellIndex != ((amountOfRows - 2) * amountOfColumns + (amountOfColumns - 2)) && cellIndex != ((amountOfRows - 3) * amountOfColumns + (amountOfColumns - 2)) && cellIndex != ((amountOfRows - 2) * amountOfColumns + (amountOfColumns - 3))) //no blocks in the top right corner
				{

					if (rowNr % 2 == 0 && rowNr > 0 && rowNr < (amountOfRows - 2) && colNr % 2 == 0 && colNr > 0 && colNr < (amountOfColumns - 2))
					{
						auto pMetalBlock = pGameScene->AddChild(new GameObject());
						pMetalBlock->GetTransform()->Scale(1.f);
						pMetalBlock->GetTransform()->Translate(static_cast<float>(colNr), 1.5f, static_cast<float>(rowNr));
						pModel = pMetalBlock->AddComponent(new ModelComponent(L"Meshes/Cube.ovm"));
						pModel->SetMaterial(pMetalPlateMaterial);
						pRigidBody = pMetalBlock->AddComponent(new RigidBodyComponent(true));
						pRigidBody->AddCollider(PxBoxGeometry(0.75f / 2.f, 0.75f / 2.f, 0.75f / 2.f), *pPhysxMaterial);
						m_PlayingFieldCells.push_back(new Cell(pGameScene, cellPos, rowNr, colNr, Cell::State::wall, pMetalBlock));
					}
					else
					{
						auto pCrackedBrick{ pGameScene->AddChild(new GameObject()) };
						pCrackedBrick->GetTransform()->Scale(0.01f);
						pCrackedBrick->GetTransform()->Translate(static_cast<float>(colNr), 1.5f, static_cast<float>(rowNr));
						pModel = pCrackedBrick->AddComponent(new ModelComponent(L"Meshes/CrackedBrick.ovm"));
						pModel->SetMaterial(pCrackedBrickMaterial);
						pRigidBody = pCrackedBrick->AddComponent(new RigidBodyComponent(true));
						pRigidBody->AddCollider(PxBoxGeometry(0.75f / 2.f, 0.75f / 2.f, 0.75f / 2.f), *pPhysxMaterial);
						m_PlayingFieldCells.push_back(new Cell(pGameScene, cellPos, rowNr, colNr, Cell::State::crackedWall, pCrackedBrick));
					}
				}
				else
				{
					m_PlayingFieldCells.push_back(new Cell(pGameScene, cellPos, rowNr, colNr, Cell::State::empty));
				}
			}
		}
	}

	m_PlayingFieldCells[0]->InitializeGridAndCallBacks(this);
}

Grid::~Grid()
{
	for (auto cell : m_PlayingFieldCells)
	{
		SafeDelete(cell);
	}

	for (auto pGameObject : m_BottomLayerGameObject)
	{
		pGameObject->GetScene()->RemoveChild(pGameObject, true);
	}
}

void Grid::Update()
{
	for (auto cell : m_PlayingFieldCells)
	{
		cell->Update();
	}
}

void Grid::PlaceBomb(XMFLOAT3 posInCell, CharacterDesc* pCharacterDesc)
{
	auto pCell{ GetCell(posInCell) };

	if(pCell && pCell->GetState() != Cell::State::bomb)
		pCell->PlaceBomb(pCharacterDesc);
}

Cell* Grid::GetCell(int rowNr, int colNr) const 
{ 
	const int cellIndex{ rowNr * m_AmountOfColumns + colNr };
	if(cellIndex < (m_AmountOfRows) * (m_AmountOfColumns) && cellIndex > 0)
		return m_PlayingFieldCells[cellIndex]; 

	return nullptr;
}

Cell* Grid::GetCell(XMFLOAT3 posInCell) const
{
	for (auto& cell : m_PlayingFieldCells)
	{
		if (posInCell.x < cell->GetMiddlePos().x - 0.5f)
			continue;

		if (posInCell.x > cell->GetMiddlePos().x + 0.5f)
			continue;

		if (posInCell.y < cell->GetMiddlePos().y - 0.5f)
			continue;

		if (posInCell.y > cell->GetMiddlePos().y + 0.5f)
			continue;

		if (posInCell.z < cell->GetMiddlePos().z - 0.5f)
			continue;

		if (posInCell.z > cell->GetMiddlePos().z + 0.5f)
			continue;

		return cell;
	}

	return nullptr;
}