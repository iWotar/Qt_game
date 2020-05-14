#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QVector2D>
#include <QSound>
#include <QtGui>

#include "movableentity.h"

class SceneBase;
class CollisionRect;

enum class Directions { UP, DOWN, RIGHT, LEFT, STAY };

enum class SoundType { BOW_SHOT, STEPS };

class Player : public QObject, public MovableEntity {
  Q_OBJECT

 public:
  explicit Player(SceneBase* parent);

  void NextFrame();

  int32_t GetHealth() const;
  int32_t GetDamage() const;

  QVector2D GetDirectionVector() const;
  void SetHealth(int32_t hp);

  void Attack();

  Directions direction_;

  void StartSound(SoundType type);

  void StopSound(SoundType type);

 public slots:
  void FlushCooldown();

 private:
  void ProcessMovement(QVector2D way) override;

  SceneBase* parent_scene_;

  int32_t damage_ = 10;
  int32_t attack_cd_ = 1;
  int32_t health_ = 100;
  bool cooldown_ = false;

  QMap<SoundType, QSound*> sounds_;
};

#endif  // PLAYER_H
