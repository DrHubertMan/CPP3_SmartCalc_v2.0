
#include <QApplication>
#include "viewsmartcalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    s21::ViewSmartCalc w;
    w.show();
    return a.exec();
}
