#include "player.h"

#include "collisionrect.h"
#include "environment.h"
#include "scene_base.h"

Player::Player(SceneBase* parent) : parent_scene_(parent) {
  width_ = 100;
  height_ = 200;
  setRect(0, 0, width_, height_);

  speed_ = 20;
  comp_angular_coord_ = {QVector2D(0, height_ / 3 * 2),
                         QVector2D(width_, height_)};

  collision_component_ = new CollisionRect(
      ObjectType::PLAYER,
      comp_angular_coord_.dw_right_.x() - comp_angular_coord_.up_left_.x(),
      comp_angular_coord_.dw_right_.y() - comp_angular_coord_.up_left_.y(),
      CollisionLayer::PHYSICS_BODY, parent_scene_, this);
  collision_component_->SetVisibility(true);
  parent_scene_->addItem(collision_component_);

  direction_ = Directions::STAY;
}

void Player::NextFrame() {
  QVector2D dir = GetDirectionVector();
  Move(dir);
}

int32_t Player::GetHealth() const { return health_; }

QVector2D Player::GetDirectionVector() const {
  switch (direction_) {
    case Directions::UP:
      return QVector2D(0, -speed_);
    case Directions::DOWN:
      return QVector2D(0, speed_);
    case Directions::LEFT:
      return QVector2D(-speed_, 0);
    case Directions::RIGHT:
      return QVector2D(speed_, 0);
    case Directions::STAY:
      return QVector2D();
  }
}

void Player::SetHealth(int32_t hp) { health_ = hp; }

void Player::ProcessMovement(QVector2D way) {
  collision_component_->CheckCollision();

  QVector<QGraphicsItem*> pushable_in_touch =
      collision_component_->GetCollidingObjects(CollisionLayer::PUSHABLE_BODY);
  QVector<QGraphicsItem*> dragble_in_touch =
      collision_component_->GetCollidingObjects(CollisionLayer::DRAGGABLE_BODY);

  collision_component_->CheckWay(way);

  if (!dragble_in_touch.isEmpty()) {
    Environment* it;
    for (auto item : dragble_in_touch) {
      it = dynamic_cast<Environment*>(item);
      it->Push(way, 3);
    }
  }
  if (!pushable_in_touch.isEmpty()) {
    Environment* it;
    for (auto item : pushable_in_touch) {
      it = dynamic_cast<Environment*>(item);
      it->Push(way, 3);
    }
  }
}
