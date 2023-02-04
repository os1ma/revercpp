#pragma once

#include <array>

namespace
{
  const int BOARD_SIZE = 8;
}

namespace engine
{

  class Board
  {
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> discs;

  public:
    Board();
    std::array<std::array<int, BOARD_SIZE>, BOARD_SIZE> get_discs() const
    {
      return discs;
    }
  };

}
