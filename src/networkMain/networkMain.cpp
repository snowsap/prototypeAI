#include "networkMain.h"


network::network() {


}

std::shared_ptr<iteratorVector<layer>> network::getAllLayers() {
	return std::shared_ptr<iteratorVector<layer>>(&this->layers, [](iteratorVector<layer>*) {});
}

double network::getLearningRate() {
	return this->learningRate;
}

double network::getLearningDeclineRate() {
	return this->learningDeclineRate;
}

void network::setAmountOfLayers(size_t setAmountOfLayers, layer &defaultLayer) {
	this->layers.resizeTheVector(setAmountOfLayers, defaultLayer);
}

void network::setLayer(std::shared_ptr<layer> layerToReplace, size_t index) {
	if (this->layers.getAmountOfValues() > index) {
		this->layers.changeValueByIndex(index, layerToReplace);
	}
	else {
		std::cerr << "Errror, accessing out of range value";
	}
}

void network::setLearningRate(double newValue) {
	this->learningRate = newValue;
}

void network::setLearningDeclineRate(double newValue) {
	this->learningDeclineRate = newValue;
}
