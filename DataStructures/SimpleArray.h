#pragma once

//namespace DataStructures {
//	template<typename T> class DataBlock {
//		size_t capacity, size;
//		T* data;
//
//		DataBlock() {
//			capacity = size = 0;
//			data = nullptr;
//		}
//	public:
//		DataBlock(size_t capacity) : DataBlock() {
//			realloc(capacity);
//		}
//
//		T& operator[](int index) {
//			return data[index];
//		}
//
//		size_t getCapacity() {
//			return capacity;
//		}
//
//		size_t getSize() {
//			return size;
//		}
//
//		void realloc(size_t capacity) {
//			if (data) 
//				dispose();
//
//			data = new T[capacity];
//			this->capacity = capacity;
//		}
//
//		void copy(DataBlock source) {
//			if (source.data)
//				for (size_t i = 0; i < source.getSize(); i++)
//					data[i] = source.data[i];
//		}
//
//		void replaceRight(int index) {
//			data[index] = data[index + 1];
//		}
//
//		void replaceLeft(int index) {
//			data[index] = data[index - 1];
//		}
//
//		void insert(T value, int index) {
//			data[index] = value;
//			size++;
//		}
//
//		void remove(int index) {
//			data[index] = default(T);
//			size--;
//		}
//
//		void dispose() {
//			delete data;
//		}
//	};
//
//	template<typename T> class DataBlockArray {
//		DataBlock<T>* block;
//	public:
//		DataBlockArray(size_t capacity) {
//			block = new DataBlock<T>(capacity);
//		}
//
//		T& operator[](int index) {
//			return (*block)[index];
//		}
//
//		void insert(T value, size_t index) {
//			if (size() >= capacity())
//				rescaleDataBlock();
//			
//			for (size_t i = block->getSize(); i >= index; i--)
//				block->replaceLeft(i);
//
//			block->insert(value, index);
//		}
//
//		void rescaleDataBlock() {
//			DataBlock<T>* newBlock = new DataBlock<T>(capacity() * 2);
//			newBlock->copy(*block);
//			block->dispose();
//			free(block);
//			block = newBlock;
//		}
//
//		size_t size() {
//			return block->getSize();
//		}
//
//		size_t capacity() {
//			return block->getCapacity();
//		}
//	};
//
//	template<typename T> class SimpleArray {
//		size_t m_capacity, m_size;
//		T* block;
//
//		SimpleArray() {
//			m_capacity = m_size = 0;
//			block = nullptr;
//		}
//
//		void copyBlock(T*& target, T*& source, size_t sourceSize) {
//			if (source)
//				for (size_t i = 0; i < sourceSize; i++)
//					target[i] = source[i];
//		}
//
//		void reallocBlock(T*& source, size_t capacity) {
//			T* newBlock = new T[capacity];
//
//			copyBlock(newBlock, source, m_size);
//			delete source;
//
//			m_capacity = capacity;
//			source = newBlock;
//		}
//	public:
//
//		SimpleArray(size_t capacity) : SimpleArray() {
//			reallocBlock(block, capacity);
//		}
//		~SimpleArray() {
//			delete block;
//		}
//
//		T& operator[](int index) {
//			return block[index];
//		}
//
//		void insert(T value, size_t index) {
//			if (m_size > m_capacity)
//				reallocBlock(block, m_capacity * 2);
//
//			for (size_t i = m_capacity; i > index; i--) {
//				block[i] = block[i - 1];
//			}
//
//			block[index] = value;
//			m_size++;
//		}
//
//		bool remove(size_t index) {
//
//		}
//
//		size_t capacity() {
//			return m_capacity;
//		}
//
//		size_t size() {
//			return m_size;
//		}
//
//		T get(size_t index) {
//			return block[index];
//		}
//	};
//}
