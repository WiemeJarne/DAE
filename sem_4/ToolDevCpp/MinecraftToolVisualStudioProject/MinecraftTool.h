#pragma once
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

	bool isOpaque{};

	std::wstring layer{};

	bool operator==(Cube other)
	{
		if (p1 == other.p1 && p2 == other.p2
			&& p3 == other.p3 && p4 == other.p4
			&& p5 == other.p5 && p6 == other.p6
			&& p7 == other.p7 && p8 == other.p8)
		{
			return true;
		}

		return false;
	}
};

void CreateCube(const std::wstring& layer, const Position& pos, bool isOpaque, std::vector<Cube>& cubes);
void WriteCubesToFile(FILE* pOFile, const std::vector<Cube>& cubes);
void CalculateCubesNeigbors(std::vector<Cube>& cubes);
void PrintInstructions();
std::wstring Replace(const std::wstring& str, const std::wstring& subStrToReplace, const std::wstring& strToReplaceSubStringWith);