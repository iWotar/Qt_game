#include "archer.h"

Archer::Archer(SceneBase *parent) : Enemy(parent) {
  speed_ = 6;
  damage_ = 8;
}

void Archer::Attack(Player *target) {
  Q_UNUSED(target);
  if (!cooldown_) {
    Bullet *bullet = new Bullet(parent_scene_, this);
    bullet->setPos(pos());
    parent_scene_->addItem(bullet);
    parent_scene_->AddBullet(bullet);
    cooldown_ = true;
    QTimer::singleShot(attack_cd_ * 1000, this, &Enemy::FlushCooldown);
  }
}

void Archer::ProcessMovement(QVector2D way) {
  collision_component_->CheckCollision();
  collision_component_->CheckWay(way);
}

void Archer::NextFrame() {
  if (health_ <= 0) {
    delete this;
    return;
  }
  Player *target = parent_scene_->GetPlayer();

  QVector2D p_vect = target->GetDirectionVector();
  QVector2D vec_to_p = VectorToPlayer(target);
  SetSightDir(vec_to_p);

  QVector2D result_dir = p_vect + vec_to_p;
  result_dir.normalize();
  result_dir *= speed_;

  if (vec_to_p.length() > attack_dist_) {
    Move(result_dir);
  } else {
    Attack(target);
  }
}
