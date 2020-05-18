#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QSound>
#include <QVector2D>
#include <QtGui>

#include "collisionrect.h"
#include "hpbar.h"
#include "interactableobject.h"
#include "movableentity.h"

class SceneBase;
class CollisionRect;
class PickableObject;

enum class Directions { UP, DOWN, RIGHT, LEFT, STAY };

enum class SoundType { BOW_SHOT, STEPS };

class Player : public QObject, public MovableEntity {
  Q_OBJECT

 public:
  explicit Player(SceneBase* parent);

  void NextFrame();

  SceneBase* GetCurScene();

  void MoveToScene(SceneBase* scene);

  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

  int32_t GetHealth() const;
  QVector2D GetDirectionVector() const;
  QVector<QGraphicsItem*> GetNearbyObjects();
  int32_t GetDamage() const;

  void SetHealth(int32_t hp);

  void Interact();
  void Activate(int index);

  void AttackStart();
  Directions direction_;

  void StartSound(SoundType type);

  void StopSound(SoundType type);

 public slots:
  void FlushCooldown();
  void Attack();

 private:
  friend InteractableObject;
  friend PickableObject;

  QPixmap sprite_ = QPixmap(":/imges/Images/Player.png");

  void ProcessAnimation() override;
  void ProcessMovement(QVector2D way) override;

  QRectF boundingRect() const override;

  SceneBase* parent_scene_ = nullptr;

  CollisionRect* interaction_aura_ = nullptr;
  InteractableObject* GetClosestInteractableObject();
  InteractableObject* previous_highlight_ = nullptr;
  QVector<InteractableObject*> inventory_;

  bool is_attacking = false;
  int32_t damage_ = 30;
  int32_t attack_cd_ = 1;
  int32_t cur_health_ = 100;
  int32_t max_health_ = 100;
  bool cooldown_ = false;

  QMap<SoundType, QSound*> sounds_;
  HpBar* hp_bar_;
};

#endif  // PLAYER_H
