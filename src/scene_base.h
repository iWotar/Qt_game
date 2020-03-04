#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include "player.h"

class SceneBase : public QGraphicsScene {
  Q_OBJECT

 public:
  SceneBase();
  void timerEvent(QTimerEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent *event) override;

 private:
  void SetupField();
  Player* player_;
};

#endif  // SCENE_BASE_H
