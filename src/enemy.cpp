#include "enemy.h"

#include <QTimer>

#include "collisionrect.h"
#include "scene_base.h"

Enemy::Enemy(SceneBase* parent)
    : parent_scene_(parent) {
  width_ = 64;
  height_ = 64;
  setRect(0, 0, width_, height_);

  speed_ = 5;
  hp_bar_ = new HpBar(this, &cur_health_, &max_health_);
  attack_sprite_ = QPixmap(":/sprites/Sprites/RogueAttack.png");
  walking_sprite_ = QPixmap(":/sprites/Sprites/RogueWalking.png");
  current_sprite_ = walking_sprite_;

  comp_angular_coord_ = {QVector2D(width_ / 3, height_ / 2),
                         QVector2D(width_ / 3 * 2, height_)};

  collision_component_ = new CollisionRect(
      ObjectType::ENEMY,
      comp_angular_coord_.dw_right_.x() - comp_angular_coord_.up_left_.x(),
      comp_angular_coord_.dw_right_.y() - comp_angular_coord_.up_left_.y(),
      CollisionLayer::PHYSICS_BODY, parent_scene_, this);
  collision_component_->SetVisibility(false);

  parent_scene_->addItem(collision_component_);
  current_sprite_ = walking_sprite_;
}

Enemy::~Enemy() {
  parent_scene_->DeleteEnemy(this);
  delete collision_component_;
}

void Enemy::NextFrame() {
  if (cur_health_ <= 0) {
    delete this;
    return;
  }
  Player* target = parent_scene_->GetPlayer();

  QVector2D p_vect = target->GetDirectionVector();
  QVector2D vec_to_p = VectorToPlayer(target);
  SetSightDir(vec_to_p);

  QVector2D result_dir = p_vect + vec_to_p;
  result_dir.normalize();
  result_dir *= speed_;

  Move(result_dir);
  ProcessAnimation();
}

void Enemy::Attack(Player* target) {
  if (!cooldown_) {
    current_sprite_ = attack_sprite_;
    current_frame_x_ = 0;
    sprite_width_ = 384;
    target->SetHealth(target->GetHealth() - damage_);
    QTimer::singleShot(attack_cd_ * 1000, this, &Enemy::FlushCooldown);
  }
}

QVector2D Enemy::VectorToPlayer(Player* target) const {
  return QVector2D(target->x() + target->Width() / 2 - (x() + width_ / 2),
                   target->y() + target->Height() / 2 - (y() + height_ / 2));
}

int32_t Enemy::GetDamage() const { return damage_; }

int32_t Enemy::GetHealth() const { return cur_health_; }

void Enemy::SetHealth(int32_t hp) { cur_health_ = hp; }

void Enemy::FlushCooldown() {
  cooldown_ = false;
  attack_played = false;
  current_sprite_ = walking_sprite_;
  sprite_width_ = 576;
}

void Enemy::ProcessMovement(QVector2D way) {
  collision_component_->CheckCollision();

  bool is_touching_player = false;
  if (collision_component_->IsTouching(ObjectType::PLAYER)) {
    Attack(parent_scene_->GetPlayer());
    is_touching_player = true;
  }

  collision_component_->CheckWay(way);

  if (is_touching_player && !cooldown_) {
    cooldown_ = true;
    parent_scene_->GetPlayer()->Push(way, 20);
  }
}

void Enemy::ProcessAnimation() {
  if (sight_dir_.x() >= 0.7) {
    current_frame_y_ = 3 * frame_height_;
  } else if (sight_dir_.x() <= -0.7) {
    current_frame_y_ = frame_height_;
  } else if (sight_dir_.y() >= 0.7) {
    current_frame_y_ = 2 * frame_height_;
  } else if (sight_dir_.y() <= -0.7) {
    current_frame_y_ = 0;
  }

  if (current_sprite_ == walking_sprite_ || !attack_played) {
    current_frame_x_ = (current_frame_x_ + frame_width_) % sprite_width_;
    if (current_frame_x_ == 0 && current_sprite_ == attack_sprite_) {
      attack_played = true;
    }
  }

  this->update(QRectF(0, 0, width_, height_));
}

void Enemy::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                  QWidget* widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);
  painter->drawPixmap(0, 0, current_sprite_, current_frame_x_, current_frame_y_,
                      frame_width_, frame_height_);
}

QRectF Enemy::boundingRect() const { return QRectF(0, 0, width_, height_); }
