#include "player.hpp"
#include "elem.hpp"
#include <QKeyEvent>
#include <iostream>
//#include <QGraphicsView>
#include "missile.hpp"
#include "missile.hpp"
#include <QDebug>

player::player(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void player::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qreal xPosQ = qreal(xPos);
    qreal yPosQ = qreal(yPos);
    qreal widthQ = qreal(width);
    qreal lengthQ = qreal(length);
    QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
    QImage image{"/Users/lloydtmaodzeka/space/space_invaders/PickCannon.png"};
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

void player::keyPressEvent(QKeyEvent * event)
{
  qDebug() << "Player knows you pressed a key";
  switch(event->key()) {
//    case Qt::Key_Up:
//      setPos(x(), y() - 10);
//      break;
//    case Qt::Key_Down:
//      setPos(x(), y() + 10);
//      break;
    case Qt::Key_Left:
      setPos(x() - 10, y());
      //xPos = xPos - 10;
      break;
    case Qt::Key_Right:
      setPos(x() + 10, y());
      //xPos = xPos + 10;
      break;
    case Qt::Key_Space:
      //missile m{20, 30, 2, 5};
      missile * missile = new class missile();
      //missile * missile = new missile(0, 0, 0, 0);
      missile->setPos(x(), y ());
      //std::cout << x() << " " << y();
      scene()->addItem(missile);
      qDebug() << "missile created";
      //missile m{20, 30, 2, 5};
      break;
  }
}
