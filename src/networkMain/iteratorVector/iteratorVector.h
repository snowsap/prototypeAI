#include "iostream"
#include "vector"

template<typename T>
class iteratorVector {

private:
	std::vector<T> value;
	std::vector<T>::iterator getIterator;
	std::vector<T>::iterator setIterator;

	
public:
	/* */
	iteratorVector(size_t amountOfElements, T defaultValue);
	/*   the iterator */
	void startGetIterator();
	/* reset the iterator to 0 */
	void endGetIterator();
	/* iterate through the getter*/
	void getterIterate();

	/* get the iterater on the index you are on */
	std::shared_ptr<T> getIteratorValue();
	/* get the value by an index */
	std::shared_ptr<T> getValueByIndex( size_t index );
	
	/* start the changer iterator */
	void startChangerIterator();
	/* reset the iterator to 0 */
	void endChangerIterator();

	void setIteratorValue(const T& valueToSet);

	/* change the iterater on the index you are on */
	void setIteratorValue(std::shared_ptr <T>valueToSet);
	/* change the value by an index */
	void changeValueByIndex(size_t index, std::shared_ptr<T> valueToSet);
	/* iterate through the changer */
	void changerIterate();

	/* return amount of Values*/
	size_t getAmountOfValues();

	/* resize the amount of values */
	void resizeTheVector(size_t amountOfValue, T defaultValue);


};
