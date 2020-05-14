#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <QSound>

#include "enemy.h"
#include "player.h"

enum class MusicType { CALM, FIGHT, NONE };

class SceneBase : public QGraphicsScene {
  Q_OBJECT

 public:
  SceneBase();

  void SetPaused(bool state);
  bool IsPaused() const;

  Player* GetPlayer() const;

  void timerEvent(QTimerEvent* event) override;
  void keyPressEvent(QKeyEvent* event) override;
  void keyReleaseEvent(QKeyEvent* event) override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

  void wheelEvent(QGraphicsSceneWheelEvent* event) override;

  void AddBullet(Bullet* b);
  void DeleteBullet(Bullet* b);
  void DeleteEnemy(Enemy* e);

  void PlayMusic(MusicType type);
  void StopAnyMusic();

 signals:
  void SceneIsPaused();

 private:
  void SetupField();

  Player* player_;
  QVector<Enemy*> enemies_;
  QVector<Bullet*> bullets_;

  QScrollBar* scroll_v_;
  QScrollBar* scroll_h_;

  bool paused_;

  QMap<MusicType, QSound*> music_;
  MusicType what_is_playing_;
};

#endif  // SCENE_BASE_H
