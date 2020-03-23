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

  void Resize(int x, int y);

  int Width() const;
  int Height() const;

 protected:
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

 signals:
  void Clicked();

 private:
  QPixmap* image_;

  int width_;
  int height_;
};

#endif  // PIXMAPBUTTON_H
