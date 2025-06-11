#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
    int currentSize = 0; //현재 원소의 개수
    int currentCapacity = 0; //현재 내부 배열의 크기

	void resize(int newCapacity);
public:
    T* data;
    SimpleVector();
    SimpleVector(int capacity);
	SimpleVector(const SimpleVector& other);

    void push_back(const T& value);
    void pop_back();
    int size();
    int capacity();
	void sortData();

    ~SimpleVector();

	//operator
	T& operator[](size_t index);
};

template <typename T>
SimpleVector<T>::SimpleVector() : currentSize(0), currentCapacity(10) {
	data = new T[currentCapacity];
}

template <typename T>
SimpleVector<T>::SimpleVector(int capacity) : currentSize(0), currentCapacity(capacity){
	data = new T[currentCapacity];
}
template <typename T>
SimpleVector<T>::SimpleVector(const SimpleVector& other)
: currentSize(other.currentSize), currentCapacity(other.currentCapacity){
	data = new T[currentCapacity];
	for (int i = 0; i < currentSize; i++) {
		data[i] = other.data[i];
	}
}
template <typename T>
void SimpleVector<T>::resize(int newCapacity) {

	//현재 배열보다 크기가 클때만 작동
	if (newCapacity > currentCapacity) {
		//깊은 복사를 통한 resize
		T* cloneData = new T[newCapacity];

		//data[i]가 쓰레기 값일 때의 버퍼 오버런 방지
		if (data != nullptr) {
			//새 배열로 복사하기
			for (int i = 0; i < currentSize; i++) {
				cloneData[i] = data[i];
			}
		}

		delete[] data; //기존 배열 메모리 해제

		data = cloneData; //새 배열을 기존 data가 가리키도록 해줌
		currentCapacity = newCapacity;
	}
}

template <typename T>
void SimpleVector<T>::push_back(const T& value) {

	//배열의 크기보다 원소의 개수가 많아질 때
	if (currentSize >= currentCapacity) {
		resize(currentCapacity + 5); //push_back에서는 배열의 크기 5 증가
	}

	data[currentSize++] = value;
}

template <typename T>
void SimpleVector<T>::pop_back() {
	if (currentSize <= 0) {
		throw std::out_of_range("Cannot pop_back from empty vector");
	}
	else {
		currentSize--;
	}
}

template <typename T>
int SimpleVector<T>::size() {

	return currentSize;
}

template <typename T>
int SimpleVector<T>::capacity() {

	return currentCapacity;
}

template <typename T>
void SimpleVector<T>::sortData() {
	sort(data, data + currentSize);
}

template <typename T>
SimpleVector<T>::~SimpleVector() {
	delete[] data; //메모리 해제
}

//operator
template <typename T>
T& SimpleVector<T>::operator[] (size_t index){
	return data[index];
}
#endif