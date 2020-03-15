#pragma once
#include "IOrder.h"

class Order : public IOrder
{

public:
	void createOrders(/*std::string path*/ISource*) override;
	TupleVec getOrders() const override;
	uint totalQuantity() const override;

private:
	TupleVec orders;
};

