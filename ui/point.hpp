#pragma once

namespace ui
{

  class Point
  {
    int x;
    int y;

  public:
    Point(int x, int y) : x(x), y(y) {}

    bool is(int x, int y) const;
    void left();
    void right();
    void up();
    void down();

    int get_x() const
    {
      return x;
    }
    int get_y() const
    {
      return y;
    }
  };

}
