#include "elem.hpp"
#include <QObject>

#ifndef PLAYER_HPP
#define PLAYER_HPP

class player : public QObject, public elem
{
    Q_OBJECT
  public:
    player(int, int, int, int);
    
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;
    QRectF boundingRect() const override;
    void erase(QPainter*) const override;
    void updatePos(int, int, QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override;

protected:
    void keyPressEvent(QKeyEvent *event) override;

public slots:
    void alienMove();
 };

#endif
