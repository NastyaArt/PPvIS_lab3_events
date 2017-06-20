#ifndef DRAWWINDOW_H
#define DRAWWINDOW_H

#include <QWidget>
#include <QPainter>
#include <QScrollArea>
#include <QLabel>
#include <QPixmap>
#include <QWheelEvent>
#include <QtMath>
#include <QMessageBox>
#include <QScrollArea>
#include <QScrollBar>
#include "coordinateslist.h"

class DrawWindow : public QWidget
{
    Q_OBJECT
public:
    explicit DrawWindow(QWidget *parent = 0);

    void SetCoordinates(CoordinatesList list);
    void ScaledGraph(int scale);

private:
    CoordinatesList coordinates;
    QLabel *outputGraph;
    QScrollArea *scrollArea;
    QPoint mousePos;
    const int onePixel=100;
    const int numShift=3;
    const int traitsDist=10;
    int OxLength=0;
    int OyLength=0;

    int OxMinPix;
    int OxMaxPix;
    int OyMinPix;
    int OyMaxPix;
    double OxMin;
    double OxMax;
    double OyMin;
    double OyMax;
    double scl=1.0;
    const double hScl=0.1;
    const double minScl=0.1;
    const double maxScl=2.0;
    const float h=0.5f;
    void SetScaled();
    void CalcParam();
protected:
    void paintEvent(QPaintEvent *);
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);

signals:
    void ResetScale(double scale);

public slots:
};

#endif // DRAWWINDOW_H
