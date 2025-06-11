#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

#include <algorithm>

using namespace std;

template <typename T>
class SimpleVector {
private:
    int currentSize = 0; //���� ������ ����
    int currentCapacity = 0; //���� ���� �迭�� ũ��

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

	//���� �迭���� ũ�Ⱑ Ŭ���� �۵�
	if (newCapacity > currentCapacity) {
		//���� ���縦 ���� resize
		T* cloneData = new T[newCapacity];

		//data[i]�� ������ ���� ���� ���� ������ ����
		if (data != nullptr) {
			//�� �迭�� �����ϱ�
			for (int i = 0; i < currentSize; i++) {
				cloneData[i] = data[i];
			}
		}

		delete[] data; //���� �迭 �޸� ����

		data = cloneData; //�� �迭�� ���� data�� ����Ű���� ����
		currentCapacity = newCapacity;
	}
}

template <typename T>
void SimpleVector<T>::push_back(const T& value) {

	//�迭�� ũ�⺸�� ������ ������ ������ ��
	if (currentSize >= currentCapacity) {
		resize(currentCapacity + 5); //push_back������ �迭�� ũ�� 5 ����
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
	delete[] data; //�޸� ����
}

//operator
template <typename T>
T& SimpleVector<T>::operator[] (size_t index){
	return data[index];
}
#endif