#include "node.h"
#include "networkMain.h"


std::shared_ptr<iteratorVector<layer>> network::getAllLayers() {
	return std::make_shared(this->layers);
}

double network::getLearningRate() {
	return this->learningRate;
}

double network::getLearningDeclineRate() {
	return this->learningDeclineRate;
}

void network::setLayer(std::shared_ptr<layer> layerToReplace, size_t index) {
	this->layers.changeValueByIndex(index, layerToReplace);
}

void network::setLearningRate(double newValue) {
	this->learningRate = newValue;
}

void network::setLearningDeclineRate(double newValue) {
	this->learningDeclineRate = newValue;
}
