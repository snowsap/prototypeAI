#include "propagation.h"
#pragma once


void propagate(std::shared_ptr<network> targetNetwork) {

    std::shared_ptr<layer> currentLayer;
    std::shared_ptr<layer> previousLayer;
    double nodeValue;
    size_t amountOfLayers = targetNetwork->getAllLayers()->getAmountOfValues();
    uint64_t amountOfNodes;
    uint64_t amountOfWeights;
    std::shared_ptr<node> currentNode;

    currentLayer = targetNetwork->getAllLayers()->getValueByIndex(1);
    previousLayer = targetNetwork->getAllLayers()->getValueByIndex(0);

    for (uint64_t a = 1; a < amountOfLayers; ++a) {

        currentLayer = targetNetwork->getAllLayers()->getValueByIndex(a);
        previousLayer = targetNetwork->getAllLayers()->getValueByIndex(a - 1);
        amountOfNodes = currentLayer->allNodes()->getAmountOfValues();

        for (uint64_t b = 0; b < amountOfNodes; ++b) {

            nodeValue = 0;

            previousLayer->allNodes()->startGetIterator();
            currentNode = currentLayer->allNodes()->getValueByIndex(b);

            currentNode->getWeights()->startGetIterator();
            amountOfWeights = currentNode->getWeights()->getAmountOfValues();

            for (uint64_t c = 0; c < amountOfWeights; ++c) {

                nodeValue += *currentNode->getWeights()->getIteratorValue() *
                    previousLayer->allNodes()->getIteratorValue()->getNodeValue();

                currentNode->getWeights()->getterIterate();
                previousLayer->allNodes()->getterIterate();
            }

            nodeValue = sigmoid(nodeValue + currentLayer->getBias());

            currentNode->setNodeValue(nodeValue);
        }

        currentLayer = targetNetwork->getAllLayers()->getValueByIndex(a);
    }
}
