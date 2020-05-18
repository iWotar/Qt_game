#include "mainmenu.h"

#include <QGraphicsSceneWheelEvent>

MainMenu::MainMenu() : QGraphicsScene() {
  setSceneRect(0, 0, 1280, 720);

  btn_begin_ = new PixmapButton(new QPixmap(":/imges/Images/Begin.png"));
  connect(btn_begin_, &PixmapButton::Clicked, this, &MainMenu::OpenLevel);
  addItem(btn_begin_);

  btn_exit_ = new PixmapButton(new QPixmap(":/imges/Images/Exit.png"));
  connect(btn_exit_, &PixmapButton::Clicked, this, &MainMenu::CloseGame);
  addItem(btn_exit_);
}

void MainMenu::Resize() {
  QGraphicsView *view = views()[0];

  setSceneRect(0, 0, view->width(), view->height());
  view->horizontalScrollBar()->setValue(1);
  view->verticalScrollBar()->setValue(1);

  btn_begin_->setPos(360 - 125, 50);
  btn_begin_->Resize(250 * 2, 150 * 2);

  btn_exit_->setPos(360 - 125, 100 + 250);
  btn_exit_->Resize(250 * 2, 150 * 2);
}

void MainMenu::keyPressEvent(QKeyEvent *event) {
  switch (event->key()) {
    case Qt::Key_G:
      emit OpenLevel();
      break;

    case Qt::Key_E:
      emit CloseGame();
      break;

    default:
      break;
  }
}

void MainMenu::wheelEvent(QGraphicsSceneWheelEvent *event) { event->accept(); }
