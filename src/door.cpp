#include "door.h"

#include "citylocation.h"
#include "collisionrect.h"
#include "environment.h"
#include "player.h"
#include "scene_base.h"

Door::Door(Environment* first_part, Environment* second_part,
           SceneBase* first_scene, SceneBase* second_scene, QPoint first_coord,
           QPoint second_coord)
    : QGraphicsRectItem(),
      first_part_(first_part),
      second_part_(second_part),
      first_scene_(first_scene),
      second_scene_(second_scene),
      first_coord_(first_coord),
      second_coord_(second_coord) {
  first_part_->GetCollisionComponent()->SetObjectType(ObjectType::DOOR);
  second_part_->GetCollisionComponent()->SetObjectType(ObjectType::DOOR);
  first_part_->GetCollisionComponent()->SetParent(this);
  second_part_->GetCollisionComponent()->SetParent(this);
}

void Door::SetFirstScene(SceneBase* scene) { first_scene_ = scene; }

void Door::SetSecondScene(SceneBase* scene) { second_scene_ = scene; }

void Door::SetLocation(CityLocation* location) { location_ = location; }

void Door::SetDirType(DirectionType type) { dir_type_ = type; }

Environment* Door::GetSecondPart() const { return second_part_; }

Environment* Door::GetFirstPart() const { return first_part_; }

bool Door::Teleport(Player* player) {
  if (player->GetCurScene() == first_scene_ &&
      dir_type_ != DirectionType::SECOND_TO_FIRST) {
    player->MoveToScene(second_scene_);
    player->SetPos(second_coord_.x(), second_coord_.y());
    location_->ChangeCurScene(second_scene_);
    first_scene_->SetPaused(true);
    second_scene_->SetPaused(false);
    return true;
  } else if (player->GetCurScene() == second_scene_ &&
             dir_type_ != DirectionType::FIRST_TO_SECOND) {
    player->MoveToScene(first_scene_);
    player->SetPos(first_coord_.x(), first_coord_.y());
    location_->ChangeCurScene(first_scene_);
    first_scene_->SetPaused(false);
    second_scene_->SetPaused(true);
    return true;
  }
  return false;
}
