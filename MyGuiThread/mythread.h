#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = 0);

    void run();
    void setStop(bool need2stop);
    bool isStopped() const;

signals:
    void numberChanged(int);

private:
    bool _stop;
};

#endif // MYTHREAD_H
