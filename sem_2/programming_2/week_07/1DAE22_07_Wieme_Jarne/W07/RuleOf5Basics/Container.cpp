#include "pch.h"
#include "Container.h"
#include <cassert>

Container::Container( int capacity ) 
	: m_Size{ 0 }
	, m_Capacity{ capacity }
	, m_pElement{ new int[capacity] }
{
}

Container::Container(const Container& container)
	:Container(container.Capacity())
{
	for (int index{}; index < m_Size; ++index)
	{
		m_pElement[index] = container[index];
	}
}

Container::Container(Container&& container) noexcept
	:m_Size{ container.m_Size }
	,m_Capacity { container.m_Capacity }
	,m_pElement { container.m_pElement }
{
	container.m_Size = 0;
	container.m_Capacity = 0;
	container.m_pElement = nullptr;
}

Container::~Container( ) 
{ 
	delete[] m_pElement; 
}

Container& Container::operator=(const Container& rhs)
{
	if (m_pElement != rhs.m_pElement)
	{
		for (int index{}; index < rhs.m_Size; ++index)
		{
			m_pElement[index] = rhs[index];
		}
	}

	return *this;
}

Container& Container::operator=(Container&& rhs) noexcept
{
	if (&rhs != this)
	{
		delete[] m_pElement;

		m_Size = rhs.m_Size;
		m_Capacity = rhs.m_Capacity;
		m_pElement = rhs.m_pElement;
		
		rhs.m_Size = 0;
		rhs.m_Capacity = 0;
		rhs.m_pElement = nullptr;
	}
	return *this;
}

int Container::Size( ) const
{ 
	return m_Size; 
}

int Container::Capacity( ) const
{
	return m_Capacity;
}

int Container::Get( int index ) const
{
	assert( index >= 0 && index < m_Size );
	return m_pElement[index];
}

void Container::Set( int index, int value )
{
	assert( index >= 0 && index < m_Size );
	m_pElement[index] = value;
}

void Container::PushBack( int value )
{
	if ( !( m_Size < m_Capacity ) )
	{
		Reserve( m_Capacity * 2  + 1);
	}
	m_pElement[m_Size] = value;
	++m_Size;
}

//int Container::operator[](int index) const
int& Container::operator[](int index) 
{
	assert(index >= 0 && index < m_Size);
	return m_pElement[index];
}

int Container::operator[](int index) const
{
	assert(index >= 0 && index < m_Size);
	return m_pElement[index];
}

void Container::Reserve( int newCapacity )
{
	if ( newCapacity <= m_Capacity )
	{
		return;
	}

	// Dynamically allocate memory
	int * pNew = new int[newCapacity] {};
	// Copy the elements into this new memory
	for ( int i{ 0 }; i < m_Size; ++i )
	{
		pNew[i] = m_pElement[i];
	}
	// Free the old memory
	delete[] m_pElement;

	// Adapt the data members to this new situation
	m_pElement = pNew;
	m_Capacity = newCapacity;
}