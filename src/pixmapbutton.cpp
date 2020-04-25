#include "pixmapbutton.h"

PixmapButton::PixmapButton(QPixmap* img)
    : QObject(), QGraphicsPixmapItem(), image_(img) {
  width_ = image_->width();
  height_ = image_->height();
}

void PixmapButton::Resize(int32_t x, int32_t y) {
  setPixmap(image_->scaled(x, y));
  width_ = x;
  height_ = y;
}

int32_t PixmapButton::Width() const { return width_; }

int32_t PixmapButton::Height() const { return height_; }

void PixmapButton::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  Q_UNUSED(event);

  emit Clicked();
}
