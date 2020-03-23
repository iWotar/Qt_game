#include "mainmenu.h"

MainMenu::MainMenu() : QGraphicsScene() {
  setSceneRect(0, 0, 1000, 1000);

  btn_begin_ = new PixmapButton(new QPixmap(":/imges/Images/Begin.bmp"));
  connect(btn_begin_, &PixmapButton::Clicked, this, &MainMenu::OpenLevel);
  addItem(btn_begin_);

  btn_exit_ = new PixmapButton(new QPixmap(":/imges/Images/Exit.bmp"));
  connect(btn_exit_, &PixmapButton::Clicked, this, &MainMenu::CloseGame);
  addItem(btn_exit_);
}

void MainMenu::Resize() {
  QGraphicsView* view = views()[0];

  setSceneRect(0, 0, view->width(), view->height());
  view->horizontalScrollBar()->setValue(1);
  view->verticalScrollBar()->setValue(1);

  int w = view->width();
  int h = view->height();

  btn_begin_->Resize(w / 4 * 2, h / 5);
  btn_begin_->setPos(w / 4, h / 5 * 2);

  btn_exit_->Resize(w / 4 * 2, h / 5);
  btn_exit_->setPos(w / 4, h / 5 * 3);
}

void MainMenu::keyPressEvent(QKeyEvent* event) {
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
