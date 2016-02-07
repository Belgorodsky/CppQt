#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    QMutex mutex;
    for( int i = 0 ; i < 1e4; ++i)
    {
        mutex.lock();
        if(_stop)
        {
            mutex.unlock();
            break;
        }
        mutex.unlock();
        emit numberChanged(i);
        msleep(100);
    }
}

void MyThread::setStop(bool need2stop)
{
    QMutex mutex;
    mutex.lock();
    _stop = need2stop;
    mutex.unlock();
}

bool MyThread::isStopped() const
{
    return _stop;
}
