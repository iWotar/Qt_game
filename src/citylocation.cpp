#include "citylocation.h"

#include <QGraphicsPixmapItem>

#include "archer.h"
#include "collisionrect.h"
#include "door.h"
#include "enemy.h"
#include "environment.h"
#include "gameview.h"
#include "interactableobject.h"
#include "pickableobject.h"
#include "player.h"
#include "scene_base.h"

CityLocation::CityLocation(GameView* view) {
  SetView(view);
  {
    SceneBase* room = new SceneBase("player_house", view);
    room->setSceneRect(0, 0, 438, 336);

    room->SetPaused(true);

    // Частота обновления кадров
    room->startTimer(30);

    QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
        QPixmap(":/imges/Images/rooms/player_house_inside.png"));
    room->addItem(back);
    back->setZValue(-1);

    {{Environment* inv_walls =
          new Environment(188, 47, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(2, 289);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(47, 50, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(1, 241);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(405, 72, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(1, 1);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(47, 49, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(2, 72);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(52, 27, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(45, 68);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(289, 29, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(119, 72);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(25, 43, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(120, 100);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(87, 56, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(174, 167);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }
}

{
  {
    Environment* inv_walls =
        new Environment(93, 43, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(312, 101);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(22, 169, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(384, 143);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(189, 46, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(217, 288);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(24, 24, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(360, 193);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(26, 23, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(287, 121);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(25, 29, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(48, 262);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }

  {
    Environment* inv_walls =
        new Environment(22, 120, CollisionLayer::PHYSICS_BODY, room);
    inv_walls->CustomizeColComp(
        QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
    inv_walls->SetPos(1, 123);
    inv_walls->SetColCompVisibility(false);
    inv_walls->SetVisibility(false);
    room->addItem(inv_walls);
  }
}

Environment* door = new Environment(24, 48, CollisionLayer::NONE, room);
door->SetPixmap(new QPixmap(":/imges/Images/locked_door.png"));
door->SetPos(192, 289);
room->addItem(door);
doors_["player_house_to_city"].append({door, QPoint{170, 233}});

rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("city", view);

  room->setSceneRect(0, 0, 1600, 1600);
  room->SetPaused(true);

  QGraphicsPixmapItem* back =
      new QGraphicsPixmapItem(QPixmap(":/imges/Images/City.png"));
  room->addItem(back);
  back->setZValue(-1);

  // Частота обновления кадров
  room->startTimer(30);

  {
    Enemy* enemy_ = new Enemy(room);
    enemy_->setPos(280, 360);
    room->enemies_.append(enemy_);
    room->addItem(enemy_);
  }

  {
    Enemy* enemy_ = new Enemy(room);
    enemy_->setPos(90, 1090);
    room->enemies_.append(enemy_);
    room->addItem(enemy_);
  }

  {
    Enemy* enemy_ = new Enemy(room);
    enemy_->setPos(1327, 336);
    room->enemies_.append(enemy_);
    room->addItem(enemy_);
  }

  {{Environment* inv_walls =
        new Environment(1596, 118, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(QVector2D(0, 0), QVector2D(1596, 118));
  inv_walls->SetPos(1, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(40, 161, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(200, 119);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(240, 110, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(240, 210);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(160, 160, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(40, 240);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(410, 180, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(177, 582);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(44, 98, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(199, 483);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(65, 79, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(519, 762);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(104, 14, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(415, 827);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(170, 14, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(175, 827);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(10, 66, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(175, 761);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

// Невидимые стены
{
  Environment* inv_walls =
      new Environment(40, 41, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(40, 560);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(38, 84, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(41, 638);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(40, 83, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(120, 681);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(40, 73, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(80, 767);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(43, 159, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(39, 924);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(41, 78, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(160, 924);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(41, 194, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(159, 1046);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(41, 79, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(79, 1163);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{{Environment* inv_walls =
      new Environment(42, 119, CollisionLayer::PHYSICS_BODY, room);
inv_walls->CustomizeColComp(QVector2D(0, 0),
                            QVector2D(inv_walls->Width(), inv_walls->Height()));
inv_walls->SetPos(40, 1282);
inv_walls->SetColCompVisibility(false);
inv_walls->SetVisibility(false);
room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(440, 132, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(200, 1069);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(120, 81, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(200, 1201);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(159, 81, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(520, 1201);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(681, 121, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(39, 1401);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(721, 119, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(840, 1402);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(42, 79, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(760, 1442);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(40, 1494, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 111);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(1710, 89, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(39, 1520);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(36, 1412, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1559, 115);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(199, 149, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1080, 170);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
{
  Environment* inv_walls =
      new Environment(43, 86, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1279, 198);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
// Невидимые стены
{
  Environment* inv_walls =
      new Environment(232, 198, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1323, 122);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(119, 160, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(840, 160);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(38, 39, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1000, 242);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(43, 77, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(958, 162);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(239, 118, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(600, 161);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(120, 98, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(600, 222);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(38, 39, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(521, 242);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(241, 159, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1279, 480);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(40, 9, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1241, 481);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(206, 91, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1161, 674);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(197, 118, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(963, 443);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(43, 79, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1198, 441);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(9, 189, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1240, 487);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
// Невидимые стены
{
  Environment* inv_walls =
      new Environment(160, 90, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1240, 711);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(43, 87, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1519, 716);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(199, 155, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(960, 688);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{{Environment* inv_walls =
      new Environment(42, 130, CollisionLayer::PHYSICS_BODY, room);
inv_walls->CustomizeColComp(QVector2D(0, 0),
                            QVector2D(inv_walls->Width(), inv_walls->Height()));
inv_walls->SetPos(1119, 561);
inv_walls->SetColCompVisibility(false);
inv_walls->SetVisibility(false);
room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(42, 77, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1519, 924);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(319, 163, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1200, 1038);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(200, 209, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1319, 1194);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(40, 39, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1159, 1241);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(120, 141, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1039, 1140);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(119, 118, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(880, 1163);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(43, 41, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(719, 279);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
// Невидимые стены
{
  Environment* inv_walls =
      new Environment(43, 42, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(599, 559);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(37, 76, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(882, 604);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(37, 80, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(762, 803);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(41, 39, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(919, 482);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(39, 10, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1520, 479);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(43, 42, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(199, 399);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(410, 19, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(175, 560);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(38, 67, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(281, 760);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(104, 27, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(415, 801);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(28, 28, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(317, 801);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(30, 31, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(841, 1084);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(30, 30, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(687, 1081);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(35, 34, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(685, 1244);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
// Невидимые стены
{
  Environment* inv_walls =
      new Environment(33, 32, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(841, 1248);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(30, 32, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(685, 687);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(30, 30, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(846, 691);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(30, 28, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(685, 447);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(31, 29, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(842, 445);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(81, 44, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1480, 313);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
{
  Environment* inv_walls =
      new Environment(16, 234, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(569, 562);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}
{{Environment* build = new Environment(240, 160, CollisionLayer::NONE, room);
build->SetPixmap(new QPixmap(":/imges/Images/buildings/nun_house.png"));
build->CustomizeColComp(QVector2D(0, 0),
                        QVector2D(build->Width(), build->Height()));
build->SetPos(240, 160);
build->SetColCompVisibility(false);
build->setZValue(280);
room->addItem(build);
}

{
  Environment* build = new Environment(160, 160, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/fake_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(40, 240);
  build->SetColCompVisibility(false);
  build->setZValue(390);
  room->addItem(build);
}

{
  Environment* build = new Environment(280, 320, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/church.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(240, 441);
  build->SetColCompVisibility(false);
  build->setZValue(740);
  room->addItem(build);
}

{
  Environment* build = new Environment(441, 279, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/trader_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(199, 1002);
  build->SetColCompVisibility(false);
  build->setZValue(1170);
  room->addItem(build);
}

{
  Environment* build = new Environment(360, 240, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/main_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(600, 80);
  build->SetColCompVisibility(false);
  build->setZValue(263);
  room->addItem(build);
}

{
  Environment* build = new Environment(240, 240, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/hunter_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(1280, 401);
  build->SetColCompVisibility(false);
  build->setZValue(610);
  room->addItem(build);
}

{
  Environment* build = new Environment(200, 200, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/player_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(959, 640);
  build->SetColCompVisibility(false);
  build->setZValue(830);
  room->addItem(build);
}

{
  Environment* build = new Environment(120, 200, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/empty_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(1039, 1081);
  build->SetColCompVisibility(false);
  build->setZValue(1260);
  room->addItem(build);
}

{
  Environment* build = new Environment(119, 160, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/poor_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(880, 1121);
  build->SetColCompVisibility(false);
  build->setZValue(1260);
  room->addItem(build);
}

{
  Environment* build = new Environment(200, 200, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/maid_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(1080, 121);
  build->SetColCompVisibility(false);
  build->setZValue(300);
  room->addItem(build);
}

{
  Environment* build = new Environment(320, 519, CollisionLayer::NONE, room);
  build->SetPixmap(new QPixmap(":/imges/Images/buildings/mercenary_house.png"));
  build->CustomizeColComp(QVector2D(0, 0),
                          QVector2D(build->Width(), build->Height()));
  build->SetPos(1199, 881);
  build->SetColCompVisibility(false);
  build->setZValue(1180);
  room->addItem(build);
}
}

{
  {
    Environment* door =
        new Environment(14, 20, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(1054, 820);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["player_house_to_city"].append({door, QPoint(1040, 810)});
  }

  {
    Environment* door =
        new Environment(19, 21, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(372, 740);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["church_to_city"].append({door, QPoint(365, 745)});
    rooms_[room->GetName()] = room;
  }

  {
    Environment* door =
        new Environment(26, 23, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(1447, 617);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["city_to_hunterhs"].append({door, QPoint(1435, 643)});
    rooms_[room->GetName()] = room;
  }

  {
    Environment* door =
        new Environment(23, 23, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(409, 1178);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["city_to_traderhs"].append({door, QPoint(396, 1187)});
    rooms_[room->GetName()] = room;
  }

  {
    Environment* door =
        new Environment(22, 24, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(770, 255);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["city_to_mainhs"].append({door, QPoint(777, 300)});
    rooms_[room->GetName()] = room;
  }

  {
    Environment* door =
        new Environment(33, 33, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(1163, 285);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["city_to_maidhs"].append({door, QPoint(1150, 317)});
    rooms_[room->GetName()] = room;
  }

  {
    Environment* door =
        new Environment(30, 22, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(404, 295);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["city_to_nunhs"].append({door, QPoint(389, 307)});
    rooms_[room->GetName()] = room;
  }

  {
    Environment* door =
        new Environment(22, 27, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(929, 1253);
    door->SetColCompVisibility(false);
    door->SetVisibility(false);
    room->addItem(door);
    doors_["city_to_poorhs"].append({door, QPoint(918, 1263)});
    rooms_[room->GetName()] = room;
  }
}

connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("church", view);
  room->setSceneRect(0, 0, 504, 696);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/church_inside.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(22, 548, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(25, 49);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(71, 70, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(24, 576);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(121, 71, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(95, 625);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(142, 82, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(289, 624);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(70, 47, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(409, 578);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 554, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(457, 25);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(313, 69, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(145, 26);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(102, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(44, 49);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(68, 52, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(97, 67);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(72, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(336, 72);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(72, 95, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(120, 144);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
// Невидимые стены
{
  Environment* inv_walls =
      new Environment(25, 144, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(192, 120);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 143, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(288, 120);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(73, 96, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(310, 144);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(74, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(215, 120);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 23, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(241, 218);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(130, 240, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(76, 311);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(130, 240, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(302, 309);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* door = new Environment(55, 10, CollisionLayer::NONE, room);
  door->SetPos(224, 683);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["church_to_city"].append({door, QPoint{240, 600}});
}
}

{
  Environment* door = new Environment(17, 12, CollisionLayer::NONE, room);
  door->SetPos(76, 61);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["churchin_to_churchcab"].append({door, QPoint{60, 80}});
}

{
  Environment* door = new Environment(18, 19, CollisionLayer::NONE, room);
  door->SetPos(243, 219);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["churchin_to_churchbase"].append({door, QPoint{234, 252}});
}

// Пауза
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("churchcab", view);
  room->setSceneRect(0, 0, 216, 288);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/church_cabinet.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(216, 70, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 219, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 69);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 219, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(193, 69);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(94, 25, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(72, 71);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 27, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(96, 96);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(72, 26, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(72, 121);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(74, 47, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(22, 241);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(73, 49, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(120, 240);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(19, 12, CollisionLayer::NONE, room);
  door->SetPos(99, 273);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["churchin_to_churchcab"].append({door, QPoint{82, 175}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("churchbase", view);
  room->setSceneRect(0, 0, 456, 240);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/church_basement.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(105, 237, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(232, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(51, 62, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(335, 172);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(35, 69, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(324, 3);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(99, 20, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(356, 3);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(20, 220, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(433, 19);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(61, 18, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(379, 217);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(22, 22, CollisionLayer::NONE, room);
  door->SetPos(409, 123);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["churchin_to_churchbase"].append({door, QPoint{365, 95}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("hunterhs", view);
  room->setSceneRect(0, 0, 359, 311);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/hunter_house_inside.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(119, 94, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 96);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 52, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 189);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 44, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 234);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(98, 49, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(21, 264);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(214, 47, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(147, 265);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 260, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(336, 5);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(73, 56, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(240, 166);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(17, 18, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(244, 221);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(20, 20, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(314, 195);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(121, 52, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(216, 21);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(51, 50, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(287, 70);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(213, 68, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(2, 3);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(49, 35, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 65);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(121, 27, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(144, 69);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 76, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(192, 92);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(17, 20, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(148, 146);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(314, 240);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}
{
  Environment* door = new Environment(17, 18, CollisionLayer::NONE, room);
  door->SetPos(123, 292);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["city_to_hunterhs"].append({door, QPoint{109, 209}});
}

{
  Environment* door = new Environment(18, 16, CollisionLayer::NONE, room);
  door->SetPos(51, 77);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["hunterhs_to_hunterbase"].append({door, QPoint{85, 49}});
}

rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("hunterbase", view);
  room->setSceneRect(0, 0, 216, 288);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/hunter_house_basement.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(241, 22, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 3);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 218, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 18);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(220, 20, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(16, 216);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(21, 200, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(216, 18);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(72, 25, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(96, 23);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 11, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(25, 25);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 94, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(26, 98);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 22, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(49, 74);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(44, 39, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(169, 54);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 21, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(168, 172);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(20, 17, CollisionLayer::NONE, room);
  door->SetPos(194, 125);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["hunterhs_to_hunterbase"].append({door, QPoint{144, 102}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("traderhs", view);
  room->setSceneRect(0, 0, 576, 408);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/trader_house_inside.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(429, 45, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 361);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(118, 46, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(457, 362);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(96, 56, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(457, 256);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(74, 27, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(480, 311);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(47, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(506, 337);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 95, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(360, 193);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(192, 72, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(383, 192);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 191, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(552, 2);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(270, 69, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(283, 2);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(96, 22, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(456, 73);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(456, 95);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(96, 55, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(312, 95);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(65, 25, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(315, 70);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(19, 19, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(315, 148);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(18, 20, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(387, 147);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 288, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(265, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(265, 71, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(96, 26, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(96, 71);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(44, 46, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(122, 98);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(50, 49, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(94, 121);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(47, 51, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(120, 166);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(120, 71, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(72, 216);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(46, 50, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 69);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 98, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 119);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(73, 54, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(46, 311);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(46, 147, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 217);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 28, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(118, 337);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(29, 47, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(239, 143);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(55, 74, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(217, 215);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(18, 20, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(387, 146);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(21, 23, CollisionLayer::NONE, room);
  door->SetPos(434, 381);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["city_to_traderhs"].append({door, QPoint{407, 301}});
}

{
  Environment* door = new Environment(17, 18, CollisionLayer::NONE, room);
  door->SetPos(507, 173);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["traderhs_to_traderbase"].append({door, QPoint{450, 136}});
}

rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("traderbase", view);
  room->setSceneRect(0, 0, 240, 240);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/trader_basement.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(145, 71, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 47, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(145, 2);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(70, 21, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(169, 3);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 26, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(47, 70);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 166, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 73);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(25, 72);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 89, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(24, 148);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 67, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(48, 171);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 46, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(73, 195);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(143, 22, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(95, 217);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 201, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(216, 20);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(170, 169);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(19, 22, CollisionLayer::NONE, room);
  door->SetPos(196, 121);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["traderhs_to_traderbase"].append({door, QPoint{147, 94}});
}

rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("mainhs", view);
  room->setSceneRect(0, 0, 504, 480);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/main_house_1f.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(73, 288, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(23, 24);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(123, 95, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(92, 26);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(170, 126, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(166, 168);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(71, 119, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(25, 335);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 72, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(92, 216);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 73, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(146, 215);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 28, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(95, 117);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 65, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(97, 387);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(144, 145, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(192, 25);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 29, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(25, 308);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(115, 90, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(360, 30);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 60, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(335, 35);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(47, 115, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(432, 115);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(50, 73, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(335, 167);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 26, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(336, 238);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(71, 38, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(168, 279);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 97, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(384, 263);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 191, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(455, 261);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(170, 47, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(287, 407);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(98, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(118, 407);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 51, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(213, 432);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 46, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(267, 432);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 27, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(431, 238);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(19, 22, CollisionLayer::NONE, room);
  door->SetPos(245, 455);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["city_to_mainhs"].append({door, QPoint{227, 370}});
}

{
  Environment* door = new Environment(21, 20, CollisionLayer::NONE, room);
  door->SetPos(363, 337);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["mainhs_to_mainhs2f"].append({door, QPoint{311, 328}});
}

{
  Environment* door = new Environment(19, 14, CollisionLayer::NONE, room);
  door->SetPos(50, 318);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["mainhs_to_mainbase"].append({door, QPoint{100, 305}});
}

rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("mainhs2f", view);
  room->setSceneRect(0, 0, 408, 360);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/main_house_2f.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(162, 72, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(99, 191);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 72, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(24, 192);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 102, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(24, 91);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(359, 71, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(24, 24);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(50, 53, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(46, 91);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(124, 50, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(118, 95);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(71, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(144, 145);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(72, 50, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(25, 287);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(97, 54, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(288, 95);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(19, 21, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(267, 96);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(96, 72, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(290, 192);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(72, 22, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(312, 147);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(287, 22, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(97, 311);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(22, 26, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(25, 262);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(69, 51, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(313, 262);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 32, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(359, 165);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 31, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(312, 165);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(215, 170);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(21, 19, CollisionLayer::NONE, room);
  door->SetPos(293, 267);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["mainhs_to_mainhs2f"].append({door, QPoint{235, 255}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("mainbase", view);
  room->setSceneRect(0, 0, 240, 240);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/main_house_basemt.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(236, 23, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(2, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(21, 213, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(3, 22);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 130, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(23, 97);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(94, 50, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(144, 22);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(23, 21, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(169, 171);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(69, 46, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(170, 72);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 125, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(216, 115);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(192, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(24, 216);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(48, 170);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 27, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(48, 143);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 25, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(48, 72);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(24, 20, CollisionLayer::NONE, room);
  door->SetPos(72, 4);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["mainhs_to_mainbase"].append({door, QPoint{82, 34}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("maidhs", view);
  room->setSceneRect(0, 0, 336, 336);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/maid_house_inside.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(119, 47, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 289);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(120, 95, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 25);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 178, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 110);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 77, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(72, 143);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(26, 24, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(23, 266);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(19, 19, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(51, 172);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(20, 19, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(122, 147);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(17, 20, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(124, 194);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 75, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(119, 21);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(190, 52, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(145, 20);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 54, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(192, 67);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(142, 73, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(192, 142);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(191, 49, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(146, 287);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 50, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(192, 214);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(287, 215);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(287, 72);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(120, 168, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(312, 120);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(16, 20, CollisionLayer::NONE, room);
  door->SetPos(123, 311);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["city_to_maidhs"].append({door, QPoint{110, 195}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("nunhs", view);
  room->setSceneRect(0, 0, 264, 264);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/nun_house_inside.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(95, 95, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(48, 66, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 171);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 84, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 92);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(142, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(48, 217);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 26, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(47, 195);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 29, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(48, 90);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(168, 70, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(95, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(69, 77, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(193, 72);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(36, 40, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(172, 100);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(50, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(216, 217);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 75, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(240, 144);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(23, 22, CollisionLayer::NONE, room);
  door->SetPos(193, 240);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["city_to_nunhs"].append({door, QPoint{180, 169}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

{
  SceneBase* room = new SceneBase("poorhs", view);
  room->setSceneRect(0, 0, 168, 336);
  room->SetPaused(true);

  // Частота обновления кадров
  room->startTimer(30);

  QGraphicsPixmapItem* back = new QGraphicsPixmapItem(
      QPixmap(":/imges/Images/rooms/poor_house_inside.png"));
  room->addItem(back);
  back->setZValue(-1);

  {{Environment* inv_walls =
        new Environment(68, 45, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 289);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(70, 48, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(97, 288);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(143, 72, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(24, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(25, 290, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(1, 1);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(95, 46, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(72, 72);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 75, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(23, 70);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(28, 49, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(22, 166);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 171, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(144, 119);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}

{
  Environment* inv_walls =
      new Environment(24, 49, CollisionLayer::PHYSICS_BODY, room);
  inv_walls->CustomizeColComp(
      QVector2D(0, 0), QVector2D(inv_walls->Width(), inv_walls->Height()));
  inv_walls->SetPos(122, 144);
  inv_walls->SetColCompVisibility(false);
  inv_walls->SetVisibility(false);
  room->addItem(inv_walls);
}
}

{
  Environment* door = new Environment(18, 28, CollisionLayer::NONE, room);
  door->SetPos(74, 304);
  room->addItem(door);
  door->SetColCompVisibility(false);
  door->SetVisibility(false);
  doors_["city_to_poorhs"].append({door, QPoint{65, 234}});
}
rooms_[room->GetName()] = room;
connect(room, &SceneBase::SceneIsPaused, this, &CityLocation::SceneIsPaused);
}

// Персонаж
player_ = new Player(rooms_["player_house"]);
player_->MoveToScene(rooms_["player_house"]);
player_->SetPos(78, 122);
cur_room_ = {"player_house", rooms_["player_house"]};

//Двери
Door* player_house_to_city =
    new Door(doors_["player_house_to_city"][0].first,
             doors_["player_house_to_city"][1].first, rooms_["player_house"],
             rooms_["city"], doors_["player_house_to_city"][0].second,
             doors_["player_house_to_city"][1].second);

Door* church_to_city = new Door(
    doors_["church_to_city"][0].first, doors_["church_to_city"][1].first,
    rooms_["city"], rooms_["church"], doors_["church_to_city"][0].second,
    doors_["church_to_city"][1].second);

Door* churchin_to_churchcab =
    new Door(doors_["churchin_to_churchcab"][0].first,
             doors_["churchin_to_churchcab"][1].first, rooms_["church"],
             rooms_["churchcab"], doors_["churchin_to_churchcab"][0].second,
             doors_["churchin_to_churchcab"][1].second);

Door* churchin_to_churchbase =
    new Door(doors_["churchin_to_churchbase"][0].first,
             doors_["churchin_to_churchbase"][1].first, rooms_["church"],
             rooms_["churchbase"], doors_["churchin_to_churchbase"][0].second,
             doors_["churchin_to_churchbase"][1].second);

Door* city_to_hunterhs = new Door(
    doors_["city_to_hunterhs"][0].first, doors_["city_to_hunterhs"][1].first,
    rooms_["city"], rooms_["hunterhs"], doors_["city_to_hunterhs"][0].second,
    doors_["city_to_hunterhs"][1].second);

Door* hunterhs_to_hunterbase =
    new Door(doors_["hunterhs_to_hunterbase"][0].first,
             doors_["hunterhs_to_hunterbase"][1].first, rooms_["hunterhs"],
             rooms_["hunterbase"], doors_["hunterhs_to_hunterbase"][0].second,
             doors_["hunterhs_to_hunterbase"][1].second);

Door* city_to_traderhs = new Door(
    doors_["city_to_traderhs"][0].first, doors_["city_to_traderhs"][1].first,
    rooms_["city"], rooms_["traderhs"], doors_["city_to_traderhs"][0].second,
    doors_["city_to_traderhs"][1].second);

Door* traderhs_to_traderbase =
    new Door(doors_["traderhs_to_traderbase"][0].first,
             doors_["traderhs_to_traderbase"][1].first, rooms_["traderhs"],
             rooms_["traderbase"], doors_["traderhs_to_traderbase"][0].second,
             doors_["traderhs_to_traderbase"][1].second);

Door* city_to_mainhs = new Door(
    doors_["city_to_mainhs"][0].first, doors_["city_to_mainhs"][1].first,
    rooms_["city"], rooms_["mainhs"], doors_["city_to_mainhs"][0].second,
    doors_["city_to_mainhs"][1].second);

Door* mainhs_to_mainhs2f =
    new Door(doors_["mainhs_to_mainhs2f"][0].first,
             doors_["mainhs_to_mainhs2f"][1].first, rooms_["mainhs"],
             rooms_["mainhs2f"], doors_["mainhs_to_mainhs2f"][0].second,
             doors_["mainhs_to_mainhs2f"][1].second);

Door* mainhs_to_mainbase =
    new Door(doors_["mainhs_to_mainbase"][0].first,
             doors_["mainhs_to_mainbase"][1].first, rooms_["mainhs"],
             rooms_["mainbase"], doors_["mainhs_to_mainbase"][0].second,
             doors_["mainhs_to_mainbase"][1].second);

Door* city_to_maidhs = new Door(
    doors_["city_to_maidhs"][0].first, doors_["city_to_maidhs"][1].first,
    rooms_["city"], rooms_["maidhs"], doors_["city_to_maidhs"][0].second,
    doors_["city_to_maidhs"][1].second);

Door* city_to_nunhs =
    new Door(doors_["city_to_nunhs"][0].first, doors_["city_to_nunhs"][1].first,
             rooms_["city"], rooms_["nunhs"], doors_["city_to_nunhs"][0].second,
             doors_["city_to_nunhs"][1].second);

Door* city_to_poorhs = new Door(
    doors_["city_to_poorhs"][0].first, doors_["city_to_poorhs"][1].first,
    rooms_["city"], rooms_["poorhs"], doors_["city_to_poorhs"][0].second,
    doors_["city_to_poorhs"][1].second);

player_house_to_city->SetLocation(this);
church_to_city->SetLocation(this);
churchin_to_churchcab->SetLocation(this);
churchin_to_churchcab->SetLock(true);
churchin_to_churchbase->SetLocation(this);
churchin_to_churchbase->SetLock(true);
city_to_hunterhs->SetLocation(this);
hunterhs_to_hunterbase->SetLocation(this);
city_to_traderhs->SetLocation(this);
traderhs_to_traderbase->SetLocation(this);
city_to_mainhs->SetLocation(this);
city_to_mainhs->SetLock(true);
mainhs_to_mainhs2f->SetLocation(this);
mainhs_to_mainbase->SetLocation(this);
city_to_maidhs->SetLocation(this);
city_to_nunhs->SetLocation(this);
city_to_poorhs->SetLocation(this);

auto* place =
    new InteractableObject(40, 31, CollisionLayer::NONE, rooms_["city"], "key");
place->SetPos(1505, 365);
place->SetPixmap(QPixmap(":/imges/Images/hole.png"));
place->setVisible(false);
place->SetInteractAction([](GameView* view, Player* player) {
  if (view->flags_[ActionFlag::HOLE])
    view->DisplayText(view->dialog_notes.ShowText(NoteType::HUNTER));
});
rooms_["city"]->addItem(place);

{
  PickableObject* pickable_object =
      new PickableObject(34, 27, CollisionLayer::NONE, rooms_["city"], "key");
  pickable_object->SetPos(53, 870);
  pickable_object->SetActivateAction([place](GameView* view, Player* player) {
    auto objects = player->GetNearbyObjects();
    if (objects.contains(place)) {
      place->setVisible(true);
      view->flags_[ActionFlag::HOLE] = true;
      view->DisplayText("Из-под земли выглядывают листы бумаги.");
    }
  });
  pickable_object->SetPickText("Лопата.");
  rooms_["city"]->addItem(pickable_object);
  pickable_object->SetPixmap(QPixmap(":/imges/Images/shovel.png"));
}

{
  PickableObject* pickable_object = new PickableObject(
      20, 20, CollisionLayer::NONE, rooms_["traderbase"], "key");
  pickable_object->SetPos(50, 170);
  pickable_object->SetActivateAction(
      [churchin_to_churchbase](GameView* view, Player* player) {
        auto objects = player->GetNearbyObjects();
        if (objects.contains(churchin_to_churchbase)) {
          churchin_to_churchbase->SetLock(false);
          view->DisplayText("Проход открыт.");
        }
      });
  pickable_object->SetPickText("Неприметный медный ключ.");
  pickable_object->SetPixmap(QPixmap(":/imges/Images/key.png"));
  rooms_["traderbase"]->addItem(pickable_object);
}

{
  PickableObject* pickable_object = new PickableObject(
      35, 35, CollisionLayer::NONE, rooms_["mainhs2f"], "key");
  pickable_object->SetPos(290, 98);
  pickable_object->SetActivateAction(
      [churchin_to_churchcab](GameView* view, Player* player) {
        auto objects = player->GetNearbyObjects();
        if (objects.contains(churchin_to_churchcab)) {
          churchin_to_churchcab->SetLock(false);
          view->DisplayText("Дверь открыта.");
        }
      });
  pickable_object->SetPickText(
      "Связка ключей. Похоже тут есть ключ от каждого замка.");
  pickable_object->SetPixmap(QPixmap(":/imges/Images/keys.png"));
  rooms_["mainhs2f"]->addItem(pickable_object);
}

{
  PickableObject* pickable_object = new PickableObject(
      20, 20, CollisionLayer::NONE, rooms_["player_house"], "key");
  pickable_object->SetPos(200, 100);
  player_house_to_city->SetLock(true);
  pickable_object->SetActivateAction(
      [player_house_to_city](GameView* view, Player* player) {
        auto objects = player->GetNearbyObjects();
        if (objects.contains(player_house_to_city)) {
          player_house_to_city->GetFirstPart()->SetPixmap(
              new QPixmap(":/imges/Images/open_door.png"));
          player_house_to_city->GetFirstPart()->update();
          player_house_to_city->SetLock(false);
          view->DisplayText(
              "Еда может быть у старосты в подвале, раньше он распределял её "
              "по семьям, а остатки хранил у себя, на черный день. Может это и "
              "сейчас практикуется.");
        }
      });
  pickable_object->SetPickText("Старый медный ключ.");
  rooms_["player_house"]->addItem(pickable_object);
  pickable_object->SetPixmap(QPixmap(":/imges/Images/key.png"));
}

auto* church_table = new InteractableObject(23, 14, CollisionLayer::NONE,
                                            rooms_["churchcab"], "key");
church_table->SetPos(146, 73);
church_table->SetInteractAction([](GameView* view, Player* player) {
  if (view->flags_[ActionFlag::TABLE])
    view->DisplayText(view->dialog_notes.ShowText(NoteType::TABLE));
  else
    view->DisplayText(
        "В этой тумбочке есть странное отверстие. Наверняка магия...");
});
rooms_["churchcab"]->addItem(church_table);

{
  PickableObject* pickable_object =
      new PickableObject(35, 35, CollisionLayer::NONE, rooms_["church"], "key");
  pickable_object->SetPos(82, 313);
  pickable_object->SetActivateAction(
      [church_table](GameView* view, Player* player) {
        auto objects = player->GetNearbyObjects();
        if (objects.contains(church_table)) {
          view->flags_[ActionFlag::TABLE] = true;
          view->DisplayText("Ключ подошёл.");
        }
      });
  pickable_object->SetPixmap(QPixmap(":/imges/Images/stone.png"));
  pickable_object->SetPixmapVisible(false);
  pickable_object->SetPickText(
      "Магический камень. Интересно, какое у него предназначение?");
  rooms_["church"]->addItem(pickable_object);
}

{
  PickableObject* pickable_object =
      new PickableObject(20, 20, CollisionLayer::NONE, rooms_["maidhs"], "key");
  pickable_object->SetPos(146, 108);
  pickable_object->SetActivateAction(
      [city_to_mainhs](GameView* view, Player* player) {
        auto objects = player->GetNearbyObjects();
        if (objects.contains(city_to_mainhs)) {
          city_to_mainhs->GetFirstPart()->SetPixmap(
              new QPixmap(":/imges/Images/open_door.png"));
          city_to_mainhs->GetFirstPart()->update();
          city_to_mainhs->SetLock(false);
          view->DisplayText("Ключ подошёл.");
        }
      });
  pickable_object->SetPickText(
      "Металлический ключ. На вид использовался часто.");
  rooms_["maidhs"]->addItem(pickable_object);
  pickable_object->SetPixmap(QPixmap(":/imges/Images/old_key.png"));
}

{
  auto* object = new InteractableObject(20, 20, CollisionLayer::NONE,
                                        rooms_["player_house"], "key");
  object->SetPos(220, 175);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::BEGINNING));
  });
  rooms_["player_house"]->addItem(object);
}

{
  auto* object = new InteractableObject(10, 20, CollisionLayer::NONE,
                                        rooms_["player_house"], "key");
  object->SetPos(220, 195);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::PLAN));
  });
  rooms_["player_house"]->addItem(object);
}

{
  auto* object = new InteractableObject(16, 16, CollisionLayer::NONE,
                                        rooms_["poorhs"], "key");
  object->SetPos(123, 102);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::GIRL));
  });
  rooms_["poorhs"]->addItem(object);
}

{
  auto* object = new InteractableObject(16, 16, CollisionLayer::NONE,
                                        rooms_["nunhs"], "key");
  object->SetPos(27, 102);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::CLOISTRESS));
  });
  rooms_["nunhs"]->addItem(object);
}

{
  auto* object = new InteractableObject(15, 20, CollisionLayer::NONE,
                                        rooms_["mainhs"], "key");
  object->SetPos(55, 194);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::HEAD_DAUGHTER));
  });
  rooms_["mainhs"]->addItem(object);
}

{
  SceneBase* room = rooms_["mainhs"];
  Enemy* enemy_ = new Enemy(room);
  enemy_->setPos(344, 278);
  room->enemies_.append(enemy_);
  room->addItem(enemy_);
}

{
  SceneBase* room = rooms_["church"];
  Archer* enemy_ = new Archer(room);
  enemy_->setPos(240, 306);
  room->enemies_.append(enemy_);
  room->addItem(enemy_);
  enemy_->Push(QVector2D(1, 1), 1);
}

{
  auto* object = new InteractableObject(15, 20, CollisionLayer::NONE,
                                        rooms_["mainhs2f"], "key");
  object->SetPos(291, 122);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::STRONGBOX));
  });
  rooms_["mainhs2f"]->addItem(object);
}

{
  auto* object = new InteractableObject(14, 14, CollisionLayer::NONE,
                                        rooms_["traderhs"], "key");
  object->SetPos(150, 200);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::HEAD));
  });
  rooms_["traderhs"]->addItem(object);
}

{
  auto* object = new InteractableObject(23, 14, CollisionLayer::NONE,
                                        rooms_["churchcab"], "key");
  object->SetPos(97, 122);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(view->dialog_notes.ShowText(NoteType::PRIEST));
  });
  rooms_["churchcab"]->addItem(object);
}

{
  auto* object = new InteractableObject(24, 24, CollisionLayer::NONE,
                                        rooms_["church"], "key");
  object->SetPos(242, 218);
  object->SetInteractAction(
      [](GameView* view, Player* player) { view->DisplayText("Библия."); });
  rooms_["church"]->addItem(object);
}

{
  auto* object = new InteractableObject(240, 240, CollisionLayer::NONE,
                                        rooms_["mainbase"], "key");
  object->SetPos(0, 0);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(
        "Тут еды хватит мне на месяц, не так уж много, как я думал, но же "
        "неплохо. Переносить ее домой смысла мало, я могу тут ее брать.");
    view->flags_[ActionFlag::BASEMENT_FOOD] = true;
    if (view->flags_[ActionFlag::WELL]) view->EndDay();
  });
  rooms_["mainbase"]->addItem(object);
}

{
  auto* object = new InteractableObject(460, 240, CollisionLayer::NONE,
                                        rooms_["churchbase"], "key");
  object->SetPos(240, 70);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(
        "Чтобы такое откопать мне понадобиться время, но я так все не оставлю");
  });
  rooms_["churchbase"]->addItem(object);
}

{
  auto* object = new InteractableObject(40, 40, CollisionLayer::NONE,
                                        rooms_["city"], "key");
  object->SetPos(1040, 523);
  object->SetInteractAction([](GameView* view, Player* player) {
    view->DisplayText(
        "Колодец не пересох, да и вода вроде чистая, должна сгодится для "
        "питья.");
    view->flags_[ActionFlag::WELL] = true;
    if (view->flags_[ActionFlag::BASEMENT_FOOD]) view->EndDay();
  });
  rooms_["city"]->addItem(object);
}

{
  auto* object = new InteractableObject(24, 48, CollisionLayer::NONE,
                                        rooms_["player_house"], "key");
  object->SetPos(24, 73);
  object->SetInteractAction([](GameView* view, Player* player) {
    if (view->flags_[ActionFlag::ENDING]) view->OpenMenu();
  });
  rooms_["player_house"]->addItem(object);
}
}
