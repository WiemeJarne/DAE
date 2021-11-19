// IterationsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <math.h>

void EvenNumbers();
void ExamScores();
void RandomGuess();
void Trignometry();
void ASCIITable();

int main()
{
    EvenNumbers();
    ExamScores();
    RandomGuess();
    Trignometry();
    ASCIITable();
}

void EvenNumbers()
{
    for (int number{ 2 }; number <= 24; number += 2)
    {
        std::cout << number << " ";
    }

    std::cout << "\n";

    int number{ 0 };

    while (number < 24)
    {
        number += 2;
        std::cout << number << " ";
    }

    std::cout << "\n";

    number = 0;

    do
    {
        number += 2;
        std::cout << number << " ";
    } while (number < 24);

    std::cout << "\n\n";
}

void ExamScores()
{
    std::string scoreLog{ "" };
    
    int amountOfAPlus{ 0 };
    int amountOfA{ 0 };
    int amountOfB{ 0 };
    int amountOfC{ 0 };
    int amountOfD{ 0 };
    int amountOfE{ 0 };
    int amountOfFX{ 0 };
    int amountOfF{ 0 };

    int totalScore{ 0 };

    bool isRunning{ true };

    while (isRunning == true)
    {
        int score{};
        std::cout << "Score [0,20]? ";
        std::cin >> score;

        if (20 >= score && score >= 18)
        {
            ++amountOfAPlus;
        }

        if (17 >= score && score >= 16)
        {
            ++amountOfA;
        }

        if (score == 15)
        {
            ++amountOfB;
        }

        if (14 >= score && score >= 13)
        {
            ++amountOfC;
        }

        if (12 >= score && score >= 11)
        {
            ++amountOfD;
        }

        if (score == 10)
        {
            ++amountOfE;
        }

        if (9 >= score && score >= 8)
        {
            ++amountOfFX;
        }

        if (7 >= score && score >= 0)
        {
            ++amountOfF;
        }

        if (score == -1)
        {
            std::cout << "A+: " << amountOfAPlus << '\n'
                << "A: " << amountOfA << '\n'
                << "B: " << amountOfB << '\n'
                << "C: " << amountOfC << '\n'
                << "D: " << amountOfD << '\n'
                << "E: " << amountOfE << '\n'
                << "FX: " << amountOfFX << '\n'
                << "F: " << amountOfF << '\n';

            std::cout << "Total score: " << totalScore << "\nEntered scores: " << scoreLog;
            isRunning = false;
        }
        else if (score < -1 || score > 20)
        {
            std::cout << "Wrong score!\n";
            score = 0;
        }

        totalScore += score;
        std::string scoreString{ std::to_string(score) };
        scoreLog += scoreString;
        scoreLog += ", ";
    }
}

void RandomGuess()
{
    int numberOfGuesses{};
    int number{};
    int numberToGuess{};

    std::cout << "\n\nNumber to guess? ";
    std::cin >> numberToGuess;

    if (numberToGuess > 32767 || numberToGuess < 0)
    {
        std::cout << "\nThis is a wrong number. ";
        RandomGuess();
    }
    else
    {
        do
        {
            number = rand();
            numberOfGuesses++;
        } while (numberToGuess != number);
        std::cout << "\nNumber found after " << numberOfGuesses << " guesses\n";
    }
}

void Trignometry()
{
    std::cout << "\n";
    std::cout << std::setw(10) << "Degrees";
    std::cout << std::setw(10) << "Readians";
    std::cout << std::setw(10) << "Cos";
    std::cout << std::setw(10) << "Sin";
    std::cout << "\n";

    for (float angle{ 0.f }; angle <= 180; angle += 10)
    {
        std::cout << std::fixed;

        std::cout << std::setw(10) << std::setprecision(0) << angle;

        std::cout << std::setw(10) << std::setprecision(2) << angle * (M_PI / 180.f);

        std::cout << std::setw(10) << std::setprecision(2) << cosf( float(angle * (M_PI / 180.f)) );

        std::cout << std::setw(10) << std::setprecision(2) << sinf( float(angle * (M_PI / 180.f)) );
        std::cout << "\n";
    }   
}

void ASCIITable()
{
    std::cout << "\n";

    for (int asciiValue{ 97 }; asciiValue <= 109; ++asciiValue)
    {
        std::cout << std::setw(2) << char(asciiValue);
        std::cout << std::setw(7) << asciiValue;
        std::cout << std::setw(4) << char(asciiValue + 13);
        std::cout << std::setw(7) << (asciiValue + 13);
        std::cout << "\n";
    }
}