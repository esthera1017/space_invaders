#include <QApplication>
#include <QGraphicsView>
#include <iostream>
#include "map.hpp"
#include "alien.hpp"
#include "player.hpp"
#include "missile.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QGraphicsScene* scene{new QGraphicsScene};

//    alien a{30, 30, 20, 20};
//    //scene->addItem(&a);
//    player j{100, 100, 0, 0};
//    scene->addItem(&j);
//    j.setFlag(QGraphicsItem::ItemIsFocusable);
//    j.setFocus();
//    missile m{20, 30, 2, 5};
//    scene->addItem(&m);
    int rows{3};
       int columns{7};
       int alienSize{40};

       std::vector<alien> alienArr;
       alienArr.reserve(rows * columns);

       for (int i{0}; i < columns; i++)
         {
           for (int j{0}; j < rows; j++)
             {
               alien a{alienSize, alienSize, (20 + (int) (alienSize * 1.5 * i)), (20 + (int) (alienSize * 1.5 * j))};
//               if (j % 2 == 1)
//                 {
//                  a.setXPos((int) (alienSize * 1.5 * i));
//                 }
               alienArr.emplace_back(alien{a});
             }
         }

       for (int i{0}; i < rows * columns; i++)
         {
           scene->addItem(&alienArr[i]);
         }

//       player j{100, 100, 0, 0};
//       scene->addItem(&j);
       //player p{(int) (alienSize * 1.5), (int) (alienSize * 1.5), (int) (rows * alienSize * 1.5), (int) (columns * alienSize * 1.75)};
       player p{(int) (alienSize * 1.5), (int) (alienSize * 1.5), 0, 0};
       scene->addItem(&p);
       p.setFlag(QGraphicsItem::ItemIsFocusable);
       p.setFocus();

       map m = map(800, 600, 0, 0);
       m.setOpacity(0.4);
      // scene->addItem(&m);
    QGraphicsView view{scene};
//    QPainter p{&view};
//    a.paint(&p, nullptr, &view);

    //we can disable scroll bars if sizing doesn't work otherwise, we should set SceneSize
    view.show();
    view.setFixedSize(800, 600);
    scene->setSceneRect(0, 0, 800, 600);
    //j->rect().height();
//  j.setPos(view.width())/2, view.height());
//  player->setPos(view->width()/2,view->height() - player->rect().height());

//    j.setXPos(view.width()/2);
//    j.setYPos(view.height() - j.length);
    p.setPos(view.width()/2, view.height() - p.length);
    return app.exec();
}
