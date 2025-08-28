#include "layer.h"

layer::layer(size_t numOfNodes, std::shared_ptr<node> defaultValue, double bias) {
	this->nodeVector = std::make_shared<iteratorVector<node>>(numOfNodes, defaultValue);
	this->bias = bias;
}

layer::layer(size_t numOfNodes, std::shared_ptr <node> defaultValue) {
	this->nodeVector = std::make_shared<iteratorVector<node>>();
	this->nodeVector->resizeTheVector(numOfNodes, defaultValue);
	this->bias = 0;
}

std::shared_ptr<iteratorVector<node>> layer::allNodes() {
	return this->nodeVector;
}

size_t layer::amountOfNodes() {
	return nodeVector->getAmountOfValues();
}

double layer::getBias() {
	return this->bias;
}

void layer::changeBias(double newValue) {
	this->bias = newValue;
}
