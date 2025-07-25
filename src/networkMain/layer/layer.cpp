#include "layer.h"

layer::layer(size_t numberOfNodes, double defaultValue) {
	this->nodeVector.resizeTheVector(numberOfNodes, defaultValue);
}

size_t layer::amountOfNodes() {
	return nodeVector.getAmountOfValues();
}

double layer::getBias() {
	return this->bias;
}

void layer::changeBias(double newValue) {
	this->bias = newValue;
}
