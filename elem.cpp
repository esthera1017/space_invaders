#include "elem.hpp"

elem::elem(int width, int length, int xPos, int yPos) : width {width}, length {length}, xPos {xPos}, yPos {yPos}
{}

elem::setPos(int newX)
{
  xPos = newX;
}

elem::setYPos(int newY)
{
  yPos = newY;
}

