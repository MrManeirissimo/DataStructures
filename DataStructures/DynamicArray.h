#pragma once
#include "Container.h"

namespace DataStructures {
	template<typename T>
	class DynamicArray {
		Container<T>* container;

	public:
		DynamicArray(size_t capacity) {
			container = new Container<T>(capacity);
		}
		~DynamicArray() {
		}

		virtual void set(T value, int index) { container->set(value, index); }
		virtual T get(int index) { return container->get(index); }
		virtual size_t capacity() { return container->capacity(); }

		virtual void insert(T value, int index) {
			size_t previousCapacity = container->capacity();

			Container<T>* newContainer = new Container<T>(container->capacity() * 2);
			newContainer->copy(*container);
			swapContainer(newContainer);
			//swapContainer(Container<T>::make_from((*container), container->capacity() * 2));

			for (size_t i = previousCapacity; i > index; i--)
				container->set(container->get(i - 1), i);

			container->set(value, index);
		}

	private:
		void swapContainer(Container<T>* newContainer) {
			//container->~Container();
			container = newContainer;
		}
	};
}