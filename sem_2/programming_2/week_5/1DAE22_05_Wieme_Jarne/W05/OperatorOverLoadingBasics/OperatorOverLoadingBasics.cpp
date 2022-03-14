// 1DAE22 Wieme Jarne
#include "pch.h"

// Includes
#include <ctime>
#include <iostream>
#include <cassert>
#include <sstream>
#include "Health.h"
#include "Container.h"


// Test function declarations
void TestHealthClass( );
void TestContainerClass( );
//void PrintContainer( const Container &container );


// Your code that uses the operators
void UseHealthOperators( );
void UseContainerOperators( );


int main( )
{
	srand(int(time(nullptr)));
	

	
	//TestHealthClass( );
	//UseHealthOperators();

	TestContainerClass( );
	UseContainerOperators( );

	std::cout << "Push ENTER to quit\n";
	std::cin.get( );
	return 0;
}

// Functions definitions
void UseHealthOperators( )
{
	// similar operations should be possible with the health class
	int nr1{ 2 };
	int nr2{ 3 };
	int nr3{};
	nr1 += nr2;
	nr3 = nr1 += nr2;
	nr3 += nr2 += nr1;
	nr3 += nr2 += nr1;

	Health health1{ 2 };
	Health health2{ 3 };
	health1 += health2;
	std::cout << health1.GetValue() << '\n';

	health1 = 2;
	health2 = 3;
	health1 -= health2;
	std::cout << health1.GetValue() << '\n';

	nr1 = 2;
	health1 = 3;
	nr2 = nr1 + health1;
	std::cout << nr2 << '\n';

	nr1 = 2;
	health1 = 3;
	nr2 = nr1 - health1;
	std::cout << nr2 << '\n';

	health1 = 2;
	nr1 = 3;
	health2 = health1 + nr1;
	std::cout << health2.GetValue() << '\n';

	health1 = 2;
	nr1 = 3;
	health2 = health1 - nr1;
	std::cout << health2.GetValue() << '\n';
}
void UseContainerOperators( )
{
	const int size{ 3 };
	Container container{ size };
	
	container.PushBack(4);
	container.PushBack(8);
	container.PushBack(2);

	std::cout << container[1] << '\n';

	container[1] = 5;
	std::cout << container[1] << '\n';
}

void TestHealthClass()
{
	// Initialize
	int healthValue{ 0 };
	Health healthObject{ healthValue };
	int randValue{};
	int testCntr{};

	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: Health += int \n";
	// Positive integer
	randValue = rand() % 100 + 1;
	healthObject += randValue;
	healthValue += randValue;
	assert(healthObject.GetValue() == healthValue);
	// Negative integer
	randValue = -(rand() % 10 + 1);
	healthObject += randValue;
	healthValue += randValue;
	assert(healthObject.GetValue() == healthValue);
	// Test result of +=
	assert((healthObject += randValue).GetValue() == (healthValue += randValue));
	// Checking return is Health&
	int randValue1 = rand() % 5 + 1; //[1,5]
	int randValue2 = rand() % 5 + 6; // [6,10]
	(healthObject += randValue1) += randValue2;
	(healthValue += randValue1) += randValue2;
	assert(healthObject.GetValue() == healthValue);
	std::cout << "ok\n";


	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: Health -= int \n";
	// Positive integer
	randValue = rand() % 100 + 1;
	healthObject -= randValue;
	healthValue -= randValue;
	assert(healthObject.GetValue() == healthValue);
	// Negative integer
	randValue = -(rand() % 10 + 1);
	healthObject -= randValue;
	healthValue -= randValue;
	assert(healthObject.GetValue() == healthValue);
	// Test result of -=
	assert((healthObject -= randValue).GetValue() == (healthValue -= randValue));
	// Checking return is Health&
	(healthObject -= randValue1) -= randValue2;
	(healthValue -= randValue1) -= randValue2;
	assert(healthObject.GetValue() == healthValue);
	std::cout << "ok\n";


	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: int + Health\n";
	// Positive integer
	randValue = rand() % 100 + 1;
	randValue + healthObject;
	assert(healthObject.GetValue() == healthValue);
	healthObject = randValue + healthObject;
	healthValue = randValue + healthValue;
	assert(healthObject.GetValue() == healthValue);
	// Negative integer
	randValue = -(rand() % 10 + 1);
	healthObject = randValue + healthObject;
	healthValue = randValue + healthValue;
	assert(healthObject.GetValue() == healthValue);
	std::cout << "ok\n";


	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: int - Health\n";
	// Positive integer
	randValue = rand() % 100 + 1;
	randValue - healthObject;
	assert(healthObject.GetValue() == healthValue);
	healthObject = randValue - healthObject;
	healthValue = randValue - healthValue;
	assert(healthObject.GetValue() == healthValue);
	// Negative integer
	randValue = -(rand() % 10 + 1);
	healthObject = randValue - healthObject;
	healthValue = randValue - healthValue;
	assert(healthObject.GetValue() == healthValue);
	std::cout << "ok\n";


	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: Health + int \n";
	// Positive integer
	randValue = rand() % 100 + 1;
	healthObject + randValue;
	assert(healthObject.GetValue() == healthValue);
	healthObject = healthObject + randValue;
	healthValue = healthValue + randValue;
	assert(healthObject.GetValue() == healthValue);
	// Negative integer
	randValue = -(rand() % 10 + 1);
	healthObject = healthObject + randValue;
	healthValue = healthValue + randValue;
	assert(healthObject.GetValue() == healthValue);
	std::cout << "ok\n";


	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: Health - int \n";
	// Positive integer
	randValue = rand() % 100 + 1;
	healthObject - randValue;
	assert(healthObject.GetValue() == healthValue);
	healthObject = healthObject - randValue;
	healthValue = healthValue - randValue;
	assert(healthObject.GetValue() == healthValue);
	// Negative integer
	randValue = -(rand() % 10 + 1);
	healthObject = healthObject - randValue;
	healthValue = healthValue - randValue;
	assert(healthObject.GetValue() == healthValue);
	std::cout << "ok\n";
}

void TestContainerClass()
{
	// Initialize
	const int cap{ 5 };
	Container container{ cap };
	for (int nr{ 1 }; nr <= cap; ++nr)
	{
		container.PushBack(rand() % 20 + 1);
	}
	int testCntr{};

	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: Container[idx] to get an element\n";
	for (int idx{ 0 }; idx < container.Size(); ++idx)
	{
		assert(container[idx] == container.Get(idx));
	}
	std::cout << "ok\n";

	++testCntr;
	std::cout << "\n==> " << testCntr << ". Test of: Container[idx] to assign a new value to an element\n";
	for (int idx{ 0 }; idx < container.Size(); ++idx)
	{
		container[idx] = rand() % 20 + 1;
		assert(container[idx] == container.Get(idx));
	}
	std::cout << "ok\n";

	//++testCntr;
	//std::cout << "\n==> " << testCntr << ". Test of: Container[idx] to get an element of a const Container\n";
	//PrintContainer(container);
}

//void PrintContainer(const Container &container)
//{
//	for (int idx{ 0 }; idx < container.Size(); ++idx)
//	{
//		std::cout << container[idx] << " ";
//	}
//	std::cout << "\nok\n";
//}

