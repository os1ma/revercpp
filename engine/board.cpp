#include <array>
#include <iostream>

#include "board.hpp"
#include "disc.hpp"

namespace
{
  template <typename T>
  void join(std::vector<T> &v1, const std::vector<T> &v2)
  {
    v1.insert(v1.end(), v2.begin(), v2.end());
  }
}

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
    if (discs[p.get_y()][p.get_x()] != Disc::Empty)
    {
      return;
    }

    auto flip_points = list_flip_points(disc, p);

    if (flip_points.size() == 0)
    {
      return;
    }

    discs[p.get_y()][p.get_x()] = disc;

    for (auto &fp : flip_points)
    {
      discs[fp.get_y()][fp.get_x()] = disc;
    }

    walled_discs = wall_discs();

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
        walled[y + 1][x + 1] = discs[y][x];
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

    join(flip_points, check_flip_points(disc, p, 0, -1));
    join(flip_points, check_flip_points(disc, p, -1, -1));
    join(flip_points, check_flip_points(disc, p, -1, 0));
    join(flip_points, check_flip_points(disc, p, -1, 1));
    join(flip_points, check_flip_points(disc, p, 0, 1));
    join(flip_points, check_flip_points(disc, p, 1, 1));
    join(flip_points, check_flip_points(disc, p, 1, 0));
    join(flip_points, check_flip_points(disc, p, 1, -1));

    return flip_points;
  }

  std::vector<Point> Board::check_flip_points(Disc disc, Point p, int x_move, int y_move)
  {
    int walled_x = p.get_x() + 1;
    int walled_y = p.get_y() + 1;

    std::vector<Point> flip_candidate;

    int cur_x = walled_x + x_move;
    int cur_y = walled_y + y_move;

    while (is_opposite_disc(disc, walled_discs[cur_y][cur_x]))
    {
      flip_candidate.push_back(Point(cur_x - 1, cur_y - 1));
      cur_x += x_move;
      cur_y += y_move;
      if (disc == walled_discs[cur_y][cur_x])
      {
        return flip_candidate;
      }
    }

    return std::vector<Point>();
  }

}
