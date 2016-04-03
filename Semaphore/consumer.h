#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QSemaphore>

class QThread;

class Consumer : public QObject
{
public:
    Consumer(int dataSize,
             char buffer[],
             int bufferSize,
             QThread* workingThread,
             QObject* parent = 0);

    ~Consumer();

public slots:
    void work();

private:
    const int _dataSize;
    char* _buffer;
    int _bufferSize;
    QSemaphore* _usedSpace;
    QThread* _workingThread;
};

#endif // CONSUMER_H
