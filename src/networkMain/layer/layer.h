#include "../prototypeAI/src/networkMain/node/node.h"

class layer {
private:
	double bias;
	iteratorVector<nodes> nodeVector;

public:
	
	layer(size_t numOfNodes, double defaultValue);

	std::shared_ptr<iteratorVector<nodes>>();
	/* returns the amount of nodes */
	size_t amountOfNodes();
	/* returns the layer bias */
	double getBias();
	/* change the layer bias 
	/ @param newValue "the new bias for the layer"
	*/
	void changeBias(double newValue);



};