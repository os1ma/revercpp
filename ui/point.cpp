#include "point.hpp"

bool UIPoint::is(int x, int y) const
{
  return this->x == x && this->y == y;
}

void UIPoint::left()
{
  x--;
}
void UIPoint::right()
{
  x++;
}
void UIPoint::up()
{
  y--;
}
void UIPoint::down()
{
  y++;
}
