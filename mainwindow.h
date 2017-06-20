#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <QDesktopWidget>

#include "graphtable.h"
#include "coordinateslist.h"
#include "drawwindow.h"
#include "inputdata.h"
#include "progressevent.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void SetReceiver(QObject* pobjReceiver);


private:
    Ui::MainWindow *ui;

    QObject* m_pobjReceiver;
    void customEvent(QEvent* pe);

    GraphTable *table;
    DrawWindow *drawWind;

    QGroupBox *group;

    QLabel *scaleLbl;
    QLabel *parALbl;
    QLabel *parBLbl;
    QLabel *parXMinLbl;
    QLabel *parXMaxLbl;

    QLineEdit *scaleLine;
    QLineEdit *parALine;
    QLineEdit *parBLine;
    QLineEdit *parXMinLine;
    QLineEdit *parXMaxLine;

    QPushButton *setScaleBut;
    QPushButton *buildGraphBut;

    bool CheckInput();
    bool CheckScaleInput();
    void UpdateData(CoordinatesList list);
    void GraphIsOk(bool st);

public slots:
    void PushButtonBuildGraph();
    void PushButtonScale();
    void ResetScale(double scale);
};

#endif // MAINWINDOW_H
