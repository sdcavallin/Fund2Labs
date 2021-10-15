#pragma once
#include <iostream>
using namespace std;
template <typename T>
class ABQ {
	float scale = 2.0f;
	unsigned int cap, size;
	T* data;

public:
	ABQ(int capacity = 1);

	ABQ(const ABQ& other);
	ABQ& operator=(const ABQ& other);
	~ABQ();

	unsigned int getSize();
	unsigned int getMaxCapacity();
	T* getData();

	void enqueue(T thing);
	T peek();
	T dequeue();

	void print();
};

template <typename T>
ABQ<T>::ABQ(int capacity) {
	cap = capacity;
	size = 0;

	data = new T[cap];
}

template <typename T>
ABQ<T>::ABQ(const ABQ& other) {
	scale = other.scale;
	cap = other.cap;
	size = other.size;

	data = new T[cap];
	for (unsigned int i = 0; i < size; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ& other) {
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
ABQ<T>::~ABQ() {
	delete[] data;
}

template <typename T>
void ABQ<T>::enqueue(T thing) {
	if (size >= cap) {
		cap = (unsigned int)(cap * scale);
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
T ABQ<T>::peek() {
	if (size <= 0) {
		throw runtime_error("EMPTY");
	}
	return data[0];
}

template <typename T>

T ABQ<T>::dequeue() {
	if (size <= 0) {
		throw runtime_error("EMPTY");
	}
	T item = data[0];
	size--;
	if (((double)(size)) / ((double)(cap)) < 1 / ((double)(scale))) {
		cap = cap / (int)(scale);

		T* newData = new T[cap];

		for (unsigned int i = 0; i < cap; i++) {
			newData[i] = data[i+1];
		}

		delete[] data;
		data = newData;
	}
	else {
		T* newData = new T[cap];

		for (unsigned int i = 0; i < size; i++) {
			newData[i] = data[i + 1];
		}

		delete[] data;
		data = newData;
	}
	return item;
}

template <typename T>
T* ABQ<T>::getData() {
	return data;
}

template <typename T>
unsigned int ABQ<T>::getSize() {
	return size;
}

template <typename T>
unsigned int ABQ<T>::getMaxCapacity() {
	return cap;
}

template <typename T>
void ABQ<T>::print() {
	for (unsigned int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}