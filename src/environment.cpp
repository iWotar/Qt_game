#include "environment.h"

#include "collisionrect.h"
#include "scene_base.h"

Environment::Environment(int32_t width, int32_t height, CollisionLayer physics,
                         SceneBase *parent_scene)
    : parent_scene_(parent_scene) {
  width_ = width;
  height_ = height;
  setRect(0, 0, width_, height_);

  comp_angular_coord_ = {QVector2D(0, height_ / 2), QVector2D(width_, height_)};

  collision_component_ = new CollisionRect(
      ObjectType::ENVIRONMENT,
      comp_angular_coord_.dw_right_.x() - comp_angular_coord_.up_left_.x(),
      comp_angular_coord_.dw_right_.y() - comp_angular_coord_.up_left_.y(),
      physics, parent_scene_, this);
  collision_component_->SetVisibility(false);

  parent_scene_->addItem(collision_component_);
}

void Environment::paint(QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget) {
  if (is_visible_) {
    if (sprite_ != nullptr) {
      painter->drawPixmap(QPoint(0, 0), *sprite_);
    }
    QGraphicsRectItem::paint(painter, option, widget);
  }
}

void Environment::ProcessMovement(QVector2D way) {
  collision_component_->CheckWay(way);
}
