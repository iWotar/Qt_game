#ifndef DIALOGLABEL_H
#define DIALOGLABEL_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QFont>

class DialogLabel : public QObject {
  Q_OBJECT

 public:
  explicit DialogLabel(QWidget* parent = nullptr);

  void DisplayText(const QString& text);

 public slots:
  void hide();
  void show();

 private:
  QLabel* background_;
  QLabel* text_;
  QFont* font_;
};

#endif  // DIALOGLABEL_H
