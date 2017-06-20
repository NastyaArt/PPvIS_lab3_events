#ifndef INPUTDATA_H
#define INPUTDATA_H

#include <QEvent>

class InputData : public QEvent
{
public:
    InputData(int A, int B, int XMin, int XMax);

    void SetValue(int A, int B, int XMin, int XMax);
    int GetA() const;
    int GetB() const;
    int GetXMin() const;
    int GetXMax() const;

private:
    int a;
    int b;
    int xMin;
    int xMax;
};

#endif // INPUTDATA_H
