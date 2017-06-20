#include "drawwindow.h"

DrawWindow::DrawWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(400, 400);
    outputGraph = new QLabel;
    outputGraph->setBackgroundRole(QPalette::Light);
    outputGraph->setScaledContents(true);
    scrollArea = new QScrollArea(this);
    scrollArea->setBackgroundRole(QPalette::Light);
    scrollArea->setWidget(outputGraph);
    scrollArea->setFixedSize(400, 400);

}
void DrawWindow::CalcParam()
{
    if (coordinates.GetPointsList().length()>0)
    {
        if (coordinates.GetMinX() >= 0) OxMin = -0.5;
        else OxMin = coordinates.GetMinX();
        if (coordinates.GetMaxX() <= 0) OxMax = 0.5;
        else OxMax = coordinates.GetMaxX();
        if (coordinates.GetMinY() >= 0) OyMin = -0.5;
        else
        {
            OyMin = floor(coordinates.GetMinY());
            if ((OyMin+0.5)<coordinates.GetMinY())
                OyMin+=0.5;
        }
        if (coordinates.GetMaxY() <= 0) OyMax = 0.5;
        else
        {
            OyMax = ceil(coordinates.GetMaxY());
            if ((OyMax-0.5)>coordinates.GetMaxY())
                OyMax-=0.5;
        }
        OxMinPix = OxMin*onePixel-traitsDist;
        OxMaxPix = OxMax*onePixel+traitsDist;
        OyMinPix = OyMin*onePixel-traitsDist;
        OyMaxPix = OyMax*onePixel+traitsDist;

        OxLength = (abs(OxMinPix)+abs(OxMaxPix));
        OyLength = (abs(OyMinPix)+abs(OyMaxPix));
    }
}

void DrawWindow::paintEvent(QPaintEvent *) {

    if (coordinates.GetPointsList().length()>0)
    {
        CalcParam();
        SetScaled();

        QPixmap graph(scl*OxLength, scl*OyLength);
        graph.fill(QColor(Qt::white));

        QPainter p;
        p.begin(&graph);
        p.setWindow(QRect(OxMinPix, -OyMaxPix, OxLength, OyLength));

        p.setPen(QPen(Qt::lightGray, 1, Qt::SolidLine));
        for (int i=OxMinPix; i<=OxMaxPix; i+=traitsDist)
        {
            p.drawLine(i, -OyMaxPix, i, -OyMinPix);
        }
        for (int i=-OyMaxPix; i<=-OyMinPix; i+=traitsDist)
        {
            p.drawLine(OxMinPix, i, OxMaxPix, i);
        }

        p.setPen(QPen(Qt::black, 1, Qt::SolidLine));

        p.drawLine(OxMinPix, 0, OxMaxPix, 0);
        p.drawLine(0, -OyMinPix, 0, -OyMaxPix);

        p.drawLine(OxMaxPix, 0, OxMaxPix-10, numShift*2);
        p.drawLine(OxMaxPix, 0, OxMaxPix-10, -numShift*2);
        p.drawLine(0, -OyMaxPix, numShift*2, -OyMaxPix+10);
        p.drawLine(0, -OyMaxPix, -numShift*2, -OyMaxPix+10);

        p.setPen(QPen(Qt::green, 2, Qt::SolidLine));
        for (int i=0; i<coordinates.GetPointsList().length()-1; i++)
        {
            p.drawLine(coordinates.GetPointsList().at(i).GetX()*onePixel,-coordinates.GetPointsList().at(i).GetY()*onePixel,coordinates.GetPointsList().at(i+1).GetX()*onePixel,-coordinates.GetPointsList().at(i+1).GetY()*onePixel);
        }
        p.setPen(QPen(Qt::darkGreen, 3, Qt::SolidLine));
        for (int i=0; i<coordinates.GetPointsList().length(); i++)
        {
            p.drawPoint(coordinates.GetPointsList().at(i).GetX()*onePixel,-coordinates.GetPointsList().at(i).GetY()*onePixel);
        }
        p.setPen(QPen(Qt::black, 1, Qt::SolidLine));
        for (int i=OxMinPix+traitsDist; i<OxMaxPix; i+=5*traitsDist)
        {
            p.drawLine(i, numShift, i, -numShift);
        }
        for (int i=-OyMaxPix+traitsDist; i<-OyMinPix; i+=5*traitsDist)
        {
            p.drawLine(numShift, i, -numShift, i);
        }
        for (float num=OxMin; num<=OxMax; num+=h)
        {
            p.drawText(num*onePixel-2*numShift, numShift, 2*numShift, 2*numShift, Qt::TextDontClip, QString::number(num));
        }
        for (float num=OyMin; num<=OyMax; num+=h)
        {
           if (num!=0.0f)
           p.drawText(2*numShift, -num*onePixel-2*numShift, 2*numShift, 2*numShift, Qt::TextDontClip, QString::number(num));
        }
        p.drawText(OxMaxPix-3*numShift, -6*numShift, 2*numShift, 2*numShift, Qt::TextDontClip, "X");
        p.drawText(-4*numShift, -OyMaxPix, 3*numShift, 3*numShift, Qt::TextDontClip, "У");

        p.end();
        outputGraph->setPixmap(graph);

    }

}

void DrawWindow::wheelEvent(QWheelEvent *event)
{
    int numDegrees = event->delta() / 8;
    int numSteps = numDegrees / 15;
    if (event->modifiers() == Qt::ShiftModifier)
    {
        scl=scl+numSteps*hScl;
        if (scl<minScl) scl = minScl;
        else if (scl>maxScl) scl = maxScl;
        if (scl>=minScl && scl<=maxScl)
        {
            SetScaled();
            emit ResetScale(scl);
        }
    }
    event->accept();
}

void DrawWindow::mousePressEvent(QMouseEvent *e)
{
    mousePos = e->pos();
}
void DrawWindow::mouseMoveEvent(QMouseEvent *e)
{
    QPoint diff = e->pos() - mousePos;
    mousePos = e->pos();
    scrollArea->verticalScrollBar()->setValue(scrollArea->verticalScrollBar()->value() - diff.y());
    scrollArea->horizontalScrollBar()->setValue(scrollArea->horizontalScrollBar()->value() - diff.x());
}

void DrawWindow::SetCoordinates(CoordinatesList list)
{
    coordinates = list;
    repaint();
}

void DrawWindow::SetScaled()
{
   outputGraph->setFixedSize(scl*OxLength, scl*OyLength);
}

void DrawWindow::ScaledGraph(int scale)
{
    scl=(double)scale/(double)100;
    SetScaled();
}

