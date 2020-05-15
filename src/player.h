#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsScene>
#include <QSound>
#include <QVector2D>
#include <QtGui>

#include "collisionrect.h"
#include "hpbar.h"
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

  void AttackStart();
  Directions direction_;

  void StartSound(SoundType type);

  void StopSound(SoundType type);

 public slots:
  void FlushCooldown();
  void Attack();

 private:
  void ProcessAnimation() override;
  void ProcessMovement(QVector2D way) override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  QRectF boundingRect() const override;

  SceneBase* parent_scene_;

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
