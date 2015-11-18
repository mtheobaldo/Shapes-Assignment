#include "circle.h"
#include "point.h"
#include "color.h"
#include <cmath>
#include <GL/glut.h>
#include <iostream>

Circle::Circle(const Point &position_in, const double &radius_in)
  : Shape(position_in, color_in),
    radius(radius_in), outline(ol)
{
}

void Circle::paint() const
{
	glColor3d(col.r, col.g, col.b);
	if (outline)
	{
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		glLineWidth( 3.0f );
	}
	glBegin(GL_POLYGON);
	for (int i=0;i<32;i++)
	{
		double theta = (double)i/32.0 *2.0 * 3.1415926;
		double x = this->position.x + this->radius * cos(theta);
		double y = this->position.y + this->radius * sin(theta);
		glVertex2d(x,y);
	}
	glEnd();
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

void Circle::display(std::ostream &os) const
{
	os << "Circle " << position.x << " " << position.y << " " << radius << " " << col.r << " " << col.g << " " << col.b << " " << outline;
}

