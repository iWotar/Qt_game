#include "scene_base.h"
#include <QApplication>
#include <QGraphicsView>

int main(int argc, char *argv[]) {
  QApplication application(argc, argv);

  SceneBase* test = new SceneBase;
  QGraphicsView* view = new QGraphicsView(test);

  view->setFixedSize(QSize(1280, 720));
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->show();

  return application.exec();
}
