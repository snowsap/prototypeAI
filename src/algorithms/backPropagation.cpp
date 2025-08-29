#include "backPropagation.h"

void backPropagate(
    std::shared_ptr<network> targetNetwork, 
    std::shared_ptr<layer> idealOutput,
    double learningRate ) {

    std::shared_ptr<layer> currentLayer = targetNetwork->getAllLayers()->getValueByIndex(targetNetwork->getAllLayers()->getAmountOfValues() - 1);
    std::shared_ptr<layer> previousLayer = targetNetwork->getAllLayers()->getValueByIndex(targetNetwork->getAllLayers()->getAmountOfValues() - 2);
    std::shared_ptr<layer> tempIdealOutput = idealOutput;

    std::shared_ptr<node> targetNode;
    node zeroNode;

    double nodeValue = 0;
    double activationContributiondx = 0;
    double weightContributiondx = 0;
    double costContributiondx = 0;
    double valueContributiondx = 0;
    double totalCost = 0;
    double tempBias = 0;

    currentLayer->allNodes()->startGetIterator();
    idealOutput->allNodes()->startGetIterator();

    for (size_t nodeIndex = 0; nodeIndex < currentLayer->amountOfNodes(); ++nodeIndex) {
        totalCost += 0.5 * pow(
            idealOutput->allNodes()->getIteratorValue()->getNodeValue() -
            currentLayer->allNodes()->getIteratorValue()->getNodeValue(), 2);
            currentLayer->allNodes()->getterIterate();
            idealOutput->allNodes()->getterIterate();
    }

    for (size_t layerIndex = targetNetwork->getAllLayers()->getAmountOfValues() - 1; layerIndex > 0; --layerIndex) {
        tempBias = 0;
        currentLayer->allNodes()->startGetIterator();
        previousLayer->allNodes()->startGetIterator();
        idealOutput->allNodes()->startGetIterator();

        for (size_t nodeIndex = 0; nodeIndex < currentLayer->amountOfNodes(); ++nodeIndex) {
            targetNode = currentLayer->allNodes()->getIteratorValue();
            nodeValue = targetNode->getNodeValue();
            activationContributiondx = nodeValue * (1 - nodeValue);

            costContributiondx = idealOutput->allNodes()->getIteratorValue()->getNodeValue() - nodeValue;
            targetNode->setDesiredChange(activationContributiondx * valueContributiondx * costContributiondx);
            tempBias += activationContributiondx * costContributiondx;

            targetNode->getWeights()->startGetIterator();
            tempIdealOutput->allNodes()->startGetIterator();

            for (size_t weightIndex = 0; weightIndex < targetNode->getWeightAmount(); ++weightIndex) {
                weightContributiondx = *targetNode->getWeights()->getIteratorValue();
                tempIdealOutput->allNodes()->getIteratorValue()->setNodeValue(
                    tempIdealOutput->allNodes()->getIteratorValue()->getNodeValue() + weightContributiondx * activationContributiondx * nodeValue );
                    tempIdealOutput->allNodes()->getterIterate();
                targetNode->getWeights()->getterIterate();

                targetNode->setNodeValue(nodeValue - learningRate * targetNode->getDesiredChange());
            }

            idealOutput->allNodes()->getterIterate();
            currentLayer->allNodes()->getterIterate();
            previousLayer->allNodes()->getterIterate();
        }
        currentLayer->changeBias(currentLayer->getBias() - learningRate * tempBias);
        currentLayer = targetNetwork->getAllLayers()->getValueByIndex(layerIndex - 1);
        previousLayer = targetNetwork->getAllLayers()->getValueByIndex(layerIndex);
        idealOutput = tempIdealOutput;
        tempIdealOutput->defaultAllValues(std::make_shared<node>(zeroNode));
    }
}
