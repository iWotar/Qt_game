#include "scene_base.h"

SceneBase::SceneBase() : QGraphicsScene () {
  setSceneRect(0, 0, 1280, 720);

  SetField();
}

void SceneBase::timerEvent(QTimerEvent *event) {
  player_->NextFrame();
}

void SceneBase::keyPressEvent(QKeyEvent *event) {
  switch (event->key()){
  case Qt::Key_Right:
    player_->direction_ = RIGHT;
    break;

  case Qt::Key_Left:
    player_->direction_ = LEFT;
    break;

  case Qt::Key_Up:
    player_->direction_ = UP;
    break;

  case Qt::Key_Down:
    player_->direction_ = DOWN;
    break;

  default:
    break;
  }
}

void SceneBase::keyReleaseEvent(QKeyEvent *event) {
    player_->direction_ = STAY;
}

void SceneBase::SetField() {
    startTimer(10);

    player_ = new Player;
    player_->setPos(200, 200);
    addItem(player_);
}
