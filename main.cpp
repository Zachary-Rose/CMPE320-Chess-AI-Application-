#include "chesspp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    chesspp w;
    w.show();
    return a.exec();
}
