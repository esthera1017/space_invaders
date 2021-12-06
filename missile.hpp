#ifndef MISSILE_H
#define MISSILE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <elem.hpp>

class missile: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    missile();
    //void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
public slots:
    void move();
};

#endif // MISSILE_H
