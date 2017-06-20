#include "progressevent.h"

ProgressEvent::ProgressEvent() : QEvent((Type)ProgressType)
{

}

CoordinatesList ProgressEvent::GetList()
{
    return pointlist;
}

void ProgressEvent::SetList(CoordinatesList list)
{
    pointlist=list;
}

void ProgressEvent::SetStatus(bool st)
{
    finish=st;
}

bool ProgressEvent::GetStatus()
{
    return finish;
}
