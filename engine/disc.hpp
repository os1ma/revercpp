#pragma once

namespace engine
{
  enum Disc
  {
    Empty = 0,
    Dark = 1,
    Light = 2,
    Wall = 3,
  };

  bool is_opposite_disc(Disc d1, Disc d2);
}
