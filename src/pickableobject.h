#ifndef PICKABLEOBJECT_H_
#define PICKABLEOBJECT_H_

#include "interactableobject.h"

class PickableObject : public InteractableObject {
 public:
  using InteractableObject::InteractableObject;

  void DoInteractAction(GameView* par1, Player* par2) override;
};

#endif  // PICKABLEOBJECT_H_
