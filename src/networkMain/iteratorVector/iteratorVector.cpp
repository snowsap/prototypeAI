#include "../prototypeAI/src/networkMain/iteratorVector/iteratorVector.h"

template<typename T>
inline iteratorVector<T>::iteratorVector(size_t amountOfElements, T defaultValue) {
	this->value.resize(amountOfElements, defaultValue);
}

template<typename T>
void iteratorVector<T>::startGetIterator() {
}

template<typename T>
void iteratorVector<T>::endGetIterator() {
}

template<typename T>
void iteratorVector<T>::getterIterate() {
}

template<typename T>
std::shared_ptr<T> iteratorVector<T>::getIteratorValue() {
	return std::shared_ptr<T>();
}

template<typename T>
std::shared_ptr<T> iteratorVector<T>::getValueByIndex(size_t index) {
	return std::shared_ptr<T>();
}

template<typename T>
std::shared_ptr<T> iteratorVector<T>::startChangerIterator() {
	return std::shared_ptr<T>();
}

template<typename T>
std::shared_ptr<T> iteratorVector<T>::endChangerIterator() {
	return std::shared_ptr<T>();
}

template<typename T>
void iteratorVector<T>::getIteratorValue(const T& valueToSet) {

}

template<typename T>
void iteratorVector<T>::changeValueByIndex(size_t index, const T& valueToSet) {
}

