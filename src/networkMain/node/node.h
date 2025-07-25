#include "../prototypeAI/src/networkMain/iteratorVector/iteratorVector.h"


class node {

private: 
	iteratorVector<double> weightings;
	double nodeValue;
	double desiredChange;

public: 
	/* set the default parameters
	/ @param numberOfWeights "the number of weights on the previous layer"
	/ @param defaultValue "the default Value to be assigned"
	*/
	node(size_t numberofWeights, double defaultValue);
	/* get the modes value */
	double getNodeValue();
	/* get the weights iterator */
	std::shared_ptr<iteratorVector<double>> getWeights();
	/* get the amount of weights in the last layer */
	size_t getWeightAmount();
	/* get the amount of desired change */
	double getDesiredChange();
	/* set the new node value 
	/ @param newValue "the new value to set the node to"
	*/
	void setNodeValue(double newValue);
	/* set the desired change 
	/ @param newValue "the new value to set the node to"
	*/
	void setDesiredChange(double newValue);
	/* resize the nodeWeightings 
	/ @param amountOfValues "set the new amount of values"
	/ @param newValueDefault "the value to set the new values as"
	*/
	void resize(size_t amountOfValues, double newValueDefault);


};