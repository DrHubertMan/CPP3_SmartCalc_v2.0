#include "mainmain.h"

MainMain::MainMain()
{
    lol = new s21::MainWindow(this);
    QTabWidget *tab_widget = new QTabWidget();
    QGraphicsScene *scene_one = new QGraphicsScene();

    scene_one->addWidget(tab_widget);
    tab_widget->addTab(lol, "lol");
}
