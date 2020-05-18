#ifndef HPBAR_H
#define HPBAR_H

#include <QGraphicsRectItem>

class MovableEntity;

class HpBar : public QObject, public QGraphicsRectItem {
 public:
  HpBar(MovableEntity* parent, int32_t* cur_hp, int32_t* max_hp);

 public slots:
  void SwitchVisibility();

 protected:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget = nullptr) override;

 private:
  bool is_visible = false;

  int32_t prev_hp_;
  int32_t* cur_hp_;
  int32_t* max_hp_;

  int32_t width_;
  int32_t height_;
};

#endif  // HPBAR_H
