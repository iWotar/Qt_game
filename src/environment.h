#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QPair>
#include <QVector2D>

#include "movableentity.h"

enum class CollisionLayer;
class CollisionRect;
class SceneBase;

class Environment : public MovableEntity {
 public:
  Environment(int32_t width, int32_t height, CollisionLayer physics,
              SceneBase* parent_scene);

  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

  void SetVisibility(bool visibility);

  void SetPixmap(QPixmap* pm) { sprite_ = pm; }
  QPixmap* GetPixmap() { return sprite_; }

 private:
  void ProcessMovement(QVector2D way) override;

  SceneBase* parent_scene_;
  QPixmap* sprite_ = nullptr;

  bool is_visible_ = true;
};

#endif  // ENVIRONMENT_H
