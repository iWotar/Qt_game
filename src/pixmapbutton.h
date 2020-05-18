#ifndef PIXMAPBUTTON_H
#define PIXMAPBUTTON_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include "scene_base.h"

class PixmapButton : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT

 public:
  PixmapButton(QPixmap img, QPixmap press_img);

  void Resize(int32_t x, int32_t y);

  int32_t Width() const;
  int32_t Height() const;
  QGraphicsTextItem* Text() const;
  ActionType GetType() const;
  void SetText(QGraphicsTextItem* text);
  void SetType(ActionType type);

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

 signals:
  void Clicked();

 private:
  QPixmap image_;
  QPixmap pressed_;

  QGraphicsTextItem* text_ = nullptr;
  ActionType button_type_ = ActionType::NONE;

  int32_t width_;
  int32_t height_;
};

#endif  // PIXMAPBUTTON_H
