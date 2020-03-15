#include <string>
#include <vector>
#include <tuple>
#include <fstream>
#include "Common.h"
#include "Order.h"

//Assingment6

#include "IOrder.h"
#include "ISource.h"

void Order::createOrders(/*std::string path*/ISource* source)
{
	// open file

		//Old Code.

	/*std::ifstream ordersFile;

	double l, w, h;
	
	uint q, color;
	
	ordersFile.open(path, std::ios::in);
	
	if (ordersFile.is_open()) {
		while (true) {
			if (ordersFile.eof()) {
				ordersFile.close();
				break;
			}
			ordersFile >> l >> w >> h >> q >> color;
			orders.push_back(std::make_tuple(l, w, h, q, color));
		}
	}*/


	//New Code.
	
	orders = source->getData();

}

TupleVec Order::getOrders() const
{
	return orders;
}

uint Order::totalQuantity() const
{
	uint total = 0;
	for (auto& t : orders) {
		total += std::get<3>(t);
	}
	return total;
}
