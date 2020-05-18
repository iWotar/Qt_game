#include "gameview.h"

#include <QBrush>
#include <QColor>
#include <QGraphicsSceneWheelEvent>

#include "citylocation.h"
#include "mainmenu.h"
#include "scene_base.h"

GameView::GameView()
    : cur_scene_type_(CurrentSceneType::MAIN_MENU),
      main_menu_(new MainMenu),
      game_over_(new GameOver),
      settings_(new SettingsMenu) {
  setScene(main_menu_);

  setFixedSize(QSize(1280, 720));
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  setBackgroundBrush(QBrush(QColor(0, 0, 0)));

  show();

  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  mouse_scrolling_ = false;

  all_locations_.insert(QString("dev_lock"), new CityLocation(this));
  cur_location_ = all_locations_["dev_lock"];
  all_locations_["dev_lock"]->GetCurScene()->DefaultControl();
  connect(main_menu_, &MainMenu::OpenLevel, this, &GameView::OpenLocation);
  connect(main_menu_, &MainMenu::CloseGame, this, &GameView::ExitGame);
  connect(main_menu_, &MainMenu::OpenSettings, this, &GameView::OpenSettings);
  connect(settings_, &SettingsMenu::BackToMenu, this, &GameView::OpenMenu);
  connect(cur_location_->GetCurScene()->GetPlayer(), &Player::Dead, this,
          &GameView::OpenGameOver);
  connect(game_over_, &GameOver::BackToMenu, this, &GameView::OpenMenu);

  for (auto loc : all_locations_) {
    connect(loc, &CityLocation::SceneIsPaused, this, &GameView::OpenMenu);
    connect(settings_, &SettingsMenu::SwitchMusic, loc->GetCurScene(),
            &SceneBase::SwitchMusic);
  }

  inventory_widget = new QWidget(this);
  inventory_widget->setGeometry(1280 - 130, 0, 130, 720);
  inventory_widget->show();
  inventory_widget_layout = new QVBoxLayout(inventory_widget);
  inventory_widget_layout->setAlignment(Qt::AlignTop);
  selection_label = new QLabel(inventory_widget);
  selection_label->setPixmap(QPixmap(":/imges/Images/selection.png"));
  selection_label->hide();

  dialog_label = new DialogLabel(this);
  dialog_label->hide();
}

void GameView::resizeEvent(QResizeEvent* event) {
  Q_UNUSED(event);

  if (cur_scene_type_ == CurrentSceneType::MAIN_MENU) {
    main_menu_->Resize();
  } else if (cur_scene_type_ == CurrentSceneType::SETTINGS) {
    settings_->Resize();
  }
}

void GameView::OpenLocation() {
  if (view_scale == 1.0) {
    view_scale = game_scale;
    scale(game_scale, game_scale);
  }
  cur_scene_type_ = CurrentSceneType::GAME;
  SceneBase* cur_room = cur_location_->GetCurScene();
  setScene(cur_room);
  cur_room->SetPaused(false);
  Player* player = cur_room->GetPlayer();
  if (player != nullptr) {
    centerOn(player->pos().toPoint() +
             QPoint(player->Width() / 2, player->Height() / 2));
  }
  inventory_widget->show();
  dialog_label->hide();
}

void GameView::DisplayText(const QString& str) {
  dialog_label->DisplayText(str);
}

void GameView::OpenMenu() {
  if (view_scale == game_scale) {
    view_scale = 1.0;
    scale(1.0 / game_scale, 1.0 / game_scale);
  }
  SceneBase* cur_room = cur_location_->GetCurScene();
  cur_room->SetPaused(true);
  setScene(main_menu_);
  main_menu_->Resize();

  QGraphicsItem* mgi = main_menu_->mouseGrabberItem();
  if (mgi != nullptr) {
    mgi->setEnabled(false);
    mgi->setEnabled(true);
  }
  cur_scene_type_ = CurrentSceneType::MAIN_MENU;
  inventory_widget->hide();
  dialog_label->hide();
}

void GameView::OpenSettings() {
  setScene(settings_);
  settings_->Resize();
  cur_scene_type_ = CurrentSceneType::SETTINGS;
}

void GameView::OpenGameOver() {
  if (view_scale == game_scale) {
    view_scale = 1.0;
    scale(1.0 / game_scale, 1.0 / game_scale);
  }

  SceneBase* cur_room = cur_location_->GetCurScene();
  cur_room->SetPaused(true);
  setScene(game_over_);
  game_over_->Resize();
  inventory_widget->hide();
  dialog_label->hide();

  delete cur_location_->GetCurScene()->GetPlayer();
  delete cur_location_;
  UpdateInventoryLabels(QVector<InteractableObject*>());
  all_locations_["dev_lock"] = new CityLocation(this);
  cur_location_ = all_locations_["dev_lock"];
  cur_location_->GetCurScene()->DefaultControl();

  connect(cur_location_->GetCurScene()->GetPlayer(), &Player::Dead, this,
          &GameView::OpenGameOver);
  connect(cur_location_, &CityLocation::SceneIsPaused, this,
          &GameView::OpenMenu);
}

void GameView::ExitGame() {
  // Можно добавить окно уточнения выхода или сохранение
  QApplication::exit();
}

void GameView::wheelEvent(QWheelEvent* event) {
  // propagate event to active scene without triggering view scroll
  SceneBase* cur_room = cur_location_->GetCurScene();
  QGraphicsSceneWheelEvent* new_event = new QGraphicsSceneWheelEvent;
  new_event->setPos(event->pos());
  new_event->setDelta(event->delta());
  new_event->setButtons(event->buttons());
  cur_room->wheelEvent(new_event);
}

void GameView::UpdateInventoryLabels(
    const QVector<InteractableObject*>& objects) {
  for (auto inventory_label : inventory_labels) {
    delete inventory_label;
  }
  inventory_labels.clear();
  for (auto object : objects) {
    InventoryLabel* inventory_label = new InventoryLabel(inventory_widget);
    inventory_labels.append(inventory_label);
    inventory_label->setPixmap(object->GetPixmap());
    inventory_widget_layout->addWidget(inventory_label);
  }
  MoveInventorySelection(0);
  if (objects.empty()) {
    selection_label->hide();
  } else {
    selection_label->show();
    selection_label->setGeometry(0, inventory_selection_index * 130, 130, 130);
  }
}

void GameView::UpdateInventoryLabels() {
  if (inventory_labels.empty()) {
    selection_label->hide();
  } else {
    selection_label->show();
    selection_label->setGeometry(0, inventory_selection_index * 130, 130, 130);
  }
}

void GameView::ActivateAction() {
  SceneBase* cur_room = cur_location_->GetCurScene();
  Player* player = cur_room->GetPlayer();
  if (player != nullptr) {
    player->Activate(inventory_selection_index);
  }
}

void GameView::MoveInventorySelection(int offset) {
  inventory_selection_index += offset;
  if (inventory_selection_index >= inventory_labels.size()) {
    inventory_selection_index = inventory_labels.size() - 1;
  }
  if (inventory_selection_index < 0) {
    inventory_selection_index = 0;
  }
  UpdateInventoryLabels();
}
