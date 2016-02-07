#include <QCoreApplication>
#include "mythread.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyThread thread;

     thread.start();
     thread.wait();
     qDebug() << "Done!";

    return a.exec();
}
