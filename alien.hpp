#include "elem.hpp"

#ifndef ALIEN_HPP
#define ALIEN_HPP

class alien : public elem
{
  public:
    alien(int, int, int, int);
    alien(const alien &);

    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    QRectF boundingRect() const override;
    void erase(QPainter*) const override;
    void updatePos(int, int, QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
 };

#endif
