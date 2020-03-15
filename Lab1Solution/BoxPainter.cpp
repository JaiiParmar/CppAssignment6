#include <vector>
#include <tuple>
#include "Common.h"
#include "Box.h"
#include "BoxPainter.h"

BoxPainter* BoxPainter::GetInstance()
{
	if (singleton == nullptr) {
		singleton = new BoxPainter();
	}
	return singleton;
}

void BoxPainter::setCostPerUnitArea(double cost)
{
	rate = cost;
}

double BoxPainter::totalPaintCost() const
{
	return totalCost;
}

std::vector<Box> BoxPainter::paintBoxes(std::vector<std::pair<Box, uint>> boxesToColor)
{
	std::vector<Box> paintedBoxes;
	for (const auto& unpainted : boxesToColor) {
		Box painted(unpainted.first);
		painted.setColor(unpainted.second);
		paintedBoxes.push_back(painted);
		totalCost += painted.surfaceArea() * rate;
	}
	return paintedBoxes;
}
