#include "myobject.h"
#include <QThread>
#include <QDebug>

MyObject::MyObject(QObject *parent) : QObject(parent)
{

}

void MyObject::doSetup(QThread *pTread)
{
    _workingThread = pTread;
    connect(pTread,&QThread::started, this, &MyObject::doWork);
}

void MyObject::doWork()
{
    for(int i = 0 ; i < 1e2; ++i)
    {
        qDebug() << i;
//        _workingThread->msleep(10);
    }
    _workingThread->exit();
}
