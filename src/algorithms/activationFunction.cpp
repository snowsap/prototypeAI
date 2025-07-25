#include "activationFunction.h"

double sigmoid(double inputValue) {
	return std::pow((1 + std::exp(-inputValue)), -1);
}
