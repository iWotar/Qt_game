#include "scene_base.h"

#include <QGraphicsSceneWheelEvent>

#include "archer.h"
#include "collisionrect.h"
#include "enemy.h"
#include "environment.h"
#include "gameview.h"
#include "player.h"

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
  if (player_ == nullptr) {
    return;
  }
  switch (event->key()) {
    case Qt::Key_D:
      player_->direction_ = Directions::RIGHT;
      break;

    case Qt::Key_A:
      player_->direction_ = Directions::LEFT;
      break;

    case Qt::Key_W:
      player_->direction_ = Directions::UP;
      break;

    case Qt::Key_S:
      player_->direction_ = Directions::DOWN;
      break;

    case Qt::Key_E:
      player_->Interact();
      break;

    case Qt::Key_Up:
      view_->MoveInventorySelection(-1);
      break;

    case Qt::Key_Down:
      view_->MoveInventorySelection(1);
      break;

    case Qt::Key_Escape:
      emit SceneIsPaused();
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
  if (player_ == nullptr) {
    return;
  }
  if (event->key() == Qt::Key_D || event->key() == Qt::Key_A ||
      event->key() == Qt::Key_W || event->key() == Qt::Key_S) {
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

void SceneBase::PlayMusic(MusicType type) {
  if (type == MusicType::NONE) {
    StopAnyMusic();
    return;
  }
  if (what_is_playing_ != type) {
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
