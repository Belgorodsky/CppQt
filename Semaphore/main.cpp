#include <QCoreApplication>
#include "producer.h"
#include "consumer.h"

#include <QThread>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    const int dataSize = 1e5;
    const int bufferSize = 4096;
    char buffer[bufferSize];

    QThread thread1, thread2;

    Producer producer(dataSize, buffer, bufferSize, &thread1);
    Consumer consumer(dataSize, buffer, bufferSize, &thread2);

    thread1.start();
    thread2.start();

    thread1.wait();
    thread2.wait();

    return 0;
}
