// demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void Add(int value1, int value2);

int main(int argc, char* argv[]) //argc = argument count, argv = argument vector
{
    if (argc < 4 || argc > 4)
    {
        std::cout << "usage: operater value1 value2\n";
        std::cout << "value1 and value 2 must be integers\n";
    }

    if(reinterpret_cast<int>(argv[2]) > )
  
    
        /*if (*argv[1] == '+')
        {
            Add(std::stoi(argv[2]), std::stoi(argv[3]));
        }*/
 }

void Add(int value1, int value2)
{
    std::cout << value1 + value2 << '\n';
}