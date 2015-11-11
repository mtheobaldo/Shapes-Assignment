//
//  aux.h
//  MacGraphicsStarter
//
//  Created by Maxwell Theobald on 11/11/15.
//
//

//this will have the BUTTON, SLIDER, COLOR, POINT classes

#ifndef __MacGraphicsStarter__aux__
#define __MacGraphicsStarter__aux__

#include <stdio.h>
#include "shapes.hpp"


class Point
{
public:
    Point();
    Point(double x_in, double y_in);
    double x, y;
    void paint() const;
};

class Button : public Rectangle
{
public:
    Button(const Point &p1, const Point &p2, const Color &color);
    bool contains(const Point &point) const;
};

class Color
{
public:
    Color();
    Color(double red_in, double green_in, double blue_in);
    double r, g, b;
};




#endif /* defined(__MacGraphicsStarter__aux__) */
