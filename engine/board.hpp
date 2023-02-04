#pragma once

#include <array>
#include <vector>

#include "disc.hpp"
#include "point.hpp"

namespace
{
  const int BOARD_SIZE = 8;

  using Discs = std::array<std::array<engine::Disc, BOARD_SIZE>, BOARD_SIZE>;
  using WalledDiscs = std::array<std::array<engine::Disc, BOARD_SIZE + 2>, BOARD_SIZE + 2>;
}

namespace engine
{

  class Board
  {
    Discs discs;
    WalledDiscs walled_discs;
    Disc next_disc;

  public:
    Board();

    void place(Disc disc, Point p);

    Discs get_discs() const
    {
      return discs;
    }
    Disc get_next_disc() const
    {
      return next_disc;
    }

  private:
    WalledDiscs wall_discs();
    std::vector<Point> list_flip_points(Disc disc, Point p);
  };

}
