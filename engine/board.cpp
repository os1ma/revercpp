#include <array>
#include <iostream>

#include "board.hpp"

namespace
{
  enum Disc
  {
    Empty = 0,
    Dark = 1,
    Light = 2
  };
}

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
}
