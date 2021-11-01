#pragma once
#include <stdlib.h>
#include <iostream>

// Access: Random access data structure -> O(1) (order one time)
// Insert: Linear run time O(n)
// * if insertion is bigger than the capacity of the array, it's capacity is doubled. Those are dynamic arrays.
// Delete: Linear run time O(n)

/*
* insert(object, index)
* delete(index)
*
* capacity {get; set;}
* size {get; set;}
*/

//namespace DataStructures {
//
//	#define asIndex(size)(	\
//		sizeof(T) * size	\
//	)
//	
//	
//	class IValidable {
//	public:
//		bool virtual isValid() = 0;
//	};
//
//	template<typename T>
//	class Array : public IValidable {
//		bool isLastIndexUsed, isPenultimateIndexUsed;
//		size_t m_capacity;
//		size_t m_size;
//		T* block;
//
//		Array() {
//			isLastIndexUsed = false;
//			block = nullptr;
//		}
//
//		void allocMemory(const size_t capacity, bool b_realloc = false) {
//			block = (T*)(b_realloc ? realloc(block, sizeof(T) * capacity) : malloc(sizeof(T) * capacity));
//			m_capacity = capacity;
//		}
//
//	public:
//
//		Array(const size_t capacity) : Array() {
//			allocMemory(capacity);
//			m_size = 0;
//		}
//
//		~Array() {
//			if (block != nullptr) {
//				free(block);
//				block = nullptr;
//			}
//		}
//
//		void insert(T value, const unsigned int index) {
//			if (isLastIndexUsed || m_size >= m_capacity) {
//				allocMemory(m_capacity * 2, true);
//				isLastIndexUsed = isPenultimateIndexUsed = false;
//			}
//
//			for (size_t i = m_capacity - 1; i >= index; i--) {
//				block[i] = block[i - 1];
//			}
//
//			block[index] = value;
//			m_size++;
//		}
//
//		T get(const unsigned int index) {
//			return (T)block[index];
//		}
//
//		bool virtual isValid() {
//			return block != nullptr;
//		}
//	};
//}