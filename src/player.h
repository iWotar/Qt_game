#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QVector2D>

#include "movableentity.h"

class SceneBase;
class CollisionRect;

enum class Directions { UP, DOWN, RIGHT, LEFT, STAY };

class Player : public MovableEntity {
 public:
  explicit Player(SceneBase* parent);

  void NextFrame();

  int32_t GetHealth() const;
  QVector2D GetDirectionVector() const;

  void SetHealth(int32_t hp);

  Directions direction_;

 private:
  void ProcessMovement(QVector2D way) override;

  SceneBase* parent_scene_;

  int32_t health_ = 100;
};

#endif  // PLAYER_H
