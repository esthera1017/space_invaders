#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

#ifndef ELEM_HPP
#define ELEM_HPP

class elem : public QGraphicsItem
{
  protected:
    int width;
    int length;
    int xPos;
    int yPos;
  
   public:
    elem(int, int, int, int);
  
    virtual ~elem();
 
    void setXPos(int);
    void setYPos(int);
    virtual void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) = 0;
    virtual QRectF boundingRect() const = 0;
    virtual void erase(QPainter*) const = 0;
    virtual void updatePos(int, int, QPainter*, const QStyleOptionGraphicsItem*, QWidget*) = 0;

};
   
#endif
