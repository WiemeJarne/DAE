#pragma once
#include<memory>
#include<iostream>
#include<cassert>

template <typename T>
struct Node
{
	std::shared_ptr<Node> previous{nullptr};
	T value{};
};

template <typename T>
class LinkedListStack
{
public:
	void Push(T value)
	{
		auto newNode{std::make_shared<Node<T>>()};
		newNode->value = value;
		newNode->previous = m_TopNode;

		m_TopNode = newNode;
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