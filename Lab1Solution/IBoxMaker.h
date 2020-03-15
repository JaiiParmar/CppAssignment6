#pragma once

#include "Box.h"
#include <vector>

class IBoxMaker
{
public:
	void virtual setCostPerUnitVolume(double cost) = 0;
	std::vector<Box> virtual buildBoxes() = 0;
	void virtual takeOrder(TupleVec order) = 0;
	double virtual totalOrderCost() const = 0;
};

