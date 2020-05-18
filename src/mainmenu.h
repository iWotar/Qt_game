#ifndef MAINMENU_H
#define MAINMENU_H

#include <QApplication>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QScrollBar>

#include "pixmapbutton.h"

class MainMenu : public QGraphicsScene {
  Q_OBJECT

 public:
  MainMenu();

  void Resize();

  void keyPressEvent(QKeyEvent *event) override;

  void wheelEvent(QGraphicsSceneWheelEvent *event) override;

 signals:
  void OpenLevel();
  void CloseGame();

 private:
  PixmapButton *btn_begin_;
  PixmapButton *btn_exit_;
};

#endif  // MAINMENU_H
