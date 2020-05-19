#include "settingsmenu.h"

SettingsMenu::SettingsMenu() {
  setSceneRect(0, 0, 1000, 1000);
  font_.setPointSize(14);
  QPixmap key_pixmap = QPixmap(":/imges/Images/KeyButton.png");

  back_to_menu_ = new PixmapButton(QPixmap(":/imges/Images/Button.png"),
                                   QPixmap(":/imges/Images/Pressed.png"));

  music_checkbox_ = new PixmapButton(QPixmap(":/imges/Images/ActiveChBox.png"),
                                     QPixmap(":/imges/Images/ChBox.png"));

  for (int i = 0; i < 9; i++) {
    buttons_.push_back(new PixmapButton(key_pixmap, key_pixmap));
  }

  QVector<QString> text({"W", "S", "D", "A", "Space", "E", "Q", "UP", "DOWN"});
  QVector<QString> descr_text({"Move up", "Move down", "Move left",
                               "Move right", "Attack", "Interact", "Activate",
                               "Select Up", "Select Down"});
  QVector<ActionType> act_type(
      {ActionType::MOVE_UP, ActionType::MOVE_DOWN, ActionType::MOVE_LEFT,
       ActionType::MOVE_RIGHT, ActionType::ATTACK, ActionType::INTERACT,
       ActionType::ACTIVATE, ActionType::SELECT_UP, ActionType::SELECT_DOWN});

  for (int i = 0; i < text.size(); i++) {
    addItem(buttons_[i]);
    buttons_[i]->SetText(addText(text[i]));
    buttons_[i]->Text()->setFont(font_);
    descriptions_.push_back(addText(descr_text[i]));
    connect(buttons_[i], &PixmapButton::Clicked, this,
            &SettingsMenu::ChangeKey);
    buttons_[i]->SetType(act_type[i]);
    font_.setPointSize(20);
    descriptions_[i]->setFont(font_);
    font_.setPointSize(14);
  }

  addItem(back_to_menu_);
  font_.setPointSize(20);
  back_to_menu_->SetText(addText("Back to menu"));
  back_to_menu_->Text()->setFont(font_);
  connect(back_to_menu_, &PixmapButton::Clicked, this,
          &SettingsMenu::BackToMenu);

  addItem(music_checkbox_);
  connect(music_checkbox_, &PixmapButton::Clicked, this,
          &SettingsMenu::SwitchMusic);
  music_checkbox_->SetType(ActionType::SWITCH);
  music_checkbox_->SetText(addText("Music On/Off"));
  music_checkbox_->Text()->setFont(font_);

  QGraphicsPixmapItem *background_ = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/MenuBackground.png")
          .scaled(1280, 720, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
  addItem(background_);
  background_->setZValue(-1);
  background_->show();
}

void SettingsMenu::Resize() {
  QGraphicsView *view = views()[0];

  setSceneRect(0, 0, view->width(), view->height());
  view->horizontalScrollBar()->setValue(1);
  view->verticalScrollBar()->setValue(1);

  int32_t w = view->width();
  int32_t h = view->height();

  int32_t h_0 = h / 12;
  for (int i = 0; i < 5; i++) {
    PixmapButton *btn = buttons_[i];
    btn->Resize(btn->Width(), btn->Height());
    btn->setPos(w / 20 * 6, h_0);

    int text_len = btn->Text()->toPlainText().length();
    btn->Text()->setPos(w / 20 * 6 + btn->Width() / (3 * text_len), h_0 + 5);
    descriptions_[i]->setPos(w / 10, h_0 + 5);
    h_0 += h / 8;
  }

  h_0 = h / 12;
  for (int i = 5; i < 9; i++) {
    PixmapButton *btn = buttons_[i];
    btn->Resize(btn->Width(), btn->Height());
    btn->setPos(w / 20 * 13, h_0);

    int text_len = btn->Text()->toPlainText().length();
    btn->Text()->setPos(w / 20 * 13 + btn->Width() / (3 * text_len), h_0 + 5);
    descriptions_[i]->setPos(w / 10 * 4, h_0 + 5);
    h_0 += h / 8;
  }

  h_0 += h / 8;

  music_checkbox_->Resize(music_checkbox_->Width(), music_checkbox_->Height());
  music_checkbox_->setPos(w / 20 * 13, h_0);
  music_checkbox_->Text()->setPos(w / 5 * 2, h_0);
  h_0 += h / 8;

  back_to_menu_->Resize(back_to_menu_->Width(), back_to_menu_->Height());
  back_to_menu_->setPos(w / 5 * 2, h_0);
  back_to_menu_->Text()->setPos(w / 5 * 2 + back_to_menu_->Width() / 8 - 2,
                                h_0 + 5);
}

void SettingsMenu::ChangeKey() {
  PixmapButton *obj = dynamic_cast<PixmapButton *>(sender());
  ch_button_type = obj->GetType();
  ch_button = obj;
  obj->Text()->setPlainText("-");
}

QString SettingsMenu::KeyToString(QKeyEvent *event) const {
  switch (event->nativeVirtualKey()) {
    case 16:
      return "Shift";
    case 17:
      return "Ctrl";
    case 18:
      return "Alt";
    case 13:
      return "Enter";
    case 219:
      return "[";
    case 221:
      return "]";
    case 186:
      return ";";
    case 222:
      return "'";
    case 188:
      return ",";
    case 190:
      return ".";
    case 191:
      return "/";
  }
  int key_code = event->key();
  if (key_code >= 1040 && key_code <= 1071) {
    key_code = event->nativeVirtualKey();
  }
  QString res = QKeySequence(key_code).toString();
  return res;
}

void SettingsMenu::keyPressEvent(QKeyEvent *event) {
  if (ch_button_type != ActionType::NONE) {
    Qt::Key key = SceneBase::control_keys_.key(ch_button_type);
    SceneBase::control_keys_[key] = ActionType::NONE;
    SceneBase::control_keys_[static_cast<Qt::Key>(event->key())] =
        ch_button_type;
    QString key_name = KeyToString(event).toUpper();
    for (auto btn : buttons_) {
      if (btn->Text()->toPlainText().toUpper() == key_name) {
        btn->Text()->setPlainText(" ");
      }
    }
    ch_button->Text()->setPlainText(key_name);
    Resize();
    ch_button_type = ActionType::NONE;
  }
}
