#include "node.h"

node::node(size_t numberofWeights, double defaultValue) {
	this->weightings.resizeTheVector(numberofWeights, defaultValue);
}

double node::getNodeValue() {
	return this->nodeValue;
}

std::shared_ptr<iteratorVector<double>> node::getWeights() {
	return std::make_shared<iteratorVector<double>>(this->weightings);
}

size_t node::getWeightAmount() {
	return this->weightings.getAmountOfValues();
}

double node::getDesiredChange() {
	return this->desiredChange;
}

void node::setNodeValue(double newValue) {
	this->nodeValue = newValue;
}

void node::setDesiredChange(double newValue) {
	this->desiredChange = newValue;
}

void node::resize(size_t amountOfValues, double newValueDefault) {
	this->weightings.resizeTheVector(amountOfValues, newValueDefault);
}

