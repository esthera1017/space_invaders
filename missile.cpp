#include "missile.hpp"
#include "elem.hpp"

missile::missile(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void missile::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  painter->fillRect(xPos, yPos, width, length, "white");
}

QRectF missile::boundingRect() const
{
  qreal penWidth = 1;
  return QRectF(xPos - penWidth, yPos - penWidth,
                width + penWidth, length + penWidth);
}

void missile::erase(QPainter* painter) const
{
  painter->fillRect(xPos, yPos, width, length, "black");
}

void missile::updatePos(int dx, int dy, QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  erase(painter);
  setYPos(this->yPos + dy);
  paint(painter, option, widget);
}
