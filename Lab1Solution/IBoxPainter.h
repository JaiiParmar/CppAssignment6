#pragma once
#include <vector>
#include "Box.h"

class IBoxPainter
{
public:
	std::vector<Box> virtual paintBoxes(std::vector<std::pair<Box, uint>> boxesToColor) = 0;
	void virtual setCostPerUnitArea(double cost) =0;
	double virtual totalPaintCost() const = 0;

};

