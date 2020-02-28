#include "player.h"

Player::Player() {
  setRect(0, 0, 20, 50);

  direction_ = Directions::STAY;
}

void Player::NextFrame() {
  switch (direction_) {
  case Directions::UP:
    setPos(x(), y() - speed_);
    break;
  case Directions::DOWN:
    setPos(x(), y() + speed_);
    break;
  case Directions::RIGHT:
    setPos(x() + speed_, y());
    break;
  case Directions::LEFT:
    setPos(x() - speed_, y());
    break;
  default:
    break;
    }
}
