#include "point.hpp"

namespace ui
{

  bool Point::is(int x, int y) const
  {
    return this->x == x && this->y == y;
  }

  void Point::left()
  {
    x--;
  }
  void Point::right()
  {
    x++;
  }
  void Point::up()
  {
    y--;
  }
  void Point::down()
  {
    y++;
  }

}
