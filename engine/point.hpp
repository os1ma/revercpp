#pragma once

namespace engine
{
  class Point
  {
    int x;
    int y;

  public:
    Point(int x, int y) : x(x), y(y) {}
    int get_x()
    {
      return x;
    }
    int get_y()
    {
      return y;
    }
  };
}
