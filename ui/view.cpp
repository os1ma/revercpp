#include <ncurses.h>
#include <boost/format.hpp>
#include <string>
#include "point.hpp"

namespace ui
{

  const int BOARD_SIZE = 8;

  void initialize()
  {
    initscr();
    noecho();
    curs_set(0);
  }

  void show(const struct Point &p)
  {
    mvprintw(0, 0, "Reversi Game!!");

    mvprintw(1, 1, "+--------+");
    for (int y = 0; y < BOARD_SIZE; y++)
    {
      mvprintw(2 + y, 1, "|");
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
        mvprintw(2 + y, 2 + x, str.c_str());
      }
      mvprintw(2 + y, BOARD_SIZE + 2, "|");
    }
    mvprintw(BOARD_SIZE + 2, 1, "+--------+");

    mvprintw(BOARD_SIZE + 3, 0, "Press 'q' to quit.");
  }

}
