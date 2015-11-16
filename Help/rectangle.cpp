#include "rectangle.h"
#include "point.h"
#include "color.h"
#include <GL/glut.h>

Rectangle::Rectangle(const Point &position_in, const Point &corner_in, const Color &color_in, int ol)
 : Shape(position_in, color_in), corner(corner_in), outline(ol)
{
}

void Rectangle::paint() const
{
	glColor3d(col.r, col.g, col.b);
	if (outline)
	{
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		glLineWidth( 3.0f );
	}
	glBegin(GL_QUADS);
	glVertex2d(position.x,position.y);
	glVertex2d(position.x,corner.y);
	glVertex2d(corner.x,corner.y);
	glVertex2d(corner.x,position.y);
	glEnd();
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

bool Rectangle::contains(const Point &position_test) const
{
	if (position_test.x >= position.x && position_test.x <= corner.x)
	{
		if (position_test.y >= position.y && position_test.y <= corner.y)
		{
			return true;
		}
		if (position_test.y <= position.y && position_test.y >= corner.y)
		{
			return true;
		}
	}
	if (position_test.x <= position.x && position_test.x >= corner.x)
	{
		if (position_test.y >= position.y && position_test.y <= corner.y)
		{
			return true;
		}
		if (position_test.y <= position.y && position_test.y >= corner.y)
		{
			return true;
		}
	}
	return false;
}

void Rectangle::display(std::ostream &os) const
{
	os << "Rectangle " << position.x << " " << position.y << " " << corner.x << " " << corner.y << " " << col.r << " " << col.g << " " << col.b << " " << outline;
}
