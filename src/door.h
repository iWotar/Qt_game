#ifndef DOOR_H
#define DOOR_H

#include <QGraphicsRectItem>
#include <QPoint>

class Environment;
class SceneBase;
class Player;
class CityLocation;

enum class DirectionType { FIRST_TO_SECOND, SECOND_TO_FIRST, BIDIRECTIONAL };

class Door : public QGraphicsRectItem {
 public:
  Door(Environment* first_part, Environment* second_part,
       SceneBase* first_scene, SceneBase* second_scene, QPoint first_coord,
       QPoint second_coord);

  void SetFirstScene(SceneBase* scene);
  void SetSecondScene(SceneBase* scene);
  void SetLocation(CityLocation* location);

  void SetDirType(DirectionType type);

  Environment* GetFirstPart() const;
  Environment* GetSecondPart() const;

  bool Teleport(Player* player);

 private:
  DirectionType dir_type_ = DirectionType::BIDIRECTIONAL;

  Environment* first_part_;
  Environment* second_part_;

  SceneBase* first_scene_;
  SceneBase* second_scene_;

  CityLocation* location_;

  QPoint first_coord_;
  QPoint second_coord_;
};

#endif  // DOOR_H
