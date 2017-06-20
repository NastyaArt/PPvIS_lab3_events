#ifndef GRAPHTABLE_H
#define GRAPHTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QHeaderView>
#include "point.h"

class GraphTable : public QWidget
{
public:
    GraphTable();
    void SetData(QList<Point> list);
private:
    int numCol=2;
    QTableWidget *table;
    QString head1="X";
    QString head2="Y";
};

#endif // GRAPHTABLE_H
