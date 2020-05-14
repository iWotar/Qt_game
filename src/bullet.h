#ifndef WEAPONS_H
#define WEAPONS_H

#include <QObject>
#include <QSound>

#include "collisionrect.h"
#include "movableentity.h"

class SceneBase;

class Bullet : public QObject, public MovableEntity {
 public:
  Bullet(SceneBase* parent_scene, MovableEntity* parent_obj);
  ~Bullet() override;

  void NextFrame();

 private:
  qreal GetAngle();
  void ProcessMovement(QVector2D way) override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  QRectF boundingRect() const override;

  SceneBase* parent_scene_;
  MovableEntity* parent_obj_;
  ObjectType parent_type_;
  QPixmap* sprite_;

  QVector2D direction_;

  int distance_;

  QSound* sound_;
};

#endif  // WEAPONS_H
