#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void run();
    void setStop(bool needStop);
    bool isStoped() const;
private:
    bool _stop;
};

#endif // MYTHREAD_H
