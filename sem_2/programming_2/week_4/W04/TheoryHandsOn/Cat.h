#pragma once
#include "Animal.h"

class Cat final : public Animal
{
public:
	Cat( );
    virtual ~Cat( );
    virtual void MakeSound() const override;
	void SetNightVision(bool b);
private:
	bool m_NightVision;
};