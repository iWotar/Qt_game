#include "player.h"

Player::Player() {
  setRect(0, 0, width_, height_);

  direction_ = Directions::STAY;
}

void Player::NextFrame() {
  switch (direction_) {
  case Directions::UP:
    if (y() > 0) {
      setPos(x(), y() - speed_);
    }
    break;
  case Directions::DOWN:
    if (y() < scene()->height() - height_) {
      setPos(x(), y() + speed_);
    }
    break;
  case Directions::RIGHT:
    if (x() < scene()->width() - width_) {
      setPos(x() + speed_, y());
    }
    break;
  case Directions::LEFT:
    if (x() > 0) {
      setPos(x() - speed_, y());
    }
    break;
  default:
    break;
  }
}

int Player::GetSpeed() const {
    return speed_;
}

int Player::GetHealth() const {
    return health_;
}

QVector2D Player::GetDirectionVector() {
    switch (direction_) {
    case Directions::UP :
        return QVector2D(0, -speed_);
    case Directions::DOWN :
        return QVector2D(0, speed_);
    case Directions::LEFT :
        return QVector2D(-speed_, 0);
    case Directions::RIGHT :
        return QVector2D(speed_, 0);
    case Directions::STAY :
        return  QVector2D();
    }
}


int Player::Width() const {
  return width_;
}

int Player::Height() const {
  return height_;
}

void Player::SetSize(const QSize& size) {
  setRect(width_, height_, size.width(), Height());

  width_ = size.width();
  height_ = size.height();
}

void Player::SetHealth(int hp) {
    health_ = hp;
}
