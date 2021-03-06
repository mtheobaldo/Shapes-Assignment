//
//  classes.hpp
//  MacGraphicsStarter
//
//  Created by Maxwell Theobald on 11/11/15.
//
//this is the header for Circle Rectangle Triangle and Shape:)

#ifndef shapes_hpp
#define shapes_hpp

#include <stdio.h>
#include <cstdlib>
#include <ostream>
#include "aux.h"



//Shape
class Shape
{
public:
    Shape();
    Shape(const Point &p1);
    virtual ~Shape();
    virtual void paint() const = 0;
    virtual void print(std::ostream &os) const = 0;
protected:
    Point p1;
};

std::ostream & operator<<(std::ostream &os, const Shape &rhs);

//Circle
class Circle : public Shape
{
public:
    Circle(const Point &center, const double &radius);
    virtual void paint() const;
    virtual void print(std::ostream &os) const;
    
protected:
    double radius;


};

//Rectangle
class Rectangle : public Shape
{
public:
    Rectangle(const Point p1, const Point p2);
    virtual void paint() const;
    virtual void print(std::ostream &os) const;
    
protected:

    Point p2;
};

//Triangle
class Triangle : public Shape
{
public:
    Triangle(const Point p1, const Point p2, const Point p3);
    virtual void paint() const;
    virtual void print(std::ostream &os) const;
protected:
    Point p2;
    Point p3;

};

#endif /* shapes_hpp */
