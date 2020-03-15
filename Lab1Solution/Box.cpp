#include "Common.h"
#include "Box.h"

Box::Box(double l, double w, double h)
{
	this->l = l;
	this->w = w;
	this->h = h;
}

void Box::setLength(double l)
{
	if (l > 0)
		this->l = l;
}

void Box::setWidth(double w)
{
	if (w > 0)
		this->w = w;
}

void Box::setHeight(double h)
{
	if (h > 0)
		this->h = h;
}

void Box::setColor(uint c)
{
	color = c;
}

double Box::volume() const
{
	return l * w * h;
}

double Box::surfaceArea() const
{
	return 2 * (l*w + l*h + w*h);
}

uint Box::colorForPaint() const
{
	return color;
}
