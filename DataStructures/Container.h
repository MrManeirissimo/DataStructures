#pragma once

namespace DataStructures {
	template<typename T>
	class IContainer {
	public:
		virtual void set(T value, int index) = 0;
		virtual T& get(int index) = 0;
		virtual size_t capacity() = 0;
	};

	template<class T>
	class Container : public IContainer<T> {
		size_t m_capacity;
		T* buffer;
	public:
		//static void clone(Container& targetContainer, const Container sourceContainer) {
		//	size_t copyUntil = targetContainer.m_capacity > sourceContainer.m_capacity ? sourceContainer.m_capacity : targetContainer.m_capacity;

		//	for (size_t i = 0; i < copyUntil; i++)
		//		targetContainer.set(sourceContainer->buffer[i], i);
		//		//targetContainer.set(sourceContainer.get(i), i);
		//}

		//static Container* make_from(Container& from, size_t newCapacity) {
		//	Container c(newCapacity);
		//	clone(&c, from);
		//	return &c;
		//}

		void copy(Container<T>& source) {
			size_t copyUntil = m_capacity > source.m_capacity ? source.m_capacity : m_capacity;

			for (size_t i = 0; i < copyUntil; i++)
				set(source.get(i), i);
		}

		Container(size_t capacity) : m_capacity(capacity) {
			buffer = new T[capacity];
		}
		Container() {

		}
		~Container() {
			if (buffer) {
				delete buffer;
				buffer = nullptr;
			}
		}

		virtual void set(T value, int index) { buffer[index] = value; }
		virtual T& get(int index) { return buffer[index]; }
		virtual size_t capacity() { return m_capacity; }
	};
}