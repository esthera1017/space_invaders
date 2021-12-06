#include "player.hpp"
#include "elem.hpp"

player::player(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void player::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  qreal xPosQ = qreal(xPos);
  qreal yPosQ = qreal(yPos);
  qreal widthQ = qreal(width);
  qreal lengthQ = qreal(length);
  QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
  QImage image{"/Users/estheramao/Downloads/PinkCannon.png"};
  painter->drawImage(rectangle, image);
}

QRectF player::boundingRect() const
{
  qreal penWidth = 1;
  return QRectF(xPos - penWidth, yPos - penWidth,
                width + penWidth, length + penWidth);
}

void player::erase(QPainter* painter) const
{
  painter->fillRect(xPos, yPos, width, length, "black");
}

void player::updatePos(int dx, int dy, QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
  erase(painter);
  setXPos(this->xPos + dx);
  paint(painter, option, widget);
}
