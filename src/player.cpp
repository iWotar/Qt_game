#include "player.h"

#include <QGraphicsSceneMouseEvent>
#include <QTimer>

#include "collisionrect.h"
#include "door.h"
#include "environment.h"
#include "gameview.h"
#include "interactableobject.h"
#include "scene_base.h"

Player::Player(SceneBase* parent) : parent_scene_(parent) {
  width_ = 64;
  height_ = 64;
  setRect(0, 0, width_, height_);

  speed_ = 7;

  comp_angular_coord_ = {QVector2D(width_ / 3, height_ / 3 * 2),
                         QVector2D(width_ / 3 * 2, height_ - 10)};

  collision_component_ = new CollisionRect(
      ObjectType::PLAYER,
      comp_angular_coord_.dw_right_.x() - comp_angular_coord_.up_left_.x(),
      comp_angular_coord_.dw_right_.y() - comp_angular_coord_.up_left_.y(),
      CollisionLayer::PHYSICS_BODY, parent_scene_, this);
  collision_component_->SetVisibility(false);
  if (parent_scene_ != nullptr) {
    parent_scene_->addItem(collision_component_);
  }
  direction_ = Directions::STAY;
  SetSightDir(QVector2D(speed_, 0));

  interaction_aura_ =
      new CollisionRect(ObjectType::ENVIRONMENT, width_ * 4, height_ * 2,
                        CollisionLayer::NONE, parent_scene_, this);
  interaction_aura_->SetVisibility(false);

  if (parent_scene_ != nullptr) {
    parent_scene_->addItem(interaction_aura_);
    interaction_aura_->setPos(
        collision_component_->pos().x() + collision_component_->Width() / 2 -
            interaction_aura_->Width() / 2,
        collision_component_->pos().y() + collision_component_->Height() / 2 -
            interaction_aura_->Height() / 2);
  }

  hp_bar_ = new HpBar(this, &cur_health_, &max_health_);

  sounds_.insert(SoundType::BOW_SHOT,
                 new QSound(":/sounds/Sounds/BowShot.wav"));
  sounds_.insert(SoundType::STEPS, new QSound(":/sounds/Sounds/Steps.wav"));

  attack_sprite_ = QPixmap(":/sprites/Sprites/HeroAttack.png");
  walking_sprite_ = QPixmap(":/sprites/Sprites/HeroWalking.png");
  current_sprite_ = walking_sprite_;

  sounds_.insert(SoundType::BOW_SHOT,
                 new QSound(":/sounds/Sounds/BowShot.wav"));
  sounds_.insert(SoundType::STEPS, new QSound(":/sounds/Sounds/Steps.wav"));
}

void Player::NextFrame() {
  if (cur_health_ <= 0) {
    emit Dead();
    return;
  }
  QVector2D dir = GetDirectionVector();
  if (direction_ != Directions::STAY) {
    if (sounds_[SoundType::STEPS]->isFinished()) {
      StartSound(SoundType::STEPS);
    }
    SetSightDir(dir);
  }
  Move(dir);
  ProcessAnimation();

  interaction_aura_->setPos(
      collision_component_->pos().x() + collision_component_->Width() / 2 -
          interaction_aura_->Width() / 2,
      collision_component_->pos().y() + collision_component_->Height() / 2 -
          interaction_aura_->Height() / 2);

  if (previous_highlight_) {
    previous_highlight_->EnableHighlight(false);
    previous_highlight_->update();
  }
  auto object = GetClosestInteractableObject();
  if (object) {
    previous_highlight_ = object;
    object->EnableHighlight(true);
    object->update();
  }
}

qreal SquaredDistanceBetween(const QPointF& a, const QPointF& b) {
  return (a.x() - b.x()) * (a.x() - b.x()) + (a.y() - b.y()) * (a.y() - b.y());
}

InteractableObject* Player::GetClosestInteractableObject() {
  interaction_aura_->CheckCollision();
  QPointF player_pos = {
      collision_component_->pos().x() + collision_component_->Width() / 2,
      collision_component_->pos().y() + collision_component_->Height() / 2};

  auto objects =
      interaction_aura_->GetTouchingObjects(ObjectType::INTERACTABLE);
  InteractableObject* result = nullptr;
  for (auto& obj : objects) {
    if (auto interactable_object = dynamic_cast<InteractableObject*>(obj)) {
      if (result == nullptr ||
          SquaredDistanceBetween(player_pos, interactable_object->pos()) <
              SquaredDistanceBetween(player_pos, result->pos())) {
        result = interactable_object;
      }
    }
  }
  return result;
}

void Player::Interact() {
  auto object = GetClosestInteractableObject();
  if (object) object->DoInteractAction(GetCurScene()->GetView(), this);
}

