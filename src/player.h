#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>


enum bearings {UP, DOWN, RIGHT, LEFT, STAY};

class Player : public QGraphicsRectItem {
public:
    Player();

    void NextFrame();

    bearings derect_;

private:
    int speed_ = 5;
};

#endif // PLAYER_H
