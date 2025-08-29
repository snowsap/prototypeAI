#include "../prototypeAI/src/networkMain/node/node.h"
#pragma once

class layer {
private:
	double bias = 0;
	std::shared_ptr<iteratorVector<node>> nodeVector;

public:
	
	layer(size_t numOfNodes, std::shared_ptr<node> defaultValue, double bias);
	layer(size_t numOfNodes, std::shared_ptr<node> defaultValue);

	layer();
	
	std::shared_ptr<iteratorVector<node>> allNodes();
	/* returns the amount of nodes */
	size_t amountOfNodes();
	/* returns the layer bias */
	double getBias();
	/* change the layer bias 
	/ @param newValue "the new bias for the layer"
	*/
	void changeBias(double newValue);

	void defaultAllValues(std::shared_ptr<node> defaultValue);



};