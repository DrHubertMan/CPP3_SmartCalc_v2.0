#ifndef MAINMAIN_H
#define MAINMAIN_H

#include <QMainWindow>
#include <QTabWidget>
#include <QGraphicsScene>

#include "mainwindow.h"

class MainMain : public QMainWindow {
    Q_OBJECT
public:
    s21::MainWindow *lol;
    MainMain();
};

#endif // MAINMAIN_H
