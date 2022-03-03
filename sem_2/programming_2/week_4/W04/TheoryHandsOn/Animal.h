#pragma once
class Animal
{
public:
	enum class AnimalType{animal, cat, dog};
	Animal(AnimalType animalType);
	virtual ~Animal( );
	virtual void MakeSound( ) const; 
	AnimalType GetAnimalType() const;

private:
	const AnimalType m_AnimalType;
};