#include <QApplication>
#include <QGraphicsView>

#include "alien.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    qreal xPos{0};
    qreal yPos{0};
    qreal width{640};
    qreal height {480};

    QGraphicsScene scene{xPos, yPos, width, height, nullptr};

    alien a{10, 10, 20, 20};

    scene.addItem(&a);

    QGraphicsView view{&scene};

    QPainter p{&view};

    a.paint(&p, nullptr, &view);

    view.show();


    return app.exec();
}
