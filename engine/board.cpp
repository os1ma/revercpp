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

    walled_discs = wall_discs();

    next_disc = Disc::Dark;
  }

  void Board::place(Disc disc, Point p)
  {
    discs[p.get_y()][p.get_x()] = disc;
    next_disc = disc == Disc::Dark ? Disc::Light : Disc::Dark;
  }

  WalledDiscs Board::wall_discs()
  {
    WalledDiscs walled;

    for (auto &disc : walled[0])
    {
      disc = Disc::Wall;
    }

    for (int y = 0; y < BOARD_SIZE; y++)
    {
      walled[y + 1][0] = Disc::Wall;
      for (int x = 0; x < BOARD_SIZE; x++)
      {
        walled[y][x + 1] = discs[y][x];
      }
      walled[y + 1][BOARD_SIZE + 1] = Disc::Wall;
    }

    for (auto &disc : walled[BOARD_SIZE + 1])
    {
      disc = Disc::Wall;
    }

    return walled;
  }

  std::vector<Point> Board::list_flip_points(Disc disc, Point p)
  {
    std::vector<Point> flip_points;

    // TODO

    return flip_points;
  }
}
