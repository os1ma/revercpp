#include <ncurses.h>
#include <boost/format.hpp>

#include "point.hpp"
#include "board.hpp"

namespace ui
{

  void initialize()
  {
    initscr();
    noecho();
    curs_set(0);
  }

  void show(const Point &p)
  {
    mvprintw(0, 0, "Reversi Game!!");
    show_board(2, p);
    mvprintw(BOARD_SIZE + 4, 0, "Press 'q' to quit.");
  }

}
