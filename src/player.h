#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>

enum Directions {UP, DOWN, RIGHT, LEFT, STAY};

class Player : public QGraphicsRectItem {

 public:
  Player();
  void NextFrame();

  Directions direction_;

 private:
  int speed_ = 5;
};

#endif // PLAYER_H
