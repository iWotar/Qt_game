#include "dialoglabel.h"

#include <QTimer>

DialogLabel::DialogLabel(QWidget* parent)
    : QObject(), background_(new QLabel(parent)), text_(new QLabel(parent)) {
  background_->setPixmap(QPixmap(":/imges/Images/dialog_background.png"));
  background_->resize(900, 150);
  background_->setGeometry((1280 - background_->width()) / 2,
                           720 - background_->height() - 50,
                           background_->width(), background_->height());

  const int text_border_offset = 30;
  text_->resize(background_->width() - 2 * text_border_offset,
                background_->height() - 2 * text_border_offset);
  text_->setText("<font color=\"white\">test</font>");
  text_->setGeometry((1280 - background_->width()) / 2 + text_border_offset,
                     720 - background_->height() - 50 + text_border_offset,
                     text_->width(), text_->height());

  font_ = new QFont;
  font_->setWeight(QFont::Bold);
  font_->setPixelSize(25);
  text_->setFont(*font_);
}

void DialogLabel::DisplayText(const QString& text) {
  text_->setText(QString("<font color=\"white\">%1</font>").arg(text));
  show();
  QTimer::singleShot(1000, this, &DialogLabel::hide);
}

void DialogLabel::hide() {
  text_->hide();
  background_->hide();
}

void DialogLabel::show() {
  text_->show();
  background_->show();
}
