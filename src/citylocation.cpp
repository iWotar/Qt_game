#include "citylocation.h"

#include <QGraphicsPixmapItem>

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
    SceneBase* room = new SceneBase("base", view);
    room->setSceneRect(0, 0, 456, 360);
    room->SetPaused(true);

    // Частота обновления кадров
    room->startTimer(30);

    // Enemy* enemy_ = new Enemy(room);
    // enemy_->setPos(1800, 1600);
    // room->enemies_.append(enemy_);
    // room->addItem(enemy_);

    // Environment* block =
    //     new Environment(300, 200, CollisionLayer::PHYSICS_BODY, room);
    // block->SetPos(1000, 1000);
    // block->CustomizeColComp(QVector2D(100, 100), QVector2D(200, 200));
    // block->SetColCompVisibility(true);
    // room->addItem(block);

    // Environment* rect =
    //     new Environment(100, 100, CollisionLayer::PUSHABLE_BODY, room);
    // rect->SetPos(1600, 1600);
    // room->addItem(rect);

    // Environment* rect3 =
    //     new Environment(100, 100, CollisionLayer::PUSHABLE_BODY, room);
    // rect3->SetPos(1700, 1700);
    // room->addItem(rect3);

    // Environment* rect2 =
    //     new Environment(100, 100, CollisionLayer::PUSHABLE_BODY, room);
    // rect2->SetPos(1800, 1600);
    // room->addItem(rect2);

    // Environment* rect1 =
    //     new Environment(100, 100, CollisionLayer::PHYSICS_BODY, room);
    // rect1->SetPos(1700, 1500);
    // room->addItem(rect1);

    QGraphicsPixmapItem* back =
        new QGraphicsPixmapItem(QPixmap(":/imges/Images/house.png"));
    room->addItem(back);
    back->setZValue(-1);

    Environment* door = new Environment(24, 48, CollisionLayer::NONE, room);
    door->SetPixmap(new QPixmap(":/imges/Images/locked_door.png"));
    door->SetPos(216, 312);
    room->addItem(door);
    doors_["base_to_train"].append({door, QPoint{220, 290}});

    rooms_[room->GetName()] = room;
    connect(room, &SceneBase::SceneIsPaused, this,
            &CityLocation::SceneIsPaused);
  }

  {
    SceneBase* room = new SceneBase("train", view);
    room->setSceneRect(0, 0, 1600, 1600);
    room->SetPaused(true);

    QGraphicsPixmapItem* back =
        new QGraphicsPixmapItem(QPixmap(":/imges/Images/City.png"));
    room->addItem(back);
    back->setZValue(-1);

    // Частота обновления кадров
    room->startTimer(30);

    Enemy* enemy_ = new Enemy(room);
    enemy_->setPos(800, 800);
    room->enemies_.append(enemy_);
    room->addItem(enemy_);

    // {
    //   Environment* inv_walls =
    //       new Environment(1280, 530, CollisionLayer::PHYSICS_BODY, room);
    //   inv_walls->CustomizeColComp(QVector2D(0, 0), QVector2D(1280, 530));
    //   inv_walls->SetPos(1, 1);
    //   inv_walls->SetColCompVisibility(false);
    //   room->addItem(inv_walls);
    // }

    // {
    //   Environment* inv_walls =
    //       new Environment(1280, 100, CollisionLayer::PHYSICS_BODY, room);
    //   inv_walls->CustomizeColComp(
    //       QVector2D(0, 0), QVector2D(inv_walls->Width(),
    //       inv_walls->Height()));
    //   inv_walls->SetPos(1, 624);
    //   inv_walls->SetColCompVisibility(false);
    //   room->addItem(inv_walls);
    // }

    // {
    //   Environment* inv_walls =
    //       new Environment(108, 110, CollisionLayer::PHYSICS_BODY, room);
    //   inv_walls->CustomizeColComp(
    //       QVector2D(0, 0), QVector2D(inv_walls->Width(),
    //       inv_walls->Height()));
    //   inv_walls->SetPos(1, 440);
    //   inv_walls->SetColCompVisibility(false);
    //   room->addItem(inv_walls);
    // }

    // {
    //   Environment* inv_walls = new Environment(502, 110,
    //   CollisionLayer::PHYSICS_BODY, room); inv_walls->CustomizeColComp(
    //       QVector2D(0, 0), QVector2D(inv_walls->Width(),
    //       inv_walls->Height()));
    //   inv_walls->SetPos(368, 440);
    //   inv_walls->SetColCompVisibility(false);
    //   room->addItem(inv_walls);
    // }

    // {
    //   Environment* inv_walls = new Environment(300,
    //   110,CollisionLayer::PHYSICS_BODY, room); inv_walls->CustomizeColComp(
    //       QVector2D(0, 0), QVector2D(inv_walls->Width(),
    //       inv_walls->Height()));
    //   inv_walls->SetPos(1133, 440);
    //   inv_walls->SetColCompVisibility(false);
    //   room->addItem(inv_walls);
    // }

    Environment* door =
        new Environment(24, 48, CollisionLayer::PHYSICS_BODY, room);
    door->CustomizeColComp(QVector2D(0, 0),
                           QVector2D(door->Width(), door->Height()));
    door->SetPos(1160, 280);
    door->SetColCompVisibility(false);
    room->addItem(door);
    doors_["base_to_train"].append({door, QPoint(1168, 322)});

    rooms_[room->GetName()] = room;
    connect(room, &SceneBase::SceneIsPaused, this,
            &CityLocation::SceneIsPaused);
  }
  player_ = new Player(rooms_["base"]);
  player_->MoveToScene(rooms_["base"]);
  player_->SetPos(78, 122);
  cur_room_ = {"base", rooms_["base"]};

  Door* base_to_train = new Door(
      doors_["base_to_train"][0].first, doors_["base_to_train"][1].first,
      rooms_["base"], rooms_["train"], doors_["base_to_train"][0].second,
      doors_["base_to_train"][1].second);
  base_to_train->SetLocation(this);

  {
    PickableObject* pickable_object =
        new PickableObject(20, 20, CollisionLayer::NONE, rooms_["base"], "key");
    pickable_object->SetPos(200, 100);
    pickable_object->SetActivateAction(
        [base_to_train](GameView* view, Player* player) {
          auto objects = player->GetNearbyObjects();
          if (objects.contains(base_to_train)) {
            base_to_train->GetFirstPart()->SetPixmap(
                new QPixmap(":/imges/Images/open_door.png"));
            base_to_train->GetFirstPart()->update();
          }
        });
    rooms_["base"]->addItem(pickable_object);
    pickable_object->SetPixmap(QPixmap(":/imges/Images/key.png"));
  }

  PickableObject* pickable_object = new PickableObject(
      40, 20, CollisionLayer::NONE, rooms_["base"], "shotgun");
  pickable_object->SetPos(200, 200);
  pickable_object->SetActivateAction(
      [base_to_train](GameView* view, Player* player) {
        auto objects = player->GetNearbyObjects();
        if (objects.contains(base_to_train)) {
          base_to_train->GetFirstPart()->SetPixmap(
              new QPixmap(":/imges/Images/open_door.png"));
          base_to_train->GetFirstPart()->update();
        }
      });
  rooms_["base"]->addItem(pickable_object);
  pickable_object->SetPixmap(QPixmap(":/imges/Images/shotgun.png"));
}
