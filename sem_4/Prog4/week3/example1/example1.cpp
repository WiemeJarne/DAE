// example1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

struct Float3f
{
    float x, y, z;
};

int main()
{
    std::string pod = std::is_pod<Float3f>::value == 1 ? "yes" : "no";
    std::cout << "Is the Float3 struct a pod : " << pod << '\n';

    Float3f toWrite;
    toWrite.x = 5.2f;
    toWrite.y = 5.1f;
    toWrite.z = 9.1f;   

    std::ofstream temp;
    temp.open("test.bin", std::ios::binary);

    if (temp.is_open())
    {
        temp.write((const char*)&toWrite, sizeof(toWrite));
        temp.close();
    }

    Float3f toRead;
    std::ifstream input;
    input.open("test.bin", std::ios::binary);
    if(input.is_open())
    {
        input.read((char*)&toRead, sizeof(toRead));
        assert(toRead.x == toWrite.x);
        assert(toRead.y == toWrite.y);
        assert(toRead.z == toWrite.z);
        input.close();
    }

    std::cout << "original float3 : [" << toWrite.x << ", " << toWrite.y << ", " << toWrite.z << "]\n";
    std::cout << "read float3 : [" << toRead.x << ", " << toRead.y << ", " << toRead.z << "]\n";
}