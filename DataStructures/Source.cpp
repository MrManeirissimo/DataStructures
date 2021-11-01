#include <vector>
#include <iostream>
#include <string>

#include "Array.h";
#include "SimpleArray.h"
#include "DynamicArray.h"
#include <vector>

using namespace DataStructures;
using namespace std;

class IValidable {
public:
	virtual bool isValid() = 0;
};



template<typename T>
void printArr(DynamicArray<T>& arr) {
	cout << "[";
	for (size_t i = 0; i < arr.capacity(); i++) {
		if (i != 0)

			cout << " ";
		cout << arr.get(i);
	}
	cout << "]";
	cout << endl;
}

int main() {
	vector<int> v;
	DataStructures::DynamicArray<int> dArr(5);
	printArr(dArr);
	dArr.set(0, 0);
	dArr.set(1, 1);
	dArr.set(2, 2);
	dArr.set(3, 3);
	dArr.set(4, 4);
	printArr(dArr);

	dArr.insert(7, 2);
	printArr(dArr);
	dArr.set(9, 9);
	printArr(dArr);

	system("pause");
	return 0;
}