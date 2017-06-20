#include "coordinateslist.h"

CoordinatesList::CoordinatesList()
{


}

float CoordinatesList::GetMinX()
{
    return xMin;
}

float CoordinatesList::GetMinY()
{
    return yMin;
}

float CoordinatesList::GetMaxX()
{
    return xMax;
}

float CoordinatesList::GetMaxY()
{
    return yMax;
}

QList<Point> CoordinatesList::GetPointsList()
{
    return pointslist;
}

void CoordinatesList::AddPoint(float X, float Y)
{
    Point point(X,Y);
    pointslist.append(point);
}
