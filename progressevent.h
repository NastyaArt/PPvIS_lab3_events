#ifndef PROGRESSEVENT_H
#define PROGRESSEVENT_H

#include <QEvent>
#include "coordinateslist.h"

class ProgressEvent : public QEvent
{
public:
    enum {ProgressType = User + 1};
    ProgressEvent();
    void SetList(CoordinatesList list);
    CoordinatesList GetList();
    void SetStatus(bool st);
    bool GetStatus();
private:
    CoordinatesList pointlist;
    bool finish=false;

};

#endif // PROGRESSEVENT_H
