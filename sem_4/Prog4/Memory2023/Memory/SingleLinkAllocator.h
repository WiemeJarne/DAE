#pragma once
#include "MemoryAllocator.h"

namespace dae
{
	class SingleLinkAllocator final : public MemoryAllocator
	{
		struct Header
		{
			size_t count;
		};
		struct Block : Header
		{
			const static int size = 16; // this is a different value for x64/Win32 targets;
			union
			{
				Block* next;
				char data[size - sizeof(Header)];
			};
		};

		size_t nbBlocks;
		Block* pool;
		Block* head;

		static void FillAllocatedBlock(Block* block, size_t nbBytes);

	public:
		explicit SingleLinkAllocator(size_t);
		virtual ~SingleLinkAllocator();

		void * Acquire(size_t nbBytes) override;
		void Release(void *) override;

		// remove default copy & move constructors/assignment operators
		SingleLinkAllocator(const SingleLinkAllocator &) = delete;
		SingleLinkAllocator(SingleLinkAllocator &&) = delete;
		SingleLinkAllocator & operator= (const SingleLinkAllocator &) = delete;
		SingleLinkAllocator & operator= (const SingleLinkAllocator &&) = delete;
	};
}
