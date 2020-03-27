#include <QTimer>

#include "enemy.h"
#include "scene_base.h"

Enemy::Enemy(SceneBase* parent) : parent_scene_(parent) {
    setRect(0, 0, width_, height_);
}

void Enemy::NextFrame() {
    Player* target = parent_scene_->GetPlayer();

    QVector2D p_vect = target->GetDirectionVector();
    QVector2D vec_to_p = VectorToPlayer(target);

    QVector2D result_dir = p_vect + vec_to_p;
    result_dir.normalize();
    result_dir *= speed_;

    setPos(x() + result_dir.x(), y() + result_dir.y());

    if (vec_to_p.length() < attack_dist_) {
        Attack(target);
    }
}

void Enemy::Attack(Player* target) {
    if (!cooldown_) {
        target->SetHealth(target->GetHealth() - damage_);
        cooldown_ = true;
        qDebug() << target->GetHealth();
        QTimer::singleShot(attack_cd_*1000, this, &Enemy::FlushCooldown);
    }
}

QVector2D Enemy::VectorToPlayer(Player *target) {
    return QVector2D(target->x() + target->Width()/2
                                 - (x() + width_/2),
                     target->y() + target->Height()/2
                                 - (y() + height_/2));
}

void Enemy::FlushCooldown() {
    cooldown_ = false;
}
