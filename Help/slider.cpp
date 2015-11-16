#include "slider.h"
#include "point.h"
#include "rectangle.h"
#include "color.h"
#include <GL/glut.h>
#include <iostream>

Slider::Slider(const Point &position_in, const Point &corner_in, const Color &color_in)
 : Rectangle(position_in, corner_in, color_in, 0), adjustment(0.1)
{
	//
}

void Slider::adjust(const Point &click_in)
{
	adjustment = ((double)click_in.x-position.x)/(corner.x-position.x);
}

void Slider::setColor(const Color &color_in)
{
	col = color_in;
}

void Slider::paint() const
{
	double bar = (corner.x-10-position.x)*adjustment;
	glColor3d(col.r, col.g, col.b);
	glBegin(GL_QUADS);
	glVertex2d(position.x,position.y);
	glVertex2d(position.x,corner.y);
	glVertex2d(corner.x,corner.y);
	glVertex2d(corner.x,position.y);
	glEnd();
	glColor3d(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2d(position.x+bar,position.y);
	glVertex2d(position.x+bar,corner.y);
	glVertex2d(position.x+bar+10,corner.y);
	glVertex2d(position.x+bar+10,position.y);
	glEnd();
}

bool Slider::contains(const Point &position_test) const
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
