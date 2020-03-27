#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QVector2D>

enum class Directions {UP, DOWN, RIGHT, LEFT, STAY};

class Player : public QGraphicsRectItem {
 public:
  Player();

  void NextFrame();

  int GetSpeed() const;
  int GetHealth() const;
  QVector2D GetDirectionVector();

  int Width() const;
  int Height() const;

  void SetSize(const QSize& size);
  void SetHealth(int hp);

  Directions direction_;

 private:
  int health_ = 100;
  int speed_ = 5;

  int width_ = 100;
  int height_ = 200;
};

#endif  // PLAYER_H
