#include "scene_base.h"

Scene_base::Scene_base() : QGraphicsScene (){
    setSceneRect(0, 0, 1280, 720);

    SetField();
}

void Scene_base::timerEvent(QTimerEvent *event) {
    player_->NextFrame();
}

void Scene_base::keyPressEvent(QKeyEvent *event) {
    switch (event->key()){
    case Qt::Key_Right:
        player_->derect_ = RIGHT;
        break;

    case Qt::Key_Left:
        player_->derect_ = LEFT;
        break;

    case Qt::Key_Up:
        player_->derect_ = UP;
        break;

    case Qt::Key_Down:
        player_->derect_ = DOWN;
        break;

    default:
        break;
    }
}

void Scene_base::keyReleaseEvent(QKeyEvent *event) {
    player_->derect_ = STAY;
}

void Scene_base::SetField() {
    startTimer(10);

    player_ = new Player;
    player_->setPos(200, 200);
    addItem(player_);
}
