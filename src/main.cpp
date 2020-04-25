#include <QApplication>
#include <QGraphicsView>

#include "gameview.h"

int main(int argc, char* argv[]) {
  QApplication application(argc, argv);

  GameView *game = new GameView;
  Q_UNUSED(game);

  return application.exec();
}
