#include <QObject>
#include "elem.hpp"

#ifndef ALIEN_HPP
#define ALIEN_HPP

class alien : public QObject, public elem
{
        Q_OBJECT
  public:
    alien(int, int, int, int);
    alien(const alien *);
    int id = 0;
    bool flag = false;

    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    QRectF boundingRect() const override;
    void erase(QPainter*) const override;
    void updatePos(int, int, QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    //void move();
  public slots:
    void move();
 };

#endif
