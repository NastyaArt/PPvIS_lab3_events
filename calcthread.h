#ifndef CALCTHREAD_H
#define CALCTHREAD_H

#include <QObject>
#include <QThread>
#include <QApplication>
#include <windows.h>
#include "coordinateslist.h"
#include "progressevent.h"
#include "inputdata.h"


class CalcThread : public QThread
{
    Q_OBJECT
public:
    CalcThread(QObject* pobjReceiver);
    void run();
private:
    QObject* m_pobjReceiver;

    QMutex	m_mutex;

    void customEvent(QEvent* pe);

    int a;
    int b;
    int xMin;
    int xMax;
    float h=0.1f;
    float eps=0.0001f;

    void SetDataToStart(int A, int B, int XMin, int XMax);
};

#endif // CALCTHREAD_H
