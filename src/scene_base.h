#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QScrollBar>

#include "player.h"

class SceneBase : public QGraphicsScene {
  Q_OBJECT

 public:
  SceneBase();

  void SetPaused(bool state);

  Player* GetPlayer();

  void timerEvent(QTimerEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;

 signals:
  void SceneIsPaused();

 private:
  void SetupField();

  Player* player_;

  QScrollBar* scroll_v_;
  QScrollBar* scroll_h_;

  bool paused_;
};

#endif  // SCENE_BASE_H
