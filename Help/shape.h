#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "point.h"
#include "color.h"
#include <string>
#include <iostream>

class Shape
{
public:
	Shape();
	Shape(const Point &position_in, const Color &color_in);
	virtual ~Shape();
	virtual void paint() const = 0;
	virtual void display(std::ostream &os) const = 0;
	Color col;
protected:
	Point position;
};

std::ostream & operator<<(std::ostream &os, const Shape &rhs);

#endif /* _SHAPE_H_ */
