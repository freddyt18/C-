#include <iostream>
#include <cstdlib>
#include <new>
#include <stdexcept>

namespace M {
    class MemoryPool {
    public:
        /**
         * This function initializes a memory pool with a given size and chunk size, allocating memory
         * and throwing a bad_alloc exception if the allocation fails.
         * 
         * @param size The total size of the memory pool in bytes.
         * @param chunkSize The chunkSize parameter in the MemoryPool constructor is the size of each
         * memory block that will be allocated from the pool. This means that the pool will be divided
         * into chunks of this size, and each time a new allocation is requested, a chunk of this size
         * will be returned if available.
         */
        explicit MemoryPool(size_t size, size_t chunkSize) :
            m_size(size),
            m_chunkSize(chunkSize),
            m_allocCount(0)
        {
            m_pool = static_cast<char*>(std::malloc(m_size));
            if (m_pool == nullptr) {
                throw std::bad_alloc();
            }
        }

        ~MemoryPool() {
            std::free(m_pool);
        }

        MemoryPool(const MemoryPool&) = delete;
        MemoryPool& operator=(const MemoryPool&) = delete;

        /**
         * This is a move constructor for a memory pool that transfers ownership of the memory pool
         * from another object.
         * 
         * @param other A rvalue reference to another MemoryPool object that is being moved from.
         */
        MemoryPool(MemoryPool&& other) noexcept :
            m_size(other.m_size),
            m_chunkSize(other.m_chunkSize),
            m_allocCount(other.m_allocCount),
            m_pool(other.m_pool)
        {
            other.m_size = 0;
            other.m_chunkSize = 0;
            other.m_allocCount = 0;
            other.m_pool = nullptr;
        }

        /**
         * This is a move assignment operator for a MemoryPool class in C++.
         * 
         * @return a reference to the current object, which is of type `MemoryPool&`.
         */
        MemoryPool& operator=(MemoryPool&& other) noexcept {
            if (this != &other) {
                m_size = other.m_size;
                m_chunkSize = other.m_chunkSize;
                m_allocCount = other.m_allocCount;
                m_pool = other.m_pool;
                other.m_size = 0;
                other.m_chunkSize = 0;
                other.m_allocCount = 0;
                other.m_pool = nullptr;
            }
            return *this;
        }

        /**
         * The function allocates memory from a pre-allocated pool and throws a bad_alloc exception if
         * the pool is full.
         * 
         * @param size The size parameter represents the size of the memory block that needs to be
         * allocated.
         * 
         * @return The function `allocate` returns a pointer to a block of memory in the memory pool.
         * The pointer is calculated by adding the product of `(m_allocCount - 1)` and `m_chunkSize` to
         * the address of the memory pool `m_pool`.
         */
        void* allocate(size_t size) {
            if (m_allocCount == m_size / m_chunkSize) {
                throw std::bad_alloc();
            }

            ++m_allocCount;

            return m_pool + (m_allocCount - 1) * m_chunkSize;
        }

        void deallocate(void* ptr) {
            if (ptr < m_pool || ptr >= m_pool + m_size) {
                throw std::invalid_argument("Pointer not in pool.");
            }

            --m_allocCount;
        }

    private:
        size_t m_size;
        size_t m_chunkSize;
        size_t m_allocCount;
        char* m_pool;
    };
}

int main() {
    M::MemoryPool pool(1024, 32);

    int* p1 = new (pool.allocate(sizeof(int))) int(42);
    int* p2 = new (pool.allocate(sizeof(int))) int(100);

    std::cout << "p1 = " << *p1 << std::endl;
    std::cout << "p2 = " << *p2 << std::endl;

    pool.deallocate(p1);
    pool.deallocate(p2);

    return 0;
}


