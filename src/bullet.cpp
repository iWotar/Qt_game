#include "bullet.h"

#include "scene_base.h"

Bullet::Bullet(SceneBase* parent_scene, ObjectType parent_type,
               QVector2D sight_dir, int32_t damage)
    : parent_scene_(parent_scene),
      damage_(damage),
      parent_type_(parent_type) {
  speed_ = 40;
  distance_ = 500;

  width_ = 45;
  height_ = 20;

  direction_ = sight_dir * speed_;
  sprite_ = new QPixmap(":/imges/Images/Arrow.png");
  QPixmap* shadow = new QPixmap(":/imges/Images/Shadow.png");

  setRect(0, 0, width_, height_);

  comp_angular_coord_ = {QVector2D(0, height_), QVector2D(width_, 2 * height_)};
  collision_component_ = new CollisionRect(
      ObjectType::WEAPON,
      comp_angular_coord_.dw_right_.x() - comp_angular_coord_.up_left_.x(),
      comp_angular_coord_.dw_right_.y() - comp_angular_coord_.up_left_.y(),
      CollisionLayer::NONE, parent_scene, this, shadow);

  setRotation(GetAngle());
  collision_component_->setRotation(GetAngle());

  collision_component_->SetVisibility(false);
  parent_scene_->addItem(collision_component_);

  sprite_ = new QPixmap(":/imges/Images/Arrow.png");
  sound_ = new QSound(":/sounds/Sounds/Arrow.wav");
}

Bullet::~Bullet() {
  parent_scene_->DeleteBullet(this);
  delete collision_component_;
}

void Bullet::NextFrame() {
  if (distance_ > 0) {
    Move(direction_);
    distance_ -= direction_.length();
    update(QRectF(0, 0, width_, height_));
  } else {
    deleteLater();
  }
}

qreal Bullet::GetAngle() {
  if (direction_.y() < 0) {
    return acos(-direction_.x() / direction_.length()) * 57;
  }
  return -acos(-direction_.x() / direction_.length()) * 57;
}

void Bullet::ProcessMovement(QVector2D way) {
  Q_UNUSED(way);
  collision_component_->CheckCollision();

  if (collision_component_->IsColliding()) {
    if (collision_component_->IsTouching(ObjectType::PLAYER) &&
        parent_type_ == ObjectType::ENEMY) {
      Player* target = parent_scene_->GetPlayer();
      target->SetHealth(target->GetHealth() - damage_ / 2);
      distance_ = 0;
      target->Push(way, 5);
      sound_->play();
    } else if (collision_component_->IsTouching(ObjectType::ENEMY) &&
               parent_type_ == ObjectType::PLAYER) {
      Enemy* target = dynamic_cast<Enemy*>(
          collision_component_->GetTouchingObjects(ObjectType::ENEMY)[0]);
      target->SetHealth(target->GetHealth() - damage_ / 2);
      qDebug() << target->GetHealth();
      distance_ = 0;
      target->Push(way, 5);
      sound_->play();
    }
  }
}

void Bullet::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);
  painter->drawPixmap(0, 0, *sprite_);
}

QRectF Bullet::boundingRect() const { return QRectF(0, 0, width_, height_); }
