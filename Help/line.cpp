#include "line.h"
#include "point.h"
#include "color.h"
#include <cmath>
#include <GL/glut.h>
#include <iostream>

Line::Line(const Point &position_in, const Point &point_in, const Color &color_in)
  : Shape(position_in, color_in),
    pt(point_in)
{
}

void Line::paint() const
{
	glColor3d(col.r, col.g, col.b);
	glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
	glLineWidth( 3.0f );
	glBegin(GL_LINES);
	glVertex2f(position.x, position.y);
	glVertex2f(pt.x, pt.y);
	glEnd();
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

void Line::display(std::ostream &os) const
{
	os << "Line " << position.x << " " << position.y << " " << pt.x << " " << pt.y << " " << col.r << " " << col.g << " " << col.b;
}
