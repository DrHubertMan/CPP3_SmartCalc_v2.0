#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsItem>
#include <QPainter>
#include <QColor>
#include <QDebug>

namespace s21 {
class button : public QGraphicsItem
{
public:
    button();
    ~button() = default;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void SetGeometry(int heigth, int width) noexcept;
    void setText(const QString &text) noexcept;

    void hoverEnterEvent(QGraphicsSceneHoverEvent*) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;
    void mousePressEvent(QGraphicsSceneMouseEvent*) override;
private:
    int width_{0};
    int heigth_{0};
    QString text_;
    QColor color_;
};
};
#endif // BUTTON_H
