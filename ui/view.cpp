#include <ncurses.h>
#include <string>

#include "point.hpp"
#include "board.hpp"
#include "../engine/board.hpp"

namespace
{
  std::string message = "";

  enum Colors
  {
    Warning = 1
  };
}

namespace ui
{

  void initialize()
  {
    initscr();

    noecho();
    curs_set(0);

    start_color();
    init_pair(Warning, COLOR_RED, COLOR_BLACK);
  }

  void show(const engine::Board &board, const Point &p)
  {
    mvprintw(0, 0, "Reversi Game!!");

    attron(COLOR_PAIR(Warning));
    mvprintw(1, 0, message.c_str());
    attroff(COLOR_PAIR(Warning));

    show_board(2, board, p);
    mvprintw(BOARD_SIZE + 4, 0, "Press 'q' to quit.");
  }

  void set_message(const std::string &msg)
  {
    message = msg;
  }

}
