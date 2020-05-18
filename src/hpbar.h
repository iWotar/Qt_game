#ifndef HPBAR_H
#define HPBAR_H

#include <QGraphicsRectItem>

class MovableEntity;

class HpBar : public QGraphicsRectItem {
 public:
  HpBar(MovableEntity* parent, int32_t* cur_hp, int32_t* max_hp);

 protected:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget = nullptr) override;

 private:
  int32_t* cur_hp_;
  int32_t* max_hp_;

  int32_t width_;
  int32_t height_;
};

#endif  // HPBAR_H
