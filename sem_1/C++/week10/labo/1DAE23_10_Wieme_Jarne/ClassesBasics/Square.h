#pragma once
class Square
{
public:
	//constructors an destructor
	Square(float size);
	Square(float size, float left, float bottom);
	~Square();

	//public member functions
	void Print();
	void Translate(float deltaLeft, float deltaBottom);
	void SetSize(float newSize);

private:
	//private member functions
	float GetArea();
	float GetPerimeter();

	//private datamembers
	float m_Left;
	float m_Bottom;
	float m_Size;
};