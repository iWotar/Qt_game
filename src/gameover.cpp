#include "gameover.h"

GameOver::GameOver() {
  setSceneRect(0, 0, 1000, 1000);
  font_.setPointSize(20);

  back_to_menu_ = new PixmapButton(QPixmap(":/imges/Images/Button.png"),
                                   QPixmap(":/imges/Images/Pressed.png"));

  connect(back_to_menu_, &PixmapButton::Clicked, this, &GameOver::BackToMenu);
  addItem(back_to_menu_);

  back_to_menu_->SetText(addText("Back to menu"));
  back_to_menu_->Text()->setFont(font_);

  font_.setPointSize(45);
  logo_ = addText("Game Over");
  logo_->setFont(font_);

  background_ = QPixmap(":/imges/Images/MenuBackground.png");
  setBackgroundBrush(background_.scaled(1000, 1000, Qt::IgnoreAspectRatio,
                                        Qt::SmoothTransformation));
}

void GameOver::Resize() {
  QGraphicsView *view = views()[0];

  setSceneRect(0, 0, view->width(), view->height());
  view->horizontalScrollBar()->setValue(1);
  view->verticalScrollBar()->setValue(1);

  int32_t w = view->width();
  int32_t h = view->height();

  back_to_menu_->Resize(back_to_menu_->Width(), back_to_menu_->Height());
  back_to_menu_->setPos((w - back_to_menu_->Width()) / 2, h / 3 * 2);
  back_to_menu_->Text()->setPos(
      (w - back_to_menu_->Width()) / 2 + back_to_menu_->Width() / 8 - 2,
      h / 3 * 2 + 5);

  logo_->setPos((w - 350) / 2, h / 3);
}
