#include "viewdepositcalc.h"

ViewDepositCalc::ViewDepositCalc() {
    setAttribute(Qt::WA_QuitOnClose, false);
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheNone);
    setWindowTitle("Credit_Calc_V2.0");
    setFrameStyle(0);
    setSceneRect(0, 0, 300, 900);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setFixedSize(300, 900);
    scene_ = new QGraphicsScene();
    scene_->setItemIndexMethod(QGraphicsScene::NoIndex);
    setScene(scene_);
    setBackgroundBrush(QBrush(Qt::darkCyan));
}
