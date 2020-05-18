#ifndef CITYLOCATION_H_
#define CITYLOCATION_H_

#include <QMap>
#include <QObject>
#include <QPoint>
#include <QString>
#include <QVector>

#include "locationbase.h"

class SceneBase;
class Environment;
class GameView;
class Player;

class CityLocation : public LocationBase {
  Q_OBJECT

 public:
  explicit CityLocation(GameView*);
};

#endif  // CITYLOCATION_H_
