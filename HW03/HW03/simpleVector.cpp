//#include <iostream>
//
//#include "simpleVector.h"
//
//using namespace std;
//
//template <typename T>
//SimpleVector<T>::SimpleVector() {
//	data = new T[10];
//}
//template <typename T>
//SimpleVector<T>::SimpleVector(int capacity) {
//	data = new T[capacity];
//	currentCapacity = capacity;
//}
//template <typename T>
//void SimpleVector<T>::resize() {
//	
//}
//template <typename T>
//void SimpleVector<T>::push_back(const T& value) {
//
//	data[currentSize] = value;
//	
//	currentSize++; //���� �迭�� ���� ���� ����
//
//	//���� ������ ������ currentCapacity���� ũ�ų� ���� ��
//	if(currentSize > currentCapacity){
//		currentCapacity++; //���� �迭�� �뷮 ����
//	}
//}
//template <typename T>
//void SimpleVector<T>::pop_back() {
//	data.remove();
//}
//template <typename T>
//int SimpleVector<T>::size() {
//
//	return currentSize;
//}
//template <typename T>
//int SimpleVector<T>::capacity() {
//	return 0;
//}
//template <typename T>
//SimpleVector<T>::~SimpleVector() {
//
//}