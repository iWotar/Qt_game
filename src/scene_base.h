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

class Player;
class Enemy;
class GameView;

class CityLocation;

enum class MusicType { CALM, FIGHT, NONE };
enum class ActionType {
  MOVE_UP,
  MOVE_DOWN,
  MOVE_RIGHT,
  MOVE_LEFT,
  ATTACK,
  PAUSE,
  SWITCH,
  SELECT_UP,
  SELECT_DOWN,
  INTERACT,
  ACTIVATE,
  NONE
};

class SceneBase : public QGraphicsScene {
  Q_OBJECT

 public:
  SceneBase(QString name, GameView* view);

  virtual void SetupField() {}

  void SetPaused(bool state);
  bool IsPaused() const;

  Player* GetPlayer() const;

  void SetPlayer(Player* player);

  QString GetName();
  GameView* GetView() { return view_; }

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
  void DefaultControl();

  static QHash<int, ActionType> control_keys_;

 public slots:
  void SwitchMusic();

 signals:
  void SceneIsPaused();

 protected:
  QString name_;

  GameView* view_;

  Player* player_;
  QVector<Enemy*> enemies_;
  QVector<Bullet*> bullets_;

  QScrollBar* scroll_v_;
  QScrollBar* scroll_h_;

  bool paused_;
  static bool music_stop_;

  friend CityLocation;
  QMap<MusicType, QSound*> music_;
  MusicType what_is_playing_;
};

#endif  // SCENE_BASE_H
