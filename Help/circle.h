#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "shape.h"
#include "color.h"

class Circle : public Shape
{
public:
  Circle(const Point &position_in, const double &radius_in, const Color &color_in, int ol);
  virtual void paint() const;
  virtual void display(std::ostream &os) const;

protected:
  double radius;
  int outline;
private:
};

#endif /* _CIRCLE_H_ */
