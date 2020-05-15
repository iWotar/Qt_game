#include "hpbar.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QPainter>

#include "movableentity.h"

HpBar::HpBar(MovableEntity *parent, int32_t *cur_hp, int32_t *max_hp)
    : QGraphicsRectItem(parent), cur_hp_(cur_hp), max_hp_(max_hp) {
  width_ = parent->Width() + 20;
  height_ = 10;
  setRect(0, 0, width_, height_);
  setPos(-10, -10);
}

void HpBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
  painter->setBrush(QBrush("red"));
  painter->drawRect(0, 0, width_, height_);
  painter->setBrush(QBrush("green"));
  painter->drawRect(0, 0, qMax(width_ * *cur_hp_ / *max_hp_, 0), height_);
  QGraphicsRectItem::paint(painter, option, widget);
}
