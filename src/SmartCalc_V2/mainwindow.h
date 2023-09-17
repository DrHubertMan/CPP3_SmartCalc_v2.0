#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGraphicsScene>

#include "viewsmartcalc.h"

namespace s21 {

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

signals:

};
}

#endif // MAINWINDOW_H
