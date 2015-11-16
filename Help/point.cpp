#include "point.h"
#include <cmath>
#include <GL/glut.h>

Point::Point()
 :x(-1), y(-1)
{
}

Point::Point(double x_in, double y_in)
 :x(x_in), y(y_in)
{
}

void Point::paint() const
{
	glBegin(GL_POLYGON);
	for (int i=0;i<32;i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double xx = x + 3 * cos(theta);
		double yy = y + 3 * sin(theta);
		glVertex2d(xx,yy);
	}
	glEnd();
}
