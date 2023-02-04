#include <array>
#include <iostream>

#include "board.hpp"
#include "disc.hpp"

namespace engine
{
  Board::Board()
  {
    for (auto &line : discs)
    {
      for (auto &disc : line)
      {
        disc = Disc::Empty;
      }
    }

    discs[3][3] = Disc::Dark;
    discs[3][4] = Disc::Light;
    discs[4][3] = Disc::Light;
    discs[4][4] = Disc::Dark;

    next_disc = Disc::Dark;
  }

  void Board::place(Disc disc, Point p)
  {
    discs[p.get_y()][p.get_x()] = disc;
    next_disc = disc == Disc::Dark ? Disc::Light : Disc::Dark;
  }
}
