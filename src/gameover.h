#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QScrollBar>

#include "pixmapbutton.h"
class GameOver : public QGraphicsScene {
  Q_OBJECT

 public:
  GameOver();

  void Resize();

 signals:
  void BackToMenu();

 private:
  PixmapButton* back_to_menu_;
  QPixmap background_;
  QGraphicsTextItem* logo_;

  QFont font_ = QFont("Alagard");
};

#endif  // GAMEOVER_H
