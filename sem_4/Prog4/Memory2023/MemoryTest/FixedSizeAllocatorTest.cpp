#include "CppUnitTest.h"
#include "..\Memory\MemoryOverrides.h"
#include "..\Memory\FixedSizeAllocator.h"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dae
{
	const size_t allocator_size = 1024;
	const size_t pointer_size = sizeof(void*); // this is a different value for x64/Win32 targets
	const int block_size = 8;

	class Object
	{
	public:
		int m_interger{ 0 };
		float m_float{ 0 };
	};

	TEST_CLASS(FixedSizeAllocatorTest)
	{
	public:

		TEST_METHOD(SingleAllocation)
		{
			FixedSizeAllocator allocator(allocator_size, block_size);

			void* pointer;
			pointer = allocator.Acquire();
			Assert::IsNotNull(pointer);
			allocator.Release(pointer);
		}
	};
}