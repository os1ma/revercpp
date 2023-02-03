#include <ncurses.h>

const int BOARD_SIZE = 8;

int main(void)
{
  initscr();
  noecho();
  curs_set(0);

  mvprintw(0, 0, "Reversi Game!");

  mvprintw(BOARD_SIZE, 0, "Press 'q' to quit.");

  while (true)
  {
    int ch = getch();

    if (ch == 'q')
    {
      break;
    }
  }

  endwin();
}