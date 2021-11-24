#include "missile.hpp"
#include "elem.hpp"

missile::missile(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void missile::draw() const
{
  //TODO: Will be determined by qt drawing libraries
}

void missile::erase() const
{
  //TODO: Will be determined by qt drawing libraries
}

void alien::updatePos(0, int dy)
{
  erase();
  setYPos(this->yPos + dy);
  draw();
}
