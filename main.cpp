#include <QApplication>
#include <QGraphicsView>

#include "alien.hpp"
#include "player.hpp"
#include "missile.hpp"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QGraphicsScene* scene{new QGraphicsScene};

    alien a{10, 10, 20, 20};
    //scene->addItem(&a);

    player j{100, 100, 20, 60};
    scene->addItem(&j);
    j.setFlag(QGraphicsItem::ItemIsFocusable);
    j.setFocus();

//    missile m{20, 30, 2, 5};
//    scene->addItem(&m);

    QGraphicsView view{scene};
    QPainter p{&view};
    a.paint(&p, nullptr, &view);

    view.show();
    return app.exec();
}
