#include "FixedSizeAllocator.h"
#include <stdexcept>

dae::FixedSizeAllocator::FixedSizeAllocator(size_t sizeInBytes, size_t _blockSize)
	: nbBlocks{ (sizeInBytes + sizeof(Block) - 1) / sizeof(Block) }
	, blockSize{ _blockSize }
	, pool{ new Block[nbBlocks + 1] }
	, head{ pool }
{
	for (int index{}; index < nbBlocks; ++index)
	{
		pool[index].SetSize(static_cast<int>(_blockSize));
	}

	Block* first = pool + 1;
	first->next = nullptr;

	head->next = first;
}

dae::FixedSizeAllocator::~FixedSizeAllocator()
{
	delete pool;
}

void* dae::FixedSizeAllocator::Acquire(size_t)
{
	auto previousBlock = head;
	auto nextBlock = head->next;
	
	while (nextBlock != nullptr && nextBlock != head + nbBlocks)
	{
		previousBlock = nextBlock;
		nextBlock = nextBlock->next;
	}

	if (nextBlock == head + nbBlocks) //all blocks are ocupied
		throw std::runtime_error("out of memory");

	previousBlock->next = nextBlock->next;

	return nextBlock->data;
}

void dae::FixedSizeAllocator::Release(void* pointerToBuffer)
{
	Block* block = reinterpret_cast<Block*> (pointerToBuffer) - 1;

	if (block < pool || block > pool + nbBlocks)
		throw std::runtime_error("invalid block");

	auto previousBlock = head;
	auto current = previousBlock->next;

	while (current != nullptr && current < block)
	{
		previousBlock = current;
		current = current->next;
	}

	if (current != nullptr && block == current)
		block->next = current->next;
	else
		block->next = current;

	if (previousBlock == block)
		previousBlock->next = block->next;
	else
		previousBlock->next = block;
}