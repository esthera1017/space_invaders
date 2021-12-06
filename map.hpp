#include "elem.hpp"

#ifndef MAP_HPP
#define MAP_HPP

class map : public elem
{
  public:
    map(int, int, int, int);

    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    QRectF boundingRect() const override;
    void erase(QPainter*) const override;
    void updatePos(int, int, QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
 };

#endif
