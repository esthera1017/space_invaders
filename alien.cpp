#include "alien.hpp"
#include "elem.hpp"

#include <QRect>

alien::alien(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

alien::alien(const alien & a) : elem::elem {a.width, a.length, a.xPos, a.yPos}
{}

void alien::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  qreal xPosQ = qreal(xPos);
  qreal yPosQ = qreal(yPos);
  qreal widthQ = qreal(width);
  qreal lengthQ = qreal(length);
  QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
  QImage image{"/Users/estheramao/Downloads/alien.png"};
  painter->drawImage(rectangle, image);

}

QRectF alien::boundingRect() const
{
  qreal penWidth = 1;
  return QRectF(xPos - penWidth, yPos - penWidth,
                width + penWidth, length + penWidth);
}

void alien::erase(QPainter* painter) const
{
  painter->fillRect(xPos, yPos, width, length, "black");
}

void alien::updatePos(int dx, int dy, QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  erase(painter);
  setXPos(this->xPos + dx);
  setYPos(this->yPos + dy);
  paint(painter, option, widget);
}
