#include <direct.h> // _getwcwd
#include <iostream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <string>
#include <codecvt>
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

void CreateCube(const std::wstring& layer, const Position& pos, bool isOpaque, std::vector<Cube>& cubes)
{
	Cube newCube{};

	newCube.p1 = Position(0 + pos.x, 0 + pos.z, 0 + pos.y);
	newCube.p2 = Position(0 + pos.x, 0 + pos.z, 1 + pos.y);
	newCube.p3 = Position(0 + pos.x, 1 + pos.z, 0 + pos.y);
	newCube.p4 = Position(0 + pos.x, 1 + pos.z, 1 + pos.y);
	newCube.p5 = Position(1 + pos.x, 0 + pos.z, 0 + pos.y);
	newCube.p6 = Position(1 + pos.x, 0 + pos.z, 1 + pos.y);
	newCube.p7 = Position(1 + pos.x, 1 + pos.z, 0 + pos.y);
	newCube.p8 = Position(1 + pos.x, 1 + pos.z, 1 + pos.y);
	newCube.layer = layer;
	newCube.isOpaque = isOpaque;

	cubes.push_back(newCube);
}

void WriteCubesToFile(FILE* pOFile, const std::vector<Cube>& cubes, bool verbose = false)
{
	if (verbose)
		std::wcout << "Write vertices to output file\n";
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

	if (verbose)
		std::wcout << "Write vertex normals to output file\n";

	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.f, 0.f, 1.f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.f, 0.f, -1.f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.f, 1.f, 0.f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.f, -1.f, 0.f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 1.f, 0.f, 0.f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", -1.f, 0.f, 0.f);

	if (verbose)
		std::wcout << "Write vertex texture coordinates to output file\n";
	fwprintf_s(pOFile, L"vt %.4f %.4f\n", 0.f, 0.f);
	fwprintf_s(pOFile, L"vt %.4f %.4f\n", 1.f, 0.f);
	fwprintf_s(pOFile, L"vt %.4f %.4f\n", 0.f, 1.f);
	fwprintf_s(pOFile, L"vt %.4f %.4f\n", 1.f, 1.f);

	if (verbose)
		std::wcout << "Write faces to output file:\n";

	std::wstring currentLayer{};
	for (int cubeNr{}; cubeNr < static_cast<int>(cubes.size()); ++cubeNr)
	{
		if (verbose)
			std::wcout << "-cubeNr " << cubeNr << ":\n";

		if (currentLayer.find(cubes[cubeNr].layer) == std::wstring::npos) //check if a new layer was started
		{
			currentLayer = L"usemtl " + cubes[cubeNr].layer + L'\n';
			fwrite(currentLayer.c_str(), wcslen(currentLayer.c_str()) * sizeof(wchar_t), 1, pOFile);

			if (verbose)
				std::wcout << "\tWrite usemtl command to output file: " << currentLayer << '\n';
		}

		if (verbose)
			std::wcout << "\tCube to the right of current cube?\n";

		if (!cubes[cubeNr].hasRightNeighbor)
		{
			if (verbose)
				std::wcout << "\t\tno -> write right side faces to output file\n";

			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 1 + 8 * cubeNr, 1, 2, 7 + 8 * cubeNr, 4, 2, 5 + 8 * cubeNr, 2, 2);
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 1 + 8 * cubeNr, 1, 2, 3 + 8 * cubeNr, 3, 2, 7 + 8 * cubeNr, 4, 2);
		}
		else if (verbose)
			std::wcout << "\t\tyes -> don't write right faces to output file\n";

		if (verbose)
			std::wcout << "\tCube to the back of current cube?\n";

		if (!cubes[cubeNr].hasBackNeighbor)
		{
			if (verbose)
				std::wcout << "\t\tno -> write back faces to output file\n";

			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 1 + 8 * cubeNr, 2, 6, 4 + 8 * cubeNr, 3, 6, 3 + 8 * cubeNr, 4, 6);
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 1 + 8 * cubeNr, 2, 6, 2 + 8 * cubeNr, 1, 6, 4 + 8 * cubeNr, 3, 6);
		}
		else if (verbose)
			std::wcout << "\t\tyes -> don't write back faces to output file\n";

		if (verbose)
			std::wcout << "\tCube above currentCube?\n";

		if (!cubes[cubeNr].hasTopNeighbor)
		{
			if (verbose)
				std::wcout << "\t\tno -> write top faces to output file\n";

			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 3 + 8 * cubeNr, 2, 3, 8 + 8 * cubeNr, 3, 3, 7 + 8 * cubeNr, 1, 3);
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 3 + 8 * cubeNr, 2, 3, 4 + 8 * cubeNr, 4, 3, 8 + 8 * cubeNr, 3, 3);
		}
		else if (verbose)
			std::wcout << "\t\tyes -> don't write top faces to output file\n";

		if (verbose)
			std::wcout << "\tCube in front of current cube?\n";

		if (!cubes[cubeNr].hasFrontNeighbor)
		{
			if (verbose)
				std::wcout << "\t\tno -> write front faces to output file\n";

			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 5 + 8 * cubeNr, 1, 5, 7 + 8 * cubeNr, 3, 5, 8 + 8 * cubeNr, 4, 5);
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 5 + 8 * cubeNr, 1, 5, 8 + 8 * cubeNr, 4, 5, 6 + 8 * cubeNr, 2, 5);
		}
		else if (verbose)
			std::wcout << "\t\tyes -> don't write front faces to output file\n";

		if (verbose)
			std::wcout << "\tCube below current cube?\n";

		if (!cubes[cubeNr].hasBottomNeighbor)
		{
			if (verbose)
				std::wcout << "\t\tno -> write bottom faces to output file\n";
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 1 + 8 * cubeNr, 4, 4, 5 + 8 * cubeNr, 3, 4, 6 + 8 * cubeNr, 1, 4);
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 1 + 8 * cubeNr, 4, 4, 6 + 8 * cubeNr, 1, 4, 2 + 8 * cubeNr, 2, 4);
		}
		else if (verbose)
			std::wcout << "\t\tyes -> don't write bottom faces to output file\n";

		if (verbose)
			std::wcout << "\tCube to the left of current cube?\n";

		if (!cubes[cubeNr].hasLeftNeighbor)
		{
			if (verbose)
				std::wcout << "\t\tno -> write left faces to output file\n";
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 2 + 8 * cubeNr, 1, 1, 6 + 8 * cubeNr, 2, 1, 8 + 8 * cubeNr, 4, 1);
			fwprintf_s(pOFile, L"f %d/%d/%d %d/%d/%d %d/%d/%d\n", 2 + 8 * cubeNr, 1, 1, 8 + 8 * cubeNr, 4, 1, 4 + 8 * cubeNr, 3, 1);
		}
		else if (verbose)
			std::wcout << "\t\tno -> don't write left faces to output file\n";
	}
}

