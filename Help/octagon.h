#ifndef _OCTAGON_H_
#define _OCTAGON_H_

#include "shape.h"
#include "color.h"

class Octagon : public Shape
{
public:
  Octagon(const Point &position_in, const double &radius_in, const Color &color_in, int ol);
  virtual void paint() const;
  virtual void display(std::ostream &os) const;

protected:
  double radius;
  int outline;
private:
};

#endif /* _OCTAGON_H_ */
