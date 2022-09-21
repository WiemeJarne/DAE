// demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

void PrintHelp();
void Add(int value1, int value2);
void Substract(int value1, int value2);
void Multiply(int value1, int value2);
void Divide(int value1, int value2);
void Power(int value1, int power);

int main(int argc, char* argv[]) //argc = argument count, argv = argument vector
{
    if (argc < 4 || argc > 4)
    {
        PrintHelp();
    }

    if (    *argv[1] < 58 && *argv[1] > 47 
         && *argv[3] < 58 && *argv[3] > 47)  //using ascii value to check if value1 and value2 are numbers
    {
        switch (*argv[2])
        {
        case '+':
            Add(std::stoi(argv[1]), std::stoi(argv[3]));
            break;
        case '-':
            Substract(std::stoi(argv[1]), std::stoi(argv[3]));
            break;
        case '*':
            Multiply(std::stoi(argv[1]), std::stoi(argv[3]));
            break;
        case '/':
            Divide(std::stoi(argv[1]), std::stoi(argv[3]));
            break;
        case'p':
            Power(std::stoi(argv[1]), std::stoi(argv[3]));
            break;
        }
    }
    else
    {
        PrintHelp();
    }
 }

void PrintHelp()
{
    std::cout << "usage: value1 operater value2\n";
    std::cout << "value1 and value2 must be integers\n";
    std::cout << "Possible operators: + - * / p(for power)";
}

void Add(int value1, int value2)
{
    std::cout << value1 + value2 << '\n';
}

void Substract(int value1, int value2)
{
    std::cout << value1 - value2 << '\n';
}

void Multiply(int value1, int value2)
{
    std::cout << value1 * value2 << '\n';
}

void Divide(int value1, int value2)
{
    if (value2 == 0)
    {
        std::cout << "Can't divide by zero.\n";
    }
    else
    {
        int remainder{ value1 % value2 };

        if (remainder == 0)
        {
            std::cout << value1 / value2 << '\n';
        }
        else
        {
            std::cout << value1 / value2 << " with a remainder of " << remainder << '\n';
        }
    }
}

void Power(int value1, int power)
{
    std::cout << pow(value1, power) << '\n';
}