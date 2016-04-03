#include "producer.h"

#include <QThread>

Producer::Producer(int dataSize,
                   char buffer[],
                   int bufferSize,
                   QThread *workingThread,
                   QObject *parent) :
    QObject(parent),
    _dataSize(dataSize), _buffer(buffer), _bufferSize(bufferSize),
    _freeSpace(new QSemaphore(bufferSize)), _workingThread(workingThread)
{
    connect(workingThread,&QThread::started, this, &Producer::work);
    moveToThread(workingThread);
}

Producer::~Producer()
{
    delete _freeSpace;
}

void Producer::work()
{
    for(int i = 0; i < _dataSize; ++i)
    {
        _freeSpace->acquire();
        _buffer[i % _bufferSize] = "YTSD"[(int)rand() % 4];
        _freeSpace->release();
        _workingThread->msleep(50);
    }
}
