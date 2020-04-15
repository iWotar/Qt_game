#ifndef ENEMY_H
#define ENEMY_H

#include "movableentity.h"
#include "player.h"

class SceneBase;
class CollisionRect;

class Enemy : public QObject, public MovableEntity {
  Q_OBJECT

 public:
  explicit Enemy(SceneBase* parent);
  void NextFrame();
  void Attack(Player* target);
  QVector2D VectorToPlayer(Player* target) const;

 public slots:
  void FlushCooldown();

 private:
  void ProcessMovement(QVector2D way) override;

  SceneBase* parent_scene_;

  int32_t damage_ = 10;
  int32_t attack_cd_ = 1;
  bool cooldown_ = false;
};

#endif  // ENEMY_H
