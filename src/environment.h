#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QGraphicsRectItem>
#include <QPair>
#include <QVector2D>

#include "movableentity.h"

enum class CollisionLayer;
class CollisionRect;
class SceneBase;

class Environment : public MovableEntity {
 public:
  Environment(int32_t width, int32_t height, CollisionLayer phisics,
              SceneBase* parent_scene);

 private:
  void ProcessMovement(QVector2D way) override;

  SceneBase* parent_scene_;
};

#endif  // ENVIRONMENT_H
