#include "game.hpp"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "alien.hpp"
#include <iostream>
#include <stdlib.h>
#include "score.hpp"

//score sc;

game::game(QWidget *parent){
    // create the scene'
    //alienArr = NULL;
    scene = new QGraphicsScene();
    setScene(scene);
    setFixedSize(800, 800);
    setSceneRect(0, 0, 800, 800);
   // spawn enemies
//    QTimer * timer = new QTimer();
//    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
//    timer->start(2000);

    //enemies
    //std::vector<alien> alienArr;
    int rows{4};
    int columns{10};
    int alienSize{40};
    alienArr->reserve(rows * columns);
    for (int i{0}; i < columns; i++)
      {
        for (int j{0}; j < rows; j++)
          {
            al = new alien (alienSize, alienSize, (110 + (int) (alienSize * 1.5 * i)), (20 + (int) (alienSize * 1.5 * j)));
            if (j % 2 == 1)
              {
               al->setXPos((int) (alienSize * 1.5 * i) + 70);
              }
            alienArr->emplace_back(new alien{al});
           // alienArr->at(num) = new alien{al};
          }
      }

    for (int i{0}; i < rows * columns; i++)
     {
       scene->addItem(alienArr->at(i));
       alienArr->at(i)->id = i;
     }

//    //Create Player
      pl = new player((int) (alienSize * 1.5), (int) (alienSize * 1.5), 0, 0);
  // player p{(int) (alienSize * 1.5), (int) (alienSize * 1.5), 0, 0};
//    scene->addItem(&p);
    pl->setFlag(QGraphicsItem::ItemIsFocusable);
    pl->setFocus();
     //pl->setPos(400,500);
     scene->addItem(pl);
       std::cout<<(pl->length);
    //     p.setPos(view.width()/2 - p.width/2, view.height() - p.length);
    pl->setPos(this->width()/2 - pl->width/2, this->height() - pl->length);


   //  create the score/health
    sc = new score();
    scene->addItem(sc);

    //health = new Health();
    //health->setPos(health->x(),health->y()+25);
    //scene->addItem(health);

    // spawn enemies
    //random number btwn 0-39
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),pl,SLOT(alienMove()));
    timer->start(2000);

    show();
}


//Thread 0 Crashed::  Dispatch queue: com.apple.main-thread
//0   spaceInvadersProject          	       0x100a49998 alien*& std::__1::vector<alien*, std::__1::allocator<alien*> >::emplace_back<alien*>(alien*&&) + 24 (vector:1682)
//1   spaceInvadersProject          	       0x100a49662 game::game(QWidget*) + 594 (game.cpp:37)
//2   spaceInvadersProject          	       0x100a49a7d game::game(QWidget*) + 29 (game.cpp:11)
//3   spaceInvadersProject          	       0x100a4aeb6 main + 86 (main.cpp:69)
//4   dyld                          	       0x10eb5f4fe start + 462

