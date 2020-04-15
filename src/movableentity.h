#ifndef MOVABLEENTITY_H
#define MOVABLEENTITY_H

#include <QGraphicsRectItem>
#include <QVector2D>
class CollisionRect;

class MovableEntity : public QGraphicsRectItem {
 public:
  MovableEntity();

  void Push(QVector2D dir, int32_t strength);
  void Move(QVector2D dir);

  int32_t Width() const;
  int32_t Height() const;

  int32_t GetSpeed() const;

  void SetSize(int32_t width, int32_t height);
  void SetPos(int32_t x, int32_t y);
  void SetColCompVisibility(bool is_visible);

  void CustomizeColComp(QVector2D coord, QSize size);
  void CustomizeColComp(QVector2D up_left_coord, QVector2D dw_right_coord);
  void CustomizeColComp(QPair<QVector2D, QVector2D> comp_angular_coord);

 protected:
  virtual void ProcessMovement(QVector2D way) = 0;

  CollisionRect* collision_component_ = nullptr;

  struct CompAngularCoord {
    QVector2D up_left_;
    QVector2D dw_right_;
  };

  CompAngularCoord comp_angular_coord_ = {QVector2D(), QVector2D()};

  int32_t width_ = 0;
  int32_t height_ = 0;

  int32_t speed_ = 0;
};

#endif  // MOVABLEENTITY_H
