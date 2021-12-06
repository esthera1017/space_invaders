#include "elem.hpp"

#ifndef MISSILE_HPP
#define MISSILE_HPP

class missile : public elem
{
  public:
    missile(int, int, int, int);
    
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    QRectF boundingRect() const override;
    void erase(QPainter*) const override;
    void updatePos(int, int, QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
 };

#endif
