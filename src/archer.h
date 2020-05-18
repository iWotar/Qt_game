#ifndef ARCHER_H
#define ARCHER_H

#include <QSound>

#include "enemy.h"
#include "player.h"
#include "scene_base.h"

class Archer : public Enemy {
 public:
  explicit Archer(SceneBase* parent);
  void Attack(Player* target) override;
  void ProcessMovement(QVector2D way) override;
  void NextFrame() override;

 private:
  int64_t attack_dist_ = 300;

  QSound* bow_shot_;
};

#endif  // ARCHER_H
