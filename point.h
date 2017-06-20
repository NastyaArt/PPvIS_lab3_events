#ifndef POINT_H
#define POINT_H

#include <QObject>

class Point
{

public:

    Point(float X, float Y);

    float GetX() const;
    float GetY() const;

private:
    float x;
    float y;


};

#endif // POINT_H
