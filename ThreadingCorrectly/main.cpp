#include <QCoreApplication>
#include <QThread>
#include "myobject.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread cThread;

    QObject::connect(&cThread, &QThread::finished, &a, &QCoreApplication::quit);

    MyObject cObject;
    cObject.doSetup(&cThread);
    cObject.moveToThread(&cThread);

    cThread.start();

    return a.exec();
}
