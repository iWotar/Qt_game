#include "inventorylabel.h"

InventoryLabel::InventoryLabel(QWidget* parent) : QLabel(parent) {}

void InventoryLabel::setPixmap(const QPixmap& pixmap) {
  QLabel::setPixmap(pixmap.scaled(130, 130, Qt::KeepAspectRatio));
  setMinimumSize(130, 130);
  setMaximumSize(130, 130);
  resize(130, 130);
}
