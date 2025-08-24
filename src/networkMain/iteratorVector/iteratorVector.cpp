#include "iteratorVector.h"

template<typename T>
iteratorVector<T>::iteratorVector(size_t amountOfElements, T defaultValue) : value(defaultValue) {
	this->value.resize(amountOfElements, defaultValue);

}

template<typename T>
iteratorVector<T>::iteratorVector()
{
}

template<typename T>
void iteratorVector<T>::startGetIterator() {
	this->getIterator = this->value.begin();
}

template<typename T>
void iteratorVector<T>::endGetIterator() {
	this->value.end();
}

template<typename T>
void iteratorVector<T>::getterIterate() {
	++this->getIterator;
}

template<typename T>
std::shared_ptr<T> iteratorVector<T>::getIteratorValue() {
	return std::make_shared<T>(this->getIterator);
}

template<typename T>
std::shared_ptr<T> iteratorVector<T>::getValueByIndex(size_t index) {
	return std::make_shared<T>(this->value.at(index));
}

template<typename T>
void iteratorVector<T>::startChangerIterator() {
	this->setIterator = this->value.begin();
}

template<typename T>
void iteratorVector<T>::endChangerIterator() {
	this->value.end();
}

template<typename T>
void iteratorVector<T>::changeValueByIndex(size_t index, std::shared_ptr<T> valueToSet) {
	this->value.at(index) = *valueToSet;
}

template<typename T>
void iteratorVector<T>::changerIterate() {
	++this->getIterator;
}

template<typename T>
size_t iteratorVector<T>::getAmountOfValues() {
	return size_t(this->value.size());
}

template<typename T>
void iteratorVector<T>::resizeTheVector(size_t amountOfValue, T defaultValue) {
	this->value.resize(defaultValue, defaultValue);
}
