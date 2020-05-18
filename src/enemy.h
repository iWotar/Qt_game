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
  void ProcessAnimation() override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;
  QRectF boundingRect() const override;

  SceneBase* parent_scene_;

  int32_t damage_ = 50;
  int32_t attack_cd_ = 1;
  int32_t cur_health_ = 100;
  int32_t max_health_ = 100;
  bool cooldown_ = false;
  bool attack_played = false;
  HpBar* hp_bar_;
};

#endif  // ENEMY_H
