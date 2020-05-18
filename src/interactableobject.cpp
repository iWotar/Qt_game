#include "interactableobject.h"

#include "collisionrect.h"
#include "gameview.h"
#include "scene_base.h"

InteractableObject::InteractableObject(int32_t width, int32_t height,
                                       CollisionLayer physics,
                                       SceneBase *parent_scene, QString name)
    : parent_scene_(parent_scene) {
  width_ = width;
  height_ = height;
  setRect(0, 0, width_, height_);

  comp_angular_coord_ = {QVector2D(0, 0), QVector2D(width_, height_)};

  collision_component_ = new CollisionRect(
      ObjectType::INTERACTABLE,
      comp_angular_coord_.dw_right_.x() - comp_angular_coord_.up_left_.x(),
      comp_angular_coord_.dw_right_.y() - comp_angular_coord_.up_left_.y(),
      physics, parent_scene_, this);
  collision_component_->SetVisibility(false);

  parent_scene_->addItem(collision_component_);
  name_ = name;
}

void InteractableObject::EnableHighlight(bool enable) {
  highlight_enabled_ = enable;
}

void InteractableObject::paint(QPainter *painter,
                               const QStyleOptionGraphicsItem *option,
                               QWidget *widget) {
  if (is_visible_) {
    if (highlight_enabled_) {
      painter->setPen(QPen(QBrush(QColor()), 0, Qt::NoPen));
      painter->setBrush(QBrush(QColor(0xd7, 0x99, 0x21)));
      painter->drawEllipse(0, 0, width_, height_);
    }
    if (sprite_ != nullptr) {
      painter->drawPixmap(QPoint(0, 0), *sprite_);
    }
    QGraphicsRectItem::paint(painter, option, widget);
  }
}

void InteractableObject::ProcessMovement(QVector2D way) {
  collision_component_->CheckWay(way);
}

QString InteractableObject::GetName() const { return name_; }
