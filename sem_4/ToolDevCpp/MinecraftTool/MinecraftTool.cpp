// MinecraftTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <direct.h> // _getwcwd
#include <iostream>
#include <fstream>
#include <windows.h>
#include "rapidjson.h"
#include "document.h"
#include "stream.h"
#include "filereadstream.h"
#include "istreamwrapper.h"

void CreateCube(FILE* pOFile, int x, int y, int z);

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
		for (Value::ConstValueIterator it = jsonDoc.Begin(); it != jsonDoc.End(); ++it)
		{
			const Value& cube{ *it };

			if (cube.HasMember("positions"))
			{
				const Value& positions{ cube["positions"] };

				for (int index{}; index < positions.Size(); ++index)
				{
					const Value& pos{ positions[index] };

					if (pos.Size() == 3)
					{
						if (pos[0].IsInt() && pos[1].IsInt() && pos[2].IsInt())
						{
							CreateCube(pOFile, pos[0].GetInt(), pos[1].GetInt(), pos[2].GetInt());
							++amountOfCubes;
						}
					}
				}
			}
		}
	}
	
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 0.0f, 1.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 0.0f, -1.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, 1.0f, 0.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 0.0f, -1.0f, 0.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", 1.0f, 0.0f, 0.0f);
	fwprintf_s(pOFile, L"vn %.4f %.4f %.4f\n", -1.0f, 0.0f, 0.0f);

	for (int cubeNr{}; cubeNr < amountOfCubes; ++cubeNr)
	{
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 2, 7 + 8 * cubeNr, 2, 5 + 8 * cubeNr, 2);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 2, 3 + 8 * cubeNr, 2, 7 + 8 * cubeNr, 2);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 6, 4 + 8 * cubeNr, 6, 3 + 8 * cubeNr, 6);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 6, 2 + 8 * cubeNr, 6, 4 + 8 * cubeNr, 6);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 3 + 8 * cubeNr, 3, 8 + 8 * cubeNr, 3, 7 + 8 * cubeNr, 3);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 3 + 8 * cubeNr, 3, 4 + 8 * cubeNr, 3, 8 + 8 * cubeNr, 3);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 5 + 8 * cubeNr, 5, 7 + 8 * cubeNr, 5, 8 + 8 * cubeNr, 5);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 5 + 8 * cubeNr, 5, 8 + 8 * cubeNr, 5, 6 + 8 * cubeNr, 5);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 4, 5 + 8 * cubeNr, 4, 6 + 8 * cubeNr, 4);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 1 + 8 * cubeNr, 4, 6 + 8 * cubeNr, 4, 2 + 8 * cubeNr, 4);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 2 + 8 * cubeNr, 1, 6 + 8 * cubeNr, 1, 8 + 8 * cubeNr, 1);
		fwprintf_s(pOFile, L"f %d//%d %d//%d %d//%d\n", 2 + 8 * cubeNr, 1, 8 + 8 * cubeNr, 1, 4 + 8 * cubeNr, 1);
	}

	fclose(pOFile);
	return 0;
}

void CreateCube(FILE* pOFile, int x, int y, int z)
{
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 0.0 + x, 0.0 + z, 0.0f + y);
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 0.0 + x, 0.0 + z, 1.0f + y);
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 0.0 + x, 1.0 + z, 0.0f + y);
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 0.0 + x, 1.0 + z, 1.0f + y);
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 1.0 + x, 0.0 + z, 0.0f + y);
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 1.0 + x, 0.0 + z, 1.0f + y);
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 1.0 + x, 1.0 + z, 0.0f + y);
	fwprintf_s(pOFile, L"v %.4f %.4f %.4f\n", 1.0 + x, 1.0 + z, 1.0f + y);
}