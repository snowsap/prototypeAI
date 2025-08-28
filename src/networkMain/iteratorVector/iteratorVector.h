
#include "iostream"
#include "vector"
#include "memory"

#pragma once


template<typename T>
class iteratorVector {

private:
	std::shared_ptr<std::vector<std::shared_ptr<T>>> value;
	typename std::vector<std::shared_ptr<T>>::iterator getIterator;
	typename std::vector<std::shared_ptr<T>>::iterator setIterator;



public:
	iteratorVector(size_t amountOfElements, std::shared_ptr<T> defaultValue) {
		value = std::make_shared<std::vector<std::shared_ptr<T>>>();
		value->resize(amountOfElements, defaultValue);
		getIterator = value->begin();
		setIterator = value->begin();


	}

	iteratorVector() {
		value = std::make_shared<std::vector<std::shared_ptr<T>>>();
		getIterator = value->begin();
		setIterator = value->begin();

	}


	/* the iterator */
	void startGetIterator() {
		getIterator = value->begin();
	}

	/* iterate through the getter*/
	void getterIterate() {
		if (getIterator != value->end()) ++getIterator;
	}

	/* get the iterater on the index you are on */
	std::shared_ptr<T> getIteratorValue() {
		return *getIterator;
	}

	T& getIteratorValueRef() {
		return *getIterator->get();
	}

	/* get the value by an index */
	std::shared_ptr<T> getValueByIndex(size_t index) {
		return value->at(index);
	};

	/* start the changer iterator */
	void startChangerIterator() {
		this->setIterator = this->value->begin();
	};


	/* change the value by an index */
	void changeValueByIndex(size_t index, std::shared_ptr<T> valueToSet) {
		this->value->at(index) = valueToSet;
	};

	/* iterate through the changer */
	void changerIterate() {
		if (setIterator != value->end()) ++setIterator;
	};

	void set(T value) {

		*this->setIterator = value;
		return;

	}
	/* return amount of Values*/
	size_t getAmountOfValues() {
		return size_t(this->value->size());
	};

	/* resize the amount of values */
	void resizeTheVector(size_t amountOfValue, std::shared_ptr<T> defaultValue) {
		value->clear();
		value->reserve(amountOfValue);
		for (size_t i = 0; i < amountOfValue; ++i) {
			value->push_back(std::make_shared<T>(*defaultValue)); 
		}
		getIterator = value->begin();
		setIterator = value->begin();
	}




};