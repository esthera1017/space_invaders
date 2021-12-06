#include "map.hpp"
#include "elem.hpp"

#include <QRect>

map::map(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void map::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  qreal xPosQ = qreal(xPos);
  qreal yPosQ = qreal(yPos);
  qreal widthQ = qreal(width);
  qreal lengthQ = qreal(length);
  QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
  QImage image{"/Users/estheramao/Downloads/space.jpg"};
  painter->drawImage(rectangle, image);

}

QRectF map::boundingRect() const
{
  qreal penWidth = 1;
  return QRectF(xPos - penWidth, yPos - penWidth,
                width + penWidth, length + penWidth);
}

void map::erase(QPainter* painter) const
{
  painter->fillRect(xPos, yPos, width, length, "black");
}

void map::updatePos(int dx, int dy, QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  erase(painter);
  setXPos(this->xPos + dx);
  setYPos(this->yPos + dy);
  paint(painter, option, widget);
}
