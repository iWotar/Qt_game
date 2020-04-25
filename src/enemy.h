#ifndef ENEMY_H
#define ENEMY_H

#include "bullet.h"
#include "movableentity.h"
#include "player.h"

class SceneBase;
class CollisionRect;

class Enemy : public QObject, public MovableEntity {
  Q_OBJECT

 public:
  explicit Enemy(SceneBase* parent);
  ~Enemy() override;
  virtual void NextFrame();
  virtual void Attack(Player* target);

  QVector2D VectorToPlayer(Player* target) const;
  int32_t GetDamage() const;
  int32_t GetHealth() const;

  void SetHealth(int32_t hp);

 public slots:
  void FlushCooldown();

 protected:
  void ProcessMovement(QVector2D way) override;

  SceneBase* parent_scene_;

  int32_t damage_ = 10;
  int32_t attack_cd_ = 1;
  int32_t health_ = 100;
  bool cooldown_ = false;
};

#endif  // ENEMY_H
