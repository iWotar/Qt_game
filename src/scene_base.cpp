#include "scene_base.h"
#include "enemy.h"

SceneBase::SceneBase() : QGraphicsScene(), paused_(false) {
  setSceneRect(0, 0, 3000, 3000);
  SetupField();
}

void SceneBase::SetPaused(bool state) {
  paused_ = state;
  player_->direction_ = Directions::STAY;
}

Player *SceneBase::GetPlayer() {
  return player_;
}

void SceneBase::timerEvent(QTimerEvent* event) {
  Q_UNUSED(event);

  if (paused_) {
    return;
  }

  player_->NextFrame();
  for (auto e : enemies_) {
      e->NextFrame();
  }

  // Скроллинг экрана
  if (!views().empty())
    views()[0]->ensureVisible(player_->sceneBoundingRect(), 200, 200);
}

void SceneBase::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
    case Qt::Key_Right:
      player_->direction_ = Directions::RIGHT;
      break;

    case Qt::Key_Left:
      player_->direction_ = Directions::LEFT;
      break;

    case Qt::Key_Up:
      player_->direction_ = Directions::UP;
      break;

    case Qt::Key_Down:
      player_->direction_ = Directions::DOWN;
      break;

    case Qt::Key_Escape:
      emit SceneIsPaused();
      break;

    default:
      break;
  }
}

void SceneBase::keyReleaseEvent(QKeyEvent* event) {
  if (event->key() == Qt::Key_Right || event->key() == Qt::Key_Left ||
      event->key() == Qt::Key_Up || event->key() == Qt::Key_Down) {
    player_->direction_ = Directions::STAY;
  }
}

void SceneBase::SetupField() {
  // Частота обновления кадров
  startTimer(10);

  // Создание игрока
  player_ = new Player;
  player_->setPos(1500, 1500);
  addItem(player_);

  Enemy* enemy_ = new Enemy(this);
  enemy_->setPos(1800, 1500);
  enemies_.append(enemy_);
  addItem(enemy_);
}
