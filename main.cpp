#include "main.h"



int main(void) {
	
	network exampleNetwork;

	std::shared_ptr<network> exampleNetworkPTR = std::make_shared<network>(exampleNetwork);

;	node hiddenNode(2, 0.5);
	node inputLayerNode(1, 0.5);


	layer inputLayer(2, std::make_shared<node>(inputLayerNode), 0);
	inputLayer.allNodes()->getValueByIndex(0)->setNodeValue(1000);
	inputLayer.allNodes()->getValueByIndex(1)->setNodeValue(1000);


	layer hiddenLayer(2, std::make_shared<node>(hiddenNode), 0);
	layer outputLayer(1, std::make_shared<node>(hiddenNode), 0);

	exampleNetworkPTR->setAmountOfLayers(3, std::make_shared<layer>(hiddenLayer));

	exampleNetworkPTR->setLayer(std::make_shared<layer>(inputLayer), 0);
	exampleNetworkPTR->setLayer(std::make_shared<layer>(hiddenLayer), 1);
	exampleNetworkPTR->setLayer(std::make_shared<layer>(outputLayer), 2);

	propagate(exampleNetworkPTR);

	std::cout << exampleNetworkPTR->getAllLayers()->getValueByIndex(2)->allNodes()->getValueByIndex(0)->getNodeValue();


}