void CalculateCubesNeigbors(std::vector<Cube>& cubes)
{
	for (auto& cube : cubes)
	{
		for (auto& otherCube : cubes)
		{
			//make sure cube is not the same as otherCube
			if (cube == otherCube || !cube.isOpaque || !otherCube.isOpaque)
				continue;

			//check if otherCube is a rightNeighbor for cube
			if (cube.p3 == otherCube.p1 && cube.p4 == otherCube.p2
				&& cube.p7 == otherCube.p5 && cube.p8 == otherCube.p6)
			{
				cube.hasTopNeighbor = true;
				otherCube.hasBottomNeighbor = true;
			}

			//check if otherCube is a topNeighbor for cube
			if (cube.p1 == otherCube.p2 && cube.p3 == otherCube.p4
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

void JsonToObj(const std::wstring& inputFile, const std::wstring& outputFile = L"", bool verbose = false)
{
	std::wstring outputFileName;

	if (outputFile == L"")
	{
		outputFileName = inputFile;
		outputFileName.erase(inputFile.find(L"json")).append(L"obj");
	}
	else
	{
		outputFileName = outputFile;
	}

	std::ifstream is{ inputFile };

	if (verbose)
		std::wcout << L"opened input file\n";

	using namespace rapidjson;
	IStreamWrapper isw{ is };
	if (verbose)
		std::wcout << L"created IStreamWrapper\n";
	Document jsonDoc;
	jsonDoc.ParseStream(isw);

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter{};

	int amountOfCubes{};

	if (verbose)
		std::wcout << L"Is jsonDoc array? ";

	if (jsonDoc.IsArray())
	{
		if (verbose)
			std::wcout << L"yes\n";

		std::vector<Cube> cubes{};

		for (Value::ConstValueIterator it = jsonDoc.Begin(); it != jsonDoc.End(); ++it)
		{
			if (verbose)
				std::cout << "start reading in cubes.\n";

			const Value& newCubes{ *it };

			std::wstring newCubesLayer{};

			if (newCubes.HasMember("layer"))
			{
				const Value& layer{ newCubes["layer"] };

				if (layer.IsString())
				{
					newCubesLayer = converter.from_bytes(layer.GetString());
					//make the first letter capitilized
					newCubesLayer[0] = static_cast<wchar_t>(std::toupper(newCubesLayer[0]));

					if (verbose)
						std::wcout << "layer: " << newCubesLayer << '\n';
				}
			}

			bool areNewCubesOpaque{};
			if (newCubes.HasMember("opaque"))
			{
				const Value& isOpaque{ newCubes["opaque"] };

				if (verbose)
					std::wcout << "Is Opaque? ";

				if (isOpaque.IsBool())
					areNewCubesOpaque = isOpaque.GetBool();

				if (verbose)
					std::wcout << areNewCubesOpaque << "\n";
			}

			if (newCubes.HasMember("positions"))
			{
				const Value& positions{ newCubes["positions"] };

				if (verbose)
					std::wcout << L"amount of cubes in current layer: " << positions.Size() << '\n';

				for (int index{}; index < static_cast<int>(positions.Size()); ++index)
				{
					const Value& pos{ positions[index] };

					if (pos.Size() == 3 && pos[0].IsInt() && pos[1].IsInt() && pos[2].IsInt())
					{
						int x{ pos[0].GetInt() }, y{ pos[1].GetInt() }, z{ pos[2].GetInt() };

						CreateCube(newCubesLayer, Position(x, y, z), areNewCubesOpaque, cubes);

						if (verbose)
							std::wcout << "cube created at position: {" << x << ", " << y << ", " << z << "}\n";

						++amountOfCubes;
					}
				}
			}
		}

		if (verbose)
			std::wcout << "finnished reading in. Read in " << amountOfCubes << " cubes.\ncaculating cube neighbors\n";

		CalculateCubesNeigbors(cubes);

		FILE* pOFile = nullptr;
		_wfopen_s(&pOFile, outputFileName.c_str(), L"w+,ccs=UTF-8");

		if (verbose)
			std::wcout << "Opend output file " << outputFileName << "\n";

		if (pOFile == nullptr)
		{
			std::wcout << "failed to open output\n";
			return;
		}

		// it was possible to create the file for writing.
		const wchar_t* text = L"#∂ is the symbol for partial derivative.\n";
		fwrite(text, wcslen(text) * sizeof(wchar_t), 1, pOFile);

		text = L"mtllib minecraftMats.mtl\n";
		fwrite(text, wcslen(text) * sizeof(wchar_t), 1, pOFile);

		WriteCubesToFile(pOFile, cubes, verbose);

		if (verbose)
			std::wcout << "Close output file\n";
		fclose(pOFile);

		return;
	}

	if (verbose)
		std::wcout << L"no\n";
}