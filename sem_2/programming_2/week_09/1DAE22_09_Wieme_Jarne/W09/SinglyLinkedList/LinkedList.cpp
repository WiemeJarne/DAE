#include "pch.h"
#include "LinkedList.h"

Node::Node(int value, Node* pNext)
	: value{ value }
	, pNext{ pNext }
{
}

LinkedList::LinkedList( )
	: m_pFirstNode{ nullptr }
	, m_Size{ }
{
}

LinkedList::~LinkedList()
{
}

// Wrap the value in a new Node object and add it as first Node of the list
void LinkedList::PushFront(int  value)
{

}

// Remove and delete first Node
void LinkedList::PopFront()
{
}

// Remove all Nodes having this value
void LinkedList::Remove(int value)
{
}

// Wrap the value in a new Node object and insert it after the specified Node 
void LinkedList::InsertAfter(Node* pBefore, int value)
{
}

// Return pointer to first Node
Node* LinkedList::Begin() const
{
	return m_pFirstNode;
}

// Return number of Node objects in the list
size_t LinkedList::Size() const
{
	return m_Size;
}

// Send the values of the list to the out object, use a space as element separator
std::ostream& operator<<(std::ostream& out, const LinkedList& list)
{
	return out;
}