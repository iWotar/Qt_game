#include "pickableobject.h"

#include "collisionrect.h"
#include "gameview.h"
#include "player.h"
#include "scene_base.h"

void PickableObject::DoInteractAction(GameView* par1, Player* par2) {
  par2->inventory_.append(this);
  par2->parent_scene_->removeItem(this);
  par2->parent_scene_->removeItem(this->GetCollisionComponent());

  par1->UpdateInventoryLabels(par2->inventory_);

  if (text_ != "")
    par1->DisplayText(text_);
}

void PickableObject::SetPickText(const QString& str) {
  text_ = str;
}
