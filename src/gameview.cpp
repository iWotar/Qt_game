#include "gameview.h"

GameView::GameView() : cur_scene_(Scene::MAIN_MENU),
                       main_menu_(new MainMenu),
                       dev_location_(new SceneBase) {
  dev_location_->SetPaused(true);

  setScene(main_menu_);

  setMinimumSize(QSize(800, 800));

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  show();

  connect(main_menu_, &MainMenu::OpenLevel, this, &GameView::OpenLocation);
  connect(main_menu_, &MainMenu::CloseGame, this, &GameView::ExitGame);
  connect(dev_location_, &SceneBase::SceneIsPaused, this, &GameView::OpenMenu);
}

void GameView::resizeEvent(QResizeEvent* event) {
  Q_UNUSED(event);

  if (cur_scene_ == Scene::MAIN_MENU) {
    main_menu_->Resize();
  }
}

void GameView::OpenLocation() {
  cur_scene_ = Scene::DEV_LOCATION;

  setScene(dev_location_);
  dev_location_->SetPaused(false);
  Player* player = dev_location_->GetPlayer();
  centerOn(player->pos().toPoint() +
           QPoint(player->Width() / 2, player->Height() / 2));
}

void GameView::OpenMenu() {
  dev_location_->SetPaused(true);
  setScene(main_menu_);
  main_menu_->Resize();

  QGraphicsItem* mgi =  main_menu_->mouseGrabberItem();
  if (mgi != nullptr) {
    mgi->setEnabled(false);
    mgi->setEnabled(true);
  }

  cur_scene_ = Scene::MAIN_MENU;
}

void GameView::ExitGame() {
  // Можно добавить окно уточнения выхода или сохранение
  QApplication::exit();
}
