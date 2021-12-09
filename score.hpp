#ifndef SCORE_HPP
#define SCORE_HPP

#include <QGraphicsTextItem>

class score: public QGraphicsTextItem{
public:
    score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int scor;
};

#endif // SCORE_HPP
