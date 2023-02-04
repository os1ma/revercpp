#include "ui/view.hpp"
#include "ui/point.hpp"
#include <ncurses.h>

int main(void)
{
  ui::initialize();

  ui::Point p(3, 4);

  while (true)
  {
    ui::show(p);

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