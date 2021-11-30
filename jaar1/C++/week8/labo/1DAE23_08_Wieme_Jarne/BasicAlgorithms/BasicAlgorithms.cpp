//Wieme Jarne 1DAE23
// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int Count(int array[], const int arraySize, int userInput);
int MinElement(int array[], const int arraySize);
int MaxElement(int array[], const int arraySize);

void PrintArray(int array[], const int arraySize);
void Swap(int array[], const int arraySize, int indexFirstNumber, int indexSecondNumber);
void SwapWithoutPrinting(int array[], const int arraySize, int indexFirstNumber, int indexSecondNumber);
void Shuffle(int array[], const int arraySize, int numberOfSwaps);
void BubbleSort(int array[], int arraySize);
int GenerateRandomIndexes(int maxIndex);
void TestCount();
void TestMinMax();
void TestSwap();
void TestShuffle();
void TestBubbleSort();

const int g_ArraySize{ 10 };
int g_Array[g_ArraySize]{ 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };

int main()
{
	srand(time(nullptr));

	PrintArray(g_Array, g_ArraySize);
	TestCount();
	TestMinMax();
	TestSwap();
	TestShuffle();
	TestBubbleSort();
}

void PrintArray(int array[], const int arraySize)
{
	for (int index{}; index < arraySize; ++index)
	{
		std::cout << array[index] << " ";
	}
	std::cout << std::endl << std::endl;
}

int Count(int array[], const int arraySize, int userInput)
{
	int count{};
	for (int index{}; index < arraySize; ++index)
	{
		if (array[index] == userInput)
		{
			++count;
		}
	}
	return count;
}

void TestCount()
{
	std::cout << "Give a number\n";

	int number{};

	std::cin >> number;

	std::cout << number << " occurs " << Count(g_Array, g_ArraySize, number) << " times in this array\n\n";
}

int MinElement(int array[], const int arraySize)
{
	int minElement{array[0]};
	for (int index{}; index - 1 < arraySize; ++index)
	{
		if (array[index] < minElement)
		{
			minElement = array[index];
		}
	}
	return minElement;
}

int MaxElement(int array[], const int arraySize)
{
	int maxElement{array[0]};
	for (int index{}; index - 1 < arraySize; ++index)
	{
		if (array[index] > maxElement)
		{
			maxElement = array[index];
		}
	}
	return maxElement;
}

void TestMinMax()
{
	std::cout << MinElement(g_Array, g_ArraySize) << " is the smallest value in this array\n";
	std::cout << MaxElement(g_Array, g_ArraySize) << " is the largest value in this array\n\n";
}

void Swap(int array[], const int arraySize, int indexFirstNumber, int indexSecondNumber)
{
	int firstElement{ array[indexFirstNumber] };
	int lastElement{ array[indexSecondNumber] };
	
	array[indexFirstNumber] = lastElement;
	array[indexSecondNumber] = firstElement;

	PrintArray(array, arraySize);
}

void SwapWithoutPrinting(int array[], const int arraySize, int indexFirstNumber, int indexSecondNumber)
{
	int firstElement{ array[indexFirstNumber] };
	int lastElement{ array[indexSecondNumber] };

	array[indexFirstNumber] = lastElement;
	array[indexSecondNumber] = firstElement;
}

void TestSwap()
{
	Swap(g_Array, g_ArraySize, 0, 9);
}

void Shuffle(int array[], const int arraySize, int numberOfSwaps)
{
	for (int swapNumber{}; swapNumber < numberOfSwaps; ++swapNumber)
	{
		int randomNumber1{ GenerateRandomIndexes(arraySize) };
		int randomNumber2{ GenerateRandomIndexes(arraySize) };

		if (randomNumber1 == randomNumber2 && (0 < randomNumber1 && randomNumber1 < arraySize))
		{
			++randomNumber1;
		}
		else if (randomNumber1 == randomNumber2 && (0 < randomNumber2 && randomNumber2 < arraySize))
		{
			++randomNumber2;
		}

		SwapWithoutPrinting(array, arraySize, randomNumber1, randomNumber2);
	}
	PrintArray(array, arraySize);
}

int GenerateRandomIndexes(int maxIndex)
{
	int randomNumber = rand() % maxIndex;
}

void TestShuffle()
{
	int numberOfSwaps{ 5 };
	std::cout << "Before shuffling:\n";
	PrintArray(g_Array, g_ArraySize);
	std::cout << "Ater shuffling " << numberOfSwaps << " times:\n";
	Shuffle(g_Array, g_ArraySize, numberOfSwaps);
}

void BubbleSort(int array[], int arraySize)
{
	if(arraySize > 1)
	{
		for (int index{}; index < arraySize; ++index)
		{
			if (array[index] > array[index + 1])
			{
				SwapWithoutPrinting(array, arraySize, index, index + 1);
			}
		}
		BubbleSort(array, --arraySize);
	}
	else
	{
		PrintArray(array, g_ArraySize);
	}
}

void TestBubbleSort()
{
	std::cout << "Before sort:\n";
	PrintArray(g_Array, g_ArraySize);
	std::cout << "After sort:\n";
	BubbleSort(g_Array, g_ArraySize);
}