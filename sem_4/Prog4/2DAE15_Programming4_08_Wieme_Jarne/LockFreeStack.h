#pragma once
#include <intrin.h>

class PoppedOnEmptyStackException {};

template<typename T>
class LockFreeStack final
{
public:
   
    LockFreeStack() = default;

    ~LockFreeStack() = default;
    LockFreeStack(const LockFreeStack& other) = delete;
    LockFreeStack(LockFreeStack&& other) = delete;
    LockFreeStack& operator=(const LockFreeStack& other) = delete;
    LockFreeStack& operator=(LockFreeStack&& other) = delete;

    void Push(T value)
    {
        Node* pNode{ new Node(value) };

        while (true)
        {
            pNode->pNext = pHead;

            if (_InterlockedCompareExchangePointer(reinterpret_cast<void**>(&pHead), reinterpret_cast<void*>(pNode), reinterpret_cast<void*>(pNode->pNext)))
                break;
        }
    }

    T Pop()
    {
        Node* pOriginalHead{};

        while (true)
        {
            //if pHead is a nullptr the stack is empty so throw exception
            if (!pHead)
                throw(PoppedOnEmptyStackException());

            pOriginalHead = pHead;

            if (_InterlockedCompareExchangePointer(reinterpret_cast<void**>(&pHead), reinterpret_cast<void*>(pHead->pNext), reinterpret_cast<void*>(pOriginalHead)))
            {
                T value{ pOriginalHead->value };
                delete pOriginalHead;

                return value;
            }
        }
    }

private:
    struct Node
    {
        Node(T _value)
            : value{ _value }
            , pNext{ nullptr }
        {}

        T value{};
        Node* pNext{};
    };

    Node* pHead{};
};