#include "pixmapbutton.h"

PixmapButton::PixmapButton(QPixmap img, QPixmap press_img)
    : QObject(), QGraphicsPixmapItem(), image_(img), pressed_(press_img) {
  width_ = image_.width();
  height_ = image_.height();
  setPixmap(image_);
}

void PixmapButton::Resize(int32_t x, int32_t y) {
  setPixmap(pixmap().scaled(x, y));

  width_ = x;
  height_ = y;
}

int32_t PixmapButton::Width() const { return width_; }

int32_t PixmapButton::Height() const { return height_; }

QGraphicsTextItem *PixmapButton::Text() const { return text_; }

ActionType PixmapButton::GetType() const { return button_type_; }

void PixmapButton::SetText(QGraphicsTextItem *text) { text_ = text; }

void PixmapButton::SetType(ActionType type) { button_type_ = type; }

void PixmapButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);
  if (pixmap() == pressed_) {
    setPixmap(image_);
  } else {
    setPixmap(pressed_);
  }
}

void PixmapButton::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  Q_UNUSED(event);
  if (button_type_ != ActionType::SWITCH) {
    setPixmap(image_);
  }
  emit Clicked();
}
