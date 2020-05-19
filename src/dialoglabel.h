#ifndef DIALOGLABEL_H
#define DIALOGLABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFont>
#include <QTimer>

class DialogLabel : public QObject {
  Q_OBJECT

 public:
  explicit DialogLabel(QWidget* parent = nullptr);

  void DisplayText(const QString& text, bool timeout = true);

 public slots:
  void hide();
  void show();

 private:
  QLabel* background_;
  QLabel* text_;
  QFont* font_;

  QTimer* timer_;
};

#endif  // DIALOGLABEL_H
