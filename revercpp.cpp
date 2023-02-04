#include <ncurses.h>
#include <string>
#include <boost/format.hpp>

#include "ui/view.hpp"
#include "ui/point.hpp"

#include "engine/board.hpp"

int main(void)
{
  engine::Board board;

  ui::initialize();

  ui::Point p(0, 0);

  while (true)
  {
    ui::show(board, p);

    auto ch = getch();

    if (ch == 'h')
    {
      p.left();
    }
    else if (ch == 'j')
    {
      p.down();
    }
    else if (ch == 'k')
    {
      p.up();
    }
    else if (ch == 'l')
    {
      p.right();
    }
    else if (ch == '\n')
    {
      board.place(engine::Disc::Dark, p.get_x(), p.get_y());
    }
    else if (ch == 'q')
    {
      break;
    }
  }

  endwin();
}