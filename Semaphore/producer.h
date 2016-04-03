#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QSemaphore>

class QThread;

class Producer : public QObject
{
public:
    Producer(int dataSize,
             char buffer[],
             int bufferSize,
             QThread* workingThread,
             QObject* parent = 0);
    ~Producer();

public slots:
    void work();

private:
    const int _dataSize;
    char* _buffer;
    int _bufferSize;
    QSemaphore* _freeSpace;
    QThread* _workingThread;
};

#endif // PRODUCER_H
