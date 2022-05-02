#include "pch.h"
//#include "Container.h"
//#include <cassert>
//#include <iostream>

//Container::Container( int capacity ) 
//	: m_Size{ 0 }
//	, m_Capacity{ capacity }
//	, m_pElements{ new int[capacity] }
//{
//}

//Container::Container(const std::initializer_list<int>& list)
//	:Container(list.size( ))
//{
//	for (int element : list)
//	{
//		PushBack(element);
//	}
//}

//Container::Container( const Container& other )
//	: m_Size{ 0 }
//	, m_Capacity{ other.m_Capacity }
//	, m_pElements{ new int[other.m_Capacity] }
//{
//	// Copy the elements
//	for ( int idx{}; idx < other.m_Size; ++idx )
//	{
//		PushBack( other[idx] );
//	}
//}

//Container& Container::operator=( const Container& other )
//{
//	if ( this != &other  )// no self assignment
//	{
//		// Delete dyn allocated memory and create new
//		delete[] m_pElements;
//		m_pElements = new int[other.m_Capacity];
//		m_Capacity = other.m_Capacity;
//		m_Size = 0;
//
//		// Copy the elements
//		for ( int idx{}; idx < other.m_Size; ++idx )
//		{
//			PushBack( other[idx] );
//		}
//	}
//	return *this;
//}

//Container::Container( Container&& other ) noexcept
//	: m_Size{ other.m_Size }
//	, m_Capacity{ other.m_Capacity }
//	, m_pElements{ other.m_pElements }
//{
//	other.m_Capacity = 0;
//	other.m_Size = 0;
//	other.m_pElements = nullptr;
//}

//Container& Container::operator=( Container&& other )noexcept
//{
//	if (this != &other)// no self assignment
//	{
//		m_Size = other.m_Size;
//		m_Capacity = other.m_Capacity;
//		delete[] m_pElements;
//		m_pElements = other.m_pElements;
//
//		other.m_Size = 0;
//		other.m_pElements = nullptr;
//		other.m_Capacity = 0;
//	}
//	return *this;  
//}

//Container::~Container( ) 
//{ 
//	delete[] m_pElements;
//	m_pElements = nullptr;
//}

//int Container::Size( ) const
//{ 
//	return m_Size; 
//}
//
//int Container::Capacity( ) const
//{
//	return m_Capacity;
//}
//
//int Container::Get( int index ) const
//{
//	assert( index >= 0 && index < m_Size );
//	return m_pElements[index];
//}
//
//void Container::Set( int index, int value )
//{
//	assert( index >= 0 && index < m_Size );
//	m_pElements[index] = value;
//}
//
//void Container::PushBack( int value )
//{
//	if ( !( m_Size < m_Capacity ) )
//	{
//		Reserve( m_Capacity * 2 );
//	}
//	m_pElements[m_Size] = value;
//	++m_Size;
//}
//
//int& Container::operator[]( int index )
//{
//	assert( index >= 0 && index < m_Size );
//	return m_pElements[index];
//}
//
//const int& Container::operator[]( int index ) const
//{
//	assert( index >= 0 && index < m_Size );
//	return m_pElements[index];
//}
//
//void Container::Reserve( int newCapacity )
//{
//	if ( newCapacity <= m_Capacity )
//	{
//		return;
//	}
//
//	// Dynamically allocate memory
//	int* pCopiedElements = new int[newCapacity] {};
//	// Copy the elements into this new memory
//	for ( int i{ 0 }; i < m_Size; ++i )
//	{
//		pCopiedElements[i] = m_pElements[i];
//	}
//	// Free the old memory
//	delete[] m_pElements;
//
//	// Adapt the data members to this new situation
//	m_pElements = pCopiedElements;
//	m_Capacity = newCapacity;
//}