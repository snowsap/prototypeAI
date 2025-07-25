#include "propagation.h"


void propagate(std::shared_ptr<network> targetNetwork) {
	
	layer *currentLayer;
	layer *previousLayer;
	double nodeValue;
	uint64_t amountOfLayers = targetNetwork->getAllLayers()->getAmountOfValues();
	uint64_t amountOfNodes;
	uint64_t amountOfWeights;
	node *currentNode;

	currentLayer = &(targetNetwork->getAllLayers()->getValueByIndex(1));
	previousLayer = &(targetNetwork->getAllLayers()->getValueByIndex(0));

	for (uint64_t a = 2; a < amountOfLayers; ++a) {

		currentLayer->allNodes()->startGetIterator();
		amountOfNodes = currentLayer->allNodes()->getValueByIndex(0)->getWeightAmount();

		for (uint64_t b = 0; b < amountOfNodes; ++b) {

			nodeValue = 0;

			previousLayer->allNodes()->startGetIterator();
			currentNode = &(currentLayer->allNodes()->getIteratorValue());
			currentNode->getWeights()->startGetIterator();
			amountOfWeights = currentNode->getWeights()->getAmountOfValues();

			for (uint64_t c = 0; c < amountOfWeights; ++c) {

				nodeValue += currentNode->getWeights()->getIteratorValue() *
							 previousLayer->allNodes()->getIteratorValue(); 
				
				currentNode->getWeights()->getterIterate();
				previousLayer->allNodes()->getterIterate();

			}

			nodeValue = sigmoid(nodeValue + currentLayer->getBias());

			currentLayer->allNodes()->getIteratorValue()->setNodeValue(nodeValue);
			currentLayer->allNodes()->getterIterate();
		}
		previousLayer = currentLayer;
		currentLayer = &(targetNetwork->getAllLayers()->getValueByIndex(a));
	}


}