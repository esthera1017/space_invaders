#include "score.hpp"
#include <QFont>

score::score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    scor = 0;

    // draw the text
    setPlainText(QString("Score: ") + QString::number(scor)); // Score: 0
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void score::increase(){
    scor++;
    setPlainText(QString("Score: ") + QString::number(scor)); // Score: 1
}

int score::getScore(){
    return scor;
}
