#include "alien.hpp"
#include "elem.hpp"

alien::alien(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void alien::draw() const
{
  //TODO: Will be determined by qt drawing libraries
}

void alien::erase() const
{
  //TODO: Will be determined by qt drawing libraries
}

void alien::updatePos(int dx, int dy)
{
  erase();
  setXPos(this->xPos + dx);
  setYPos(this->yPos + dy);
  draw();
}
