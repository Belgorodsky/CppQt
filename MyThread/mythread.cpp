#include "mythread.h"
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
{
    for(int i = 0; i < 1e4; ++i)
        qDebug() << "Running " << objectName() << i;
}
