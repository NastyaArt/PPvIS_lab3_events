#include "mainwindow.h"
#include "calcthread.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CalcThread ct(&w);
    w.SetReceiver(&ct);

    w.setWindowTitle("Лабораторная работа 3");
    w.show();

    return a.exec();
}
