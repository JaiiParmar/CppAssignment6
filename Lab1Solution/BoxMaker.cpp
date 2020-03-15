#include <vector>
#include <tuple>
#include "Common.h"
#include "Box.h"
#include "BoxMaker.h"

void BoxMaker::setCostPerUnitVolume(double cost)
{
	rate = cost;
}

void BoxMaker::takeOrder(TupleVec order)
{
	this->order = order;
}

Boxes BoxMaker::buildBoxes()
{
	Boxes boxes;
	for (auto& t : order) {
		Box bBox{ std::get<0>(t),
				  std::get<1>(t),
				  std::get<2>(t) };
		for(int i = 0; i < std::get<3>(t); i++)
			boxes.push_back(bBox);
		totalCost += bBox.volume() * rate * std::get<3>(t);
	}

	return boxes;
}

double BoxMaker::totalOrderCost() const
{
	return this->totalCost;
}
