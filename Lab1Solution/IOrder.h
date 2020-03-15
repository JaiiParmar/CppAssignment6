#pragma once
#include<string>
#include"Common.h"

class IOrder
{
public:
	void virtual createOrders(std::string path) = 0;
	TupleVec virtual getOrders() const = 0;
	uint virtual totalQuantity() const = 0;
};



