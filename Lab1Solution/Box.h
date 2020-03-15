#pragma once

#include "Common.h"

class Box
{
public:
	// constructors
	Box(double l, double w, double h);
	
	// interface
	void setLength(double l);
	void setWidth(double w);
	void setHeight(double h);
	void setColor(uint c);

	double volume() const;
	double surfaceArea() const;
	uint colorForPaint() const;

private:
	double l, w, h;
	uint color;
};

