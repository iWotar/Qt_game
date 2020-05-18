#ifndef INVENTORYLABEL_H
#define INVENTORYLABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>

class InventoryLabel : public QLabel {
  Q_OBJECT
 public:
  explicit InventoryLabel(QWidget* parent);

  void setPixmap(const QPixmap&);
};

#endif  // INVENTORYLABEL_H
