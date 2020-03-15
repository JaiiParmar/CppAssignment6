#include <vector>
#include <tuple>
#include <iostream>
#include <string>
#include <map>
#include "Common.h"
#include "Box.h"
#include "Order.h"
#include "BoxMaker.h"
#include "BoxPainter.h"
#include "AssemblyLine.h"


//Assignment6
#include "IBoxMaker.h"
#include "IBoxPainter.h"
#include "IOrder.h"
#include "ISource.h"
#include "Source.h"
//Constructor...
AssemblyLine::AssemblyLine()
{
	colorCodeToColorName[101] = "Red";
	colorCodeToColorName[102] = "Green";
	colorCodeToColorName[103] = "Blue";
	colorCodeToColorName[104] = "Black";
	colorCodeToColorName[105] = "Yellow";
}

void AssemblyLine::Start() const
{
	
	ISource* pSource = new Source();

	IOrder* pOrder = new Order;

	//pOrder->createOrders("C:\\Users\\Jayesh\\Downloads\\Lab1Solution\\Lab1Solution\\Orders.txt");
	pOrder->createOrders(pSource);

	std::cout << "New order received" << std::endl;
	std::cout << "Manufacturing " << pOrder->totalQuantity() << " boxes"<< std::endl;
	
	IBoxMaker* pBoxMaker = new BoxMaker;
		//set the cost per volume.
	
	pBoxMaker->setCostPerUnitVolume(5.0);
	std::cout << "\n" << "Phase 1: Building " << pOrder->totalQuantity() << " boxes" << std::endl;
	
	//get Orders from the Orders
	auto toProcess = pOrder->getOrders();
					//pass the order...
	pBoxMaker->takeOrder(toProcess);
	
		//Build Boxes.
	auto boxes = pBoxMaker->buildBoxes();

	std::cout << "Box building completed" << std::endl;
							//print total cost of building the boxes
	std::cout << "Total cost of box building is INR " << pBoxMaker->totalOrderCost() << "\n" << std::endl;
		
						//prepare the paint order.
	auto unpainted = preparePaintOrder(boxes, toProcess);
		/*
			BoxPainter is singleton, so, there is only one BoxPainter: painter.
		*/

	IBoxPainter* pBoxPainter = BoxPainter::GetInstance();
	
	std::cout << "\n" << "Phase 2: Painting " << boxes.size() << " boxes" << std::endl;
		//set painting cost per Area.
	pBoxPainter->setCostPerUnitArea(4.0);
		
		//colored boxes.
	auto finishedBoxes = pBoxPainter->paintBoxes(unpainted);
	
	std::cout << "Painting boxes completed" << std::endl;
		//calculate total cost of painting...
	std::cout << "Total cost of painting is INR " << pBoxPainter->totalPaintCost() << std::endl;

	std::cout << "\n" << "Order completed" << std::endl;
						//total cost.		
	std::cout << "Total production cost is INR " << pBoxMaker->totalOrderCost() + pBoxPainter->totalPaintCost() << std::endl;
						//total volume.
	std::cout << "Total volume created is " << getTotalVolume(boxes) <<" cubic units" << std::endl;
						//total surface area.
	std::cout << "Total paint surface area is " << getTotalSurfaceArea(boxes) << " square units" << std::endl;

	displayColorWiseInfo(finishedBoxes);

}

std::vector<std::pair<Box, uint>> AssemblyLine::preparePaintOrder(Boxes boxes, TupleVec order) const
{
	std::vector<std::pair<Box, uint>> unpainted;
	for (int i = 0; i < order.size(); i++) {
		for (int j = 0; j < std::get<3>(order[i]); j++)
			unpainted.push_back(std::make_pair(boxes[i+j], std::get<4>(order[i])));
	}
	return unpainted;
}

double AssemblyLine::getTotalVolume(Boxes boxes) const
{
	double totalVolume = 0.0;
	for (const auto& box : boxes) {
		totalVolume += box.volume();
	}
	return totalVolume;
}

double AssemblyLine::getTotalSurfaceArea(Boxes boxes) const
{
	double totalSurfaceArea = 0.0;
	for (const auto& box : boxes) {
		totalSurfaceArea += box.surfaceArea();
	}
	return totalSurfaceArea;
}

void AssemblyLine::displayColorWiseInfo(Boxes finished) const
{
	std::map<std::string, uint> colorToBoxCount;

	for (const auto& box : finished) {
		auto colorName = colorCodeToColorName.at(box.colorForPaint());

		if (colorToBoxCount.find(colorName) == colorToBoxCount.end()) {
			// create new key
			colorToBoxCount[colorName] = 1;
		}
		else
			colorToBoxCount[colorName]++;
	}
	std::cout << "\nColor --------- Boxes" << std::endl;
	std::string c{ "           " };

	for (const auto& p : colorToBoxCount) {
		std::string b = c;
		b.replace(0, p.first.length(), p.first);
		std::cout << b << "       " << p.second << std::endl;
	}
}
