#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "player.hpp"
#include "alien.hpp"
#include "score.hpp"
//#include "Health.h"

class game: public QGraphicsView{
public:
    game(QWidget * parent=0);

    QGraphicsScene * scene;
    player * pl;
    score * sc;
    alien * al;
    int store[40];
    std::vector<alien *> * alienArr = new std::vector<alien *> ();

    //Health * health;

};

#endif // GAME_H
