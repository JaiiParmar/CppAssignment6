#include "Source.h"

Source::Source() {
	//code..
	/*
	
	l	 w	   h   s  color
   --------------------------
	6.0  8.0  4.0  5  101
	7.6  3.1  4.5  3  105
	1.3  4.5  6.7  9  103
	4.4  1.9  8.2  4  104
	5.1  2.6  7.2  3  102
	
	*/
	tupV.push_back(std::make_tuple(6.0, 8.0, 4.0, 5, 101));
	tupV.push_back(std::make_tuple(7.6, 3.1, 4.5, 3, 105));
	tupV.push_back(std::make_tuple(1.3, 4.5, 6.7, 9, 103));
	tupV.push_back(std::make_tuple(4.4, 1.9, 8.2, 4, 104));
	tupV.push_back(std::make_tuple(5.1, 2.6, 7.2, 3, 102));

	//push_back(std::make_tuple(l, w, h, q, color));

}

TupleVec Source::getData() const {
	//code..
	return tupV;
}