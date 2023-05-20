#pragma once
#include "MemoryAllocator.h"

namespace dae
{
	class FixedSizeAllocator final : public MemoryAllocator
	{
	public:
		explicit FixedSizeAllocator(size_t, size_t);
		~FixedSizeAllocator();

		FixedSizeAllocator(const FixedSizeAllocator&) = delete;
		FixedSizeAllocator(FixedSizeAllocator&&) = delete;
		FixedSizeAllocator& operator= (const FixedSizeAllocator&) = delete;
		FixedSizeAllocator& operator= (const FixedSizeAllocator&&) = delete;

		void* Acquire(size_t = 0) override;
		void Release(void*) override;

	private:
		struct Block
		{
			union
			{
				Block* next;
				char* data{ nullptr };
			};

			void SetSize(int size)
			{
				if(data)
					delete data;

				data = new char[size];
			}
		};

		size_t nbBlocks;
		size_t blockSize;
		Block* pool;
		Block* head;
	};
}

