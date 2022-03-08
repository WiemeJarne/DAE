#pragma once
#include "GameObject.h"
#include <string>


class Weapon : public GameObject
{
public:
	Weapon( );
	virtual ~Weapon( ); 

	virtual std::string ToString( ) const override;

private:
	static int m_InstanceCounter;
};