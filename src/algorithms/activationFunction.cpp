#include "activationFunction.h"
#pragma once

double sigmoid(double inputValue) {
	return std::pow((1 + std::exp(-inputValue)), -1);
}
