#pragma once
#include "MemoryAllocator.h"

namespace dae
{
	class StackAllocator final : public MemoryAllocator
	{
	public:
		explicit StackAllocator(size_t);
		~StackAllocator() = default;

		StackAllocator(const StackAllocator&) = delete;
		StackAllocator(StackAllocator&&) = delete;
		StackAllocator& operator= (const StackAllocator&) = delete;
		StackAllocator& operator= (const StackAllocator&&) = delete;

		void* Acquire(size_t = 0) override;
		void Release(void*) override;
		void* GetMarker();
		void FreeToMarker();

	private:

	};
}
