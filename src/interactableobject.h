#ifndef INTERACTABLE_OBJECT_H_
#define INTERACTABLE_OBJECT_H_

#include <QGraphicsRectItem>
#include <QObject>
#include <QPair>
#include <QVector2D>

#include "movableentity.h"

enum class CollisionLayer;
class CollisionRect;
class SceneBase;
class GameView;
class Player;

typedef std::function<void(GameView*, Player*)> Action;

class InteractableObject : public MovableEntity {
 public:
  InteractableObject(int32_t width, int32_t height,
                     CollisionLayer physics_layer, SceneBase* parent_scene,
                     QString name);

  QString GetName() const;
  const QPixmap& GetPixmap() const { return *sprite_; }
  void SetPixmap(const QPixmap& pixmap) { sprite_ = new QPixmap(pixmap); }
  void EnableHighlight(bool);
  void SetPixmapVisible(bool);

  void SetInteractAction(const Action& action) { interact_action_ = action; }
  void SetActivateAction(const Action& action) { activate_action_ = action; }
  virtual void DoInteractAction(GameView* par1, Player* par2) {
    interact_action_(par1, par2);
  }
  void DoActivateAction(GameView* par1, Player* par2) {
    activate_action_(par1, par2);
  }

  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget) override;

 private:
  void ProcessMovement(QVector2D way) override;

  SceneBase* parent_scene_;
  QPixmap* sprite_ = nullptr;

  bool highlight_enabled_ = false;
  bool pixmap_visible_ = true;
  QString name_;
  Action interact_action_;
  Action activate_action_;
};

#endif  // INTERACTABLE_OBJECT_H_
