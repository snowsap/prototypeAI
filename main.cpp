#include "main.h"



int main(void) {
	network exampleNetwork;

	node hiddenNode(2, 0);
	node inputLayerNode(0, 0);


	layer inputLayer(2, std::make_shared<node>(inputLayerNode));
	inputLayer.allNodes()->getValueByIndex(0)->setNodeValue(0);
	inputLayer.allNodes()->getValueByIndex(1)->setNodeValue(1);


	layer hiddenLayer(2, std::make_shared<node>(hiddenNode));
	layer outputLayer(1, std::make_shared<node>(hiddenNode));

	exampleNetwork.setLayer(std::make_shared<layer>(inputLayer), 0);
	exampleNetwork.setLayer(std::make_shared<layer>(hiddenLayer), 1);
	exampleNetwork.setLayer(std::make_shared<layer>(outputLayer), 2);

	propagate(std::make_shared<network>(exampleNetwork));



}