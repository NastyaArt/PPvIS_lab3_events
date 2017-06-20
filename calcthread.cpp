#include "calcthread.h"

CalcThread::CalcThread(QObject* pobjReceiver) : m_pobjReceiver(pobjReceiver)
{

}


void CalcThread::SetDataToStart(int A, int B, int XMin, int XMax)
{
    a=A;
    b=B;
    xMin=XMin;
    xMax=XMax;
    start();
}

void CalcThread::run()
{
    CoordinatesList pointlist;

    m_mutex.lock();
    pointlist.xMin=xMin;
    pointlist.xMax=xMax;
    m_mutex.unlock();

    float ymin=0.0f, ymax=0.0f;

    for (float x=(float)xMin; abs(x - xMax) < eps || x<(float)xMax; x=x+h)
    {
        int i=1;
        float yi=1.0f, y=0;

        while (abs(yi)>eps) {
                yi=pow(-1, i-1)*sin(i*(a*x-b))/i;
                y+=yi;
                i++;
        }
        y = floor(y*pow(10.0,4)+0.5)/pow(10.0,4); //округление
        x = floor(x*pow(10.0,1)+0.5)/pow(10.0,1);
        if(y < ymin)
            ymin = y;
        if(y > ymax)
            ymax = y;

        m_mutex.lock();
        pointlist.AddPoint(x, y);
        pointlist.yMin=ymin;
        pointlist.yMax=ymax;
        m_mutex.unlock();
        ProgressEvent* pe = new ProgressEvent;
        pe->SetList(pointlist);
        if (abs(x - xMax) == eps || x==(float)xMax) pe->SetStatus(true);
        QApplication::postEvent(m_pobjReceiver, pe);

    }
    return;
}

void CalcThread::customEvent(QEvent* pe)
{
    if ((int)pe->type() == InputData::User) {
        SetDataToStart(((InputData*)(pe))->GetA(), ((InputData*)(pe))->GetB(), ((InputData*)(pe))->GetXMin(), ((InputData*)(pe))->GetXMax());
    }
}
