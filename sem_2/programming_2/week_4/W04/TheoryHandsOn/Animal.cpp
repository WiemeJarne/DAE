#include "pch.h"			
#include "Animal.h"

Animal::Animal(AnimalType animalType)
	:m_AnimalType{animalType}
{
	std::cout << "Animal constructor\n";
}

Animal::~Animal()
{
	std::cout << "Animal destructor\n";
}

void Animal::MakeSound() const
{
	std::cout <<"I am an Animal, I have no idea what sound to make!\n";
}

Animal::AnimalType Animal::GetAnimalType() const
{
	return m_AnimalType;
}