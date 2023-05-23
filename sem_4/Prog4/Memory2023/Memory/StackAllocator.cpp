#include "StackAllocator.h"

dae::StackAllocator::StackAllocator(size_t)
{

}

void* dae::StackAllocator::Acquire(size_t )
{
	return nullptr;
}

void dae::StackAllocator::Release(void*)
{

}

void* dae::StackAllocator::GetMarker()
{
	return nullptr;
}

void dae::StackAllocator::FreeToMarker()
{

}