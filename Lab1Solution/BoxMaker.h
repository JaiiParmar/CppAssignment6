#pragma once
#include"IBoxMaker.h"

typedef std::vector<Box> Boxes;

class BoxMaker : public IBoxMaker
{
public:
	void setCostPerUnitVolume(double cost) override;
	void takeOrder(TupleVec order) override;
	Boxes buildBoxes() override;
	double totalOrderCost() const override;

private:
	double rate, totalCost;
	TupleVec order;
};

