#include <ncurses.h>
#include <string>
#include <boost/format.hpp>

#include "ui/view.hpp"
#include "ui/point.hpp"

#include "engine/board.hpp"
#include "engine/point.hpp"

int main(void)
{
  engine::Board board;
  engine::Disc disc = board.get_next_disc();

  ui::initialize();

  ui::Point cur(0, 0);

  while (true)
  {
    ui::show(board, cur);

    auto ch = getch();

    if (ch == 'h')
    {
      cur.left();
    }
    else if (ch == 'j')
    {
      cur.down();
    }
    else if (ch == 'k')
    {
      cur.up();
    }
    else if (ch == 'l')
    {
      cur.right();
    }
    else if (ch == '\n')
    {
      engine::Point p(cur.get_x(), cur.get_y());
      board.place(disc, p);

      auto next_disc = board.get_next_disc();

      if (disc == next_disc)
      {
        ui::set_message("skipped!");
      }

      disc = next_disc;
    }
  }

  endwin();
}