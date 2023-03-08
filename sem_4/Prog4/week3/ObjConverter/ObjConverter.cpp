// ObjConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <vector>

int main()
{
    std::string filePath{ "Resources/Bunny.obj" };

    std::ifstream inputFile{ filePath };

    if (!inputFile.is_open())
    {
        assert("failed to open file");
    }

    std::ofstream outputFile{ "output.bobj", std::ios::binary };

    if (!outputFile.is_open())
    {
        assert("failed to open output file");
    }

    //read the file
    std::string command{};
    while (!inputFile.eof())
    {
        inputFile >> command;

        if (command == "v")
        {
            //read in the 3 floats
            float x, y, z;

            inputFile >> x >> y >> z;

            //write to the binary file
            outputFile.write((const char*)&x, sizeof(x));
            outputFile.write((const char*)&y, sizeof(y));
            outputFile.write((const char*)&z, sizeof(z));
        }
        else if (command == "f")
        {
            //read in 3 ints
            int x, y, z;
            
            inputFile >> x >> y >> z;

            //write to the binary file
            outputFile.write((const char*)&x, sizeof(x));
            outputFile.write((const char*)&y, sizeof(y));
            outputFile.write((const char*)&z, sizeof(z));
        }
    }
}
