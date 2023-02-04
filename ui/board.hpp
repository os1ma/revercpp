#include <ncurses.h>
#include <string>

#include "point.hpp"
#include "../engine/board.hpp"

namespace ui
{
  const int BOARD_SIZE = 8;

  void show_board(int offset_y,
                  const engine::Board &board,
                  const Point &p);
}