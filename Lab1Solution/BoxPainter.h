#pragma once
#include "IBoxPainter.h"

// Making BoxPainter a singleton

class BoxPainter: public IBoxPainter
{
public:
	static BoxPainter* GetInstance();
	void setCostPerUnitArea(double cost)override;
	std::vector<Box> paintBoxes(std::vector<std::pair<Box, uint>> boxesToColor) override;
	double totalPaintCost() const override;

private:
	BoxPainter() { rate = totalCost = 0.0; }	// set default constructor as private

private:
	double rate, totalCost;
	inline static BoxPainter* singleton;
};

