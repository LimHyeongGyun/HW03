#ifndef SIMPLEVECTOR_H_
#define SIMPLEVECTOR_H_

template <typename T>
class SimpleVector {
private:
    T* data;
    int currentSize = 0; //현재 원소의 개수
    int currentCapacity = 0; //현재 내부 배열의 크기

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

	//깊은 복사를 통한 resize

	int cloneCapacity = currentCapacity + 2; //2배씩 크기가 증가하도록
	T* cloneData = new T[cloneCapacity];

	//data[i]가 쓰레기 값일 때의 버퍼 오버런 방지
	if (data != nullptr) {
		//새 배열로 복사하기
		for (int i = 0; i < currentSize; i++) {
			cloneData[i] = data[i];
		}
	}

	delete[] data; //기존 배열 메모리 해제

	data = cloneData; //새 배열을 기존 data가 가리키도록 해줌
	currentCapacity = cloneCapacity;
}

template <typename T>
void SimpleVector<T>::push_back(const T& value) {

	//배열의 크기보다 원소의 개수가 많아질 때
	if (currentSize >= currentCapacity) {
		resize(); //배열의 크기 조정
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
	delete[] data; //메모리 해제
}

//operator
template <typename T>
T& SimpleVector<T>::operator[] (size_t index){
	return data[index];
}
#endif