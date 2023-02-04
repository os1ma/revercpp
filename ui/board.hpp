#include <ncurses.h>
#include <string>

#include "point.hpp"

namespace ui
{
  const int BOARD_SIZE = 8;

  void show_board(int offset_y, const Point &p);
}