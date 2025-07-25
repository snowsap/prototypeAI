#include "iostream"
#include "vector"

template<typename T>
class iteratorVector {

private:
	std::vector<T> value;
	
public:
	/* */
	iteratorVector(size_t amountOfElements, T defaultValue);
	/* start the iterator */
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
	std::shared_ptr<T> startChangerIterator();
	/* reset the iterator to 0 */
	std::shared_ptr<T> endChangerIterator();

	/* change the iterater on the index you are on */
	void getIteratorValue(const T &valueToSet);
	/* change the value by an index */
	void changeValueByIndex(size_t index, const T& valueToSet);
	/* iterate through the changer */





};
