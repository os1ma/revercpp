#include <ncurses.h>

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

    int ch = getch();

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
    else if (ch == 'q')
    {
      break;
    }
  }

  endwin();
}