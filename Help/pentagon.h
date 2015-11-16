#ifndef _PENTAGON_H_
#define _PENTAGON_H_

#include "shape.h"
#include "point.h"
#include "color.h"

class Pentagon : public Shape
{
public:
  Pentagon(const Point &position_in, const Point &second_in, const Point &third_in, const Point &fourth_in, const Point &fifth_in, const Color &color_in, int ol);
  virtual void paint() const;
  virtual void display(std::ostream &os) const;

protected:
  Point second;
  Point third;
  Point fourth;
  Point fifth;
  int outline;
private:
};

#endif /* _PENTAGON_H_ */
