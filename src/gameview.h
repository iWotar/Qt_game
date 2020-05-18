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

class SceneBase;
class MainMenu;
class DevLocation;
class LocationBase;

enum class CurrentSceneType { MAIN_MENU, GAME_MENU, GAME };

class GameView : public QGraphicsView {
  Q_OBJECT

 public:
  GameView();

  void resizeEvent(QResizeEvent* event) override;

 public slots:
  void OpenLocation();
  void OpenMenu();

  void ExitGame();

  void UpdateInventoryLabels(const QVector<InteractableObject*>& objects);
  void UpdateInventoryLabels();
  void MoveInventorySelection(int);
  void ActivateAction();
  void DisplayText(const QString& text);

 protected:
  void wheelEvent(QWheelEvent* event) override;

 private:
  CurrentSceneType cur_scene_type_;
  SceneBase* cur_scene_;

  MainMenu* main_menu_;
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
