#include "triangle.h"
#include "point.h"
#include "color.h"
#include <GL/glut.h>

Triangle::Triangle(const Point &position_in, const Point &second_in, const Point &third_in, const Color &color_in, int ol)
 : Shape(position_in, color_in), second(second_in), third(third_in), outline(ol)
{
}

void Triangle::paint() const
{
	glColor3d(col.r, col.g, col.b);
	if (outline)
	{
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		glLineWidth( 3.0f );
	}
	glBegin(GL_TRIANGLES);
	glVertex2d(position.x, position.y);
	glVertex2d(second.x, second.y);
	glVertex2d(third.x, third.y);
	glEnd();
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

void Triangle::display(std::ostream &os) const
{
	os << "Triangle " << position.x << " " << position.y << " " << second.x << " " << second.y << " " << third.x << " " << third.y << " " <<col.r << " " << col.g << " " << col.b << " " << outline;
}
