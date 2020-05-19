#include "mainmenu.h"

#include <QGraphicsSceneWheelEvent>
#include <QLabel>

MainMenu::MainMenu() : QGraphicsScene() {
  setSceneRect(0, 0, 1000, 1000);
  font_.setPointSize(24);
  int id = QFontDatabase::addApplicationFont(":/fonts/Fonts/alagard.ttf");
  QString family = QFontDatabase::applicationFontFamilies(id).at(0);
  font_.setFamily(family);

  btn_begin_ = new PixmapButton(QPixmap(":/imges/Images/Button.png"),
                                QPixmap(":/imges/Images/Pressed.png"));

  connect(btn_begin_, &PixmapButton::Clicked, this, &MainMenu::OpenLevel);
  addItem(btn_begin_);

  btn_exit_ = new PixmapButton(QPixmap(":/imges/Images/Button.png"),
                               QPixmap(":/imges/Images/Pressed.png"));

  connect(btn_exit_, &PixmapButton::Clicked, this, &MainMenu::CloseGame);
  addItem(btn_exit_);

  btn_settings_ = new PixmapButton(QPixmap(":/imges/Images/Button.png"),
                                   QPixmap(":/imges/Images/Pressed.png"));
  connect(btn_settings_, &PixmapButton::Clicked, this, &MainMenu::OpenSettings);
  addItem(btn_settings_);

  btn_begin_->SetText(addText("Play", font_));
  btn_settings_->SetText(addText("Settings", font_));
  btn_exit_->SetText(addText("Exit", font_));

  logo_ = addPixmap(QPixmap(":/imges/Images/Logo.png"));

  QGraphicsPixmapItem *background_ = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/MenuBackground.png")
          .scaled(1280, 720, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
  addItem(background_);
  background_->setZValue(-1);
  background_->show();
}

void MainMenu::Resize() {
  QGraphicsView *view = views()[0];

  setSceneRect(0, 0, view->width(), view->height());
  view->horizontalScrollBar()->setValue(1);
  view->verticalScrollBar()->setValue(1);

  int32_t w = view->width();
  int32_t h = view->height();

  btn_begin_->Resize(btn_begin_->Width(), btn_begin_->Height());
  btn_begin_->setPos((w - btn_begin_->Width()) / 2, h / 6);

  btn_settings_->Resize(btn_exit_->Width(), btn_exit_->Height());
  btn_settings_->setPos((w - btn_exit_->Width()) / 2, h / 4);

  btn_exit_->Resize(btn_exit_->Width(), btn_exit_->Height());
  btn_exit_->setPos((w - btn_exit_->Width()) / 2, h / 3);

  btn_begin_->Text()->setPos(
      (w - btn_begin_->Width()) / 2 + btn_begin_->Width() / 3, h / 6 + 5);
  btn_settings_->Text()->setPos(
      (w - btn_settings_->Width()) / 2 + btn_settings_->Width() / 5 + 5,
      h / 4 + 5);
  btn_exit_->Text()->setPos(
      (w - btn_exit_->Width()) / 2 + btn_exit_->Width() / 3, h / 3 + 5);

  logo_->setPos((w - 650) / 2, h / 3 * 2);
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
