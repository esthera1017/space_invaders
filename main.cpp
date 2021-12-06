#include <QApplication>
#include <QGraphicsView>
#include <iostream>

#include "alien.hpp"
#include "player.hpp"
#include "missile.hpp"
#include "map.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QGraphicsScene* scene{new QGraphicsScene};

    int rows{5};
    int columns{10};
    int alienSize{40};

    std::vector<alien> alienArr;
    alienArr.reserve(rows * columns);

    for (int i{0}; i < columns; i++)
      {
        for (int j{0}; j < rows; j++)
          {
            alien a{alienSize, alienSize, (100 + (int) (alienSize * 1.5 * i)), (100 + (int) (alienSize * 1.5 * j))};
            if (j % 2 == 1)
              {
               //a.setXPos((int) (alienSize * 1.5 * i));
              }
            alienArr.emplace_back(alien{a});
          }
      }

    for (int i{0}; i < rows * columns; i++)
      {
        scene->addItem(&alienArr[i]);
      }

    player p{(int) (alienSize * 1.5), (int) (alienSize * 1.5), (int) (rows * alienSize * 1.5), (int) (columns * alienSize * 1.75)};

    scene->addItem(&p);

    map m{800, 800, 0, 0};

    m.setOpacity(0.4);

    scene->addItem(&m);

    QGraphicsView view{scene};

    view.show();


    return app.exec();
}
