#pragma once
// MinecraftTool.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "JsonToObj.h"

void PrintInstructions();

int wmain(int argc, wchar_t* argv[], wchar_t* envp[])
{
	if (argc != 3 && argc != 4 && argc != 5 && argc != 6)
	{
		std::wcout << "wrong amount of arguments\n";
		PrintInstructions();
		return -1;
	}

	if (std::wstring(argv[1]) != L"-i")
	{
		std::wcout << L"Wrong 2nd argument\n";
		PrintInstructions();
		return -1;
	}

	std::wstring inputFile{ argv[2] };
	if (std::wstring(inputFile).find(L".json") == 0)
	{
		std::wcout << L"InputFile must be a json file.\n";
		PrintInstructions();
		return -1;
	}

	std::ifstream is{ inputFile };
	if (!is)
	{
		std::wcout << L"Failed to open inputFile\n";
		PrintInstructions();
		return -1;
	}

	bool verbose{};

	if (argc == 4)
	{
		if(std::wstring(argv[3]) == L"-v")
			verbose = true;
		else
		{
			std::wcout << L"Wrong 4th argument\n";
			PrintInstructions();
			return -1;
		}
	}

	if (argc == 5 || argc == 6)
	{
		if (std::wstring(argv[3]) != L"-o")
		{
			std::wcout << L"Wrong 4rd argument\n";
			PrintInstructions();
			return -1;
		}

		std::wstring outputFile{ argv[4] };

		if (outputFile.find(L".obj") == 0)
		{
			std::wcout << L"OutputFile must be an obj file.\n";
			PrintInstructions();
			return -1;
		}

		if (argc == 6)
		{
			if(std::wstring(argv[5]) == L"-v")
				verbose = true;
			else
			{
				std::wcout << L"Wrong 6th argument\n";
				PrintInstructions();
				return -1;
			}
		}

		JsonToObj(inputFile, outputFile, verbose);
	}
	else JsonToObj(inputFile, L"", verbose);

	std::cout << "Convertion completed\n";

	return 0;
}

void PrintInstructions()
{
	std::wcout << L"Possible commands:\n";
	std::wcout << L"\tMinecraftTool -i inputFileName.json\n";
	std::wcout << "\tMinecraftTool -i inputFileName.json -o outputFileName.obj\n";
	std::wcout << "After the previous 2 commands you can use -v this will give you more info of what is happening while converting the file.\n";
}