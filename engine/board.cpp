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
        disc = Empty;
      }
    }

    discs[3][3] = Dark;
    discs[3][4] = Light;
    discs[4][3] = Light;
    discs[4][4] = Dark;
  }

  void Board::place(Disc disc, int x, int y)
  {
    discs[y][x] = disc;
  }
}
