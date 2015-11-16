#include "pentagon.h"
#include "point.h"
#include "color.h"
#include <GL/glut.h>

Pentagon::Pentagon(const Point &position_in, const Point &second_in, const Point &third_in, const Point &fourth_in, const Point &fifth_in, const Color &color_in, int ol)
 : Shape(position_in, color_in), second(second_in), third(third_in), fourth(fourth_in), fifth(fifth_in), outline(ol)
{
}

void Pentagon::paint() const
{
	glColor3d(col.r, col.g, col.b);
	if (outline)
	{
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		glLineWidth( 3.0f );
	}
	glBegin(GL_POLYGON);
	glVertex2d(position.x, position.y);
	glVertex2d(second.x, second.y);
	glVertex2d(third.x, third.y);
	glVertex2d(fourth.x, fourth.y);
	glVertex2d(fifth.x, fifth.y);
	glEnd();
	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

void Pentagon::display(std::ostream &os) const
{
	os << "Pentagon " << position.x << " " << position.y << " " << second.x << " " << second.y << " " << third.x << " " << third.y << " " << fourth.x << " " << fourth.y << " " << fifth.x << " " << fifth.y << " " <<col.r << " " << col.g << " " << col.b << " " << outline;
}
