#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem>

#include "player.h"

class SceneBase;

class Enemy : public QObject, public QGraphicsRectItem {
    Q_OBJECT
 public:
    explicit Enemy(SceneBase* parent);
    void NextFrame();
    void Attack(Player* target);
    QVector2D VectorToPlayer(Player* target);

 public slots:
    void FlushCooldown();

 private:
    SceneBase* parent_scene_;

    int speed_ = 1;
    int damage_ = 10;
    int attack_cd_ = 1;
    double attack_dist_ = 10;
    bool cooldown_ = false;

    int width_ = 50;
    int height_ = 100;
};

#endif  // ENEMY_H
