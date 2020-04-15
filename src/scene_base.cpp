#include "scene_base.h"

#include <QGraphicsSceneWheelEvent>

#include "collisionrect.h"
#include "enemy.h"
#include "environment.h"

SceneBase::SceneBase() : QGraphicsScene(), paused_(false) {
  setSceneRect(0, 0, 3000, 3000);
  SetupField();
}

void SceneBase::SetPaused(bool state) {
  paused_ = state;
  player_->direction_ = Directions::STAY;
}

bool SceneBase::IsPaused() const { return paused_; }

Player* SceneBase::GetPlayer() const { return player_; }

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

void SceneBase::wheelEvent(QGraphicsSceneWheelEvent* event) { event->accept(); }

void SceneBase::SetupField() {
  // Частота обновления кадров
  startTimer(30);

  // Создание игрока
  player_ = new Player(this);
  player_->setPos(1400, 1500);
  addItem(player_);

  Enemy* enemy_ = new Enemy(this);
  enemy_->setPos(1800, 1600);
  enemies_.append(enemy_);
  addItem(enemy_);

  Enemy* enemy = new Enemy(this);
  enemy->setPos(1800, 1600);
  enemies_.append(enemy);
  addItem(enemy);

  Environment* block =
      new Environment(300, 200, CollisionLayer::PUSHABLE_BODY, this);
  block->SetPos(1000, 1000);
  block->CustomizeColComp(QVector2D(100, 100), QSize(33, 100));
  block->SetColCompVisibility(true);
  addItem(block);

  Environment* rect =
      new Environment(100, 100, CollisionLayer::DRAGGABLE_BODY, this);
  rect->SetPos(1600, 1600);
  addItem(rect);

  Environment* rect3 =
      new Environment(100, 100, CollisionLayer::PUSHABLE_BODY, this);
  rect3->SetPos(1700, 1700);
  addItem(rect3);

  Environment* rect2 = new Environment(100, 100, CollisionLayer::NONE, this);
  rect2->SetPos(1800, 1600);
  addItem(rect2);

  Environment* rect1 =
      new Environment(100, 100, CollisionLayer::PHYSICS_BODY, this);
  rect1->SetPos(1700, 1500);
  addItem(rect1);
}
