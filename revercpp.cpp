#include <ncurses.h>
#include <boost/format.hpp>
#include <string>

const int BOARD_SIZE = 8;

struct Point
{
  int x;
  int y;
} Point;

void initialize()
{
  initscr();
  noecho();
  curs_set(0);
}

void show(struct Point p)
{
  mvprintw(0, 0, "Reversi Game!!");

  mvprintw(1, 1, "+--------+");
  for (int y = 0; y < BOARD_SIZE; y++)
  {
    mvprintw(2 + y, 1, "|");
    for (int x = 0; x < BOARD_SIZE; x++)
    {
      std::string str;
      if (x == p.x && y == p.y)
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

  auto output = boost::format("%d %d") % p.x % p.y;
  auto str = output.str().c_str();
  mvprintw(BOARD_SIZE + 4, 0, str);
}

int main(void)
{
  initialize();

  struct Point p
  {
    3, 4
  };

  while (true)
  {
    show(p);

    int ch = getch();

    if (ch == 'h')
    {
      p.x--;
    }
    else if (ch == 'j')
    {
      p.y++;
    }
    else if (ch == 'k')
    {
      p.y--;
    }
    else if (ch == 'l')
    {
      p.x++;
    }
    else if (ch == 'q')
    {
      break;
    }
  }

  endwin();
}