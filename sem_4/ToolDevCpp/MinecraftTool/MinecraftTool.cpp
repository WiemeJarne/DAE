// MinecraftTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <direct.h> // _getwcwd
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include "rapidjson.h"
#include "document.h"
#include "stream.h"
#include "filereadstream.h"
#include "istreamwrapper.h"

struct Position
{
	Position()
	: x{ 0 }
	, y{ 0 }
	, z{ 0 }
	{}

	Position(int _x, int _y, int _z)
		: x{ _x }
		, y{ _y }
		, z{ _z }
	{}

	int x, y, z;

	bool operator==(Position other)
	{
		if (x == other.x && y == other.y && z == other.z)
			return true;

		return false;
	}
};

struct Cube
{
	Position p1;
	Position p2;
	Position p3;
	Position p4;
	Position p5;
	Position p6;
	Position p7;
	Position p8;

	bool hasRightNeighbor{};
	bool hasLeftNeighbor{};
	bool hasTopNeighbor{};
	bool hasBottomNeighbor{};
	bool hasBackNeighbor{};
	bool hasFrontNeighbor{};

	bool operator==(Cube other)
	{
		if (	p1 == other.p1 && p2 == other.p2
			 && p3 == other.p3 && p4 == other.p4
			 && p5 == other.p5 && p6 == other.p6
			 && p7 == other.p7 && p8 == other.p8)
		{
			return true;
		}

		return false;
	}
};

void CreateCube(int x, int y, int z, std::vector<Cube>& cubes);
void WriteCubesToFile(FILE* pOFile, const std::vector<Cube>& cubes);
void CalculateCubesNeigbors(std::vector<Cube>& cubes);

int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
{
	FILE* pOFile = nullptr;
	_wfopen_s(&pOFile, L"scene.obj", L"w+,ccs=UTF-8");

	if (pOFile == nullptr)
		return -1;

	std::ifstream is{ "scene.json" };

	if (!is)
		return -1;

	// it was possible to create the file for writing.
	const wchar_t* text = L"#∂ is the symbol for partial derivative.\n";
	fwrite(text, wcslen(text) * sizeof(wchar_t), 1, pOFile);

	using namespace rapidjson;
	IStreamWrapper isw{ is };
	Document jsonDoc;
	jsonDoc.ParseStream(isw);

	int amountOfCubes{};

	if (jsonDoc.IsArray())
	{
		std::vector<Cube> cubes{};

		for (Value::ConstValueIterator it = jsonDoc.Begin(); it != jsonDoc.End(); ++it)
		{
			const Value& cube{ *it };

			if (cube.HasMember("positions"))
			{
				const Value& positions{ cube["positions"] };

				for (int index{}; index < static_cast<int>(positions.Size()); ++index)
				{
					const Value& pos{ positions[index] };

					if (pos.Size() == 3)
					{
						if (pos[0].IsInt() && pos[1].IsInt() && pos[2].IsInt())
						{
							CreateCube(pos[0].GetInt(), pos[1].GetInt(), pos[2].GetInt(), cubes);
							++amountOfCubes;
						}
					}
				}
			}
		}
		CalculateCubesNeigbors(cubes);
		WriteCubesToFile(pOFile, cubes);
	}

	
	
	

	fclose(pOFile);
	return 0;
}

void CreateCube(int x, int y, int z, std::vector<Cube>& cubes)
{
	Cube newCube{};

	newCube.p1 = Position(0 + x, 0 + z, 0 + y);
	newCube.p2 = Position(0 + x, 0 + z, 1 + y);
	newCube.p3 = Position(0 + x, 1 + z, 0 + y);
	newCube.p4 = Position(0 + x, 1 + z, 1 + y);
	newCube.p5 = Position(1 + x, 0 + z, 0 + y);
	newCube.p6 = Position(1 + x, 0 + z, 1 + y);
	newCube.p7 = Position(1 + x, 1 + z, 0 + y);
	newCube.p8 = Position(1 + x, 1 + z, 1 + y);

	cubes.push_back(newCube);
}

