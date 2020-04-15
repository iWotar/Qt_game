#ifndef COLLISIONRECT_H
#define COLLISIONRECT_H

#include <QDebug>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QMap>
#include <QTimer>

class SceneBase;

enum class ObjectType { PLAYER, ENEMY, ENVIRONMENT };
enum class CollisionLayer { PHYSICS_BODY, PUSHABLE_BODY, DRAGGABLE_BODY, NONE };

class CollisionRect : public QGraphicsRectItem {
 public:
  CollisionRect(ObjectType type, int32_t width, int32_t height,
                CollisionLayer tangibility, SceneBase* parent_scene,
                QGraphicsItem* parent);

  void CheckCollision();

  void SetVisibility(bool visibility);
  void SetSize(int32_t width, int32_t height);

  bool IsTouching(ObjectType type) const;
  QVector<QGraphicsItem*> GetTouchingObjects(ObjectType type) const;

  CollisionLayer GetPhysics() const;
  bool IsColliding() const;
  const QVector<QGraphicsItem*> GetCollidingObjects(CollisionLayer type) const;

  bool IsMaterial() const;

  QGraphicsItem* GetParent() const;

  void CheckWay(QVector2D way);

  int32_t Width() const;
  int32_t Height() const;

 protected:
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget = nullptr) override;

 private:
  ObjectType type_;
  CollisionLayer phis_type_;

  QMap<ObjectType, QVector<QGraphicsItem*>> obj_in_touch_;
  QMap<CollisionLayer, QVector<QGraphicsItem*>> phis_in_touch_;

  QGraphicsItem* parent_;

  int32_t width_;
  int32_t height_;

  bool is_visible_ = true;

  SceneBase* parent_scene_;
};

#endif  // COLLISIONRECT_H
