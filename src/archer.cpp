#include "archer.h"

#include "hpbar.h"
Archer::Archer(SceneBase *parent) : Enemy(parent) {
  hp_bar_ = new HpBar(this, &cur_health_, &max_health_);
  attack_sprite_ = QPixmap(":/sprites/Sprites/SkeletonAttack.png");
  walking_sprite_ = QPixmap(":/sprites/Sprites/SkeletonWalking.png");
  current_sprite_ = walking_sprite_;
  speed_ = 6;
  damage_ = 8;

  bow_shot_ = new QSound(":/sounds/Sounds/BowShot.wav");
}

void Archer::Attack(Player *target) {
  Q_UNUSED(target);
  if (!cooldown_) {
    current_sprite_ = attack_sprite_;
    current_frame_x_ = 0;
    sprite_width_ = 832;
    Bullet *bullet =
        new Bullet(parent_scene_, ObjectType::ENEMY, sight_dir_, damage_);
    bullet->setPos(pos());
    parent_scene_->addItem(bullet);
    parent_scene_->AddBullet(bullet);
    cooldown_ = true;
    QTimer::singleShot(attack_cd_ * 1000, this, &Enemy::FlushCooldown);

    bow_shot_->play();
  }
}

void Archer::ProcessMovement(QVector2D way) {
  collision_component_->CheckCollision();
  collision_component_->CheckWay(way);
}

void Archer::NextFrame() {
  if (cur_health_ <= 0) {
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

  if (vec_to_p.length() > attack_dist_ && !cooldown_) {
    Move(result_dir);
  } else {
    Attack(target);
  }

  ProcessAnimation();

  this->update(QRectF(0, 0, width_, height_));
}
