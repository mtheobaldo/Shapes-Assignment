#include "button.h"
#include "point.h"
#include "rectangle.h"
#include "color.h"
#include <GL/glut.h>
#include <iostream>

Button::Button(const Point &position_in, const Point &corner_in, const Color &color_in)
 : Rectangle(position_in, corner_in, color_in, 0)
{
	//
}


bool Button::contains(const Point &pbosition_test) const
{
	double x = position_test.x;
	double y = position_test.y;
	if (x > position.x && x < corner.x)
	{
		if (y > position.y && y < corner.y)
		{
			return true;
		}
		else if (y < position.y && y > corner.y)
		{
			return true;
		}
	}
	if (x < position.x && x > corner.x)
	{
		if (y > position.y && y < corner.y)
		{
			return true;
		}
		else if (y < position.y && y > corner.y)
		{
			return true;
		}
	}
	return false;
}
