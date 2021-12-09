#include <QApplication>
#include <QGraphicsView>
#include <iostream>
#include "map.hpp"
#include "alien.hpp"
#include "player.hpp"
#include "missile.hpp"
#include "score.hpp"
#include "game.hpp"

//int main(int argc, char *argv[])
//{
//    QApplication app(argc, argv);
//    QGraphicsScene* scene{new QGraphicsScene};


//    //Create Aliens
//    std::vector<alien> alienArr;
//    int rows{4};
//    int columns{10};
//    int alienSize{40};
//    for (int i{0}; i < columns; i++)
//      {
//        for (int j{0}; j < rows; j++)
//          {
//            alien a{alienSize, alienSize, (110 + (int) (alienSize * 1.5 * i)), (20 + (int) (alienSize * 1.5 * j))};
//            if (j % 2 == 1)
//              {
//               a.setXPos((int) (alienSize * 1.5 * i) + 70);
//              }
//            alienArr.emplace_back(alien{a});
//          }
//      }
//    for (int i{0}; i < rows * columns; i++)
//     {
//       scene->addItem(&alienArr[i]);
//     }

//    //Create Player
//    player p{(int) (alienSize * 1.5), (int) (alienSize * 1.5), 0, 0};
//    scene->addItem(&p);
//    p.setFlag(QGraphicsItem::ItemIsFocusable);
//    p.setFocus();

//    //Create Score
//    score * sc = new score();
//    scene->addItem(sc);

//    //Create Background
//   //map m = map(800, 600, 0, 0);
//   //m.setOpacity(0.4);
//   //scene->addItem(&m);
//    QGraphicsView view{scene};

//    //we can disable scroll bars if sizing doesn't work otherwise, we should set SceneSize
//    view.show();
//    view.setFixedSize(800, 800);
//    scene->setSceneRect(0, 0, 800, 800);
//    p.setPos(view.width()/2 - p.width/2, view.height() - p.length);
//    return app.exec();
//}


game * gm;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    gm = new game();
    gm->show();


    return a.exec();
}
