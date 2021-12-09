#include "missile.hpp"
#include "alien.hpp"
#include <QTimer>
#include <QDebug>
#include <iostream>
#include <QList>
#include "game.hpp"
#include "score.hpp"

extern game * gm;

missile::missile() : elem::elem {20, 30, 0, 0}
{
// connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void missile::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    qreal xPosQ = qreal(xPos);
    qreal yPosQ = qreal(yPos);
    qreal widthQ = qreal(width);
    qreal lengthQ = qreal(length);
    QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
    QImage image{"/Users/lloydtmaodzeka/space/space_invaders/fireball.png"};
    painter->drawImage(rectangle, image);
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
  setXPos(this->xPos + dx);
  paint(painter, option, widget);
}

void missile::move(){
    //check collision
    QList<QGraphicsItem *> collision = collidingItems();

    for (int i = 0, j = collision.size(); i < j; ++i)
    {
        if (typeid(*(collision[i])) == typeid(alien))
        {
            gm->sc->increase();
            //
            scene()->removeItem(collision[i]);
            scene()->removeItem(this);
            delete collision[i];
            delete this;
            return;
        }
    }

   // std::cout << "PROCEED";
    setPos(x(),y()-10);
    if (pos().y() + length < 0) {
        scene()->removeItem(this);
        delete this;
        qDebug () << "deleted";
    }

//    for (int i{0}; i < 40; i++)
//     {
//       //scene->addItem(&alienArr[i]);
////        alien ** data = gm->alienArr->data();
////        if (*data == NULL)
////            std::cout << "BANG BANG";
//         gm->alienArr->at(12)->move();
//     }
 }

