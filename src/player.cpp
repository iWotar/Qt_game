#include "player.h"

Player::Player() {
    setRect(0, 0, 20, 50);

    derect_ = STAY;
}

void Player::NextFrame() {
    switch (derect_) {
    case UP:
        setPos(x(), y() - speed_);
        break;
    case DOWN:
        setPos(x(), y() + speed_);
        break;
    case RIGHT:
        setPos(x() + speed_, y());
        break;
    case LEFT:
        setPos(x() - speed_, y());
        break;
    default:
        break;
    }
}
