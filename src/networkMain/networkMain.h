 #include "../prototypeAI/src/networkMain/layer/layer.h"

class network {
private:
	iteratorVector<layer> layers;
	double learningRate;
	double learningDeclineRate;

public:
	
	/* returns all layers */
	std::shared_ptr<iteratorVector<layer>> getAllLayers();
	/* return the learning rate */
	double getLearningRate();
	/* return the rate that the learning rate declines per iteration */
	double getLearningDeclineRate();
	
	/* defines a layer */
	void setLayer(std::shared_ptr<layer> layerToReplace, size_t index);
	/* defines the learning rate */
	void setLearningRate(double newValue);
	/* defines the rate that the learning rate declines per iteration */
	void setLearningDeclineRate(double newValue);




};