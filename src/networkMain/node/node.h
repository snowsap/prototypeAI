#include "../prototypeAI/src/networkMain/iteratorVector/iteratorVector.h"


class node {

private: 
	iteratorVector<double> weightings;
	double nodeValue;

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
	double getDesiredChange();
	void setNodeValue(double value);
	void setDesiredChange(double newValue);




};