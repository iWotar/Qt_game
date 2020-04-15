#include "collisionrect.h"

#include <QList>

#include "scene_base.h"

CollisionRect::CollisionRect(ObjectType type, int32_t width, int32_t height,
                             CollisionLayer tangibility,
                             SceneBase* parent_scene, QGraphicsItem* parent)
    : QGraphicsRectItem(),
      type_(type),
      phis_type_(tangibility),
      parent_(parent),
      width_(width),
      height_(height),
      parent_scene_(parent_scene) {
  setRect(0, 0, width_, height_);
}

void CollisionRect::CheckCollision() {
  if (parent_scene_->IsPaused()) {
    return;
  }
  QList<QGraphicsItem*> collision_items = collidingItems();
  CollisionRect* it;
  obj_in_touch_.clear();
  phis_in_touch_.clear();
  for (auto item : collision_items) {
    if ((it = dynamic_cast<CollisionRect*>(item))) {
      obj_in_touch_[it->type_].append(it->GetParent());
      phis_in_touch_[it->phis_type_].append(it->GetParent());
    }
  }
}

void CollisionRect::SetVisibility(bool visibility) { is_visible_ = visibility; }

void CollisionRect::SetSize(int32_t width, int32_t height) {
  width_ = width;
  height_ = height;
  setRect(0, 0, width_, height_);
}

bool CollisionRect::IsTouching(ObjectType type) const {
  return !obj_in_touch_[type].isEmpty();
}

QVector<QGraphicsItem*> CollisionRect::GetTouchingObjects(
    ObjectType type) const {
  return obj_in_touch_[type];
}

CollisionLayer CollisionRect::GetPhysics() const { return phis_type_; }

bool CollisionRect::IsColliding() const {
  return !phis_in_touch_[CollisionLayer::PHYSICS_BODY].isEmpty() ||
         !phis_in_touch_[CollisionLayer::PUSHABLE_BODY].isEmpty();
}

const QVector<QGraphicsItem*> CollisionRect::GetCollidingObjects(
    CollisionLayer type) const {
  return phis_in_touch_[type];
}

bool CollisionRect::IsMaterial() const {
  return phis_type_ != CollisionLayer::NONE;
}

QGraphicsItem* CollisionRect::GetParent() const { return parent_; }

void CollisionRect::CheckWay(QVector2D way) {
  if (phis_type_ == CollisionLayer::NONE ||
      phis_type_ == CollisionLayer::DRAGGABLE_BODY || way.isNull()) {
    return;
  }

  CheckCollision();

  way.normalize();
  way *= -1;
  QPoint step_back = way.toPoint();

  while (IsColliding()) {
    setPos(scenePos() + step_back);
    CheckCollision();
  }
}

int32_t CollisionRect::Width() const { return width_; }

int32_t CollisionRect::Height() const { return height_; }

void CollisionRect::paint(QPainter* painter,
                          const QStyleOptionGraphicsItem* option,
                          QWidget* widget) {
  if (is_visible_) {
    QGraphicsRectItem::paint(painter, option, widget);
  }
}
