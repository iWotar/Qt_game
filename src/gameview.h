#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QApplication>
#include <QGraphicsView>
#include <QObject>
#include <QResizeEvent>

#include "mainmenu.h"
#include "player.h"
#include "scene_base.h"

enum class Scene { MAIN_MENU, DEV_LOCATION };

class GameView : public QGraphicsView {
  Q_OBJECT

 public:
  GameView();

  void resizeEvent(QResizeEvent* event) override;

 public slots:
  void OpenLocation();
  void OpenMenu();

  void ExitGame();

 private:
  Scene cur_scene_;

  MainMenu* main_menu_;
  SceneBase* dev_location_;

  bool mouse_scrolling_;
};

#endif  // GAMEVIEW_H
