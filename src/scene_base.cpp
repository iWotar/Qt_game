#include "scene_base.h"

#include <QGraphicsSceneWheelEvent>

#include "archer.h"
#include "collisionrect.h"
#include "enemy.h"
#include "environment.h"
#include "gameview.h"
#include "player.h"

bool SceneBase::music_stop_ = false;
QHash<Qt::Key, ActionType> SceneBase::control_keys_ = {};

SceneBase::SceneBase(QString name, GameView *view)
    : QGraphicsScene(),
      name_(name),
      view_(view),
      player_(nullptr),
      paused_(false) {
  what_is_playing_ = MusicType::NONE;
  music_.insert(MusicType::CALM, new QSound(":/sounds/Sounds/CalmMusic.wav"));

  music_.insert(MusicType::FIGHT, new QSound(":/sounds/Sounds/FightMusic.wav"));
  for (auto &elem : music_) {
    elem->setLoops(QSound::Infinite);
  }
}

void SceneBase::SetPaused(bool state) {
  paused_ = state;
  if (player_ != nullptr) {
    player_->direction_ = Directions::STAY;
  }
  if (paused_) {
    StopAnyMusic();
  }
}

bool SceneBase::IsPaused() const { return paused_; }

Player *SceneBase::GetPlayer() const { return player_; }

void SceneBase::SetPlayer(Player *player) { player_ = player; }

QString SceneBase::GetName() { return name_; }

void SceneBase::timerEvent(QTimerEvent *event) {
  Q_UNUSED(event);

  if (paused_) {
    StopAnyMusic();
    return;
  }

  if (player_ != nullptr) {
    player_->NextFrame();
    // Скроллинг экрана
    if (!views().empty())
      views()[0]->ensureVisible(player_->sceneBoundingRect(), 200, 200);
  }

  for (auto e : enemies_) {
    e->NextFrame();
  }
  for (auto b : bullets_) {
    b->NextFrame();
  }

  // Скроллинг экрана
  if (!views().empty())
    views()[0]->ensureVisible(player_->sceneBoundingRect(), 200, 200);

  if (enemies_.empty()) {
    PlayMusic(MusicType::CALM);
  } else {
    PlayMusic(MusicType::FIGHT);
  }
}

void SceneBase::keyPressEvent(QKeyEvent *event) {
  if (!SceneBase::control_keys_.contains(static_cast<Qt::Key>(event->key())) ||
      player_ == nullptr) {
    return;
  }
  switch (SceneBase::control_keys_[static_cast<Qt::Key>(event->key())]) {
    case ActionType::MOVE_RIGHT:
      player_->direction_ = Directions::RIGHT;
      break;

    case ActionType::MOVE_LEFT:
      player_->direction_ = Directions::LEFT;
      break;

    case ActionType::MOVE_UP:
      player_->direction_ = Directions::UP;
      break;

    case ActionType::MOVE_DOWN:
      player_->direction_ = Directions::DOWN;
      break;

    case ActionType::PAUSE:
      emit SceneIsPaused();
      break;

    case ActionType::INTERACT:
      player_->Interact();
      break;

    case ActionType::SELECT_UP:
      view_->MoveInventorySelection(-1);
      break;

    case ActionType::SELECT_DOWN:
      view_->MoveInventorySelection(1);
      break;

    case ActionType::ATTACK:
      player_->AttackStart();
      break;
    case ActionType::ACTIVATE:
      view_->ActivateAction();
      break;
    default:
      break;
  }
}

void SceneBase::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) {
  if (mouseEvent->button() == Qt::RightButton) {
    view_->ActivateAction();
  } else if (mouseEvent->button() == Qt::LeftButton) {
    player_->AttackStart();
  }
}

void SceneBase::keyReleaseEvent(QKeyEvent *event) {
  if (!SceneBase::control_keys_.contains(static_cast<Qt::Key>(event->key())) ||
      player_ == nullptr) {
    return;
  }

  ActionType action = control_keys_[static_cast<Qt::Key>(event->key())];
  if (action == ActionType::MOVE_UP || action == ActionType::MOVE_DOWN ||
      action == ActionType::MOVE_RIGHT || action == ActionType::MOVE_LEFT) {
    player_->direction_ = Directions::STAY;
  }
}

void SceneBase::wheelEvent(QGraphicsSceneWheelEvent *event) {
  if (event->delta() > 0) view_->MoveInventorySelection(-1);
  if (event->delta() < 0) view_->MoveInventorySelection(1);
}

void SceneBase::AddBullet(Bullet *b) { bullets_.append(b); }

void SceneBase::DeleteBullet(Bullet *b) {
  bullets_.remove(bullets_.indexOf(b));
}

void SceneBase::DeleteEnemy(Enemy *e) { enemies_.remove(enemies_.indexOf(e)); }

void SceneBase::DeletePlayer() {
  delete player_;
  player_ = nullptr;
}

void SceneBase::PlayMusic(MusicType type) {
  if (type == MusicType::NONE) {
    StopAnyMusic();
    return;
  }
  if (what_is_playing_ != type && !SceneBase::music_stop_) {
    if (what_is_playing_ != MusicType::NONE) {
      music_[what_is_playing_]->stop();
    }
    music_[type]->play();
    what_is_playing_ = type;
  }
}

void SceneBase::StopAnyMusic() {
  for (auto &elem : music_) {
    elem->stop();
  }
  what_is_playing_ = MusicType::NONE;
}

void SceneBase::SwitchMusic() {
  SceneBase::music_stop_ = !SceneBase::music_stop_;
}

void SceneBase::DefaultControl() {
  SceneBase::control_keys_[Qt::Key_W] = ActionType::MOVE_UP;
  SceneBase::control_keys_[Qt::Key_A] = ActionType::MOVE_LEFT;
  SceneBase::control_keys_[Qt::Key_S] = ActionType::MOVE_DOWN;
  SceneBase::control_keys_[Qt::Key_D] = ActionType::MOVE_RIGHT;
  SceneBase::control_keys_[Qt::Key_Space] = ActionType::ATTACK;
  SceneBase::control_keys_[Qt::Key_Escape] = ActionType::PAUSE;
  SceneBase::control_keys_[Qt::Key_E] = ActionType::INTERACT;
  SceneBase::control_keys_[Qt::Key_Up] = ActionType::SELECT_UP;
  SceneBase::control_keys_[Qt::Key_Down] = ActionType::SELECT_DOWN;
  SceneBase::control_keys_[Qt::Key_Q] = ActionType::ACTIVATE;
}
