#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "shape.h"
#include "point.h"
#include "color.h"
#include <iostream>

class Rectangle : public Shape
{
public:
  Rectangle(const Point &position_in, const Point &corner_in, const Color &color_in, int ol);
  bool contains(const Point &position_test) const;
  virtual void paint() const;
  virtual void display(std::ostream &os) const;

protected:
  Point corner;
  int outline;
private:
};

#endif /* _RECTANGLE_H_ */
