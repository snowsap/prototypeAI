#include "iostream"
#include "vector"

#pragma once


template<typename T>
class iteratorVector {

private:
	std::vector<T> value;
	std::vector<T>::iterator getIterator;
	std::vector<T>::iterator setIterator;

	
public:
	/* */
	iteratorVector(size_t amountOfElements, T defaultValue) {
		this->value.resize(amountOfElements, defaultValue);
	};
	iteratorVector() {};
	/*   the iterator */
	void startGetIterator() {
		this->getIterator = this->value.begin();
	};
	/* reset the iterator to 0 */
	void endGetIterator() {
		this->value.end();
	};
	/* iterate through the getter*/
	void getterIterate() {
		++this->getIterator;
	};

	/* get the iterater on the index you are on */
	std::shared_ptr<T> getIteratorValue() {
		return std::make_shared<T>(this->getIterator);
	};
	/* get the value by an index */
	std::shared_ptr<T> getValueByIndex( size_t index ) {
		return std::make_shared<T>(this->value.at(index));
	};
	
	/* start the changer iterator */
	void startChangerIterator() {
		this->setIterator = this->value.begin();
	};
	/* reset the iterator to 0 */
	void endChangerIterator() {
		this->value.end();
	};

	/* change the value by an index */
	void changeValueByIndex(size_t index, std::shared_ptr<T> valueToSet) {
		this->value.at(index) = *valueToSet;
	};
	/* iterate through the changer */
	void changerIterate() {
		++this->getIterator;
	};

	/* return amount of Values*/
	size_t getAmountOfValues() {
		return size_t(this->value.size());
	};

	/* resize the amount of values */
	void resizeTheVector(size_t amountOfValue, T defaultValue) {
		this->value.resize(defaultValue, defaultValue);
	};

};
