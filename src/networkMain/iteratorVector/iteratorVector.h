
#include "iostream"
#include "vector"
#include "memory"

#pragma once


template<typename T>
class iteratorVector {

private:
	std::shared_ptr<std::vector<T>> value;
	std::vector<T>::iterator getIterator;
	std::vector<T>::iterator setIterator;
	size_t backUpIndexGet;
	size_t backUpIndexSet;


public:
	iteratorVector(size_t amountOfElements, T defaultValue) {
		value = std::make_shared<std::vector<T>>();
		value->resize(amountOfElements, defaultValue);
		getIterator = value->begin();
		setIterator = value->begin();

	}

	iteratorVector() {
		value = std::make_shared<std::vector<T>>();
		getIterator = value->begin();
		setIterator = value->begin();

	}


	/* the iterator */
	void startGetIterator() {
		if (this->value->empty()) {
			this->getIterator = this->value->end();
		}
		else {
			this->getIterator = this->value->begin();
		}
	}

	/* iterate through the getter*/
	void getterIterate() {
		if (getIterator != value->end()) ++getIterator;
	}

	/* get the iterater on the index you are on */
	std::shared_ptr<T> getIteratorValue() {
		return std::shared_ptr<T>(&*this->getIterator, [](T*) {});
	}


	/* get the value by an index */
	std::shared_ptr<T> getValueByIndex(size_t index) {
		return std::shared_ptr<T>(&this->value->at(index), [](T*) {});
	};

	/* start the changer iterator */
	void startChangerIterator() {
		this->setIterator = this->value->begin();
	};


	/* change the value by an index */
	void changeValueByIndex(size_t index, std::shared_ptr<T> valueToSet) {
		this->value->at(index) = *valueToSet;
	};

	/* change the value by an index */
	void changeValueByIndex(size_t index, T &valueToSet) {
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
	void resizeTheVector(size_t amountOfValue, T defaultValue) {
		this->value->resize(amountOfValue, defaultValue);
		this->getIterator = this->value->begin();
		this->setIterator = this->value->begin();

	}


};