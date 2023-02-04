#pragma once

class UIPoint
{
  int x;
  int y;

public:
  UIPoint(int x, int y) : x(x), y(y) {}
  bool is(int x, int y) const;
  void left();
  void right();
  void up();
  void down();
};
