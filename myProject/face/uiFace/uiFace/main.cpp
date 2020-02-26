#include "facewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    faceWindow w;
    w.show();

    return a.exec();
}
