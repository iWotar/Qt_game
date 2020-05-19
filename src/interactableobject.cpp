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
  SetColCompVisibility(false);

  parent_scene_->addItem(collision_component_);
  name_ = name;
}

void InteractableObject::EnableHighlight(bool enable) {
  highlight_enabled_ = enable;
}

void InteractableObject::SetPixmapVisible(bool b) {
  pixmap_visible_ = b;
}

void InteractableObject::paint(QPainter *painter,
                               const QStyleOptionGraphicsItem *option,
                               QWidget *widget) {
  if (isVisible()) {
    if (highlight_enabled_) {
      painter->setPen(QPen(QBrush(QColor()), 0, Qt::NoPen));
      // painter->setBrush(QBrush(QColor(0xff, 0x09, 0x01, 200)));
      // painter->drawEllipse(0, 0, width_, height_);
      QRadialGradient grad(QPointF(width_ / 2, height_ / 2),
                           qMax(width_, height_) / 2);
      grad.setColorAt(0, Qt::red);
      grad.setColorAt(0.9, Qt::transparent);
      QRect rect(0, 0, width_, height_);
      painter->fillRect(rect, grad);
    }
    if (sprite_ != nullptr && pixmap_visible_) {
      painter->drawPixmap(QPoint(0, 0), *sprite_);
    }
  }
}

void InteractableObject::ProcessMovement(QVector2D way) {
  collision_component_->CheckWay(way);
}

QString InteractableObject::GetName() const { return name_; }
