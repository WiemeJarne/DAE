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
	Node* pNext{ m_pFirstNode };
	while (pNext != nullptr)
	{
		Node* pTemp = pNext;
		pNext = pNext->pNext;
		delete pTemp;
	}
}

// Wrap the value in a new Node object and add it as first Node of the list
void LinkedList::PushFront(int  value)
{
	Node* newNode{ new Node{value, m_pFirstNode} };
	m_pFirstNode = newNode;
	++m_Size;
}

// Remove and delete first Node
void LinkedList::PopFront()
{
	if (m_pFirstNode != nullptr)
	{
		Node* pSecondNode = m_pFirstNode->pNext;
		delete m_pFirstNode;
		m_pFirstNode = pSecondNode;
		--m_Size;
	}
}

// Remove all Nodes having this value
void LinkedList::Remove(int value)
{
	Node* pBefore{ nullptr };
	Node* node{ m_pFirstNode };

	while (node != nullptr)
	{
		if (node->value == value)
		{
			if (node == m_pFirstNode)
			{
				m_pFirstNode = node->pNext;
			}
			else
			{
				pBefore->pNext = node->pNext;
			}

			Node* pTemp{ node };
			pBefore = node;
			node = node->pNext;
			delete pTemp;
			--m_Size;
		}
		else
		{
			pBefore = node;
			node = node->pNext;
		}	
	}
}

// Wrap the value in a new Node object and insert it after the specified Node 
void LinkedList::InsertAfter(Node* pBefore, int value)
{
	Node* newNode{ new Node{value, pBefore->pNext} };
	pBefore->pNext = newNode;
	++m_Size;
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
	Node* pNext{ list.Begin( ) };
	while (pNext != nullptr)
	{
		out << pNext->value << " ";
		pNext = pNext->pNext;
	}
	
	return out;
}