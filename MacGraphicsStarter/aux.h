//
//  aux.h
//  MacGraphicsStarter
//
//  Created by Maxwell Theobald on 11/11/15.
//
//

//this will have the BUTTON, SLIDER, POINT classes

#ifndef __MacGraphicsStarter__aux__
#define __MacGraphicsStarter__aux__

#include <stdio.h>
#include "shapes.hpp"

//Point Class will take an x and y and then draw a little circle
class Point
{
public:
    Point();
    Point(double x_in, double y_in);
    double x, y;
    void paint() const;
};


//Button Class will take 2 points and draw a Rectangle
//Pretty much it will be a rectangle with a function to check clicks
class Button : public Rectangle
{
public:
    Button(const Point &p1, const Point &p2);
    bool contains(const Point &point) const;
};







#endif /* defined(__MacGraphicsStarter__aux__) */
