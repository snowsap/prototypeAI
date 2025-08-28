#include "node.h"

node::node(size_t numberofWeights, double defaultValue) {
	this->weightings = iteratorVector<double>(numberofWeights, std::make_shared<double>(defaultValue));
}

node::node() {
}

double node::getNodeValue() {
	return nodeValue;
}

std::shared_ptr<iteratorVector<double>> node::getWeights() {
	return std::shared_ptr<iteratorVector<double>>(&this->weightings, [](iteratorVector<double>*) {});
}

size_t node::getWeightAmount() {
	return this->weightings.getAmountOfValues();
}

double node::getDesiredChange() {
	return this->desiredChange;
}

void node::setNodeValue(double newValue) {
	nodeValue = newValue;
}

void node::setDesiredChange(double newValue) {
	this->desiredChange = newValue;
}

void node::resize(size_t amountOfValues, double newValueDefault) {
	this->weightings.resizeTheVector(amountOfValues, std::make_shared<double>(newValueDefault));
}

