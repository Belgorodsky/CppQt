#include "mythread.h"
#include <QDebug>

MyThread::MyThread()
{

}

void MyThread::run()
{
    QMutex mutex;
    qDebug() << "Running ";

    for(int i = 0; i < 1e4; ++i)
    {
        mutex.lock();
        if(_stop)
        {
            mutex.unlock();
            break;
        }
        mutex.unlock();
        sleep(1);
        qDebug() <<  objectName() << i;

    }
}

void MyThread::setStop(bool needStop)
{
    QMutex mutex;
    mutex.lock();
    _stop = needStop;
    mutex.unlock();
}

bool MyThread::isStoped() const
{
    return _stop;
}
