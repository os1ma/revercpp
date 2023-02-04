#include <ncurses.h>
#include <boost/format.hpp>
#include <string>

#include "ui/point.hpp"

const int BOARD_SIZE = 8;

void initialize()
{
  initscr();
  noecho();
  curs_set(0);
}

void show(const struct UIPoint &p)
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

int main(void)
{
  initialize();

  UIPoint p(3, 4);

  while (true)
  {
    show(p);

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