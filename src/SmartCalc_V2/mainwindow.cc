#include "mainwindow.h"
#include <QGridLayout>
#include <QVBoxLayout>

s21::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent} {

//    QTabWidget *tab_widget = new QTabWidget(this);

//    QWidget *tab_one = new QWidget();
//    QWidget *tab_two = new QWidget();

    ViewSmartCalc *default_calc = new ViewSmartCalc(this);
//    QGridLayout *main_layout = new QGridLayout();
//    main_layout->addWidget(default_calc);
////    QGridLayout *credit_layout = new QGridLayout();
//    QVBoxLayout *layout_one = new QVBoxLayout(tab_one);
//    layout_one->addLayout(main_layout);
//    tab_widget->addTab(tab_one, "default_calc");
//    resize(800, 800);
//    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
//    tab_widget->show();
//    default_calc->show();
//    tab_one->show();
}