void Player::Activate(int index) {
  if (inventory_.empty()) {
    return;
  }
  inventory_[index]->DoActivateAction(GetCurScene()->GetView(), this);
}

SceneBase* Player::GetCurScene() { return parent_scene_; }

QVector<QGraphicsItem*> Player::GetNearbyObjects() {
  QVector<QGraphicsItem*> result;
  interaction_aura_->CheckCollision();
  auto objects = interaction_aura_->GetTouchingObjects(ObjectType::DOOR);
  result.append(objects);
  objects = interaction_aura_->GetTouchingObjects(ObjectType::ENVIRONMENT);
  result.append(objects);
  return result;
}

int32_t Player::GetHealth() const { return cur_health_; }

int32_t Player::GetDamage() const { return damage_; }

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

void Player::SetHealth(int32_t hp) { cur_health_ = hp; }

void Player::Attack() {
  Bullet* bullet =
      new Bullet(parent_scene_, ObjectType::PLAYER, sight_dir_, damage_);
  bullet->setPos(pos() + QPoint(width_ / 2, height_ / 2));
  parent_scene_->addItem(bullet);
  parent_scene_->AddBullet(bullet);
  QTimer::singleShot(attack_cd_ * 1000, this, &Player::FlushCooldown);
}

void Player::ProcessAnimation() {
  switch (direction_) {
    case Directions::UP:
      current_frame_y_ = 0;
      break;
    case Directions::DOWN:
      current_frame_y_ = frame_height_ * 2;
      break;
    case Directions::RIGHT:
      current_frame_y_ = frame_height_ * 3;
      break;
    case Directions::LEFT:
      current_frame_y_ = frame_height_;
      break;
    default:
      break;
  }
  if (current_sprite_ == walking_sprite_) {
    if (direction_ != Directions::STAY) {
      current_frame_x_ = (current_frame_x_ + frame_width_) % sprite_width_;
    } else {
      current_frame_x_ = 0;
    }
  } else if (current_sprite_ == attack_sprite_) {
    current_frame_x_ = (current_frame_x_ + frame_width_) % sprite_width_;
    if (current_frame_x_ == 0) {
      current_sprite_ = walking_sprite_;
      sprite_width_ = 576;
    }
  }

  this->update(QRectF(0, 0, width_, height_));
}

void Player::FlushCooldown() { cooldown_ = false; }

void Player::AttackStart() {
  if (!cooldown_) {
    current_sprite_ = attack_sprite_;
    sprite_width_ = 832;
    current_frame_x_ = 0;
    cooldown_ = true;
    QTimer::singleShot(210, this, &Player::Attack);
  }
}

void Player::ProcessMovement(QVector2D way) {
  collision_component_->CheckCollision();

  QVector<QGraphicsItem*> pushable_in_touch =
      collision_component_->GetCollidingObjects(CollisionLayer::PUSHABLE_BODY);
  QVector<QGraphicsItem*> dragble_in_touch =
      collision_component_->GetCollidingObjects(CollisionLayer::DRAGGABLE_BODY);
  if (collision_component_->IsTouching(ObjectType::DOOR)) {
    QGraphicsItem* door =
        collision_component_->GetTouchingObjects(ObjectType::DOOR)[0];
    if (dynamic_cast<Door*>(door)->Teleport(this)) {
      return;
    }
  }

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

  this->update(QRectF(0, 0, width_, height_));
}

void Player::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
                   QWidget* widget) {
  Q_UNUSED(option);
  Q_UNUSED(widget);
  painter->drawPixmap(0, 0, current_sprite_, current_frame_x_, current_frame_y_,
                      frame_width_, frame_height_);
}

QRectF Player::boundingRect() const { return QRectF(0, 0, width_, height_); }

void Player::StartSound(SoundType type) { sounds_[type]->play(); }

void Player::StopSound(SoundType type) { sounds_[type]->stop(); }

void Player::MoveToScene(SceneBase* scene) {
  if (parent_scene_ != nullptr) {
    parent_scene_->SetPlayer(nullptr);
    parent_scene_->removeItem(this);
    parent_scene_->removeItem(collision_component_);
    parent_scene_->removeItem(interaction_aura_);
    collision_component_->SetScene(scene);
    interaction_aura_->SetScene(scene);
  }

  parent_scene_ = scene;
  parent_scene_->SetPlayer(this);
  collision_component_->SetScene(parent_scene_);
  interaction_aura_->SetScene(parent_scene_);
  parent_scene_->addItem(this);
  parent_scene_->addItem(collision_component_);
  parent_scene_->addItem(interaction_aura_);
}
