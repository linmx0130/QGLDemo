#include "paintingwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintingWidget w(nullptr);
    w.resize(800, 600);
    w.show();
    return a.exec();
}
