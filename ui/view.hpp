#pragma once

#include <string>

#include "point.hpp"
#include "../engine/board.hpp"

namespace ui
{
  void initialize();
  void show(const engine::Board &board, const Point &p);
  void set_message(const std::string &message);
}
