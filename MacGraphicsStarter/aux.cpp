//
//  aux.cpp
//  MacGraphicsStarter
//
//  Created by Maxwell Theobald on 11/11/15.
//
//

#include "aux.h"


//Point class will take and x and y and draw a little circle
Point::Point()
{
    x=0;
    y=0;
}

Point::Point(x_in, y_in)
{
    x = x_in;
    y = y_in;
}

void Point::paint()const
{
    glColor3d(R,G,B);
    if (outline)
    {
        glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
        glLineWidth( 1.0f );
    }
    glBegin(GL_POLYGON);
    for (int i=0;i<32;i++)
    {
        double theta = (double)i/32.0 *2.0 * 3.1415926;
        double xx = this->x + 2 * cos(theta);
        double yy = this->y + 2 * sin(theta);
        glVertex2d(xx,yy);
    }
    glEnd();
    glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}


//Button Class will take 2 points and draw a Rectangle
//Pretty much it will be a rectangle with a function to check clicks
Button::Button(Point &p1, Point &p2)
: Rectangle(p1, p2)
{
    //empty
}

bool Button::contains(<#const Point &point#>)
{
    double x = point.x;
    double y = point.y;
    if(x > p1.x && x < p2.x)
    {
        if(y > p1.y && y < p2.y)
        {
            return true;
        }
        if(y < p1.y && y > p2.y)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}








