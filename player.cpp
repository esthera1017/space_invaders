#include "player.hpp"
#include "elem.hpp"
#include "game.hpp"
#include <QKeyEvent>
#include <iostream>
//#include <QGraphicsView>
#include "missile.hpp"
#include "alien.hpp"
#include <QDebug>
#include <QTimer>

extern game * gm;

player::player(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{}

void player::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qreal xPosQ = qreal(xPos);
    qreal yPosQ = qreal(yPos);
    qreal widthQ = qreal(width);
    qreal lengthQ = qreal(length);
    QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
    QImage image{"/Users/lloydtmaodzeka/space/space_invaders/PinkCannon.png"};
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
    case Qt::Key_Left:
      if ((x() - 10  < 0) == false) {
        setPos(x() - 10, y());
      }
      break;
    case Qt::Key_Right:
      if ((x() + 10 > 800 - width) == false) {
        setPos(x() + 10, y());
      }
      break;
  case Qt::Key_Up:
    if ((x() + 10 > 800 - width) == false) {
      setPos(x(), y() - 10);
    }
    break;
    case Qt::Key_Space:
      missile * missile = new class missile();
      missile->setPos(x() + (width/2 - 10), y ());
      scene()->addItem(missile);
      qDebug() << "missile created";
      break;
  }
}

void player::alienMove()
{
    int rand{(int)arc4random_uniform(39)};
    if (gm->store[rand] == -99 || gm->alienArr->at(rand)->id < 0 || gm->alienArr->at(rand)->id > 39) return;
    gm->store[rand] = -99;
    std::cout << rand << "\n";
    std::cout << gm->alienArr->at(rand)->id << "\n\n";
    if (gm->alienArr->at(rand) != NULL) {
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),gm->alienArr->at(rand),SLOT(move()));
        //timer->start(50);
        timer->start(50);
    } else {
        return;
    }
}


