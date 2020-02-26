#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <wiringSerial.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "facewindow.h"
int fd;
int main(int argc, char *argv[])
{

    char ctl=50;
    if((fd = serialOpen("/dev/ttyAMA0", 38400)) < 0)
    {
        fprintf(stderr,"Unable to open serial device: %s\n", strerror(errno));
        //return 1;
    }

    serialPuts(fd, "Usart send Test,Just by launcher!");
    serialPutchar(fd, ctl);
    QApplication a(argc, argv);
    faceWindow w;
        w.show();
    w.move ((QApplication::desktop()->width() - w.width())/2,(QApplication::desktop()->height() - w.height())/2);
    return a.exec();
}
