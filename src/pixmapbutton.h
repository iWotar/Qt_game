#ifndef PIXMAPBUTTON_H
#define PIXMAPBUTTON_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>

class PixmapButton : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT

 public:
  explicit PixmapButton(QPixmap* img);

  void Resize(int32_t x, int32_t y);

  int32_t Width() const;
  int32_t Height() const;

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 signals:
  void Clicked();

 private:
  QPixmap* image_;

  int32_t width_;
  int32_t height_;
};

#endif  // PIXMAPBUTTON_H
