#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "shape.h"
#include "point.h"
#include "color.h"

class Triangle : public Shape
{
public:
  Triangle(const Point &position_in, const Point &second_in, const Point &third_in, const Color &color_in, int ol);
  virtual void paint() const;
  virtual void display(std::ostream &os) const;

protected:
  Point second;
  Point third;
  int outline;
private:
};

#endif /* _TRIANGLE_H_ */
