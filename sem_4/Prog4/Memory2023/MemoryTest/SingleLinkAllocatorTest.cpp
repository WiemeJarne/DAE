#include "CppUnitTest.h"
#include "..\Memory\MemoryOverrides.h"
#include "..\Memory\SingleLinkAllocator.h"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace dae
{
	const size_t allocator_size = 1024;
	const size_t pointer_size = sizeof(void*); // this is a different value for x64/Win32 targets

	class Object
	{
	public:
		int m_integer{ 0 };
		float m_float{ 0 };
	};

	TEST_CLASS(SingleLinkAllocatorTest)
	{
	public:
		
		TEST_METHOD(SingleAllocation)
		{
			SingleLinkAllocator allocator(allocator_size);

			const size_t test_size = allocator_size - pointer_size;
			void* pointer;
			pointer = allocator.Acquire(test_size);
			Assert::IsNotNull(pointer);
			std::memset(pointer, 1, test_size);
			allocator.Release(pointer);
		}

		TEST_METHOD(InvalidRelease)
		{
			SingleLinkAllocator allocator(allocator_size);

			void* pointer = new char;
			Assert::ExpectException<std::runtime_error>([&]() {allocator.Release(pointer);});
			delete pointer;
		}

		TEST_METHOD(TwoAllocations)
		{
			SingleLinkAllocator allocator(allocator_size);

			const size_t test_size = allocator_size / 2 - pointer_size;
			void* pointer_a{};
			void* pointer_b{};
			pointer_a = allocator.Acquire(test_size);
			pointer_b = allocator.Acquire(test_size);
			Assert::IsNotNull(pointer_a);
			Assert::IsNotNull(pointer_b);
			std::memset(pointer_a, 1, test_size);
			std::memset(pointer_b, 1, test_size);
			allocator.Release(pointer_a);
			allocator.Release(pointer_b);
		}

		TEST_METHOD(ManySmallAllocations)
		{
			SingleLinkAllocator allocator(allocator_size);

			const size_t nbPieces = allocator_size / 16;
			void** pointers = new void* [nbPieces];
			const size_t test_size = allocator_size / nbPieces - pointer_size;
			for (int i = 0; i < nbPieces; i++)
			{
				pointers[i] = allocator.Acquire(test_size);
				Assert::IsNotNull(pointers[i]);
				std::memset(pointers[i], 1, test_size);
			}
			for (int i = 0; i < nbPieces; i++)
				allocator.Release(pointers[i]);
			delete[] pointers;
		}

		TEST_METHOD(OutOfMemory)
		{
			SingleLinkAllocator allocator(allocator_size);
			const size_t test_size = allocator_size - pointer_size;
			void* pointer;
			pointer = allocator.Acquire(test_size);
			Assert::IsNotNull(pointer);
			std::memset(pointer, 1, test_size);
			Assert::ExpectException<std::runtime_error>([&]() {allocator.Acquire(16); });
			allocator.Release(pointer);
		}

		TEST_METHOD(SingleObjectAllocationWithAcquire)
		{
			SingleLinkAllocator allocator(allocator_size);

			auto pointer = reinterpret_cast<Object*>(allocator.Acquire(sizeof(Object)));
			Assert::AreEqual(pointer->m_integer, 0);
			Assert::AreEqual(pointer->m_float, 0.f);
			allocator.Release(pointer);
		}

		TEST_METHOD(SingleObjectAllocationWithNew)
		{
			SingleLinkAllocator allocator(allocator_size);

			auto pointer = new (allocator) Object();
			Assert::AreEqual(pointer->m_integer, 0);
			Assert::AreEqual(pointer->m_float, 0.f);
			allocator.Release(pointer);
		}

		TEST_METHOD(Fragmentation)
		{
			SingleLinkAllocator allocator(allocator_size);

			const size_t nbPieces = allocator_size / 16;
			void** pointers = new void* [nbPieces];
			const size_t test_size = allocator_size / nbPieces - pointer_size;
			//allocate a number of things
			for (int i = 0; i < nbPieces; i++)
			{
				pointers[i] = allocator.Acquire(test_size);
				Assert::IsNotNull(pointers[i]);
			}

			//release some of them
			int i{};
			int amountOfReleased{};
			while (i < nbPieces)
			{
				allocator.Release(pointers[i]);
				i += rand() % 3 + 1;
				++amountOfReleased;
			}

			//allocate something that is less than the free amount of memory, but larger than the hole
			Assert::ExpectException<std::runtime_error>([&]() {allocator.Acquire(amountOfReleased * test_size - test_size); });

			delete[] pointers;
		}
	};
}
