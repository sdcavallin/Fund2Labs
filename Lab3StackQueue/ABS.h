#pragma once
#include <iostream>
using namespace std;
template <typename T>
class ABS {
	float scale = 2.0f;
	unsigned int cap, size;
	T* data;

public:
	ABS(int capacity = 1);

	ABS(const ABS& other);
	ABS& operator=(const ABS& other);
	~ABS();

	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();

	void push(T thing);
	T peek();
	T pop();
};

template <typename T>
ABS<T>::ABS(int capacity) {
	cap = capacity;
	size = 0;

	data = new T[cap];
}

template <typename T>
ABS<T>::ABS(const ABS& other) {
	scale = other.scale;
	cap = other.cap;
	size = other.size;

	data = new T[cap];
	for (unsigned int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
ABS<T>& ABS<T>::operator=(const ABS& other) {
	scale = other.scale;
	cap = other.cap;
	size = other.size;

	data = new T[cap];
	for (unsigned int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}

	return *this;
}

template <typename T>
ABS<T>::~ABS() {
	delete[] data;
}

template <typename T>
void ABS<T>::push(T thing) {
	if (size >= cap) { 
		cap = (unsigned int) (cap * scale);
		T* newData = new T[cap];
		for (unsigned int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	data[size] = thing;
	size++;
}

template <typename T>
T ABS<T>::peek() {
	if (size <= 0) {
		throw runtime_error("EMPTY");
	}
	return data[size-1];
}

template <typename T>
/*T ABS<T>::pop() {
	cout << " \n[Test " << (unsigned int)(cap / 2) << "]";
	if (size <= (unsigned int)(cap / 2)) {
		cap = size;
		T* newData = new T[cap];
		for (unsigned int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		delete[] data;
		data = newData;
	}
	size--;
	return data[size];
}*/
T ABS<T>::pop() {
	if (size <= 0) {
		throw runtime_error("EMPTY");
	}
	T item = data[size-1];
	size--;
	if (((double)(size)) / ((double)(cap)) < 1 / ((double)(scale))) {
		cap = cap / (int)(scale);

		T* newData = new T[cap];

		for (unsigned int i = 0; i < cap; i++) {
			newData[i] = data[i];
		}

		delete[] data;
		data = newData;
	}
	return item;
}

template <typename T>
T* ABS<T>::getData() {
	return data;
}

template <typename T>
unsigned int ABS<T>::getSize() {
	return size;
}

template <typename T>
unsigned int ABS<T>::getMaxCapacity() {
	return cap;
}