#include "graphtable.h"

GraphTable::GraphTable()
{

    table = new QTableWidget();
    table->setRowCount(0);
    table->setColumnCount(numCol);

    QStringList nameTable;
    nameTable << head1 << head2;

    table->setHorizontalHeaderLabels(nameTable);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QVBoxLayout *lay = new QVBoxLayout;
    lay->addWidget(table);

    setLayout(lay);
}

void GraphTable::SetData(QList<Point> list)
{

    table->setRowCount(list.length());

    for(int row = 0; row < table->rowCount(); row++)
      for(int column = 0; column < table->columnCount(); column++)
         table->setItem(row, column, new QTableWidgetItem());

    for (int i=0; i<list.length(); i++)
    {
        table->item(i,0)->setText(QString::number(list.at(i).GetX(), 'g', 4));
        table->item(i,1)->setText(QString::number(list.at(i).GetY(), 'g', 4));
    }
}
