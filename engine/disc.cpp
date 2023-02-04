#include "disc.hpp"

namespace engine
{
  bool is_opposite_disc(Disc d1, Disc d2)
  {
    return (d1 == Dark && d2 == Light) || (d1 == Light && d2 == Dark);
  }
}
