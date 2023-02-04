#include <ncurses.h>
#include <string>

#include "point.hpp"
#include "../engine/board.hpp"

namespace ui
{
  void show_board(int offset_y,
                  const engine::Board &board,
                  const Point &p);
}