void WriteCubesToFile(FILE* pOFile, const std::vector<Cube>& cubes)
{
	for (auto& cube : cubes)
	{
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p1.x, cube.p1.y, cube.p1.z);
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p2.x, cube.p2.y, cube.p2.z);
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p3.x, cube.p3.y, cube.p3.z);
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p4.x, cube.p4.y, cube.p4.z);
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p5.x, cube.p5.y, cube.p5.z);
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p6.x, cube.p6.y, cube.p6.z);
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p7.x, cube.p7.y, cube.p7.z);
		fwprintf_s(pOFile, L"v %i %i %i\n", cube.p8.x, cube.p8.y, cube.p8.z);
	}

	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 0.0f, 1.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 0.0f, -1.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 1.0f, 0.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, -1.0f, 0.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 1.0f, 0.0f, 0.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", -1.0f, 0.0f, 0.0f);

	for (int cubeNr{}; cubeNr < static_cast<int>(cubes.size()); ++cubeNr)
	{
		if (!cubes[cubeNr].hasRightNeighbor)
		{
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 2, 7 + 8 * cubeNr, 2, 5 + 8 * cubeNr, 2);
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 2, 3 + 8 * cubeNr, 2, 7 + 8 * cubeNr, 2);
		}

		if (!cubes[cubeNr].hasBackNeighbor)
		{

			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 6, 4 + 8 * cubeNr, 6, 3 + 8 * cubeNr, 6);
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 6, 2 + 8 * cubeNr, 6, 4 + 8 * cubeNr, 6);
		}

		if (!cubes[cubeNr].hasTopNeighbor)
		{
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 3 + 8 * cubeNr, 3, 8 + 8 * cubeNr, 3, 7 + 8 * cubeNr, 3);
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 3 + 8 * cubeNr, 3, 4 + 8 * cubeNr, 3, 8 + 8 * cubeNr, 3);
		}
		
		if (!cubes[cubeNr].hasFrontNeighbor)
		{
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 5 + 8 * cubeNr, 5, 7 + 8 * cubeNr, 5, 8 + 8 * cubeNr, 5);
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 5 + 8 * cubeNr, 5, 8 + 8 * cubeNr, 5, 6 + 8 * cubeNr, 5);
		}
		
		if (!cubes[cubeNr].hasBottomNeighbor)
		{
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 4, 5 + 8 * cubeNr, 4, 6 + 8 * cubeNr, 4);
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 4, 6 + 8 * cubeNr, 4, 2 + 8 * cubeNr, 4);
		}
		
		if (!cubes[cubeNr].hasLeftNeighbor)
		{
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 2 + 8 * cubeNr, 1, 6 + 8 * cubeNr, 1, 8 + 8 * cubeNr, 1);
			fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 2 + 8 * cubeNr, 1, 8 + 8 * cubeNr, 1, 4 + 8 * cubeNr, 1);
		}
	}
}

void CalculateCubesNeigbors(std::vector<Cube>& cubes)
{
	for (auto& cube : cubes)
	{
		for (auto& otherCube : cubes)
		{
			//make sure cube is not the same as otherCube
			if (cube == otherCube)
				continue;

			//check if otherCube is a rightNeighbor for cube
			if (	cube.p3 == otherCube.p1 && cube.p4 == otherCube.p2
				 && cube.p7 == otherCube.p5 && cube.p8 == otherCube.p6)
			{
				cube.hasTopNeighbor = true;
				otherCube.hasBottomNeighbor = true;
			}

			//check if otherCube is a topNeighbor for cube
			if (	cube.p1 == otherCube.p2 && cube.p3 == otherCube.p4
				 && cube.p5 == otherCube.p6 && cube.p7 == otherCube.p8)
			{
				cube.hasRightNeighbor = true;
				otherCube.hasLeftNeighbor = true;
			}

			//check if otherCube is a backNeighbor for cube
			if (cube.p1 == otherCube.p5 && cube.p2 == otherCube.p6
				&& cube.p3 == otherCube.p7 && cube.p4 == otherCube.p8)
			{
				cube.hasBackNeighbor = true;
				otherCube.hasFrontNeighbor = true;
			}
		}
	}
}