#include "viewsmartcalc.h"

s21::viewSmartCalc::viewSmartCalc() {
  setRenderHint(QPainter::Antialiasing);
  setCacheMode(QGraphicsView::CacheNone);
  setWindowTitle("SmartCalc v2.0");
  setFrameStyle(0);
  setSceneRect(0, 0, 800, 800);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(800, 800);

  scene_.setItemIndexMethod(QGraphicsScene::NoIndex);

  setScene(&scene_);
  InitViewElement();
};

void s21::viewSmartCalc::InitViewElement() {
    InitNumberButtton();
    InitOperatorButton();
    AddBtnAtScene();
}

void s21::viewSmartCalc::InitNumberButtton() {
    btn_7_.setPos(10, 70);
    btn_7_.SetGeometry(50, 50);
    btn_7_.setText("7");

    btn_8_.setPos(70, 70);
    btn_8_.SetGeometry(50, 50);
    btn_8_.setText("8");

    btn_9_.setPos(130, 70);
    btn_9_.SetGeometry(50, 50);
    btn_9_.setText("9");

    btn_4_.setPos(10, 130);
    btn_4_.SetGeometry(50, 50);
    btn_4_.setText("4");

    btn_5_.setPos(70, 130);
    btn_5_.SetGeometry(50, 50);
    btn_5_.setText("5");

    btn_6_.setPos(130, 130);
    btn_6_.SetGeometry(50, 50);
    btn_6_.setText("6");

    btn_1_.setPos(10, 190);
    btn_1_.SetGeometry(50, 50);
    btn_1_.setText("1");

    btn_2_.setPos(70, 190);
    btn_2_.SetGeometry(50, 50);
    btn_2_.setText("2");

    btn_3_.setPos(130, 190);
    btn_3_.SetGeometry(50, 50);
    btn_3_.setText("3");

    btn_0_.setPos(10, 250);
    btn_0_.SetGeometry(50, 110);
    btn_0_.setText("0");

    btn_point_.setPos(130, 250);
    btn_point_.SetGeometry(50, 50);
    btn_point_.setText(".");
}

void s21::viewSmartCalc::InitOperatorButton() {
    btn_mod_.setPos(10, 10);
    btn_mod_.SetGeometry(50, 50);
    btn_mod_.setText("%");

    btn_div_.setPos(70, 10);
    btn_div_.SetGeometry(50, 50);
    btn_div_.setText("/");

    btn_mul_.setPos(130, 10);
    btn_mul_.SetGeometry(50, 50);
    btn_mul_.setText("*");

    btn_minus_.setPos(190, 10);
    btn_minus_.SetGeometry(50, 50);
    btn_minus_.setText("-");

    btn_plus_.setPos(190, 70);
    btn_plus_.SetGeometry(110, 50);
    btn_plus_.setText("+");

}

void s21::viewSmartCalc::AddBtnAtScene() {
    scene_.addItem(&btn_7_);
    scene_.addItem(&btn_8_);
    scene_.addItem(&btn_9_);
    scene_.addItem(&btn_4_);
    scene_.addItem(&btn_5_);
    scene_.addItem(&btn_6_);
    scene_.addItem(&btn_1_);
    scene_.addItem(&btn_2_);
    scene_.addItem(&btn_3_);
    scene_.addItem(&btn_0_);
    scene_.addItem(&btn_mod_);
    scene_.addItem(&btn_div_);
    scene_.addItem(&btn_mul_);
    scene_.addItem(&btn_minus_);
    scene_.addItem(&btn_plus_);
    scene_.addItem(&btn_point_);

//    button btn_eq_;

//    button btn_sep_;
//    button btn_open_br_;
//    button btn_closed_br_;

//    button btn_exp_;

//    button btn_sin_;
//    button btn_cos_;
//    button btn_tan_;
//    button btn_asin_;
//    button btn_acos_;
//    button btn_atan_;
//    button btn_sqrt_;
//    button btn_ln_;
//    button btn_log_;
}
