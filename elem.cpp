#include "elem.hpp"

elem::elem(int width, int length, int xPos, int yPos) : width {width}, length {length}, xPos {xPos}, yPos {yPos}
{}

elem::~elem()
{}

void elem::setXPos(int newX)
{
  xPos = newX;
}

void elem::setYPos(int newY)
{
  yPos = newY;
}

