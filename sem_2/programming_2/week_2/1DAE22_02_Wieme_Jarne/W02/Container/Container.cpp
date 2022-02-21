#include "pch.h"
#include "Container.h"

Container::Container(int capacity)
	:m_Size{}
	,m_Capacity{capacity}
	,m_pElement{new int[capacity]}
{

}

Container::~Container()
{
	delete[] m_pElement;
}

int Container::Size() const
{
	return m_Size;
}

int Container::Capacity() const
{
	return m_Capacity;
}

int Container::Get(int index) const
{
	return m_pElement[index];
}

void Container::Set(int index, int newValue)
{
	m_pElement[index] = newValue;
}

void Container::PushBack(int element)
{
	++m_Size;

	if (m_Capacity == m_Size)
	{

	}

	m_pElement[m_Size - 1] = element;
}

void Container::Reverse(int NewCapacity)
{

}