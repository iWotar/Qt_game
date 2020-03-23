#include "gameview.h"

#include <QApplication>
#include <QGraphicsView>

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);

  GameView* game = new GameView;
  Q_UNUSED(game);

  return application.exec();
}
