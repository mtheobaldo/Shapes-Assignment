//
//  classes.cpp
//  MacGraphicsStarter
//
//  Created by Maxwell Theobald on 11/11/15.
//
//

#include "shapes.hpp"
#include <string>
#include <iostream>

Shape::Shape()
{
    p1 = Point();
    mColor = Color();
}

Shape::Shape(const Point &p1_in, const Color &color)
{
    p1 = p1_in;
    mColor = color;
}

Shape::~Shape()
{
    //nothing
}

std::ostream & operator<<(std::ostream &os, const Shape &rhs)
{
    rhs.display(os);
    return os;
}