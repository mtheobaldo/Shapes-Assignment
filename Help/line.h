#ifndef _LINE_H_
#define _LINE_H_

#include "shape.h"
#include "color.h"

class Line : public Shape
{
public:
  Line(const Point &position_in, const Point &point_in, const Color &color_in);
  virtual void paint() const;
  virtual void display(std::ostream &os) const;

protected:
  Point pt;
private:
};

#endif /* _LINE_H_ */
