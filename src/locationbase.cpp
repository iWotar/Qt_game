#include "locationbase.h"

#include <QGraphicsPixmapItem>

#include "collisionrect.h"
#include "door.h"
#include "enemy.h"
#include "environment.h"
#include "gameview.h"
#include "scene_base.h"

LocationBase::LocationBase() : view_(nullptr), player_(nullptr) {}

SceneBase* LocationBase::GetCurScene() { return cur_room_.second; }

void LocationBase::ChangeCurScene(SceneBase* scene) {
  cur_room_ = {scene->GetName(), scene};
  view_->OpenLocation();
}

void LocationBase::SetView(GameView* view) { view_ = view; }
