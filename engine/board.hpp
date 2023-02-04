#pragma once

#include <array>

#include "disc.hpp"

namespace
{
  const int BOARD_SIZE = 8;
}

namespace engine
{

  class Board
  {
    std::array<std::array<Disc, BOARD_SIZE>, BOARD_SIZE> discs;
    Disc next_disc;

  public:
    Board();

    void place(Disc disc, int x, int y);

    std::array<std::array<Disc, BOARD_SIZE>, BOARD_SIZE> get_discs() const
    {
      return discs;
    }
    Disc get_next_disc() const
    {
      return next_disc;
    }
  };

}
