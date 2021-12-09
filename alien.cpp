#include "alien.hpp"
#include "elem.hpp"
#include "missile.hpp"
#include "player.hpp"
#include "game.hpp"
#include <QRect>
#include <iostream>
#include <QTimer>
#include <QList>

extern game * gm;

alien::alien(int width, int length, int xPos, int yPos) : elem::elem {width, length, xPos, yPos}
{
    /*/ make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);*/
}

alien::alien(const alien* al) : elem::elem {al->width, al->length, al->xPos, al->yPos}
{}

void alien::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
 // painter->fillRect(xPos, yPos, width, length, "green");

  qreal xPosQ = qreal(xPos);
  qreal yPosQ = qreal(yPos);
  qreal widthQ = qreal(width);
  qreal lengthQ = qreal(length);
  QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
  QImage image{"/Users/lloydtmaodzeka/space/space_invaders/alien.png"};
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
/*
void alien::shoot(){
    // shoot alien missile

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
*/

void alien::move(){
    //check collision
    QList<QGraphicsItem *> collision = collidingItems();
    for (int i = 0, j = collision.size(); i < j; ++i)
    {
        if (typeid(*(collision[i])) == typeid(player))
        {
            gm->sc->increase();
            //scene()->removeItem(collision[i]);
            scene()->removeItem(this);
            gm->alienArr->at(this->id) = NULL;
            delete this;
            flag = true;

            //delete collision[i];
            //delete this;

            return;
        } else if (typeid(*(collision[i])) == typeid(missile)) {
            flag = true;
            return;
        }
    }

   // std::cout << "PROCEED";
    if (!flag){
        setPos(x(),y()+10);
     if (pos().y() - this->length == 760) {
         scene()->removeItem(this);
//         scene()->removeItem(this);
 //        delete gm->alienArr->at(num);
         gm->alienArr->at(this->id) = NULL;
         delete this;
         qDebug () << "deleted";
     }
    }
//       setPos(x(),y()+10);
//    if (pos().y() - this->length > 800) {
//        scene()->removeItem(this);
////        delete gm->alienArr->at(num);
//        gm->alienArr->at(this->id) = NULL;
//        delete this;
//        qDebug () << "deleted";
//    }
}
