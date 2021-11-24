#include "player.hpp"
#include "elem.hpp"

player::player(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void player::draw() const
{
  //TODO: Will be determined by qt drawing libraries
}

void player::erase() const
{
  //TODO: Will be determined by qt drawing libraries
}

void player::updatePos(int dx, 0)
{
  erase();
  setXPos(this->xPos + dx);
  draw();
}
