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
//	currentSize++; //현재 배열의 원소 개수 증가
//
//	//현재 원소의 개수가 currentCapacity보다 크거나 같을 때
//	if(currentSize > currentCapacity){
//		currentCapacity++; //현재 배열의 용량 증가
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