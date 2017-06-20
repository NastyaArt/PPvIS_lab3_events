#ifndef COORDINATESLIST_H
#define COORDINATESLIST_H

#include <QObject>
#include <QMetaType>
#include "point.h"


class CoordinatesList
{

public:

    CoordinatesList();
    QList<Point> GetPointsList();

    float GetMinX();
    float GetMinY();
    float GetMaxX();
    float GetMaxY();
    void AddPoint(float X, float Y);
    float yMin;
    float yMax;
    int xMin;
    int xMax;

private:
    QList<Point> pointslist;
};


#endif // COORDINATESLIST_H

