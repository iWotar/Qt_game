#include "pixmapbutton.h"

PixmapButton::PixmapButton(QPixmap* img) : QObject(),
                                           QGraphicsPixmapItem(),
                                           image_(img) {
  width_ = image_->width();
  height_ = image_->height();
}

void PixmapButton::Resize(int x, int y) {
  setPixmap(image_->scaled(x, y));
  width_ = x;
  height_ = y;
}

int PixmapButton::Width() const {
  return width_;
}

int PixmapButton::Height() const {
  return height_;
}

void PixmapButton::mousePressEvent(QGraphicsSceneMouseEvent* event) {
  Q_UNUSED(event);

  emit Clicked();
}
