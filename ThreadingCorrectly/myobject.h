#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>

class QThread;

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);
    void doSetup(QThread* pTread);
signals:

public slots:
    void doWork();
private:
    QThread* _workingThread;
};

#endif // MYOBJECT_H
