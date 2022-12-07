#pragma once
#include<memory>
#include<iostream>
#include<cassert>

template <typename T>
struct Node
{
	Node(const T& value, std::shared_ptr<Node> previous)
		: value{ value }, previous{ previous }
	{
	}

	std::shared_ptr<Node> previous;
	T value;
};

template <typename T>
class LinkedListStack
{
public:
	void Push(const T& value)
	{
		m_TopNode = std::make_shared<Node<T>>(value, m_TopNode);
	}

	T Pop()
	{
		//assert when this function gets called on an empty stack
		assert(m_TopNode.get() && "calling Pop() on an empty linkedListStack");

		T returnValue{ m_TopNode->value };
		
		m_TopNode = m_TopNode->previous; //assign the new topNode to the node below the topNode

		return returnValue;
	}

private:
	std::shared_ptr<Node<T>> m_TopNode{ nullptr };
};