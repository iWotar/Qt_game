#include "movableentity.h"

#include <QVector2D>

#include "collisionrect.h"

MovableEntity::MovableEntity() {}

void MovableEntity::Move(QVector2D dir) {
  QPoint int_dir = dir.toPoint();
  collision_component_->setPos(scenePos() +
                               comp_angular_coord_.up_left_.toPoint());

  collision_component_->setPos(collision_component_->x() + int_dir.x(),
                               collision_component_->y());
  ProcessMovement(QVector2D(int_dir.x(), 0));

  collision_component_->setPos(collision_component_->x(),
                               collision_component_->y() + int_dir.y());
  ProcessMovement(QVector2D(0, int_dir.y()));

  setPos(collision_component_->scenePos() -
         comp_angular_coord_.up_left_.toPoint());
}

void MovableEntity::Push(QVector2D dir, int32_t strength) {
  dir.normalize();
  dir *= strength;
  Move(dir);
}

int32_t MovableEntity::Width() const { return width_; }

int32_t MovableEntity::Height() const { return height_; }

int32_t MovableEntity::GetSpeed() const { return speed_; }

QVector2D MovableEntity::GetSightDir() const { return sight_dir_; }

void MovableEntity::SetSize(int32_t width, int32_t height) {
  qreal w_coef = width / width_;
  qreal h_coef = height / height_;

  width_ = width;
  height_ = height;
  setRect(0, 0, width_, height_);

  comp_angular_coord_ = {comp_angular_coord_.up_left_ * w_coef,
                         comp_angular_coord_.dw_right_ * h_coef};

  QPoint size = comp_angular_coord_.dw_right_.toPoint() -
                comp_angular_coord_.up_left_.toPoint();

  collision_component_->SetSize(size.x(), size.y());
  collision_component_->setPos(scenePos() +
                               comp_angular_coord_.up_left_.toPoint());
}

void MovableEntity::SetPos(int32_t qx, int32_t qy) {
  setPos(qx, qy);
  collision_component_->setPos(scenePos() +
                               comp_angular_coord_.up_left_.toPoint());
}

void MovableEntity::SetColCompVisibility(bool is_visible) {
  collision_component_->SetVisibility(is_visible);
}

void MovableEntity::SetSightDir(QVector2D dir) {
  sight_dir_ = dir;
  sight_dir_.normalize();
}

void MovableEntity::CustomizeColComp(QVector2D coord, QSize size) {
  comp_angular_coord_.up_left_ = coord;
  comp_angular_coord_.dw_right_ =
      QVector2D(coord.x() + size.width(), coord.y() + size.height());

  collision_component_->SetSize(size.width(), size.height());
  collision_component_->setPos(scenePos() +
                               comp_angular_coord_.up_left_.toPoint());
}

void MovableEntity::CustomizeColComp(QVector2D up_left_coord,
                                     QVector2D dw_right_coord) {
  QPoint size = dw_right_coord.toPoint() - up_left_coord.toPoint();

  CustomizeColComp(up_left_coord, QSize(size.x(), size.y()));
}

void MovableEntity::CustomizeColComp(
    QPair<QVector2D, QVector2D> comp_angular_coord) {
  QPoint size =
      comp_angular_coord.second.toPoint() - comp_angular_coord.first.toPoint();

  CustomizeColComp(comp_angular_coord.first, QSize(size.x(), size.y()));
}

void MovableEntity::ProcessAnimation() {}

CollisionRect *MovableEntity::GetCollisionComponent() const {
  return collision_component_;
}
