#include "inputdata.h"

InputData::InputData(int A, int B, int XMin, int XMax)  : QEvent(QEvent::User)
{
    a=A;
    b=B;
    xMin=XMin;
    xMax=XMax;
}

void InputData::SetValue(int A, int B, int XMin, int XMax)
{
    a=A;
    b=B;
    xMin=XMin;
    xMax=XMax;
}

int InputData::GetA() const
{
    return a;
}
int InputData::GetB() const
{
    return b;
}
int InputData::GetXMin() const
{
    return xMin;
}
int InputData::GetXMax() const
{
    return xMax;
}
