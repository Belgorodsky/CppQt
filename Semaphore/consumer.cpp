#include "consumer.h"

#include <QThread>

#include <iostream>

Consumer::Consumer(int dataSize,
                   char buffer[],
                   int bufferSize,
                   QThread *workingThread,
                   QObject *parent) :
    QObject(parent),
    _dataSize(dataSize), _buffer(buffer), _bufferSize(bufferSize),
    _usedSpace(new QSemaphore(2 * bufferSize)), _workingThread(workingThread)
{
    connect(workingThread,&QThread::started, this, &Consumer::work);
    moveToThread(workingThread);
}

Consumer::~Consumer()
{
    delete _usedSpace;
}

void Consumer::work()
{
    for(int i = 0; i < _dataSize; ++i)
    {
        _usedSpace->acquire();
        std::cerr << _buffer[i % _bufferSize];
        _usedSpace->release();
        _workingThread->msleep(50);
    }
    std::cerr << std::endl;
}
