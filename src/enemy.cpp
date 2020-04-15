#include "enemy.h"

#include <QTimer>

#include "collisionrect.h"
#include "scene_base.h"

Enemy::Enemy(SceneBase* parent) : parent_scene_(parent) {
  width_ = 50;
  height_ = 100;
  setRect(0, 0, width_, height_);

  speed_ = 5;
  comp_angular_coord_ = {QVector2D(0, height_ / 2), QVector2D(width_, height_)};

  collision_component_ = new CollisionRect(
      ObjectType::ENEMY,
      comp_angular_coord_.dw_right_.x() - comp_angular_coord_.up_left_.x(),
      comp_angular_coord_.dw_right_.y() - comp_angular_coord_.up_left_.y(),
      CollisionLayer::PHYSICS_BODY, parent_scene_, this);
  collision_component_->SetVisibility(true);

  parent_scene_->addItem(collision_component_);
}

void Enemy::NextFrame() {
  Player* target = parent_scene_->GetPlayer();

  QVector2D p_vect = target->GetDirectionVector();
  QVector2D vec_to_p = VectorToPlayer(target);

  QVector2D result_dir = p_vect + vec_to_p;
  result_dir.normalize();
  result_dir *= speed_;

  Move(result_dir);
}

void Enemy::Attack(Player* target) {
  if (!cooldown_) {
    target->SetHealth(target->GetHealth() - damage_);
    cooldown_ = true;
    qDebug() << target->GetHealth();
    QTimer::singleShot(attack_cd_ * 1000, this, &Enemy::FlushCooldown);
  }
}

QVector2D Enemy::VectorToPlayer(Player* target) const {
  return QVector2D(target->x() + target->Width() / 2 - (x() + width_ / 2),
                   target->y() + target->Height() / 2 - (y() + height_ / 2));
}

void Enemy::FlushCooldown() { cooldown_ = false; }

void Enemy::ProcessMovement(QVector2D way) {
  collision_component_->CheckCollision();

  bool is_touching_player = false;
  if (collision_component_->IsTouching(ObjectType::PLAYER)) {
    Attack(parent_scene_->GetPlayer());
    is_touching_player = true;
  }

  collision_component_->CheckWay(way);

  if (is_touching_player) {
    parent_scene_->GetPlayer()->Push(way, 20);
  }
}
