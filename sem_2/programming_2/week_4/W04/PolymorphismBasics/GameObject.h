#pragma once
#include<string>

class GameObject
{
public:
	GameObject(int id );
	virtual ~GameObject( );
	
	virtual std::string ToString( ) const;
	// Implicitly defined copy/move constructors and operator= are ok

protected:
	int m_Id;

private: 
};



