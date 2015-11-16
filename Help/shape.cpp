#include "point.h"
#include "shape.h"
#include "color.h"
#include <string>
#include <iostream>

Shape::Shape()
{
	this->position = Point();
	this->col = Color();
}

Shape::Shape(const Point &position_in, const Color &color_in)
{
	this->position = position_in;
	this->col = color_in;
}

Shape::~Shape()
{
	//
}

std::ostream & operator<<(std::ostream &os, const Shape &rhs)
{
	rhs.display(os);
	return os;
}
