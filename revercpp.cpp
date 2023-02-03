#include <ncurses.h>
#include <boost/format.hpp>

const int BOARD_SIZE = 8;

struct Point
{
  int x;
  int y;
} Point;

void init()
{
  initscr();
  noecho();
  curs_set(0);
}

void show(struct Point p)
{
  mvprintw(0, 0, "Reversi Game!");

  auto output = boost::format("%d %d") % p.x % p.y;
  auto str = output.str().c_str();
  mvprintw(1, 0, str);

  mvprintw(BOARD_SIZE, 0, "Press 'q' to quit.");
}

int main(void)
{
  init();

  struct Point p
  {
    3, 4
  };

  while (true)
  {
    show(p);

    int ch = getch();

    if (ch == 'q')
    {
      break;
    }
  }

  endwin();
}