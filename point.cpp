#include "point.h"

Point::Point(float X, float Y)
{
    x=X;
    y=Y;
}

float Point::GetX() const
{
   return x;
}

float Point::GetY() const
{
   return y;
}
