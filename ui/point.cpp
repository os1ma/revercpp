#include "point.hpp"
#include "../engine/board.hpp"

namespace ui
{

  bool Point::is(int x, int y) const
  {
    return this->x == x && this->y == y;
  }

  void Point::left()
  {
    if (x <= 0)
    {
      return;
    }
    x--;
  }
  void Point::right()
  {
    if (x >= BOARD_SIZE - 1)
    {
      return;
    }
    x++;
  }
  void Point::up()
  {
    if (y <= 0)
    {
      return;
    }
    y--;
  }
  void Point::down()
  {
    if (y >= BOARD_SIZE - 1)
    {
      return;
    }
    y++;
  }

}
