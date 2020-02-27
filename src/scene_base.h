#ifndef SCENE_BASE_H
#define SCENE_BASE_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QGraphicsView>
#include "player.h"

class Scene_base : public QGraphicsScene {
    Q_OBJECT
public:
    Scene_base();
    void timerEvent (QTimerEvent* event);
    void keyPressEvent (QKeyEvent* event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    void SetField();
    Player* player_;
};

#endif // SCENE_BASE_H
