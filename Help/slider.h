#ifndef _SLIDER_H_
#define _SLIDER_H_

#include "rectangle.h"
#include "point.h"
#include "color.h"

class Slider : public Rectangle
{
public:
  Slider(const Point &position_in, const Point &corner_in, const Color &color_in);
  void setColor(const Color &color_in);
  bool contains(const Point &position_test) const;
  void adjust(const Point &click_in);
  virtual void paint() const;
  double adjustment;

protected:
private:
};

#endif /* _SLIDER_H_ */
