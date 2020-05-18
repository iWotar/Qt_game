#ifndef LOCATIONBASE_H
#define LOCATIONBASE_H

#include <QMap>
#include <QObject>
#include <QPoint>
#include <QString>
#include <QVector>

class SceneBase;
class Environment;
class GameView;
class Player;

class LocationBase : public QObject {
  Q_OBJECT

 public:
  LocationBase();

  SceneBase* GetCurScene();
  void ChangeCurScene(SceneBase* scene);
  void SetView(GameView* view);

 signals:
  void SceneIsPaused();

 protected:
  QMap<QString, SceneBase*> rooms_;
  QMap<QString, QVector<QPair<Environment*, QPoint>>> doors_;

  QPair<QString, SceneBase*> cur_room_;

  GameView* view_;

  Player* player_;
};

#endif  // LOCATIONBASE_H
