#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize = 0; //���� ������ ����
    int currentCapacity = 0; //���� ���� �迭�� ũ��

	void resize();
public:
    SimpleVector();
    SimpleVector(int capacity);

    void push_back(const T& value);
    void pop_back();
    int size();
    int capacity();

    ~SimpleVector();

	//operator
	T& operator[](size_t index);
};

template <typename T>
SimpleVector<T>::SimpleVector() {
	data = new T[currentCapacity = 10];
}

template <typename T>
SimpleVector<T>::SimpleVector(int capacity) {
	data = new T[currentCapacity = capacity];
}

template <typename T>
void SimpleVector<T>::resize() {

	//���� ���縦 ���� resize

	int cloneCapacity = currentCapacity + 2; //2�辿 ũ�Ⱑ �����ϵ���
	T* cloneData = new T[cloneCapacity];

	//data[i]�� ������ ���� ���� ���� ������ ����
	if (data != nullptr) {
		//�� �迭�� �����ϱ�
		for (int i = 0; i < currentSize; i++) {
			cloneData[i] = data[i];
		}
	}

	delete[] data; //���� �迭 �޸� ����

	data = cloneData; //�� �迭�� ���� data�� ����Ű���� ����
	currentCapacity = cloneCapacity;
}

template <typename T>
void SimpleVector<T>::push_back(const T& value) {

	//�迭�� ũ�⺸�� ������ ������ ������ ��
	if (currentSize >= currentCapacity) {
		resize(); //�迭�� ũ�� ����
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
SimpleVector<T>::~SimpleVector() {
	delete[] data; //�޸� ����
}

//operator
template <typename T>
T& SimpleVector<T>::operator[] (size_t index){
	return data[index];
}
#endif