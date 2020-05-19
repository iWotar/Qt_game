#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QApplication>
#include <QGraphicsView>
#include <QMap>
#include <QObject>
#include <QResizeEvent>
#include <QVBoxLayout>

#include "dialoglabel.h"
#include "interactableobject.h"
#include "inventorylabel.h"
#include "player.h"
#include "dialogs_and_notes.h"
#include "settingsmenu.h"
#include "gameover.h"

class SceneBase;
class MainMenu;
class DevLocation;
class LocationBase;

enum class CurrentSceneType { MAIN_MENU, GAME_MENU, GAME, SETTINGS };

enum class ActionFlag { HOLE, TABLE, WELL, BASEMENT_FOOD, ENDING };

class GameView : public QGraphicsView {
  Q_OBJECT

 public:
  GameView();

  void resizeEvent(QResizeEvent* event) override;

  DialogsAndNotes dialog_notes;

 public slots:
  void OpenLocation();
  void OpenMenu();
  void OpenSettings();
  void OpenGameOver();
  void ExitGame();

  void UpdateInventoryLabels(const QVector<InteractableObject*>& objects);
  void UpdateInventoryLabels();
  void MoveInventorySelection(int);
  void ActivateAction();
  void DisplayText(const QString& text);
  void EndDay();

 private slots:
  void EndDayImpl();

 public:
  QMap<ActionFlag, bool> flags_;

 protected:
  void wheelEvent(QWheelEvent* event) override;

 private:
  CurrentSceneType cur_scene_type_;
  SceneBase* cur_scene_;

  MainMenu* main_menu_;

  SceneBase* dev_location_;
  GameOver* game_over_;
  SettingsMenu* settings_;
  LocationBase* cur_location_;
  QMap<QString, LocationBase*> all_locations_;

  bool mouse_scrolling_;

  QWidget* inventory_widget;
  QLabel* selection_label;
  QVector<InventoryLabel*> inventory_labels;
  QVBoxLayout* inventory_widget_layout;
  int inventory_selection_index = 0;

  DialogLabel* dialog_label;

  qreal view_scale = 1.0;
  const qreal game_scale = 2.5;
};

#endif  // GAMEVIEW_H
