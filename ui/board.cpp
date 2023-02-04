#include <ncurses.h>
#include <string>

#include "board.hpp"
#include "point.hpp"

namespace ui
{
  void show_board(int offset_y, const Point &p)
  {
    mvprintw(offset_y, 1, "+--------+");
    for (int y = 0; y < BOARD_SIZE; y++)
    {
      mvprintw(offset_y + 1 + y, 1, "|");
      for (int x = 0; x < BOARD_SIZE; x++)
      {
        std::string str;
        if (p.is(x, y))
        {
          str = "a";
        }
        else
        {
          str = " ";
        }
        mvprintw(offset_y + 1 + y, 2 + x, str.c_str());
      }
      mvprintw(offset_y + 1 + y, BOARD_SIZE + 2, "|");
    }
    mvprintw(offset_y + BOARD_SIZE + 1, 1, "+--------+");
  }
}