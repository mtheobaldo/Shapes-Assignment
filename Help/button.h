#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "rectangle.h"
#include "point.h"
#include "color.h"

class Button : public Rectangle
{
public:
  Button(const Point &position_in, const Point &corner_in, const Color &color_in);
  bool contains(const Point &position_test) const;

protected:
private:
};

#endif /* _BUTTON_H_ */
