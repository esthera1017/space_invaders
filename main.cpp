#include <QApplication>
#include <QGraphicsView>
#include <iostream>

#include "alien.hpp"
#include "player.hpp"
#include "missile.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QGraphicsScene* scene{new QGraphicsScene};

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
            if (j % 2 == 1)
              {
               a.setXPos((int) (alienSize * 1.5 * i));
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

    QGraphicsView view{scene};

    QPainter painter{&view};

    qreal xPosQ = qreal(0);
    qreal yPosQ = qreal(0);
    qreal widthQ = qreal(1000);
    qreal lengthQ = qreal(1000);
    QRectF rectangle{xPosQ, yPosQ, widthQ, lengthQ};
    QImage image{"/Users/estheramao/Downloads/space.jpg"};
    painter.drawImage(rectangle, image);

    view.show();


    return app.exec();
}
